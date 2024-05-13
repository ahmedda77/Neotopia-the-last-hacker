#include "enigme.h"
#include <string.h>
#include <math.h>
void init_enigme( enigme* en )
{
    en->image_enigme = IMG_Load("background/background4.png");
    en->position_enigme.x = 0;
    en->position_enigme.y = 0;
    en->resultat = 0;
    en->correct =IMG_Load("correct.png");
    en->wrong =IMG_Load("wrong.png");
    en->position_correct.x = 250;
    en->position_correct.y = 200;
    en->position_wrong.x = 250;
    en->position_wrong.y = 200;

    en->police=TTF_OpenFont("police.ttf",45 );
    en->reponse_1 = NULL;
    en->pos_reponse_1.x=120;
    en->pos_reponse_1.y=300;

    en->reponse_2 = NULL;
    en->pos_reponse_2.x=260;
    en->pos_reponse_2.y=300;

    en->reponse_3 = NULL;
    en->pos_reponse_3.x=380;
    en->pos_reponse_3.y=300;

    en->police_q=TTF_OpenFont("police.ttf",30 );

    en->question = NULL;
    en->pos_question.x=200;
    en->pos_question.y=100;
    en->num_enigme = 1;

}

void alea_enigme(enigme *en ,SDL_Color Color)
{
	FILE* fichier = NULL;
	char ques[20] = {0};
	char rep1[10] = {0};
	char rep2[10] = {0};
	char rep3[10] = {0};
	int caracterelu,ligne =1;
	srand(time(0));
	do {
		en->num_enigme = rand()%4 + 1;
	}while ( en->num_enigme <1 || en->num_enigme > 4 );

	fichier = fopen("questions","r");
	if ( fichier != NULL )
	{
		while ( caracterelu!=EOF && ligne < en->num_enigme )
		{
			caracterelu = fgetc(fichier);
			if ( caracterelu == '\n')
				ligne++;
		}
		fscanf(fichier,"%s %s %s %s",ques, rep1, rep2, rep3);
		printf("%s , %s , %s , %s" , ques, rep1, rep2, rep3);
		fclose(fichier);
	}
	en->question = TTF_RenderText_Blended(en->police_q,ques,Color);
	en->reponse_1 = TTF_RenderText_Blended(en->police,rep1,Color);
	en->reponse_2 = TTF_RenderText_Blended(en->police,rep2,Color);
	en->reponse_3 = TTF_RenderText_Blended(en->police,rep3,Color);

}


void blit_enigme ( enigme *en, SDL_Surface *screen)
{
	SDL_BlitSurface(en->image_enigme,NULL, screen, &en->position_enigme );
	SDL_BlitSurface(en->reponse_1,NULL,screen,&en->pos_reponse_1);
        SDL_BlitSurface(en->reponse_2,NULL,screen,&en->pos_reponse_2);
        SDL_BlitSurface(en->reponse_3,NULL,screen,&en->pos_reponse_3);
        SDL_BlitSurface(en->question,NULL,screen,&en->pos_question);
}

void free_surface_enigme( enigme *en )
{
    SDL_FreeSurface(en->image_enigme);
    SDL_FreeSurface(en->correct);
    SDL_FreeSurface(en->wrong);
    SDL_FreeSurface(en->reponse_1);
    SDL_FreeSurface(en->reponse_2);
    SDL_FreeSurface(en->reponse_3);
    SDL_FreeSurface(en->question);
    TTF_CloseFont(en->police);
    TTF_CloseFont(en->police_q);
}


