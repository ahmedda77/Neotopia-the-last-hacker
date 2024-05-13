
#include "background.h"
#include "enigme.h"
#include "perso.h"
#include "minimap.h"
#include "ennemi.h"
void main()
{

// perso


	int num=2;
	int num1=2;



    int dure=5000;
    float max_acceleration/* = 0.4*/;
    float max_acceleration_right/* = 0.3*/;
    const float acceleration_factor = 0.025;
    const float deceleration_factor = 0.005;
    const float deceleration_factor_right = 0.005;

    back b;



        // ENNEMI

int direction = 1; // 1 for right, -1 for left
struct Animation myAnimation;

// Initialize animation frames based on the initial direction
if (direction == 1) {
    if (!init_animation_right(&myAnimation)) {
        // Handle initialization failure
        printf("Failed to initialize right animation.\n");
        return ;
    }
} else {
    if (!init_animation_left(&myAnimation)) {
        // Handle initialization failure
        printf("Failed to initialize left animation.\n");
        return ;
    }
}
       myAnimation.pos.x=0;
       myAnimation.pos.y=750;
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




SDL_Rect positionfond;
positionfond.x=0;
positionfond.y=0;
SDL_Surface *fond;
fond= IMG_Load("back.jpg");

    int ennemi_movement_enabled = 1;


    int x=1;
int xb=1;
int xbb=1;
int die=0;
int end=0;

    //FIN ENNEMI



  //  SDL_Surface *imgbackground;
    perso p2,p1;
    int acceleration_active = 0, deceleration_active = 0;
        int acceleration_active1 = 0, deceleration_active1 = 0;
    int acceleration = 0;
    int posinit = 250;
    int deceleration = 0;
    int tickrate, tickrate1;
    int quit = 1;
	int nbjumps=0;
   p2.up = 0;
    int t_prev, t_fin;
    Uint32 dt;
    Uint32 tick1=SDL_GetTicks(),tick =SDL_GetTicks(),tick2=SDL_GetTicks();
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO);
    SDL_Surface *screen = SDL_SetVideoMode(1900, 1080, 32, SDL_SWSURFACE);
  //  screen = SDL_SetVideoMode(2000, 430, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    initPerso(&p2);  // hata hathi tb3a lperso
    initPerso(&p1);
    init(&b);
        minimap m;
    initmap(&m);
	p2.ground=900;
	 p2.posperso.y =p2.ground;
	 p1.posperso.y =p2.ground;
     p1.posperso.x=500;
     p2.posperso.x=500;
  
      p2.peak = 700;
p1.peak=700;
    int posx_absolu = p2.posperso.x;
    int posy_initiale = p2.posperso.y;


    Uint32 startTime = SDL_GetTicks();
    Uint32 currentTime;
    Uint32 elapsedTime;
    int value = 0;
    int setValueAfter = 2000;
 	int nbjump;





// background
bg bg,bg1,bg2;
char nom[30];
printf("Veuillez taper votre nom:");
scanf("%s",nom);
init_bg(&bg);
init_bg(&bg1);
init_bg(&bg2);
   bg.camera.x=p1.posperso.x;
//box collision 
   SDL_Surface *box;
box=IMG_Load("box.jpg");
SDL_Rect posbox;
posbox.x = 2100-bg.camera.x;
posbox.y=820;

//loaddata(&p2.posperso,&bg.camera,"savemini");
//loaddata(&p1.posperso,&bg.camera,"savemini");


TTF_Font *fontTest;

    SDL_Color White={255,255,255};
    fontTest=TTF_OpenFont("police.ttf" ,30);
    
    
    SDL_Surface *chrono;
    char timeText[100];
    SDL_Rect chronoPosition;
    chronoPosition.x=0;
    chronoPosition.y=100;

