#include <stdio.h>
#include <SDL/SDL.h>
#include <stdlib.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "fonction.h"
#include <SDL/SDL_ttf.h>
#include <stdbool.h> 
#define NUM_FRAMES_RIGHT 13 
#define NUM_FRAMES_LEFT 13 

int main (void)
{
SDL_Surface *screen =NULL;
SDL_Init(SDL_INIT_VIDEO);
SDL_EnableKeyRepeat(10,40);
int continuer=1;
screen = SDL_SetVideoMode(1824,1024,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
SDL_Surface *fond=NULL,*perso,*flashdisk,*ennemi,*ennemi2;
SDL_Rect positionfond,positiondead,persopos,flashdiskpos,ennemipos,ennemi2pos;

SDL_Event event;

int direction = 1;
struct Animation myAnimation;
if (direction == 1) {
    if (!init_animation_right(&myAnimation)) {
        printf("Failed to initialize right animation.\n");
        return 1;
    }
} else {
    if (!init_animation_left(&myAnimation)) {
        printf("Failed to initialize left animation.\n");
        return 1;
    }
}
      myAnimation.pos.x =20;
    myAnimation.pos.y = 495;
    myAnimation.pos.h = 259;
     myAnimation.pos.w = 132;
    
int tempsx = 0;
int tempsz = 0;
int z = 1;
int tempsp=0,tempsa=0;
int v=1;
int tempspb=0,tempsab=0;
int vb=1;
int tempspbb=0,tempsabb=0;
int vbb=1;


ES es,es2,dead;
initializeES(&es);
initialiser_dead(&dead); 
int mvd=0,mvgg=0,mvg=0,verif1=0,verif2=0,verif3=0,etat;
int score=0;





positionfond.x=0;
positionfond.y=0;
fond= IMG_Load("back.jpg");

    int ennemi_movement_enabled = 1;



perso=IMG_Load("perso.png");
persopos.x=650;
persopos.y=560;
persopos.h=199;
persopos.w=139;
int x=1;
int xb=1;
int xbb=1;
int die=0;
int end=0;


while (continuer == 1)
    {
    if (end==1)
    {
        SDL_Delay(3000);
            continuer=0;
    }
    if (die==1)
{
 afficher_dead(screen,dead);
	end=1;

}
   else if (die==0){
    SDL_BlitSurface(fond,NULL,screen, &positionfond);



if(x==1)
{
mves(&es.espos,&tempsp,&tempsa,&v);
}
if(ennemi_movement_enabled)
{


 mves2(&myAnimation.pos,&tempsx,&tempsz,&z);
 if (direction == 1) {
        afficher_animation_right(myAnimation, screen);
    } else if (direction == -1){
        afficher_animation_left(myAnimation, screen);
    }

    if (direction == 1 && myAnimation.pos.x >= 250) {
        direction = -1; 
        if (!init_animation_left(&myAnimation)) {
            printf("Failed to initialize left animation.\n");
            return 1;
        }
    } else if (direction == -1 && myAnimation.pos.x <= 1) {
        direction = 1; 
        if (!init_animation_right(&myAnimation)) {

            printf("Failed to initialize right animation.\n");
            return 1;
        }
    }

if (CollisionBB(persopos, myAnimation.pos))
{
ennemi_movement_enabled=0;
die=1;

}



}


        SDL_PollEvent(&event);
        switch(event.type)
        {



            case SDL_QUIT:
                continuer = 0;
                break;
	    case SDL_MOUSEMOTION: 
			
                        break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {   
		    case SDLK_ESCAPE:
			continuer=0;
			break; 
		   
                   
                    case SDLK_RIGHT:

  etat=0;
verif2=0;
if(mvd==1)
{

persopos.x+=20;
mvd=0;
}
else
{
if(collitri(perso,flashdisk,persopos,es.espos))
{

persopos.x+=20;
x=1;

}
else {mvg=1;
     x=0; 

}  


}

		    break;

                    case SDLK_LEFT: 

persopos.x-=20;

                      break;
	
                }
               

                
}
 

SDL_BlitSurface(es.image,NULL,screen, &es.espos);
SDL_BlitSurface(perso,NULL,screen, &persopos);
}
SDL_Flip(screen);


}
libere_image(dead);
liberer_animation(&myAnimation);
}






void pause()
{
    int continuer = 1;
    SDL_Event event;
 
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
	break;
        }
    }
}


