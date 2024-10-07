#ifndef ENNEMIE_H_INCLUDED
#define ENNEMIE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include<time.h>
/*#include "entity.h"*/
#include "perso.h"


typedef struct {
	SDL_Surface *ennemie ;  
	SDL_Rect pos_ennemie; 
	SDL_Rect anim_ennemie[70]; 
	int frame_ennemie;
	int direction;
	int col ;
	int type;
	int maxi_up,maxi_down;
	int show;

}Ennemie;
/////////////////////////////////////////////entity///////////////////////////////////////////////////////////////////
typedef struct {   
	  
        SDL_Rect pos_entity; 
	SDL_Surface *entity;  
	SDL_Rect anim_entity[7];  
	int frame_entity;
	int direction;
	int col ;
	int maxi_up,maxi_down;
	int show; 

}entity ;




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void init_tab_anim_ennemie (SDL_Rect* clip,Ennemie *e); 
void initEnnemi  (Ennemie *e) ;
void afficherEnnemi (Ennemie e, SDL_Surface *screen);
void animerEnnemi (Ennemie *e);
void deplacerIA (Ennemie *e,Personne *p);
void update_ennemie (Ennemie *e,Personne *p);

/*int detect_collision_ennemie(personnage *p, Ennemie *e);*/

int gerer(Ennemie *e) ; 
///////////////////////////////////////entity///////////////////////////////////////////////////////////////////
/*void init_tab_anim_entity(SDL_Rect* clip,entity *e);
void initentity (entity *e) ;
void afficherentity(entity e , SDL_Surface *screen); 
void animerentity(entity *e);
void deplacer(entity *e);
void update_entity(entity *e);

int detect_collision(personnage *p, entity* e); 
int gestion(entity* e); 
void initialiser_perso(personnage *p);
void afficher_perso(personnage p , SDL_Surface *screen);*/



#endif 
