#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <time.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h> 
#include <SDL/SDL_ttf.h>
#include "jeux.h"
#include "constante.h"

	SDL_Rect *position_Medecin;
	SDL_Rect *position_Corona;
	int CARTE[11][40];
	int continuer=1;
	int i=0;
	int j=0;
	int scoreMedecin;
	int scoreCorona;

	 
void 	placementAleatoireObstac()
{
	int a=0;
	int b=0;
	int v;
	srand(time(NULL));
	for(a=1;a<11;a +=1)
	{
		for(b=2;b<40;b +=1)
		{
			if((CARTE[a][b]==0)&&(CARTE[a][b]!=MEDECIN))
			{
				v=rand()%2;
				if(v==0)
				{
					CARTE[a][b]=OBSTACLE_BLEU;
				}
			}
		}
	}

	for(a=1;a<11;a++)
	{
		for(b=2;b<40;b++)
		{
			if(CARTE[a][b]==MEDECIN)
			{
				if(CARTE[a+1][b]==3)
				{
					CARTE[a+1][b]=0;
				}

				if(CARTE[a-1][b]==3)
				{
					CARTE[a-1][b]=0;
				}

				if(CARTE[a][b+1]==3)
				{
					CARTE[a][b]=0;
				}

				if(CARTE[a][b-1]==3)
				{
					CARTE[a][b-1]=0;
				}
			}
		}
	}
}

 
void jouer(SDL_Surface* screen)
{
  	 //initialisation des objets 
//la carte 
CARTE[0][0]=1;
CARTE[0][1]=1;
CARTE[0][2]=1;
CARTE[0][3]=1;
CARTE[0][4]=1;
CARTE[0][5]=1;
CARTE[0][6]=1;
CARTE[0][7]=1;
CARTE[0][8]=1;
CARTE[0][9]=1;
CARTE[0][10]=1;
CARTE[0][11]=1;
CARTE[0][12]=1;
CARTE[0][13]=1;
CARTE[0][14]=1;
CARTE[0][15]=1;
CARTE[0][16]=1;
CARTE[0][17]=1;
CARTE[0][18]=1;
CARTE[0][19]=1;
CARTE[0][20]=1;
CARTE[0][21]=1;
CARTE[0][22]=1;
CARTE[0][23]=1;
CARTE[0][24]=1;
CARTE[0][25]=1;
CARTE[0][26]=1;
CARTE[0][27]=1;
CARTE[0][28]=1;
CARTE[0][29]=1;
CARTE[0][30]=1;
CARTE[0][31]=1;
CARTE[0][32]=1;
CARTE[0][33]=1;
CARTE[0][34]=1;
CARTE[0][35]=1;
CARTE[0][36]=1;
CARTE[0][37]=1;
CARTE[0][38]=1;
CARTE[0][39]=1;

CARTE[1][0]=1;
CARTE[1][1]=0;
CARTE[1][2]=0;
CARTE[1][3]=0;
CARTE[1][4]=0;
CARTE[1][5]=0;
CARTE[1][6]=0;
CARTE[1][7]=0;
CARTE[1][8]=0;
CARTE[1][9]=0;
CARTE[1][10]=0;
CARTE[1][11]=0;
CARTE[1][12]=0;
CARTE[1][13]=0;
CARTE[1][14]=0;
CARTE[1][15]=0;
CARTE[1][16]=0;
CARTE[1][17]=0;
CARTE[1][18]=0;
CARTE[1][19]=0;
CARTE[1][20]=0;
CARTE[1][21]=0;
CARTE[1][22]=0;
CARTE[1][23]=0;
CARTE[1][24]=0;
CARTE[1][25]=0;
CARTE[1][26]=0;
CARTE[1][27]=0;
CARTE[1][28]=0;
CARTE[1][29]=0;
CARTE[1][30]=0;
CARTE[1][31]=0;
CARTE[1][32]=0;
CARTE[1][33]=0;
CARTE[1][34]=0;
CARTE[1][35]=0;
CARTE[1][36]=0;
CARTE[1][37]=0;
CARTE[1][38]=0;
CARTE[1][39]=1;

CARTE[2][0]=1;
CARTE[2][1]=0;
CARTE[2][2]=0;
CARTE[2][3]=0;
CARTE[2][4]=0;
CARTE[2][5]=0;
CARTE[2][6]=0;
CARTE[2][7]=0;
CARTE[2][8]=0;
CARTE[2][9]=0;
CARTE[2][10]=0;
CARTE[2][11]=0;
CARTE[2][12]=0;
CARTE[2][13]=0;
CARTE[2][14]=0;
CARTE[2][15]=0;
CARTE[2][16]=0;
CARTE[2][17]=0;
CARTE[2][18]=0;
CARTE[2][19]=0;
CARTE[2][20]=0;
CARTE[2][21]=0;
CARTE[2][22]=0;
CARTE[2][23]=0;
CARTE[2][24]=0;
CARTE[2][25]=0;
CARTE[2][26]=0;
CARTE[2][27]=0;
CARTE[2][28]=0;
CARTE[2][29]=0;
CARTE[2][30]=0;
CARTE[2][31]=0;
CARTE[2][32]=0;
CARTE[2][33]=0;
CARTE[2][34]=0;
CARTE[2][35]=0;
CARTE[2][36]=0;
CARTE[2][37]=0;
CARTE[2][38]=0;
CARTE[2][39]=1;

CARTE[3][0]=1;
CARTE[3][1]=0;
CARTE[3][2]=0;
CARTE[3][3]=1;
CARTE[3][4]=1;
CARTE[3][5]=1;
CARTE[3][6]=1;
CARTE[3][7]=0;
CARTE[3][8]=0;
CARTE[3][9]=1;
CARTE[3][10]=1;
CARTE[3][11]=1;
CARTE[3][12]=1;
CARTE[3][13]=0;
CARTE[3][14]=0;
CARTE[3][15]=1;
CARTE[3][16]=1;
CARTE[3][17]=1;
CARTE[3][18]=1;
CARTE[3][19]=0;
CARTE[3][20]=0;
CARTE[3][21]=1;
CARTE[3][22]=1;
CARTE[3][23]=1;
CARTE[3][24]=1;
CARTE[3][25]=0;
CARTE[3][26]=0;
CARTE[3][27]=1;
CARTE[3][28]=0;
CARTE[3][29]=0;
CARTE[3][30]=1;
CARTE[3][31]=0;
CARTE[3][32]=0;
CARTE[3][33]=1;
CARTE[3][34]=1;
CARTE[3][35]=1;
CARTE[3][36]=1;
CARTE[3][37]=0;
CARTE[3][38]=0;
CARTE[3][39]=1;

CARTE[4][0]=0;
CARTE[4][1]=0;
CARTE[4][2]=0;
CARTE[4][3]=1;
CARTE[4][4]=0;
CARTE[4][5]=0;
CARTE[4][6]=0;
CARTE[4][7]=0;
CARTE[4][8]=0;
CARTE[4][9]=1;
CARTE[4][10]=1;
CARTE[4][11]=1;
CARTE[4][12]=1;
CARTE[4][13]=0;
CARTE[4][14]=0;
CARTE[4][15]=1;
CARTE[4][16]=1;
CARTE[4][17]=1;
CARTE[4][18]=1;
CARTE[4][19]=0;
CARTE[4][20]=0;
CARTE[4][21]=1;
CARTE[4][22]=1;
CARTE[4][23]=1;
CARTE[4][24]=1;
CARTE[4][25]=0;
CARTE[4][26]=0;
CARTE[4][27]=1;
CARTE[4][28]=1;
CARTE[4][29]=0;
CARTE[4][30]=1;
CARTE[4][31]=0;
CARTE[4][32]=0;
CARTE[4][33]=1;
CARTE[4][34]=1;
CARTE[4][35]=1;
CARTE[4][36]=1;
CARTE[4][37]=0;
CARTE[4][38]=0;
CARTE[4][39]=0;

CARTE[5][0]=0;
CARTE[5][1]=0;
CARTE[5][2]=0;
CARTE[5][3]=1;
CARTE[5][4]=0;
CARTE[5][5]=0;
CARTE[5][6]=0;
CARTE[5][7]=0;
CARTE[5][8]=0;
CARTE[5][9]=1;
CARTE[5][10]=1;
CARTE[5][11]=1;
CARTE[5][12]=1;
CARTE[5][13]=0;
CARTE[5][14]=0;
CARTE[5][15]=1;
CARTE[5][16]=1;
CARTE[5][17]=1;
CARTE[5][18]=1;
CARTE[5][19]=0;
CARTE[5][20]=0;
CARTE[5][21]=1;
CARTE[5][22]=1;
CARTE[5][23]=1;
CARTE[5][24]=1;
CARTE[5][25]=0;
CARTE[5][26]=0;
CARTE[5][27]=1;
CARTE[5][28]=0;
CARTE[5][29]=1;
CARTE[5][30]=1;
CARTE[5][31]=0;
CARTE[5][32]=0;
CARTE[5][33]=1;
CARTE[5][34]=1;
CARTE[5][35]=1;
CARTE[5][36]=1;
CARTE[5][37]=0;
CARTE[5][38]=0;
CARTE[5][39]=0;

CARTE[6][0]=1;
CARTE[6][1]=0;
CARTE[6][2]=0;
CARTE[6][3]=1;
CARTE[6][4]=0;
CARTE[6][5]=0;
CARTE[6][6]=0;
CARTE[6][7]=0;
CARTE[6][8]=0;
CARTE[6][9]=1;
CARTE[6][10]=1;
CARTE[6][11]=1;
CARTE[6][12]=1;
CARTE[6][13]=0;
CARTE[6][14]=0;
CARTE[6][15]=1;
CARTE[6][16]=0;
CARTE[6][17]=1;
CARTE[6][18]=0;
CARTE[6][19]=0;
CARTE[6][20]=0;
CARTE[6][21]=1;
CARTE[6][22]=1;
CARTE[6][23]=1;
CARTE[6][24]=1;
CARTE[6][25]=0;
CARTE[6][26]=0;
CARTE[6][27]=1;
CARTE[6][28]=0;
CARTE[6][29]=0;
CARTE[6][30]=1;
CARTE[6][31]=0;
CARTE[6][32]=0;
CARTE[6][33]=1;
CARTE[6][34]=0;
CARTE[6][35]=0;
CARTE[6][36]=1;
CARTE[6][37]=0;
CARTE[6][38]=0;
CARTE[6][39]=1;

CARTE[7][0]=1;
CARTE[7][1]=0;
CARTE[7][2]=0;
CARTE[7][3]=1;
CARTE[7][4]=1;
CARTE[7][5]=1;
CARTE[7][6]=1;
CARTE[7][7]=0;
CARTE[7][8]=0;
CARTE[7][9]=1;
CARTE[7][10]=1;
CARTE[7][11]=1;
CARTE[7][12]=1;
CARTE[7][13]=0;
CARTE[7][14]=0;
CARTE[7][15]=1;
CARTE[7][16]=0;
CARTE[7][17]=1;
CARTE[7][18]=0;
CARTE[7][19]=0;
CARTE[7][20]=0;
CARTE[7][21]=1;
CARTE[7][22]=1;
CARTE[7][23]=1;
CARTE[7][24]=1;
CARTE[7][25]=0;
CARTE[7][26]=0;
CARTE[7][27]=1;
CARTE[7][28]=0;
CARTE[7][29]=0;
CARTE[7][30]=1;
CARTE[7][31]=0;
CARTE[7][32]=0;
CARTE[7][33]=1;
CARTE[7][34]=0;
CARTE[7][35]=0;
CARTE[7][36]=1;
CARTE[7][37]=0;
CARTE[7][38]=0;
CARTE[7][39]=1;

CARTE[8][0]=1;
CARTE[8][1]=0;
CARTE[8][2]=0;
CARTE[8][3]=0;
CARTE[8][4]=0;
CARTE[8][5]=0;
CARTE[8][6]=0;
CARTE[8][7]=0;
CARTE[8][8]=0;
CARTE[8][9]=0;
CARTE[8][10]=0;
CARTE[8][11]=0;
CARTE[8][12]=0;
CARTE[8][13]=0;
CARTE[8][14]=0;
CARTE[8][15]=0;
CARTE[8][16]=0;
CARTE[8][17]=0;
CARTE[8][18]=0;
CARTE[8][19]=0;
CARTE[8][20]=0;
CARTE[8][21]=0;
CARTE[8][22]=0;
CARTE[8][23]=0;
CARTE[8][24]=0;
CARTE[8][25]=0;
CARTE[8][26]=0;
CARTE[8][27]=0;
CARTE[8][28]=0;
CARTE[8][29]=0;
CARTE[8][30]=0;
CARTE[8][31]=0;
CARTE[8][32]=0;
CARTE[8][33]=0;
CARTE[8][34]=0;
CARTE[8][35]=0;
CARTE[8][36]=0;
CARTE[8][37]=0;
CARTE[8][38]=0;
CARTE[8][39]=1;

CARTE[9][0]=1;
CARTE[9][1]=0;
CARTE[9][2]=0;
CARTE[9][3]=0;
CARTE[9][4]=0;
CARTE[9][5]=0;
CARTE[9][6]=0;
CARTE[9][7]=0;
CARTE[9][8]=0;
CARTE[9][9]=0;
CARTE[9][10]=0;
CARTE[9][11]=0;
CARTE[9][12]=0;
CARTE[9][13]=0;
CARTE[9][14]=0;
CARTE[9][15]=0;
CARTE[9][16]=0;
CARTE[9][17]=0;
CARTE[9][18]=0;
CARTE[9][19]=0;
CARTE[9][20]=0;
CARTE[9][21]=0;
CARTE[9][22]=0;
CARTE[9][23]=0;
CARTE[9][24]=0;
CARTE[9][25]=0;
CARTE[9][26]=0;
CARTE[9][27]=0;
CARTE[9][28]=0;
CARTE[9][29]=0;
CARTE[9][30]=0;
CARTE[9][31]=0;
CARTE[9][32]=0;
CARTE[9][33]=0;
CARTE[9][34]=0;
CARTE[9][35]=0;
CARTE[9][36]=0;
CARTE[9][37]=0;
CARTE[9][38]=0;
CARTE[9][39]=1;

CARTE[10][0]=1;
CARTE[10][1]=1;
CARTE[10][2]=1;
CARTE[10][3]=1;
CARTE[10][4]=1;
CARTE[10][5]=1;
CARTE[10][6]=1;
CARTE[10][7]=1;
CARTE[10][8]=1;
CARTE[10][9]=1;
CARTE[10][10]=1;
CARTE[10][11]=1;
CARTE[10][12]=1;
CARTE[10][13]=1;
CARTE[10][14]=1;
CARTE[10][15]=1;
CARTE[10][16]=1;
CARTE[10][17]=1;
CARTE[10][18]=1;
CARTE[10][19]=1;
CARTE[10][20]=1;
CARTE[10][21]=1;
CARTE[10][22]=1;
CARTE[10][23]=1;
CARTE[10][24]=1;
CARTE[10][25]=1;
CARTE[10][26]=1;
CARTE[10][27]=1;
CARTE[10][28]=1;
CARTE[10][29]=1;
CARTE[10][30]=1;
CARTE[10][31]=1;
CARTE[10][32]=1;
CARTE[10][33]=1;
CARTE[10][34]=1;
CARTE[10][35]=1;
CARTE[10][36]=1;
CARTE[10][37]=1;
CARTE[10][38]=1;
CARTE[10][39]=1;


	SDL_Surface* Medecin[4]={NULL};
	SDL_Surface* Actual_PositionMedecin=NULL;

	SDL_Surface* Corona[4]={NULL};
	SDL_Surface* Actual_PositionCorona=NULL;
	SDL_Surface* MUR;
	SDL_Surface* OBSTACLES_BLEU;
	SDL_Surface* OBSTACLES_VERT;
	SDL_Surface* OBSTACLES_ROUGE;

	MUR=IMG_Load("../img/MURE.png");

	OBSTACLES_BLEU=IMG_Load("../img/BB.png");
	OBSTACLES_VERT=IMG_Load("../img/BV.png");
	OBSTACLES_ROUGE=IMG_Load("../img/BR.png");

	SDL_Rect position_Medecin;
	SDL_Rect position_Corona;
	SDL_Rect position;
	SDL_Event event;


	screen=SDL_SetVideoMode(1600,430,32,SDL_HWSURFACE);

	Medecin[BAS]=IMG_Load("../img/BAS.png");
	Medecin[HAUT]=IMG_Load("../img/HAUT.png");
	Medecin[GAUCHE]=IMG_Load("../img/GAUCHE.png");
	Medecin[DROITE]=IMG_Load("../img/DROITE.png");

	Corona[BAS]=IMG_Load("../img/Coronabas.png");
	Corona[HAUT]=IMG_Load("../img/Coronahaut.png");
	Corona[GAUCHE]=IMG_Load("../img/Coronagauche.png");
	Corona[DROITE]=IMG_Load("../img/Coronadroite.png");

	
	Actual_PositionMedecin=Medecin[BAS];
	Actual_PositionCorona=Corona[BAS];
	position_Medecin.x=0;
	position_Medecin.y=5;

	position_Corona.x=1;
	position_Corona.y=5;

	CARTE[2][2]=2;

//Score Medecin
	TTF_Init();
	TTF_Font* text_scoreM;
	text_scoreM=TTF_OpenFont("Ubuntu-Bold.ttf",25);
	SDL_Surface* Text_ScM=NULL;
	SDL_Rect position_text_scM;

	position_text_scM.x=400;
	position_text_scM.y=3;


	SDL_Surface* scoreM=NULL;
	SDL_Color color1={255,255,0};
	SDL_Rect position_scoreM;
	Uint32 color_scoreM;

	position_scoreM.x=600;
	position_scoreM.y=3;
	
	scoreM=SDL_CreateRGBSurface(SDL_HWSURFACE,200,50,32,0,0,0,0);
	color_scoreM=SDL_MapRGB(scoreM->format,255,0,0);	
	SDL_FillRect(scoreM,NULL,color_scoreM);
	TTF_Font* font_text_scM;
	font_text_scM=TTF_OpenFont("Ubuntu-Bold.ttf",25);
	SDL_Flip(screen);

//Score Corona
	TTF_Init();
	TTF_Font* text_scoreC;
	text_scoreC=TTF_OpenFont("Ubuntu-Bold.ttf",25);
	SDL_Surface* Text_ScC=NULL;
	SDL_Rect position_text_scC;

	position_text_scC.x=800;
	position_text_scC.y=3;


	SDL_Surface* scoreC=NULL;
	SDL_Color color2={255,255,0};
	SDL_Rect position_scoreC;
	Uint32 color_scoreC;

	position_scoreC.x=1000;
	position_scoreC.y=3;
	
	scoreC=SDL_CreateRGBSurface(SDL_HWSURFACE,200,50,32,0,0,0,0);
	color_scoreC=SDL_MapRGB(scoreC->format,255,0,0);	
	SDL_FillRect(scoreC,NULL,color_scoreC);
	TTF_Font* font_text_scC;
	font_text_scC=TTF_OpenFont("Ubuntu-Bold.ttf",25);
	SDL_Flip(screen);



//placement aleatoire des obstacles
	placementAleatoireObstac();
	while(continuer)
	{
		if(SDL_PollEvent(&event))
		switch(event.type)
		{
			case SDL_QUIT:
				continuer=0;
			break;

			case SDL_KEYDOWN:
				switch(event.key.keysym.sym)
				{

					case SDLK_UP:
						Actual_PositionMedecin=Medecin[HAUT];
						deplacerMedecin(CARTE,&position_Medecin,&position_Corona,HAUT);
					break;

					case SDLK_DOWN:
						deplacerMedecin(CARTE,&position_Medecin,&position_Corona,BAS);
					break;

					case SDLK_RIGHT:
						Actual_PositionMedecin=Medecin[DROITE];
						deplacerMedecin(CARTE,&position_Medecin,&position_Corona,DROITE);
					break;

					case SDLK_LEFT:
						Actual_PositionMedecin=Medecin[GAUCHE];
						deplacerMedecin(CARTE,&position_Medecin,&position_Corona,GAUCHE);
					break;
					
					
					case SDLK_z:
						Actual_PositionCorona=Corona[HAUT];
						deplacerCorona(CARTE,&position_Medecin,&position_Corona,HAUT);
					break;

					case SDLK_s:
						deplacerCorona(CARTE,&position_Medecin,&position_Corona,BAS);
					break;

					case SDLK_d:
						Actual_PositionCorona=Corona[DROITE];
						deplacerCorona(CARTE,&position_Medecin,&position_Corona,DROITE);
					break;

					case SDLK_q:
						Actual_PositionCorona=Corona[GAUCHE];
						deplacerCorona(CARTE,&position_Medecin,&position_Corona,GAUCHE);
					break;
			}
		}
		SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));

		for(i=0 ; i<11 ; i++)
		{
			for(j=0 ; j<40 ; j++)
			{
				position.x=j*TAILLE_BLOC;
				position.y=i*TAILLE_BLOC;

				switch(CARTE[i][j])
				{
					case MURE:
						SDL_BlitSurface(MUR,NULL,screen,&position);
					break;

					case OBSTACLE_BLEU:
						SDL_BlitSurface(OBSTACLES_BLEU,NULL,screen,&position);
					break;
					case OBSTACLE_VERT:
						SDL_BlitSurface(OBSTACLES_VERT,NULL,screen,&position);
					break;
					case OBSTACLE_ROUGE:
						SDL_BlitSurface(OBSTACLES_ROUGE,NULL,screen,&position);
					break;
				}
			}
		}
	//Medecin
		char scoreMedecin_text[20];
	     	sprintf(scoreMedecin_text,"%d",scoreMedecin);

		scoreM=TTF_RenderText_Solid(font_text_scM,scoreMedecin_text,color1);		
		Text_ScM=TTF_RenderText_Solid(text_scoreM,"Score Medecin  : ",color1);
		SDL_BlitSurface(scoreM,NULL,screen,&position_scoreM);
		SDL_BlitSurface(Text_ScM,NULL,screen,&position_text_scM);		
     		SDL_Flip(screen);
