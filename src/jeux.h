#ifndef JEUX_H_
#define JEUX_H_

void jouer(SDL_Surface* screen);
int checkCollisions();
void deplacerMedecin(int carte[][40],SDL_Rect* position_Medecin,SDL_Rect* position_Corona,int direction);
void deplacerCorona(int carte[][40],SDL_Rect* position_Medecin,SDL_Rect* position_Corona,int direction);

void 	placementAleatoireObstac();

#endif
