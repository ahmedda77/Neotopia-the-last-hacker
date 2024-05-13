#include <stdio.h>
#include <SDL/SDL.h>
#include <stdlib.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "ennemi.h"
#include <SDL/SDL_ttf.h>

#define CHARACTER_WIDTH 100
#define CHARACTER_HEIGHT 195
#include <stdbool.h> 

#define NUM_FRAMES_RIGHT 13 // Number of frames for right direction animation
#define NUM_FRAMES_LEFT 13  // Number of frames for left direction animation

// Function to initialize animation frames for both directions
// Function to initialize animation frames for right direction
bool init_animation_right(struct Animation* anim) {
    char filename[50];

    // Load frames for right direction animation
    for (int i = 0; i < NUM_FRAMES_RIGHT; ++i) {
        snprintf(filename, sizeof(filename), "right/background%d.png", i);
        anim->anim_right[i] = IMG_Load(filename);
        if (!anim->anim_right[i]) {
            printf("Error loading right frame %d: %s\n", i, SDL_GetError());
            return false; // Return failure if any frame fails to load
        }
    }

    return true; // Return success
}

// Function to initialize animation frames for left direction
bool init_animation_left(struct Animation* anim) {
    char filename[50];

    // Load frames for left direction animation
    for (int i = 0; i < NUM_FRAMES_LEFT; ++i) {
        snprintf(filename, sizeof(filename), "left/background%d.png", i);
        anim->anim_left[i] = IMG_Load(filename);
        if (!anim->anim_left[i]) {
            printf("Error loading left frame %d: %s\n", i, SDL_GetError());
            return false; // Return failure if any frame fails to load
        }
    }

    return true; // Return success
}

// Function to display animation frames for right direction
void afficher_animation_right(struct Animation anim, SDL_Surface* screen) {
    static int frameIndex = 0; // Static variable to retain frame index between function calls
    SDL_Surface* currentFrame = anim.anim_right[frameIndex];

    // Blit the current animation frame onto the screen
    SDL_BlitSurface(currentFrame, NULL, screen, &anim.pos);

    // Increment frame index
    frameIndex++;

    // Reset frame index if it exceeds the number of frames
    if (frameIndex == NUM_FRAMES_RIGHT) {
        frameIndex = 0;
    }
}

// Function to display animation frames for left direction
void afficher_animation_left(struct Animation anim, SDL_Surface* screen) {
    static int frameIndex = 0; // Static variable to retain frame index between function calls
    SDL_Surface* currentFrame = anim.anim_left[frameIndex];

    // Blit the current animation frame onto the screen
    SDL_BlitSurface(currentFrame, NULL, screen, &anim.pos);

    // Increment frame index
    frameIndex++;

    // Reset frame index if it exceeds the number of frames
    if (frameIndex == NUM_FRAMES_LEFT) {
        frameIndex = 0;
    }
}

// Function to free resources used by animation frames
void liberer_animation(struct Animation* anim) {
    // Free surfaces for right direction animation frames
    for (int i = 0; i < NUM_FRAMES_RIGHT; ++i) {
        SDL_FreeSurface(anim->anim_right[i]);
    }

    // Free surfaces for left direction animation frames
    for (int i = 0; i < NUM_FRAMES_LEFT; ++i) {
        SDL_FreeSurface(anim->anim_left[i]);
    }
}


  
int collitri(SDL_Surface *  box,SDL_Surface *circle,SDL_Rect boxpos,SDL_Rect circlepos)
{

float a,b,r,x;

a=circlepos.x+(circlepos.w/2);
b=circlepos.y+(circlepos.h/2);
r=(circlepos.w/2)*(circlepos.w/2);//rayon carre 

   if( ( ( (boxpos.x+boxpos.w)<a || boxpos.x>a) || (((b-boxpos.y)*(b-boxpos.y)) > r) )
      &&( ( (boxpos.x+boxpos.w)<a || boxpos.x>a) || (((b-(boxpos.y+boxpos.h))*(b-(boxpos.y+boxpos.h))) > r) )
      &&(( ( ( (boxpos.x-a)*(boxpos.x-a))+(((boxpos.y+boxpos.h)-b)*((boxpos.y+boxpos.h)-b))) )>r)
      &&(( ((boxpos.x-a)*(boxpos.x-a))+((boxpos.y-b)*(boxpos.y-b)))>r)
      &&( ( (boxpos.y+boxpos.h)<b || boxpos.y>b) || ( ( (a-boxpos.x)*(a-boxpos.x)) > r) )
      &&(( ( ( ((boxpos.x+boxpos.w)-a)*((boxpos.x+boxpos.w)-a))+(((boxpos.y+boxpos.h)-b)*((boxpos.y+boxpos.h)-b))) )>r)
     &&(( (((boxpos.x+boxpos.w)-a)*((boxpos.x+boxpos.w)-a))+((boxpos.y-b)*(boxpos.y-b)))>r) 
       && ( ( (boxpos.y+boxpos.h)<b || boxpos.y>b) || ( ( (a-(boxpos.x+boxpos.w))*(a-(boxpos.x+boxpos.w))) > r) )
      )
return 1;
else return 0;
}





void initializeES(ES* es)
{
	SDL_Surface* tmp  ;
         tmp = IMG_Load("bonus.png");
	es->image = tmp;


	SDL_Rect pos;
	pos.x=1200;
	pos.y=655;
	es->espos=pos;
	
}
void mves(SDL_Rect* pos,int* tempsp, int* tempsa, int* v)
{

*tempsa=SDL_GetTicks();
if(*tempsa-*tempsp>20)
{
if(pos->x<=1200&&*v==1)
{
pos->x+=15;
if(pos->x>=1200)
*v=2;
}
if (*v==2)
{pos->x-=15;
if(pos->x<=900)
*v=1;
}
*tempsp=*tempsa;
}
}



void mves2(SDL_Rect* pos,int* tempsp, int* tempsa, int* v)
{

*tempsa=SDL_GetTicks();
if(*tempsa-*tempsp>20)
{
if(pos->x<=300&&*v==1)
{
pos->x+=15;
if(pos->x>=300)
*v=2;
}
if (*v==2)
{pos->x-=15;
if(pos->x<=1)
*v=1;
}
*tempsp=*tempsa;
}
}



int CollisionBB(SDL_Rect characterRect, SDL_Rect ennemiRect,SDL_Rect camera) {

    int ennemiMovementStartX = 1; 
    int ennemiMovementEndX = 350; 
    int ennemiY = ennemiRect.y + (ennemiRect.h / 2); 

    if (characterRect.y + characterRect.h >= ennemiRect.y && characterRect.y <= ennemiRect.y + ennemiRect.h) {

        if (characterRect.x+ characterRect.w >= ennemiMovementStartX && characterRect.x <= ennemiMovementEndX) {

            return 1;
        }
    }

    return 0;
}

void initialiser_dead(ES *imgsecond)
{
	imgsecond->url="dead.png";
	imgsecond->img=IMG_Load(imgsecond->url);
	if (imgsecond->img == NULL)
	{
		printf("unable to load background image %s\n",SDL_GetError());
		return;
	}
	imgsecond->pos_img_affiche.x=0;
	imgsecond->pos_img_affiche.y=0;
	imgsecond->pos_img_ecran.x=0;
	imgsecond->pos_img_ecran.y=0;
}

void afficher_dead(SDL_Surface *screen,ES imgsecond)
{
	SDL_BlitSurface(imgsecond.img,NULL,screen,&imgsecond.pos_img_ecran);
}

void libere_image(ES imge)
{
	SDL_FreeSurface(imge.img);
}






