//Corona
		char scoreCorona_text[20];
	     	sprintf(scoreCorona_text,"%d",scoreCorona);

		scoreC=TTF_RenderText_Solid(font_text_scC,scoreCorona_text,color2);		
		Text_ScC=TTF_RenderText_Solid(text_scoreC,"Score Corona  : ",color2);
		SDL_BlitSurface(scoreC,NULL,screen,&position_scoreC);
		SDL_BlitSurface(Text_ScC,NULL,screen,&position_text_scC);		
     		SDL_Flip(screen);

		
		position.x=position_Medecin.x*TAILLE_BLOC;
		position.y=position_Medecin.y*TAILLE_BLOC;
		SDL_BlitSurface(Actual_PositionMedecin,NULL,screen,&position);
		
		position.x=position_Corona.x*TAILLE_BLOC;
		position.y=position_Corona.y*TAILLE_BLOC;
		SDL_BlitSurface(Actual_PositionCorona,NULL,screen,&position);

		SDL_Flip(screen);
	}

	SDL_EnableKeyRepeat(0,0);
	SDL_FreeSurface(MUR);
	SDL_FreeSurface(OBSTACLES_BLEU);
	SDL_FreeSurface(OBSTACLES_VERT);
	SDL_FreeSurface(OBSTACLES_ROUGE);
	
	
	
	
	
	for(i=0 ; i<4 ; i++)
	{
		SDL_FreeSurface(Medecin[i]);
		SDL_FreeSurface(Corona[i]);
	}
}

