#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
typedef struct struct_img {
SDL_Surface* image;
SDL_Rect positioninscrenn;
SDL_Rect positionfromimage;
}struct_img;
typedef struct struct_text{
 TTF_Font *font;
 SDL_Color color;
 SDL_Surface* text;
 SDL_Rect postext;
}struct_text;
typedef struct minimap{
   struct_img minimap;
   struct_img bonhomme ;
   struct_img animation;
   struct_text time ;
   Uint32 timestarted;
}minimap;

void initmap(minimap * m);
void afficherminimap(minimap m,SDL_Surface *screen);
void Liberer (minimap * m);
void animerMinimap(minimap *m);
void MAJMinimap(SDL_Rect posJoueur,  minimap * m, SDL_Rect camera);
void savedata(SDL_Rect posjoueur,SDL_Rect camera,char fich[]);
void loaddata(SDL_Rect *posjoueur,SDL_Rect *camera,char fich[]);
void collision(SDL_Rect*posjoueur,SDL_Rect box);
