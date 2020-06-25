
#include "constante.h"
#include "jeux.h"

/**
* @struct button
* @brief struct for button
*/

typedef struct {
  char *text;
  SDL_Surface *surface;/*!< Surface. */
  SDL_Rect pos;/*!< Rectangle*/
  SDL_Color rgb;
  void (*function)(SDL_Surface *screen);
} Button;

/**
* @struct opt
* @brief struct for opt
*/

typedef struct
{
    SDL_Surface *op[3];/*!< Surface*/
    SDL_Surface *backbutton[3];/*!< Surface. */
    SDL_Rect pos;/*!< Rectangle*/
    SDL_Rect pos_msgson;/*!< Rectangle*/
    SDL_Rect pos_msgvolume;/*!< Rectangle*/
    SDL_Rect back;/*!< Rectangle*/
}opt;



/* Les fonctions */
void option(SDL_Surface *screen);
void initMenu(char font_name[]);
void afficherImg(SDL_Surface *screen, int x, int y, char *cheminFichier);
void afficherColor(SDL_Surface *screen, int hexaColorValue);
SDL_Color colorConverter(unsigned long hexaColorValue);
SDL_Surface *initText(char text[], int fontSize, int hexColorFont, int parametresTTF);
void afficherText(SDL_Surface *surface, SDL_Surface *textSurface, int x, int y);
Button initButtonImg(int x, int y, char cheminFichier[100], void (*function)());
Button initBtnRect(int x, int y, int w, int h,int hexColorRect, char text[], int fontSize, int hexColorFont,int parametresTTF, void (*function)());
void afficherButton(Button button, SDL_Surface *screen);
void afficherMenu(Button boutonsDuMenu[], SDL_Surface *screen, int nbButton);
int clickButton(Button button, SDL_Event event);
int waitEvent(Button boutonsDuMenu[], SDL_Surface *screen, int nbButton);



/*  Definition des fonctions */
char *fontName = NULL;

void initMenu(char font_name[]){
  fontName = font_name;
  if(TTF_Init() == -1) {
    fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
    exit(EXIT_FAILURE);
  }
}

void afficherImg(SDL_Surface *screen, int x, int y, char *cheminFichier){
  SDL_Surface *img = IMG_Load(cheminFichier);
  SDL_Rect position = {x, y};
  SDL_BlitSurface(img, NULL, screen, &position);
  SDL_FreeSurface(img);
  SDL_Flip(screen);
}

void afficherColor(SDL_Surface *screen, int hexColor){
  SDL_Color color = colorConverter(hexColor);
  SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, color.r, color.g, color.b));
  SDL_Flip(screen);
}

//char *fontName = NULL;
	SDL_Color colorConverter(unsigned long hexaColorValue) {
  	SDL_Color rgbColor;
  	rgbColor.r = ((hexaColorValue >> 16) & 0xFF);      
  	rgbColor.g = ((hexaColorValue >> 8) & 0xFF);    
  	rgbColor.b = ((hexaColorValue) & 0xFF);            
  	return rgbColor;
	}


SDL_Surface *initText(char text[], int fontSize, int hexColorFont, int parametresTTF){
  TTF_Font *font;
  SDL_Surface *textSurface;
  font = TTF_OpenFont(fontName, fontSize);
  TTF_SetFontStyle(font, parametresTTF);
  textSurface = TTF_RenderText_Blended(font, text, colorConverter(hexColorFont));
  TTF_CloseFont(font);
  return textSurface;
}

void afficherText(SDL_Surface *surface, SDL_Surface *textSurface, int x, int y){
  SDL_Rect position;
  position.x = x;
  position.y = y;
  SDL_BlitSurface(textSurface, NULL, surface, &position);
  SDL_FreeSurface(textSurface);
  SDL_Flip(surface);
}

Button initButtonImg(int x, int y, char cheminFichier[100], void (*function)()){
  Button button;
  button.pos.x = x;
  button.pos.y = y;
  button.surface = IMG_Load(cheminFichier);
  button.function = function;
  return button;
}

Button initBtnRect(
      int x, int y, int w, int h,
      int hexColorRect, char text[], int fontSize, int hexColorFont,
      int parametresTTF, void (*function)()
      )
      {
  Button button;
  button.pos.x = x;
  button.pos.y = y;
  button.text = text;
  button.surface = SDL_CreateRGBSurface(SDL_SWSURFACE, w, h, 32, 0, 0, 0, 0);
  button.function = function;

  SDL_Color color = colorConverter(hexColorRect);
  SDL_FillRect(button.surface, NULL, SDL_MapRGB(button.surface->format, color.r, color.g, color.b));
  SDL_Surface *textSurface = initText(text, fontSize, hexColorFont, parametresTTF);
  afficherText(button.surface, textSurface,
    ((button.surface->w)/2)-((textSurface->w)/2),
    ((button.surface->h)/2)-((textSurface->h)/2));
  return button;
}


void afficherButton(Button button, SDL_Surface *screen){
  SDL_BlitSurface(button.surface, NULL, screen, &button.pos);
  SDL_FreeSurface(button.surface);
  SDL_Flip(screen);
}

void afficherMenu(Button boutonsDuMenu[], SDL_Surface *screen, int nbButton){
  for (int i = 0; i < nbButton; i++) {
    afficherButton(boutonsDuMenu[i], screen);
  }
}

int clickButton(Button button, SDL_Event event){
  if(event.button.button == SDL_BUTTON_LEFT
        && event.button.x > button.pos.x
        && event.button.x < button.pos.x + button.surface->w
        && event.button.y > button.pos.y
        && event.button.y < button.pos.y + button.surface->h)
        return 1;
  return 0;
}



int waitEvent(Button boutonsDuMenu[], SDL_Surface *screen, int nbButton){
  int loop = 1;
  SDL_Event event;
  SDL_Rect pos;

  while (loop) {
    SDL_WaitEvent(&event);
    switch(event.type) {
      case SDL_QUIT:
            SDL_Quit();
            exit(0);
      case SDL_MOUSEBUTTONUP:
        for(int i=0; i < nbButton; i++){
          if (clickButton(boutonsDuMenu[i], event)){

              (*boutonsDuMenu[i].function)(screen);

              break;
          }
        }
    }
  }
}