void deplacerMedecin(int CARTE[11][40],SDL_Rect *position_Medecin,SDL_Rect* position_Corona,int direction)
{
switch(direction)
	{
		case HAUT:
				
		if((CARTE[position_Medecin->y-1][position_Medecin->x]==MURE)||CARTE[position_Medecin->y-1][position_Medecin->x]==OBSTACLE_ROUGE){break;}
		if((CARTE[position_Medecin->y-1][position_Medecin->x]==OBSTACLE_BLEU)||(CARTE[position_Medecin->y-1][position_Medecin->x]==OBSTACLE_ROUGE))
{CARTE[position_Medecin->y-1][position_Medecin->x]=OBSTACLE_VERT;
scoreMedecin +=10;
break;}

//verifier collisions
			if((position_Medecin->x== position_Corona->x )&&(position_Medecin->y== position_Corona->y )){break;}

			position_Medecin->y--;
			//SDL_Delay(5000);
		break;

		case BAS:
			if((CARTE[position_Medecin->y+1][position_Medecin->x]==MURE) ||( CARTE[position_Medecin->y+1][position_Medecin->x]==OBSTACLE_ROUGE))
			{break;}

			if(CARTE[position_Medecin->y+1][position_Medecin->x]==OBSTACLE_BLEU)
			{CARTE[position_Medecin->y+1][position_Medecin->x]=OBSTACLE_VERT;
			scoreMedecin +=10;
			break;}

//verifier collisions
			if((position_Medecin->x== position_Corona->x )&&(position_Medecin->y== position_Corona->y )){break;}

			position_Medecin->y++;
		break;

		case DROITE:
			if((CARTE[position_Medecin->y][position_Medecin->x+1]==MURE) || (CARTE[position_Medecin->y][position_Medecin->x+1]==OBSTACLE_ROUGE))
			{break;}

			if(CARTE[position_Medecin->y][position_Medecin->x+1]==OBSTACLE_BLEU)
			{CARTE[position_Medecin->y][position_Medecin->x+1]=OBSTACLE_VERT;
			scoreMedecin +=10;
			break;}

			////verifier collisions
			if((position_Medecin->x== position_Corona->x )&&(position_Medecin->y== position_Corona->y )){break;}

		position_Medecin->x++;
		break;

		case GAUCHE:
			if((CARTE[position_Medecin->y][position_Medecin->x-1]==MURE)||(CARTE[position_Medecin->y][position_Medecin->x-1]==OBSTACLE_ROUGE))
			{break;}

			if(CARTE[position_Medecin->y][position_Medecin->x-1]==OBSTACLE_BLEU)
			{CARTE[position_Medecin->y][position_Medecin->x-1]=OBSTACLE_VERT;
			scoreMedecin +=10;
			break;}


//verifier collisions
			if((position_Medecin->x== position_Corona->x )&&(position_Medecin->y== position_Corona->y )){break;}
			position_Medecin->x--;
		break;
	}
}

