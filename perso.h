#ifndef FICHIER_H_INCLUDED

#define FICHIER_H_INCLUDED
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

#include <stdlib.h>
#include <math.h>




typedef struct Personne

{

	SDL_Surface *images[2][6];

	SDL_Rect posperso;

	int direct;

	int nbr_frame;

	double vitesse,acceleration,vitesse_saut;

	double dx;



	int isacc,peak,ground,up,nbjumps;



}perso;



typedef struct

{

    SDL_Surface *imgbackground;

    SDL_Rect posbackground;

} back;





void initPerso(perso *p);

void init(back *b);

void animerPerso (perso* p);
void freesurface(perso *p);
void saut(perso *p, Uint32 dt, int *posx_absolu, int posy_initiale);
void deplacerPerso (perso *p,uint dt);
void aff(back b, SDL_Surface *screen);
void afficherPerso(perso p, SDL_Surface * screen);



void sautvertical(perso *p, int *num) ;



#endif
