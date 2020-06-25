
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "menu.h"
#include <SDL/SDL_mixer.h>

/**
* @file menu3.c
* @brief Testing Program.
* @author C Team
* @version 0.1
* @date jun 10, 2020
*
* Testing program for background scrollilng
*
*/

//***Global variable

int actual_etat_volume=64;



// Les fonctions
	void option(SDL_Surface *screen);
	void menu_General(SDL_Surface *screen);
	void settings(SDL_Surface *screen);
	void play(SDL_Surface *screen);
	void jouerMusic(char *nomFichierMusic);
	void arreterMusic();
	void soundControl();
	void volume_plus();
	void volume_moin();
//fentre du Menu General
	void menu_General(SDL_Surface *screen){
	
  	SDL_Event event;
  	int btnH = 80, btnW = 240;
  	int xCentre = (screen->w)/2 - btnW/2;
  	int loop = 1;
  	Button boutonsDuMenu[3] = {
    	initBtnRect(xCentre, btnH  + 40, btnW, btnH, 0xFFFF00, "Play ", 50, 0xFF0000,  TTF_STYLE_BOLD, play),
    	initBtnRect(xCentre, 2* (btnH + 10)+40, btnW, btnH, 0xFFFF00, "options", 50, 0xFF0000, TTF_STYLE_BOLD, option),
    	initBtnRect(xCentre, 3 * (btnH + 15)+40, btnW, btnH, 0xFFFF00, "Exit", 50, 0xFF0000, TTF_STYLE_BOLD, exit),
  	};

  	SDL_Surface *text = initText("Menu", 36, 0xFF0000, TTF_STYLE_BOLD);
  	afficherColor(screen, 0xFFFFFF);
  	afficherImg(screen, 50, 100, "../img/backg.png");
  	afficherText(screen, text, (screen->w)/2 - (text->w)/2 , 40);
  	afficherMenu(boutonsDuMenu, screen, 3);

  while (loop) {
    SDL_WaitEvent(&event);
    switch(event.type) {
      case SDL_QUIT:
            SDL_Quit();
            exit(0);
      case SDL_MOUSEBUTTONUP:
        for(int i=0; i < 3; i++){
          if (clickButton(boutonsDuMenu[i], event)){
		arreterMusic() ;
	(*boutonsDuMenu[i].function)(screen);
              break;
          }
        }
    }
  }

}


// fentre du Menu play
	void play(SDL_Surface *screen){
	SDL_Event event;
  	int btnH = 80, btnW = 240;
  	int xCentre = (screen->w)/2 - btnW/2;
  	int loop = 1;
  	Button boutonsDuMenu[4] = {
   	initBtnRect(xCentre, 140, btnW, btnH, 0xFFFF00, "Level 1 ", 50, 0xFF0000,  TTF_STYLE_BOLD, jouer),
  	initBtnRect(xCentre, 240, btnW, btnH, 0xFFFF00, "Level 2 ", 50, 0xFF0000,  TTF_STYLE_BOLD, menu_General),
   	initBtnRect(xCentre, 340, btnW, btnH, 0xFFFF00, "Level 3 ", 50, 0xFF0000,  TTF_STYLE_BOLD, menu_General),
    	initButtonImg(50, (screen->h) - 150, "../img/backMenu.png", menu_General),
  	};
  	afficherColor(screen, 0xFFFFFF);
    	afficherImg(screen, 50, 100, "../img/backg.png");	
  	afficherMenu(boutonsDuMenu, screen, 4);

while (loop) {
    SDL_WaitEvent(&event);
    switch(event.type) {
      case SDL_QUIT:
            SDL_Quit();
            exit(0);
      case SDL_MOUSEBUTTONUP:
        for(int i=0; i < 4; i++){
          if (clickButton(boutonsDuMenu[i], event)){
		arreterMusic();
              	(*boutonsDuMenu[i].function)(screen);
              break;
          }
        }
    }
  }

  	
}


void jouerMusic(char *nomFichierMusic){
	Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);
  	Mix_Music *musique;
  	musique=Mix_LoadMUS(nomFichierMusic);
  	  	Mix_VolumeMusic(5);
	Mix_PlayMusic(musique,-1);
	}
	
void arreterMusic(){
                Mix_CloseAudio();
}

//******