TTF_Init();
SDL_EnableKeyRepeat(60,0);
// Set up SDL window
    //SDL_Surface *screen = SDL_SetVideoMode(1920, 1080, 32, SDL_SWSURFACE);
    if (screen == NULL) {
        printf("Failed to create SDL window: %s\n", SDL_GetError());
        SDL_Quit();
        return ;
    }

    // Print screen size for debugging
    printf("SDL Surface Width: %d, SDL Surface Height: %d\n", screen->w, screen->h);
    printf("Screen Width: %d, Screen Height: %d\n", SCREEN_WIDTH, SCREEN_HEIGHT);
int q=1;


musique(1);
    SDL_Rect button_rect = { 10, 10, 0, 0 };
 SDL_Color textColor = {255, 255, 255};
    SDL_Surface* button_surface = TTF_RenderText_Solid(TTF_OpenFont("font.ttf", 32),"Show Scores",textColor);
	button_rect.w = button_surface->w;
    button_rect.h = button_surface->h;
 
    SDL_Event event;

// enigme: 



   SDL_Color Colorr = {255, 255, 255};

    // Initialize the enigma
    enigme en;
    init_enigme(&en);

    // Start background animation
  //  animationenig(screen);

    // Generate a random enigma
    alea_enigme(&en, Colorr);





while(q==1)
{

     if (end==1)
    {
        SDL_Delay(3000);
            q=0;
    }
    if (die==1) // xo hna
{
 afficher_dead(screen,dead);
    end=1;
         p1.posperso.x=500;
     p2.posperso.x=500;

}
   else if (die==0){




        SDL_BlitSurface(fond,NULL,screen, &positionfond);



    
    
   //  afficher_animation(myAnimation, screen);
if(x==1)
{
mves(&es.espos,&tempsp,&tempsa,&v);
}
if(ennemi_movement_enabled)
{


 mves2(&myAnimation.pos,&tempsx,&tempsz,&z);


    // Switch animation frames if character reached end of movement
    if (direction == 1 && myAnimation.pos.x >= 250) {
        direction = -1; // Switch to left animation
        // Re-initialize animation frames for left direction
        if (!init_animation_left(&myAnimation)) {
            // Handle initialization failure
            printf("Failed to initialize left animation.\n");
            return ;
        }
    } else if (direction == -1 && myAnimation.pos.x <= 1) {
        direction = 1; // Switch to right animation
        // Re-initialize animation frames for right direction
        if (!init_animation_right(&myAnimation)) {
            // Handle initialization failure
            printf("Failed to initialize right animation.\n");
            return ;
        }
    }

if (CollisionBB(p2.posperso,myAnimation.pos,bg.camera))
{//persopos.x-=20;
ennemi_movement_enabled=0;
die=1;

}


      
 


}




    t_prev = SDL_GetTicks();
       // aff(b,  screen);
    posbox.x = 2100-bg.camera.x;
afficher_bg( bg,screen);
SDL_BlitSurface(box,NULL,screen, &posbox);
 if (direction == 1) {
        afficher_animation_right(myAnimation, screen);
    } else if (direction == -1){
        afficher_animation_left(myAnimation, screen);
    }
  sprintf(timeText,"Timer:%d", SDL_GetTicks());
   chrono=TTF_RenderText_Blended(fontTest,timeText,White);
    SDL_BlitSurface(chrono, NULL,screen,&chronoPosition);


    MAJMinimap(p2.posperso,&m,bg.camera);
    afficherminimap (m,screen);
   collision(&p2.posperso,posbox);
    collision(&p1.posperso,posbox);

        afficherPerso(p2,  screen);
        afficherPerso(p1,  screen);
       // SDL_Flip( screen);


    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                q=0;
            case SDL_MOUSEBUTTONDOWN:
                if (event.button.x >= button_rect.x && event.button.x < button_rect.x + button_rect.w &&
                    event.button.y >= button_rect.y && event.button.y < button_rect.y + button_rect.h) {
                    show_top_scores(screen);
                }
                break;
	  case SDL_KEYDOWN:
		        switch (event.key.keysym.sym)
		        {
                case SDLK_RIGHT:
                    p2.direct = 0;
                    p2.vitesse = 0.5;
                    acceleration_active = 1;


  
                    break;
                case SDLK_LEFT:
                 
                    p2.direct = 1;
                    p2.vitesse = 0.5;
                    p2.isacc = 1;

                    break;
                case SDLK_UP:
                    p2.up = 1;
		   nbjumps++;
    printf("Up key pressed\n");
                    break;



		case SDLK_d:
			       p1.direct = 0;
                    p1.vitesse = 0.5;
                   acceleration_active1 = 1;
 		  break;

		case SDLK_q:
                  acceleration_active1 = 1;
			p1.direct=1;
                    p1.vitesse = 0.5; 		  
			break;

		case SDLK_z:
                    p1.up = 1;
		   nbjumps++;

                break;

                }
                break;


            case SDL_KEYUP:
                switch (event.key.keysym.sym)
                {
                case SDLK_RIGHT:
                    p2.vitesse = 0;
                    acceleration_active = 0;
                    deceleration_active = 1;
                    p2.isacc = 0;
		//p2.direct=-1;
                    break;
                case SDLK_LEFT:
                    p2.vitesse = 0;
                    acceleration_active = 0;
                    deceleration_active = 1;
	          p2.isacc = 0;
                    break;
                case SDLK_UP:
                    p2.up = 0;
                    break;
                    
                    
                    
               case SDLK_d:

                    p1.vitesse = 0;
			    //   p1.direct = 0;
    acceleration_active1 = 0; deceleration_active1 = 0;
 		  break;

		case SDLK_q:

                  
		
                    p1.vitesse = 0;
	//p1.direct=1;
		break;
	case SDLK_z:

                    p1.up = 0;

                break;			



        }

    }
}
// condtions:

