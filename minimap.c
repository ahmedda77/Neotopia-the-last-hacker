#include "minimap.h"
/*
void init_background(struct_img *background)
{
       background->image = IMG_Load("minimap.png");
       background->positionfromimage.x = 0;
       background->positionfromimage.y = 0;
       background->positionfromimage.h = 600;
       background->positionfromimage.w = 600;
 
};
void init_maske(struct_img *maske)
{
	maske->image = IMG_Load("masque.png");
	maske->positionfromimage.x = 0;
	maske->positionfromimage.y = 0;
	maske->positionfromimage.h = 600;
	maske->positionfromimage.w = 600;
 
};*/
void initmap(minimap * m) {
	m->minimap.image=IMG_Load("minimap.png");
	m->minimap.positioninscrenn.x=400;
	m->minimap.positioninscrenn.y=100;

	m->bonhomme.image=IMG_Load("bonhomme.png");
	m->bonhomme.positioninscrenn.x=10;
	m->bonhomme.positioninscrenn.y=10;

	m->animation.image=IMG_Load("animation.png");
	m->animation.positioninscrenn.x=200;
	m->animation.positioninscrenn.y=50;
	m->animation.positionfromimage.x=0;
	m->animation.positionfromimage.y=0;
	m->animation.positionfromimage.h=50;
	m->animation.positionfromimage.w=30;

	TTF_Init(),//time
	m->timestarted=SDL_GetTicks();
	m->time.font=TTF_OpenFont("ttf.ttf",50);
	m->time.color=(SDL_Color){0,0,205};
	m->time.postext.x=0;
	m->time.postext.y=0;
};
void afficherminimap(minimap m,SDL_Surface *screen) {

	SDL_BlitSurface(m.minimap.image,NULL,screen,&m.minimap.positioninscrenn);//minimap	
	SDL_BlitSurface(m.bonhomme.image,NULL,screen,&m.bonhomme.positioninscrenn);//bonhomme
	SDL_BlitSurface(m.animation.image,&m.animation.positionfromimage,screen,&m.animation.positioninscrenn);//animation
	SDL_BlitSurface(m.time.text,NULL,screen,&m.time.postext);//

};


void animerMinimap(minimap *m) {
	if(m->animation.positionfromimage.x>m->animation.image->w-m->animation.positionfromimage.w){
	m->animation.positionfromimage.x=0;

	}else {
	m->animation.positionfromimage.x+=m->animation.positionfromimage.w ;
	}

};
 
void MAJMinimap(SDL_Rect posJoueur,  minimap * m, SDL_Rect camera){
	
	m->bonhomme.positioninscrenn.x=(((posJoueur.x+camera.x)/6)+400);
	m->bonhomme.positioninscrenn.y=(((posJoueur.y+camera.y)/5)+95);

};
void Liberer (minimap * m){
	SDL_FreeSurface(m->minimap.image);
	SDL_FreeSurface(m->bonhomme.image);
	SDL_FreeSurface(m->animation.image);

};