void deplacerCorona(int CARTE[11][40],SDL_Rect *position_Medecin,SDL_Rect *position_Corona,int direction)
{
	switch(direction)
	{
		case HAUT:
			if((CARTE[position_Corona->y-1][position_Corona->x]==MURE)||CARTE[position_Corona->y-1][position_Corona->x]==OBSTACLE_VERT)
			{break;}

			if(CARTE[position_Corona->y-1][position_Corona->x]==OBSTACLE_BLEU)
			{CARTE[position_Corona->y-1][position_Corona->x]=OBSTACLE_ROUGE;
			scoreCorona +=10;
			break;}

//verifier collisions
			if((position_Medecin->x== position_Corona->x )&&(position_Medecin->y== position_Corona->y )){break;}

			position_Corona->y--;
			//SDL_Delay(5000);
		break;

		case BAS:
			if((CARTE[position_Corona->y+1][position_Corona->x]==MURE)||(CARTE[position_Corona->y+1][position_Corona->x]==OBSTACLE_VERT))
			{break;}

			if(CARTE[position_Corona->y+1][position_Corona->x]==OBSTACLE_BLEU)
			{CARTE[position_Corona->y+1][position_Corona->x]=OBSTACLE_ROUGE;
			scoreCorona +=10;
			break;}

//verifier collisions
			if((position_Medecin->x== position_Corona->x )&&(position_Medecin->y== position_Corona->y )){break;}

			position_Corona->y++;
		break;

		case DROITE:
			if((CARTE[position_Corona->y][position_Corona->x+1]==MURE)||(CARTE[position_Corona->y][position_Corona->x+1]==OBSTACLE_VERT))
			{break;}

			if(CARTE[position_Corona->y][position_Corona->x+1]==OBSTACLE_BLEU)
			{CARTE[position_Corona->y][position_Corona->x+1]=OBSTACLE_ROUGE;
			scoreCorona +=10;
			break;}
			//verifier collisions
			if((position_Medecin->x== position_Corona->x )&&(position_Medecin->y== position_Corona->y )){break;}
			position_Corona->x++;
		break;

		case GAUCHE:
			if((CARTE[position_Corona->y][position_Corona->x-1]==MURE)||(CARTE[position_Corona->y][position_Corona->x-1]==OBSTACLE_VERT))
			{break;}

			if(CARTE[position_Corona->y][position_Corona->x-1]==OBSTACLE_BLEU)
			{CARTE[position_Corona->y][position_Corona->x-1]=OBSTACLE_ROUGE;
			scoreCorona +=10;
			break;}

//verifier collisions
			if((position_Medecin->x== position_Corona->x )&&(position_Medecin->y== position_Corona->y )){break;}

			position_Corona->x--;
		break;
	}
}