if ( (p2.posperso.x>=750) && (p2.vitesse!=0) && (bg.camera.x < 5000 - 1500) ){
 scrolling(&bg, p2.posperso, &p2);

}
if ((p2.posperso.x <= 750) && (p2.vitesse != 0) && (bg.camera.x > 0)) {
    scrolling(&bg, p2.posperso, &p2);
}



        currentTime = SDL_GetTicks();

        elapsedTime = currentTime - startTime;

        if (elapsedTime <= dure && acceleration_active==1) {
          //  max_acceleration = 0 * (float)elapsedTime / dure;
         //   max_acceleration_right = 0 * (float)elapsedTime / dure;
        } 



else {

           // max_acceleration = 0.4;
         //   max_acceleration_right = 0.3;
        }


if(p2.posperso.x + bg.camera.x >=800){



}

 deplacerPerso(&p2, dt);


        deplacerPerso(&p1, dt);



        if(SDL_GetTicks()-tick>50){
        animerPerso(&p2);
        animerPerso(&p1);

tick=SDL_GetTicks();
}
//animation(&bg);

sautvertical(&p2,&num);

sautvertical(&p1,&num1);

if (bg.camera.x >=3500 )
{

bg.camera.x=0;
p2.posperso.x=0;
score=0;
initializeES(&es);
initialiser_dead(&dead);
    screen = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
        int res = quiz1(&en, screen);

	if (res==1){SDL_Quit();}
	

}


        tickrate = SDL_GetTicks();
tickrate1=SDL_GetTicks();
        t_fin = SDL_GetTicks();
        dt = t_fin - t_prev;







//bg_in_borders(&bg,screen);
 //afficher_bg( bg,screen);
SDL_BlitSurface(button_surface, NULL, screen, &button_rect);
}
SDL_Delay(22);

SDL_Flip(screen);
}

//Score score;
//strcpy(score.name,nom);
//score.score = bg.camera.x;
//save_score(score);
savedata(p2.posperso,bg.camera,"savemini");


SDL_FreeSurface(button_surface);
SDL_Quit();
}
