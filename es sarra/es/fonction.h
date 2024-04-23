#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <math.h>
#include <stdbool.h> 
#define NUM_FRAMES_RIGHT 13 
#define NUM_FRAMES_LEFT 13 

typedef struct ES ES ;
struct ES
{

	SDL_Surface *image;
	SDL_Rect espos;
	char *url; 
	SDL_Rect pos_img_affiche; 
	SDL_Rect pos_img_ecran;
	SDL_Surface *img; 


};
struct Animation {
    SDL_Surface* anim_right[NUM_FRAMES_RIGHT]; 
    SDL_Surface* anim_left[NUM_FRAMES_LEFT];   
    SDL_Rect pos;
    SDL_Rect espos;
    SDL_Surface *ennemi;
};

void libere_image(ES imge);
void initialiser_dead(ES *imgsecond);
void afficher_dead(SDL_Surface *screen,ES imgsecond);
bool init_animation_right(struct Animation* anim);
bool init_animation_left(struct Animation* anim);
void afficher_animation_right(struct Animation anim, SDL_Surface* screen);
void afficher_animation_left(struct Animation anim, SDL_Surface* screen);
void liberer_animation(struct Animation* anim);
int CollisionBB(SDL_Rect characterRect, SDL_Rect ennemiRect);
int collitri(SDL_Surface *  box,SDL_Surface *circle,SDL_Rect boxpos,SDL_Rect circlepos);
void initializeES(ES* es);
void mves(SDL_Rect* pos,int* tempsp, int* tempsa, int* v);
void mves2(SDL_Rect* pos,int* tempsp, int* tempsa, int* v);