int quiz1(enigme *en, SDL_Surface *screen )
{
    SDL_Event event;
    SDL_Surface *anim0,*anim1,*anim2,*anim3,*anim4;
    anim0=IMG_Load("backgroundenig/background0.png");
    anim1=IMG_Load("backgroundenig/background1.png");
    anim2=IMG_Load("backgroundenig/background2.png");
    anim3=IMG_Load("backgroundenig/background3.png");
    anim4=IMG_Load("backgroundenig/background4.png");
    int i=0;

    int continuer=1;
    SDL_Color Color = {255,255,255};
    while(continuer == 1)
    {
        SDL_PollEvent(&event);
        switch(event.type)
        {
        case SDL_QUIT:
            continuer=0;

            break;

	case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
            case SDLK_ESCAPE://pour quitter
                continuer=0;

                break;
	    case SDLK_a:
		if ( en->num_enigme == 1 )
		{
		    en->resultat= 2;
		}
		else if ( en->num_enigme == 2 )
		{
	            en->resultat= 1;
		}
		else if ( en->num_enigme == 3 )
		{
		    en->resultat= 1;
		}
		else if ( en->num_enigme == 4 )
		{
		    en->resultat= 2;
		}
		break;
            case SDLK_b:
		if ( en->num_enigme == 1 )
		{
		   en->resultat= 2;
		}
		else if ( en->num_enigme == 2 )
		{
		   en->resultat= 2;
		}
		else if ( en->num_enigme == 3 )
		{
		   en->resultat= 2;
		}
		else if ( en->num_enigme == 4 )
		{
		   en->resultat= 1;
		}
		break;
	    case SDLK_c:
		if ( en->num_enigme == 1 )
		{
		   en->resultat= 1;
		}
		else if ( en->num_enigme == 2 )
		{
		   en->resultat= 2;
		}
		else if ( en->num_enigme == 3 )
		{
		   en->resultat= 2;
		}
		else if ( en->num_enigme == 4 )
		{
		   en->resultat= 2;
		}
		break;
            }
            break;

        case SDL_MOUSEBUTTONDOWN:
        {
            switch(event.button.button)
            {
            case SDL_BUTTON_LEFT:
            {
                if ( event.button.x>120 && event.button.x<220 && event.button.y>300 && event.button.y<350) //reponse1
                {
			if ( en->num_enigme == 1 )
			{
				en->resultat= 2;
			}
			else if ( en->num_enigme == 2 )
			{
				en->resultat= 1;
			}
			else if ( en->num_enigme == 3 )
			{
				en->resultat= 1;
			}
			else if ( en->num_enigme == 4 )
			{
				en->resultat= 2;
			}
                    
                }
                if ( event.button.x>260 && event.button.x<340 && event.button.y>300 && event.button.y<350) //reponse2
                {
                    	if ( en->num_enigme == 1 )
			{
				en->resultat= 2;
			}
			else if ( en->num_enigme == 2 )
			{
				en->resultat= 2;
			}
			else if ( en->num_enigme == 3 )
			{
				en->resultat= 2;
			}
			else if ( en->num_enigme == 4 )
			{
				en->resultat= 1;
			}
                }
                if ( event.button.x>380 && event.button.x<460 && event.button.y>300 && event.button.y<350) //reponse3
                {
                    	if ( en->num_enigme == 1 )
			{
				en->resultat= 1;
			}
			else if ( en->num_enigme == 2 )
			{
				en->resultat= 2;
			}
			else if ( en->num_enigme == 3 )
			{
				en->resultat= 2;
			}
			else if ( en->num_enigme == 4 )
			{
				en->resultat= 2;
			}
                }
            }
            break; //button left
            }
        }
        break;

        }// taskiret les events mtaa les boutons

        if (i<10)
        	SDL_BlitSurface(anim0, NULL, screen, NULL);
           else
           {
           	if (i<20)
           		SDL_BlitSurface(anim1, NULL, screen, NULL);
           	         else 
           	            {
           	            	if (i<30)
           	            		SDL_BlitSurface(anim2, NULL, screen, NULL);
           	            	          else
           	            	          	  {
           	            	          	  	if (i<40)
           	            	          	  		  SDL_BlitSurface(anim3, NULL, screen, NULL);
           	            	          	  		else
           	            	          	  			  {

           	            	          	  			  	if (i<50)
           	            	          	  			  		SDL_BlitSurface(anim4, NULL, screen, NULL);

 

           	            	          	  			  }




           	            	          	  }
           	            }
           }
           i++;
           if (i==50)
             	i=0;



        blit_enigme ( en, screen);

        if ( en->resultat == 1 )
        {
            SDL_BlitSurface(en->correct,NULL, screen, &en->position_correct );
            SDL_Flip(screen);
            SDL_Delay(2000);
            continuer = 0;

	    return 1;
        }
        else if ( en->resultat == 2 )
        {
            SDL_BlitSurface(en->wrong,NULL, screen, &en->position_wrong );
            SDL_Flip(screen);
            SDL_Delay(2000);
            continuer = 0;

	    return 2;
        }
        SDL_Flip(screen);


    }
    

}



void animationenig(SDL_Surface *screen) {
    // Charger les images du dossier "background" et les afficher en séquence
    for (int i = 0; i <= 4; i++) {
        char filename[50];
        sprintf(filename, "backgroundenig/background%d.png", i); // Nom de fichier basé sur l'indice
        SDL_Surface *image = IMG_Load(filename);
        if (image == NULL) {
            printf("Erreur : Impossible de charger l'image %s.\n", filename);
            exit(1);
        }

        // Afficher l'image sur l'écran
        SDL_BlitSurface(image, NULL, screen, NULL);
        SDL_FreeSurface(image);

        // Mettre à jour l'écran
        SDL_Flip(screen);

        // Attendre quelques secondes avant de passer à l'image suivante
        SDL_Delay(600); // 2000 millisecondes (2 secondes)
    }
}