/*
void sauvgarder(Personne p,background b,char *nomfichier) {

	FILE *file=fopen(nomfichier, "w");
	fprintf(file,"%d:%d:%d:%d:%d:%d\n",b.background.positionfromimage.x,b.background.positionfromimage.y,b.stage
	,p.perso.positioninscrenn.x,p.perso.positioninscrenn.y,p.direction


	);
	fclose(file);
};

void charger(Personne *p,background *b,char *nomfichier) {


	FILE *file=fopen(nomfichier, "r");
	fscanf(file,"%hd:%hd:%d:%hd:%hd:%d\n",&b->background.positionfromimage.x,&b->background.positionfromimage.y,&b->stage
	,&p->perso.positioninscrenn.x,&p->perso.positioninscrenn.y,&p->direction);
	fclose(file);
};
SDL_Color  GetPixel(SDL_Surface *pSurface,int x,int y)

{
	SDL_Color color;
	Uint32 col=0;
	//Determine position
	char* pPosition=(char* ) pSurface->pixels;
	pPosition+= (pSurface->pitch * y);
	pPosition+= (pSurface->format->BytesPerPixel *x);
	memcpy(&col ,pPosition ,pSurface->format->BytesPerPixel);
	//convertir color
	SDL_GetRGB(col,pSurface->format, &color.r, &color.g, &color.b);
	return (color); 
	}
int collisionPP(Personne *p, SDL_Surface *Masque,background bp) {
	int persowidth=24;
	int persoheght=40;
	SDL_Color color ;
	//right
	int x=p->perso.positioninscrenn.x+persowidth+bp.background.positionfromimage.x;
	int y=p->perso.positioninscrenn.y+persoheght/2+bp.background.positionfromimage.y;
	color=GetPixel(Masque,x,y);
	if(color.r==0&&color.g==0&&color.b==0) {
	p->tabcollison[0]=1;
	}else  {
	p->tabcollison[0]=0;
	}
	//left
	int x1=p->perso.positioninscrenn.x+bp.background.positionfromimage.x;
	int y1=p->perso.positioninscrenn.y+persoheght/2+bp.background.positionfromimage.y;
	color=GetPixel(Masque,x1,y1);
	if(color.r==0&&color.g==0&&color.b==0) {
	p->tabcollison[1]=1;
	}else  {
	p->tabcollison[1]=0;
	};
	//fou9
	int x2=p->perso.positioninscrenn.x+bp.background.positionfromimage.x+persowidth/2;
	int y2=p->perso.positioninscrenn.y+bp.background.positionfromimage.y;
	color=GetPixel(Masque,x2,y2);
	if(color.r==0&&color.g==0&&color.b==0) {
	p->tabcollison[2]=1;
	}else  {
	p->tabcollison[2]=0;
	};
	//louta
	int x3=p->perso.positioninscrenn.x+bp.background.positionfromimage.x+persowidth/2;
	int y3=p->perso.positioninscrenn.y+bp.background.positionfromimage.y+persoheght;
	color=GetPixel(Masque,x3,y3);
	if(color.r==0&&color.g==0&&color.b==0) {
	p->tabcollison[3]=1;
	}else  {
	p->tabcollison[3]=0;
	};
	for (int i = 0; i < 4; i++)
	{
	 printf("tab[%d]=%d\n",i,p->tabcollison[i]);
	 }

}
*/

/*
void calculnewtime(minimap *m){
	char time[12];
	Uint32 timelapsed =SDL_GetTicks()-m->timestarted;
	sprintf(time,"%d",timelapsed/1000);
	m->time.text= TTF_RenderText_Blended(m->time.font,time,m->time.color);
	/*int timeenigme=60;
	int temprestant=timeeingme-(timelapsed/1000);
	if (tempsrestant=0){
	sprintf(time,"%d",tempsrestant/1000);
}; 
*/


void savedata(SDL_Rect posjoueur,SDL_Rect camera,char fich[])
{
	FILE *f;
	f=fopen(fich,"wb");
	if (f!=NULL){
		fwrite(&posjoueur,sizeof(SDL_Rect),1,f);
		fwrite(&camera,sizeof(SDL_Rect),1,f);
		fclose(f);
	}
}
/** 
* @brief To load game data. 
* @param fich nom du fichier
* @return Nothing
*/
void loaddata(SDL_Rect *posjoueur,SDL_Rect *camera,char fich[])
{
	FILE *f;
	f=fopen(fich,"rb");
	if (f!=NULL){
		fread(&(*posjoueur),sizeof(SDL_Rect),1,f);
		fread(&(*camera),sizeof(SDL_Rect),1,f);
		fclose(f);
	}
}


void collision(SDL_Rect*posjoueur,SDL_Rect box)
{
       

	if ((posjoueur->x+100>=box.x)&&(posjoueur->x<=box.x) && (posjoueur->y+83>=900))
		posjoueur->x=box.x-105;
	



       if ((posjoueur->x<=(box.x+170)) && (posjoueur->x>(box.x+170)) && ((posjoueur->y+83)>=900))
       	posjoueur->x=box.x+180;
       



       if (((posjoueur->x+98)>=box.x) && (posjoueur->x>=(box.x+170)) && (posjoueur->y+83<820) )
       	posjoueur->y=830-83;



 



       



}
