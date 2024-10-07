#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <time.h>
#include <SDL/SDL_mixer.h>

/*typedef struct Image
{
	SDL_Rect posfromimg;  
	SDL_Rect posinscreen; 
	SDL_Surface *img;	  
} Image;*/

typedef struct Personne
{
	int nombredevie;
	int direction;
       
	int action;
	int saut;
	int deplacerhaut;
	int acceleration;
	int score;
	/*Image scoreimg;*/
	int bonus;
	int malus;
	int newscore;
	SDL_Surface *images[4][15]; 
	SDL_Rect posperso;
    int i,j;
            
} Personne;
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
void animerPerso(Personne *p);
void animerPerso1(Personne *p1);
void animerPerso2(Personne *p2);
void MovePerso(Personne *p);
void MovePerso1(Personne *p2);
void MovePerso2(Personne *p2);
void saut(Personne *p);
void afficher_perso(Personne p, SDL_Surface *screen);
void afficher_perso1(Personne p1, SDL_Surface *screen);
void afficher_perso2(Personne p2, SDL_Surface *screen);
/*void afficher(Image p, SDL_Surface *screen);*/
void initlise_matrice(Personne* p);
void initlise_matrice1(Personne* p1);
void initlise_matrice2(Personne* p2);
void initPerso(Personne *p);
void initPerso1(Personne *p1);
void initPerso2(Personne *p2);
void init_tab_anim_ennemie (SDL_Rect* clip,Ennemie *e); 
void initEnnemi  (Ennemie *e) ;
void afficherEnnemi (Ennemie e, SDL_Surface *screen);
void animerEnnemi (Ennemie *e);
void deplacerIA (Ennemie *e,Personne *p);
/*void update_ennemie (Ennemie *e,Personne *p);*/
void init_tab_anim_entity(SDL_Rect* clip,entity *e);
void initentity (entity *e) ;
void afficherentity(entity e , SDL_Surface *screen); 
void animerentity(entity *e);
void deplacer(entity *e);
void update_entity(entity *e);
int gestion(entity* e);