void option(SDL_Surface *screen){
	SDL_Event event;
	int done=1;
	opt c;
	int x;
  	int btnH = 80, btnW = 240;
  	int xCentre = (screen->w)/2 - btnW/2;
  	int loop = 1;
  Mix_Music *music;
	SDL_Surface* SON=IMG_Load("../img/son.png");
	SDL_Surface* msg_son=IMG_Load("../img/ad.png");
	SDL_Surface* msg_volume=IMG_Load("../img/audi.png");
        c.op[0]=IMG_Load("soundVolume0.png");
        c.op[1]=IMG_Load("soundVolume1.png");
        c.op[2]=IMG_Load("soundVolume2.png");

	if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
   	{
      		printf("%s", Mix_GetError());
   	}


   music = Mix_LoadMUS("../img/menuMusic1.mp3");
  Mix_PlayMusic(music, -1); //Jouer infiniment la musique

  	Button boutonsDuMenu[5] = {
    	initBtnRect(1000, 310 , 40, 40, 0xFFFF00, "+ ", 50, 0xFF0000,  TTF_STYLE_BOLD, volume_plus),
	initButtonImg(1000, 140, "../img/sound.png", option),
    	initButtonImg(600,140, "../img/noSound.png", option),
    	initBtnRect(600, 310 , 40, 40, 0xFFFF00, "- ", 50, 0xFF0000,  TTF_STYLE_BOLD, volume_moin),
   	initButtonImg(50, (screen->h) - 150, "../img/backMenu.png", menu_General),

  	};

  	afficherColor(screen, 0xFFFFFF);
    	afficherImg(screen, 50, 100, "../img/backg.png");	
    	afficherImg(screen, 670, 130, "../img/son.png");	
    	afficherImg(screen, 1050, 90, "../img/ad.png");	
	afficherImg(screen, 700, 310, "soundVolume1.png");
    	afficherImg(screen, 950, 250, "../img/message+.png");	
  	afficherMenu(boutonsDuMenu, screen, 5);

	while (loop) 
	{
    		SDL_WaitEvent(&event);
    		switch(event.type) 
		{
      		case SDL_QUIT:
            		SDL_Quit();
            		exit(0);
      		case SDL_MOUSEBUTTONUP:
        		for(int i=0; i < 6; i++)
			{
          			if (clickButton(boutonsDuMenu[i], event))
				{
					arreterMusic();
              				(*boutonsDuMenu[i].function)(screen);
              			break;
          			}
        		}
    		}
  	}

  	
}

void volume_plus(SDL_Surface* screen)
{
	
SDL_Event event;

	int done=1;
	opt c;
	int x;
  	int btnH = 80, btnW = 240;
  	int xCentre = (screen->w)/2 - btnW/2;
  	int loop = 1;
  Mix_Music *music;
	SDL_Surface* SON=IMG_Load("../img/son.png");
	SDL_Surface* msg_son=IMG_Load("../img/ad.png");
	SDL_Surface* msg_volume=IMG_Load("../img/audi.png");
        c.op[0]=IMG_Load("soundVolume0.png");
        c.op[1]=IMG_Load("soundVolume1.png");
        c.op[2]=IMG_Load("soundVolume2.png");

	if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
   	{
      		printf("%s", Mix_GetError());
   	}


   music = Mix_LoadMUS("../img/menuMusic1.mp3");
  Mix_PlayMusic(music, -1); //Jouer infiniment la musique

  	Button boutonsDuMenu[5] = {
    	initBtnRect(1000, 310 , 40, 40, 0xFFFF00, "+ ", 50, 0xFF0000,  TTF_STYLE_BOLD,volume_plus),
	initButtonImg(1000, 140, "../img/sound.png", option),
    	initButtonImg(600,140, "../img/noSound.png", option),
    	initBtnRect(600, 310 , 40, 40, 0xFFFF00, "- ", 50, 0xFF0000,  TTF_STYLE_BOLD, volume_moin),
   	initButtonImg(50, (screen->h) - 150, "../img/backMenu.png", menu_General),

  	};

  	afficherColor(screen, 0xFFFFFF);
    	afficherImg(screen, 50, 100, "../img/backg.png");	
    	afficherImg(screen, 670, 130, "../img/son.png");	
    	afficherImg(screen, 1050, 90, "../img/ad.png");	

	if(actual_etat_volume==128)
	{
    		afficherImg(screen, 700, 310, "soundVolume0.png");	
		actual_etat_volume=128;
		Mix_VolumeMusic(128);
    	}
	else if(actual_etat_volume==64)
	{
    		afficherImg(screen, 700, 310, "soundVolume1.png");	
		actual_etat_volume=128;
		Mix_VolumeMusic(128);
    	}
	else
	{
    		afficherImg(screen, 700, 310, "soundVolume2.png");	
		actual_etat_volume=64;
		Mix_VolumeMusic(64);
    	}
	afficherImg(screen, 1050, 250, "../img/audi.png");	
  	afficherMenu(boutonsDuMenu, screen, 5);

	while (loop) 
	{
    		SDL_WaitEvent(&event);
    		switch(event.type) 
		{
      		case SDL_QUIT:
            		SDL_Quit();
            		exit(0);
      		case SDL_MOUSEBUTTONUP:
        		for(int i=0; i < 6; i++)
			{
          			if (clickButton(boutonsDuMenu[i], event))
				{
					arreterMusic();
              				(*boutonsDuMenu[i].function)(screen);
              			break;
          			}
        		}
    		}
  	}

  	
}



