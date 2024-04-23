
#ifndef _BG_H_
#define _BG_H_
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

typedef struct{
SDL_Rect pos;
char *url;
SDL_Surface *is[50];
int anim;
SDL_Rect camera;
}bg;

typedef struct {
    char name[20];
    int score;
	int temps;
} Score;

void init_bg(bg *bg);
void afficher_bg(bg bg,SDL_Surface *screen);
void anim_bg(bg *bg);
void scrolling(bg *bg,int d,int pas);
void bg_in_borders(bg *bg,SDL_Surface *screen);
void animation(bg* bg);
void animation_start(SDL_Surface *screen);
void musique(int stage);
void save_score(Score score);
void show_top_scores(SDL_Surface *screen);


#endif
