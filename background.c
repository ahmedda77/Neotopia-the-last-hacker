

#include "background.h"


void init_bg(bg *bg)
{
char ch[50];
for(int i=1;i<51;i++)
{
sprintf(ch,"sunset/Layer %d.png",i);
bg->is[i-1] = IMG_Load(ch);
}
bg->pos.w=bg->is[1]->w;
bg->pos.h=bg->is[1]->h;
bg->camera.x=0;
bg->camera.y=0;
bg->camera.w=bg->is[1]->w;
bg->camera.h=bg->is[1]->h;
bg->anim=0;
}


void afficher_bg(bg bg,SDL_Surface *screen)
{
SDL_BlitSurface(bg.is[bg.anim],&bg.camera,screen,NULL);

}


void scrolling(bg *back, SDL_Rect posPerso, perso *p)
{
  const int speed = 15;


  if (p->direct == 1) // yt7ark 3l isar
  {
	printf("%d pos perso \n",posPerso.x);
  


      back->camera.x = back->camera.x - speed;
    }
 
  else if (p->direct == 0) //  yt7ark 3l imin
  {

	printf("%d pos perso yt7ark 3l imin \n",posPerso.x);
  
      back->camera.x = back->camera.x + speed;
    
  }
}



void musique(int stage)
{
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096);
	Mix_Music *musique; 
    char nom_musique[40];
	sprintf(nom_musique,"musiques/%d.mp3",stage); 
	musique = Mix_LoadMUS(nom_musique); 
    Mix_PlayMusic(musique, -1);
	Mix_VolumeMusic(128);
}





void save_score(Score score) {
    FILE *fp;
    fp = fopen("score.txt", "a");
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }
    fprintf(fp, "%s %d\n", score.name, score.score);
    fclose(fp);
}



void show_top_scores(SDL_Surface *screen) {
    TTF_Font *font;
    SDL_Color textColor = {255, 255, 255}; 
    SDL_Surface *textSurface;
    SDL_Rect textPos;
    char scoreStr[30];
    Score scores[100] = {0};
    int i, j;
    FILE *fp;

    
    font = TTF_OpenFont("font.ttf", 28);
    if (font == NULL) {
        printf("Error opening font\n");
        return;
    }

    
    fp = fopen("score.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }
    for (i = 0; i < 100; i++) {
        if (fscanf(fp, "%s %d", scores[i].name, &scores[i].score) == EOF) {
            break;
        }
    }
    fclose(fp);
   
    for (i = 0; i < 99; i++) {
        for (j = i+1; j < 100; j++) {
            if (scores[j].score > scores[i].score) {
                Score temp = scores[i];
                scores[i] = scores[j];
                scores[j] = temp;
            }
        }
    }

   
    for (i = 0; i < 3; i++) {
        sprintf(scoreStr, "%d. %s: %d", i+1, scores[i].name, scores[i].score);
        textSurface = TTF_RenderText_Solid(font, scoreStr, textColor);
        textPos.x = (screen->w - textSurface->w) / 2;
        textPos.y = 50 + i * 50;
        SDL_BlitSurface(textSurface, NULL, screen, &textPos);
        SDL_FreeSurface(textSurface);
    }
//SDL_Flip(screen);SDL_Delay(1500);
    TTF_CloseFont(font);
}
void partage_ecran(bg bg1,bg bg2,SDL_Surface *screen)
{
SDL_BlitSurface(bg1.is[bg1.anim],&bg1.camera,screen,NULL);//affichage bg1
bg2.pos.x=screen->w/2;
SDL_BlitSurface(bg2.is[bg2.anim],&bg2.camera,screen,&bg2.pos);
}


