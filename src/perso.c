#include "perso.h"
void initPerso(Personne *p)

{
    p->posperso.x = 10;
    p->posperso.y = 560;
    p->posperso.w = 100;
    p->posperso.h = 100;

p->deplacerhaut=0;  
p->i=0;
p->j=0;
p->saut=0;
p->direction = 0; 
}
void initPerso1(Personne *p1)

{
    p1->posperso.x = 510;
    p1->posperso.y = 560;
    p1->posperso.w = 100;
    p1->posperso.h = 100;

p1->deplacerhaut=0;  
p1->i=0;
p1->j=0;
p1->saut=0;
p1->direction = 0; 
}
void initPerso2(Personne *p2)

{
    p2->posperso.x = 10;
    p2->posperso.y = 560;
    p2->posperso.w = 100;
    p2->posperso.h = 100;

p2->deplacerhaut=0;  
p2->i=0;
p2->j=0;
p2->saut=0;
p2->direction = 0; 
}
/*void afficher(Image p, SDL_Surface *screen)
{
    SDL_BlitSurface(p.img, &p.posfromimg, screen, &p.posinscreen);
}*/
void afficher_perso(Personne p, SDL_Surface *screen)
{
    SDL_BlitSurface(p.images[p.i][p.j], NULL, screen, &p.posperso);
}
void afficher_perso1(Personne p1, SDL_Surface *screen)
{
    SDL_BlitSurface(p1.images[p1.i][p1.j], NULL, screen, &p1.posperso);
}
void afficher_perso2(Personne p2, SDL_Surface *screen)
{
    SDL_BlitSurface(p2.images[p2.i][p2.j], NULL, screen, &p2.posperso);
}
void animerPerso1(Personne *p1){
     
if(p1->action==1){ 
 p1->i=p1->direction;
    if ( p1->j  > 13)  p1->j = -1;
    p1->j+=1; }

else if (p1->action==0) {
 p1->acceleration=0;
  p1->i=p1->direction+2;
 
     if ( p1->j > 13)  p1->j = -1;
     p1->j += 1; 
     
}
}
void animerPerso2(Personne *p2){
     
if(p2->action==1){ 
 p2->i=p2->direction;
    if ( p2->j  > 13)  p2->j = -1;
    p2->j+=1; }

else if (p2->action==0) {
 p2->acceleration=0;
  p2->i=p2->direction+2;
 
     if ( p2->j > 13)  p2->j = -1;
     p2->j += 1; 
     
}
}
void animerPerso(Personne *p){
     
if(p->action==1){ 
 p->i=p->direction;
    if ( p->j  > 13)  p->j = -1;
    p->j+=1; }

else if (p->action==0) {
 p->acceleration=0;
  p->i=p->direction+2;
 
     if ( p->j > 13)  p->j = -1;
     p->j += 1; 
     
}
}
void MovePerso(Personne *p){

if(p->action){

if(p->posperso.x<900&&p->direction==0){ 
p->posperso.x+=(7+p->acceleration);
if(p->acceleration<7) p->acceleration+=1;
}
else   
if(p->posperso.x>0&&p->direction==1){ 
p->posperso.x-=15;
 
}
 

}}
void MovePerso1(Personne *p1){

if(p1->action){

if(p1->posperso.x<900&&p1->direction==0){ 
p1->posperso.x+=(7+p1->acceleration);
if(p1->acceleration<7) p1->acceleration+=1;
}
else   
if(p1->posperso.x>510&&p1->direction==1){ 
p1->posperso.x-=15;
 
}
 

}}
void MovePerso2(Personne *p2){

if(p2->action){

if(p2->posperso.x<400&&p2->direction==0){ 
p2->posperso.x+=(7+p2->acceleration);
if(p2->acceleration<7) p2->acceleration+=1;
}
else   
if(p2->posperso.x>0&&p2->direction==1){ 
p2->posperso.x-=15;
 
}
 

}}
void saut(Personne* p) {
 if(p->saut&&p->posperso.y==560){
    p->deplacerhaut=1;}
if(p->deplacerhaut==1){p->posperso.y-=10;}
if(p->posperso.y<400-(p->acceleration*6)){p->deplacerhaut=0;}
if(p->deplacerhaut==0&&p->posperso.y<560){
   p->posperso.y+=10; 
} 


}
 
 

void initlise_matrice(Personne* p){
    // Initialize surface images
    for (int j = 0; j < 4; j++) {
        for (int i = 0; i <= 14; i++) {
            char filename[50];
            sprintf(filename, "images/personnage/sprite%d_%d.png", j, i);
       
            p->images[j][i] = IMG_Load(filename);
            if (p->images[j][i] == NULL) {
                printf("Error loading image: %s\n", SDL_GetError());
            }
        }
    }
}
void initlise_matrice1(Personne* p1){
    // Initialize surface images
    for (int j = 0; j < 4; j++) {
        for (int i = 0; i <= 14; i++) {
            char filename[50];
            sprintf(filename, "images/personnage/sprite%d_%d.png", j, i);
       
            p1->images[j][i] = IMG_Load(filename);
            if (p1->images[j][i] == NULL) {
                printf("Error loading image: %s\n", SDL_GetError());
            }
        }
    }
}
void initlise_matrice2(Personne* p2){
    // Initialize surface images
    for (int j = 0; j < 4; j++) {
        for (int i = 0; i <= 14; i++) {
            char filename[50];
            sprintf(filename, "images/personnage/sprite%d_%d.png", j, i);
       
            p2->images[j][i] = IMG_Load(filename);
            if (p2->images[j][i] == NULL) {
                printf("Error loading image: %s\n", SDL_GetError());
            }
        }
    }
}