void volume_moin(SDL_Surface* screen)
{
	
SDL_Event event;

	int done=1;
	opt c;
	int x;
  	int btnH = 80, btnW = 240;
  	int xCentre = (screen->w)/2 - btnW/2;
  	int loop = 1;
  Mix_Music *music;
	SDL_Surface* SON=IMG_Load("../img/son.png");
	SDL_Surface* msg_son=IMG_Load("../img/ad.png");
	SDL_Surface* msg_volume=IMG_Load("../img/audi.png");
        c.op[0]=IMG_Load("soundVolume0.png");
        c.op[1]=IMG_Load("soundVolume1.png");
        c.op[2]=IMG_Load("soundVolume2.png");

	if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
   	{
      		printf("%s", Mix_GetError());
   	}


   music = Mix_LoadMUS("../img/menuMusic1.mp3");
  Mix_PlayMusic(music, -1); //Jouer infiniment la musique

  	Button boutonsDuMenu[5] = {
    	initBtnRect(1000, 310 , 40, 40, 0xFFFF00, "+ ", 50, 0xFF0000,  TTF_STYLE_BOLD,volume_plus),
	initButtonImg(1000, 140, "../img/sound.png", option),
    	initButtonImg(600,140, "../img/noSound.png", option),
    	initBtnRect(600, 310 , 40, 40, 0xFFFF00, "- ", 50, 0xFF0000,  TTF_STYLE_BOLD, volume_moin),
   	initButtonImg(50, (screen->h) - 150, "../img/backMenu.png", menu_General),

  	};

  	afficherColor(screen, 0xFFFFFF);
    	afficherImg(screen, 50, 100, "../img/backg.png");	
    	afficherImg(screen, 670, 130, "../img/son.png");	
    	afficherImg(screen, 1050, 90, "../img/ad.png");	

	if(actual_etat_volume==128)
	{
    		afficherImg(screen, 700, 310, "soundVolume1.png");	
		actual_etat_volume=64;
		Mix_VolumeMusic(64);
    	}
	else if(actual_etat_volume==64)
	{
    		afficherImg(screen, 700, 310, "soundVolume2.png");	
		actual_etat_volume=0;
Mix_VolumeMusic(0);
    	}
	else
	{
    		afficherImg(screen, 700, 310, "soundVolume2.png");	
		actual_etat_volume=0;
Mix_VolumeMusic(0);
    	}
	afficherImg(screen, 1050, 250, "../img/audi.png");	
  	afficherMenu(boutonsDuMenu, screen, 5);

	while (loop) 
	{
    		SDL_WaitEvent(&event);
    		switch(event.type) 
		{
      		case SDL_QUIT:
            		SDL_Quit();
            		exit(0);
      		case SDL_MOUSEBUTTONUP:
        		for(int i=0; i < 6; i++)
			{
          			if (clickButton(boutonsDuMenu[i], event))
				{
					arreterMusic();
              				(*boutonsDuMenu[i].function)(screen);
              			break;
          			}
        		}
    		}
  	}

  	
}






void main(){
  SDL_Surface *screen = NULL;
  SDL_Init(SDL_INIT_VIDEO);
  screen = SDL_SetVideoMode(1600, 600, 32, SDL_SWSURFACE);
 
  
  SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
  SDL_Flip(screen);
  initMenu("Ubuntu-Bold.ttf");
  SDL_Flip(screen);

  menu_General(screen);

  SDL_Quit();
  exit(0);
}

