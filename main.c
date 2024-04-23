
#include "header.h"


void main()
{
bg bg,bg1,bg2;
char nom[30];
printf("Veuillez taper votre nom:");
scanf("%s",nom);
init_bg(&bg);
init_bg(&bg1);
init_bg(&bg2);
SDL_Init(SDL_INIT_EVERYTHING);
TTF_Init();
SDL_EnableKeyRepeat(60,0);
SDL_Surface *screen =SDL_SetVideoMode(1000,800,32,SDL_SWSURFACE);
int q=0;
afficher_bg( bg,screen);

musique(1);
    SDL_Rect button_rect = { 10, 10, 0, 0 };
    SDL_Color textColor = {255, 255, 255};
    SDL_Surface* button_surface = TTF_RenderText_Solid(TTF_OpenFont("font.ttf", 32),"Show Scores",textColor);
	button_rect.w = button_surface->w;
    button_rect.h = button_surface->h;
 
    SDL_Event event;
while(q==0)
{
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                q=1;
            case SDL_MOUSEBUTTONDOWN:
                if (event.button.x >= button_rect.x && event.button.x < button_rect.x + button_rect.w &&
                    event.button.y >= button_rect.y && event.button.y < button_rect.y + button_rect.h) {
                    show_top_scores(screen);
                }
                break;
			
			case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                case SDLK_UP:
                    scrolling(&bg,2,20);
                    break;
                case SDLK_DOWN:
                    scrolling(&bg,4,20);
                    break;
                case SDLK_LEFT:
                    scrolling(&bg,1,20);
                    break;
                case SDLK_RIGHT:
                    scrolling(&bg,3,20);
                    break;
               
                   
                default:
                    break;
            }
            default:
                break;
        }

    }

animation(&bg);


bg_in_borders(&bg,screen);
 afficher_bg( bg,screen);
SDL_BlitSurface(button_surface, NULL, screen, &button_rect);
SDL_Delay(100);
SDL_Flip(screen);
}
Score score;
strcpy(score.name,nom);
score.score = bg.camera.x;
save_score(score);
SDL_FreeSurface(button_surface);
SDL_Quit();
}
