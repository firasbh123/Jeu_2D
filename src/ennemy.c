
/*#include "ennemy.h"*/
#include "perso.h"


int 
nb_frame1=7 ,
ennemie_h=100,
ennemie_w=100,
ennemie_y=100,
ennemie_x=100;


void init_tab_anim_ennemie(SDL_Rect *clip,Ennemie *e)
{	


for (int i=0;i<nb_frame1; i++)
	{
	clip[i].h=ennemie_h;
	clip[i].w=ennemie_w;
	clip[i].x = i*ennemie_w;
	clip[i].y = 0;
        }


}




void initEnnemi(Ennemie *e)
{

    e->ennemie = IMG_Load("ENNEMIE.png");

    e->pos_ennemie.x = 500;
    e->pos_ennemie.y = 400;
    init_tab_anim_ennemie(e->anim_ennemie,e);
    e->frame_ennemie=0;
    e->direction=0;  
    e->col=0;
   /* e->show=1;*/
    
    
}



void afficherEnnemi(Ennemie e, SDL_Surface *screen)
{
   
   SDL_BlitSurface(e.ennemie,&e.anim_ennemie[e.frame_ennemie], screen, &e.pos_ennemie);
  
  

}

void deplacerIA(Ennemie *e,Personne *p)
{	srand (time(0));
	int diff;
	int maxi_down=400+rand()%300;
	int maxi_up=250+rand()%300;

  	printf("maxup : %d\tmaxdown : %d\n",maxi_up,maxi_down );


if(e->pos_ennemie.y>= maxi_down)
{
e->direction =1;
}
if(e->pos_ennemie.y<=maxi_up)
{
e->direction =0;
}

if(e->direction==1)
{   
	e->pos_ennemie.y-=7;

}
if(e->direction==0)
{
	e->pos_ennemie.y+=7;
}

  diff=e->pos_ennemie.y-p->posperso.x;
  
  if (diff<350 && diff>50 ){

e->pos_ennemie.x-=3;
  }

if (diff >-350 && diff < 0){
  
  e->pos_ennemie.x+=3;
  }


}



void animerEnnemi(Ennemie *e)
{   if (e->frame_ennemie >=0 && e->frame_ennemie <(nb_frame1-1)) 
 e->frame_ennemie++;
    if ( e->frame_ennemie ==(nb_frame1-1)) 
       e->frame_ennemie=0;
}


void update_ennemie(Ennemie *e,Personne *p)
{ 	deplacerIA(e,p);
	animerEnnemi(e);
	

}

int detect_collision_ennemie(Personne *p, Ennemie *e)
{
	

 ((p->posperso.x + p->posperso. w< e->pos_ennemie. x) || (p->posperso.x> e->pos_ennemie. x + e->pos_ennemie. w) ||
(p->posperso.y + p->posperso.h< e->pos_ennemie. y) || (p->posperso.y> e->pos_ennemie. y + e->pos_ennemie. h ));

}

int gerer(Ennemie *e) {
	
	e->show=0;
	
	return 0; 
}
/////////////////////////////////////////////////////////////////entity/////////////////////////////////////////////////////////////////////////////////////////
int 
nb_frame=8 , 

entity_h=100,
entity_w=100,
entity_y=100,
entity_x=100;

								 

void init_tab_anim_entity(SDL_Rect *clip,entity *e)
{		
	for (int j=0;j<nb_frame; j++)
	{
	clip[j].h=entity_h;
	clip[j].w=entity_w;
	clip[j].x = j*entity_x;
	clip[j].y = 0;
        }  
}




void initentity(entity *e)
{


    e->entity = IMG_Load("es.png"); 
    e->pos_entity.x = 400;
    e->pos_entity.y = 200;
    init_tab_anim_entity(e->anim_entity,e); 
    e->frame_entity=0;
    e->direction=0;  
    e->col=0;
    e->show=1; 
      
}



void afficherentity(entity e , SDL_Surface *screen)
{
   
   SDL_BlitSurface(e.entity,&e.anim_entity[e.frame_entity], screen, &e.pos_entity);

}

void deplacer(entity *e)
{	
	srand (time(0));
	int maxi_down=300+rand()%300;  
	int maxi_up=50+rand()%300; 

  	


if(e->pos_entity.y>= maxi_down)
{
e->direction =1;
}
if(e->pos_entity.y<=maxi_up) 
{
e->direction =0;
}

if(e->direction==1)
{   
	e->pos_entity.y-=5;

}
if(e->direction==0)
{
        
	e->pos_entity.y+=7;

}
}




void animerentity(entity *e)
{   
	if (e->frame_entity >=0 && e->frame_entity <(nb_frame-1))
	e->frame_entity++;
	
	if ( e->frame_entity ==(nb_frame-1)) 
	e->frame_entity=0;
}


void update_entity(entity *e)
{ 	
	deplacer(e);
	animerentity(e);	
}


/*int detect_collision(personnage *p, entity* e)
{
	
if ((p->perso_pos.x + p->perso_pos. w< e->pos_entity. x) || (p->perso_pos.x> e->pos_entity. x + e->pos_entity. w) ||
(p->perso_pos.y + p->perso_pos.h< e->pos_entity. y) || (p->perso_pos.y> e->pos_entity. y + e->pos_entity. h ))
return 0;
else 
return 1;
 
}*/

int gestion(entity* e)
{
e->show=0; 
return 0;

}







