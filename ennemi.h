#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <math.h>
#include <stdbool.h> 
#define NUM_FRAMES_RIGHT 13 // Number of frames for right direction animation
#define NUM_FRAMES_LEFT 13  // Number of frames for left direction animation

typedef struct ES ES ;
struct ES
{

	SDL_Surface *image;
	SDL_Rect espos;
	char *url; //url variable de type char pour stocker les images avant l'utilisation de IMG_Load sur cette variable
	SDL_Rect pos_img_affiche; // la partie de l'image a afficher
	SDL_Rect pos_img_ecran; // position de l'affichage de l'image sur l'ecran
	SDL_Surface *img; //pointeur sur image


};
struct Animation {
    SDL_Surface* anim_right[NUM_FRAMES_RIGHT]; // Array for right direction animation frames
    SDL_Surface* anim_left[NUM_FRAMES_LEFT];   // Array for left direction animation frames
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
int CollisionBB(SDL_Rect characterRect, SDL_Rect ennemiRect,SDL_Rect camera);
int collitri(SDL_Surface *  box,SDL_Surface *circle,SDL_Rect boxpos,SDL_Rect circlepos);
void initializeES(ES* es);
void mves(SDL_Rect* pos,int* tempsp, int* tempsa, int* v);
void mves2(SDL_Rect* pos,int* tempsp, int* tempsa, int* v);



