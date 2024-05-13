#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "perso.h"
#define vitesse_max 40
#define JUMP_INITIAL_VELOCITY 10

#define GRAVITY 0.5



void init(back *b)

{

    b->imgbackground = NULL;

    b->imgbackground = IMG_Load("Level-1.png");

    b->posbackground.x = 0;

    b->posbackground.y = 0;

}
void saut(perso *p, Uint32 dt, int *posx_absolu, int posy_initiale) {

    float peak = 100; 
    float ground = 300; 

    // If character is going up
    if (p->up == 1) {
        float c = posy_initiale;
        float a = -0.01;


        float x_relative = p->posperso.x - *posx_absolu;


        float y = a * x_relative * x_relative + c;

        p->posperso.y = y;


	
        if (p->posperso.y < peak) {


            float a = -0.01;
        float x_relative = p->posperso.x - *posx_absolu;

            float y = (a * x_relative * x_relative)*-1;

            p->posperso.y = y;


            if (p->posperso.y >= ground) {
                p->posperso.y = ground;
		*posx_absolu=p->posperso.x;
            }
        }
	  if(p->up==0 && p->posperso.y<ground) {p->posperso.y=p->posperso.y+2;*posx_absolu=p->posperso.x;}
if( y == p->posperso.y)
p->up = 0;
    }



}




void aff(back b, SDL_Surface *screen)

{

    SDL_BlitSurface(b.imgbackground, NULL, screen, &b.posbackground);

}



void afficherPerso(perso p, SDL_Surface * screen)

{
    SDL_BlitSurface(p.images[p.direct][p.nbr_frame],NULL,screen,&p.posperso);
}


void sautvertical(perso *p,int *num) {

 int isup=0;
 


    if (p->up == 0 || *num%2==1) {


        if (p->posperso.y < p->ground) {
            p->posperso.y += 7;
        }
        if (p->posperso.y >= p->ground) {
		*num=2;
            p->nbjumps = 0;
        }
    }
    else if (p->up == 1) {
	if(p->posperso.y < p->peak-50) *num=*num+1;
	else {
        p->posperso.y -= 7;
        p->nbjumps++;}
    }



}


void initPerso(perso *p)

{

    int i,j;

    char nom_image[20];

    p->acceleration=0;

	p->isacc=0;



    p->direct=0;

    p->nbr_frame=0;


	
	


    p->up=0;

    p->ground=900;



    p->posperso.x=800;

   p->posperso.y =0;

    p->posperso.w;

    p->posperso.h;



    p->vitesse=0;

    p->vitesse_saut=5;

	p->peak=700;
  p->nbjumps = 0;
 

    for ( i = 0; i < 2; i++)

    {

        for ( j = 0; j < 4; j++)

        {   

            sprintf(nom_image,"pics/%d/%d.png",i,j);

            p->images[i][j]=IMG_Load(nom_image);

        }

        

    }

    

}




void animerPerso (perso *p)

{
  p->nbr_frame++;

    if (p->nbr_frame >= 4)

 		p->nbr_frame=0;

if ((p->vitesse==0))

{

	//printf("test");

p->nbr_frame= 0;

	}
	


}










void deplacerPerso (perso *p,uint dt)
{



	p->dx = 0.5 * p->acceleration * dt * dt + p->vitesse * dt ;
    if (p->direct==1)
    {
         if (p->posperso.x > 0) 
        p->posperso.x = p->posperso.x - p->dx; 
    }
    else if (p->direct==0)
    {
      
if (p->posperso.x < 1000) 
       p->posperso.x = p->posperso.x + p->dx +0.01;  
    }
    
}
void freesurface(perso *p)

{

    int i,j;

    for ( i = 0; i < 2; i++)

    {

        for ( j = 0; j < 6; j++)

        {   

            SDL_FreeSurface(p->images[i][j]);

        }

        

    }

}



