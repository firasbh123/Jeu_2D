#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "background.h"

void initialiser_text(texte* text,char* font,float size,int r,int g,int b,int x,int y){
	text->font=TTF_OpenFont(font,size);
	text->color.r=r;
	text->color.g=g;
	text->color.b=b;
	text->pos.x=x;
	text->pos.y=y;
}
void afficher_text(SDL_Surface* screen,texte text,char* message){
	text.txt=TTF_RenderText_Blended(text.font,message,text.color);
	SDL_BlitSurface(text.txt,NULL,screen,&text.pos);
}
void free_text(texte text){
	TTF_CloseFont(text.font);//segmentation fault
}
void liberer (image1 A)
{
if (A.url != NULL)
SDL_FreeSurface (A.url);
}
void afficher1 (image1 A, SDL_Surface *screen)
{
SDL_BlitSurface(A.url,NULL,screen,&A.pos);
}
void initialise_img(image1 *A,char* path,int x,int y)
{
A->url = IMG_Load(path);
if (A->url== NULL)
 {
    printf("pas d'image\n");
}
else{
A->pos.x=x;
A->pos.y=y;
}
}
void initBack(background *b)
{

    b->image = IMG_Load("back33.png"); 
    b->camera1.x = 0;
    b->camera1.y = 0;
    b->camera1.w = 1000;
    b->camera1.h = 1000;


}
void initBack1(background *b1)
{

    b1->image = IMG_Load("back33.png"); 
    b1->camera1.x = 0;
    b1->camera1.y = 0;
    b1->camera1.w = 500;
    b1->camera1.h = 1000;
     b1->pos.x=0;
    b1->pos.y=0;

}
void initBack2(background *b2)
{

    b2->image = IMG_Load("back33.png"); 
    b2->camera1.x = 0;
    b2->camera1.y = 0;
    b2->camera1.w = 500;
    b2->camera1.h = 1000;
    b2->pos.x=500;
    b2->pos.y=0;


}
void initBack3(background *b3)
{

    b3->image = IMG_Load("back1(1).png"); 
    b3->camera1.x = 0;
    b3->camera1.y = 0;
    b3->camera1.w = 1000;
    b3->camera1.h = 1000;


}
void initBack4(background *b4)
{

    b4->image = IMG_Load("back22.png"); 
    b4->camera1.x = 0;
    b4->camera1.y = 0;
    b4->camera1.w = 1000;
    b4->camera1.h = 1000;


}
void displayBack(SDL_Surface *screen,background *b)
{

    SDL_BlitSurface(b->image, &b->camera1, screen,NULL); 

}
void displayBack1(SDL_Surface *screen,background *b1)
{

    SDL_BlitSurface(b1->image, &b1->camera1, screen,&b1->pos); 

}
void displayBack2(SDL_Surface *screen,background *b2)
{

    SDL_BlitSurface(b2->image, &b2->camera1, screen,&b2->pos); 

}
void displayBack3(SDL_Surface *screen,background *b3)
{

    SDL_BlitSurface(b3->image, &b3->camera1, screen,&b3->pos); 

}
void displayBack4(SDL_Surface *screen,background *b4)
{

    SDL_BlitSurface(b4->image, &b4->camera1, screen,&b4->pos); 

}
void scrolling1(background *b1,int direction)
{
   int avancement =15;
    if (direction ==1 )
    {
        if (b1->camera1.x < 6500)
        {
            b1->camera1.x += avancement;
        }
    }
    if (direction == 2)
    {
        if (b1->camera1.x > 0)
        {
            b1->camera1.x -= avancement;
        }
    }
    if (direction == 3)
    {
        if (b1->camera1.y > 0)
        {
            b1->camera1.y -= avancement;
        }
    }
    if (direction == 4 )
    {
        if (b1->camera1.y <750 -600 )
        {
            b1->camera1.y += avancement;
        }
    }       
}
void scrolling2(background *b2,int direction)
{
   int avancement =15;
    if (direction ==5 )
    {
        if (b2->camera1.x < 6500)
        {
            b2->camera1.x += avancement;
        }
    }
    if (direction == 6)
    {
        if (b2->camera1.x > 0)
        {
            b2->camera1.x -= avancement;
        }
    }
    if (direction == 7)
    {
        if (b2->camera1.y > 0)
        {
            b2->camera1.y -= avancement;
        }
    }
    if (direction == 8 )
    {
        if (b2->camera1.y <750 -600 )
        {
            b2->camera1.y += avancement;
        }
    }       
}
void saveScore( scoreinfo s,char *filename ) {
  FILE* file = fopen(filename, "a");
  if (file != NULL) {
    fprintf(file, "%d\n", s.score);
    fclose(file);
  } 
}
void InitMusic(Music *m)
{
if (Mix_OpenAudio(22000,MIX_DEFAULT_FORMAT,2,4096) == -1 )
{
printf("error init audio\n");
exit(1);
}
m -> bg_music = Mix_LoadMUS("Two Steps From Hell - El Dorado (Skyworld)(Epic Orchestral Hybrid).mp3");
}

void playMusic(Music *m)
{
Mix_PlayMusic(m -> bg_music,-1); 
}
void initText(Text * A)
{
A->position.x=17;
A->position.y=17;
A->textcolor.r=0;
A->textcolor.g=0;
A->textcolor.b=0;
A->font =TTF_OpenFont("Ubuntu-B.ttf" , 60);
}

void freeText(Text A)
{
SDL_FreeSurface(A.surfaceTexte);
}
void load_images(Image1 images[]) {
    images[0].filename = "2.png";
    images[1].filename = "3.png";
    images[2].filename = "1.png";
    for (int i = 0; i < 3; i++) {
        images[i].surface = IMG_Load(images[i].filename);
        if (images[i].surface == NULL) {
            fprintf(stderr, "Erreur lors du chargement de l'image %s : %s\n", images[i].filename, SDL_GetError());
            exit(EXIT_FAILURE);
        }
    }
}
void free_images(Image1 images[]) {
    for (int i = 0; i < 3; i++) {
        SDL_FreeSurface(images[i].surface);
    }
 } 
 void free_images1(Image2 images1[]) {
    for (int i = 0; i < 3; i++) {
        SDL_FreeSurface(images1[i].surface);
    }
 } 
 void free_images3(Image3 images4[]) {
    for (int i = 0; i < 6; i++) {
        SDL_FreeSurface(images4[i].surface);
    }
 } 
 void initbouton(Image *Back)
{
Back -> img=IMG_Load("bouton.png");
if (Back->img == NULL) 
{
        printf("Unable to load image: %s\n", SDL_GetError());
        return;
}
Back->pos1.x=40;
Back->pos1.y=270;
Back->pos2.x=0;
Back->pos2.y=0;
Back->pos2.w=Back->img->w;
Back->pos2.h=Back->img->h;
}
void initback(Image *Back)
{
Back -> img=IMG_Load("back(1).png");
if (Back->img == NULL) 
{
        printf("Unable to load image: %s\n", SDL_GetError());
        return;
}
Back->pos1.x=0;
Back->pos1.y=0;
Back->pos2.x=0;
Back->pos2.y=0;
Back->pos2.w=Back->img->w;
Back->pos2.h=Back->img->h;
}
void bestScore(char *filename, scoreinfo trois[]) { 
int i,j; 
scoreinfo temp; 
 FILE *fPtr; 
 fPtr = fopen(filename,"r");   
 if (fPtr == NULL) {         
 printf("Cannot open file.\n");  
 exit(0);     } 
int count = 0;   
  while (!feof(fPtr)) {       
fscanf(fPtr,"%d",  &trois[count].score);   
    count++;     }    
fclose(fPtr);        
 for (i = 0; i < count; i++) {
   for (j = 0; j < (count - 1); j++) {   
          if (trois[j].score < trois[j + 1].score) {    
                                                           
           temp = trois[j];   
            trois[j] = trois[j + 1];   
            trois[j + 1] = temp; 
         }         }     }   
         
     
 }
 void afficher_score(scoreinfo trois[3], SDL_Surface *screen)
{
int i;
     if (TTF_Init() == -1)
    {
        fprintf(stderr, "Failed to initialize SDL_ttf: %s\n", TTF_GetError());
        exit(1);
    }
    SDL_Surface *texte;
    SDL_Color couleurNoire = {0,0,0};
    TTF_Font *police = NULL;
    police = TTF_OpenFont("Ubuntu-B.ttf", 25);
  if (police == NULL) {
        fprintf(stderr, "Error: failed to load font - %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    
      char str[100];
    SDL_Rect position;

    for (i = 0; i < 3; i++)
    {
        sprintf(str, "%d", trois[i].score);
        texte = TTF_RenderText_Blended(police, str, couleurNoire);
        position.x = 550;
        position.y = i * 100 + 247;
        SDL_BlitSurface(texte, NULL, screen, &position);
    }

    SDL_FreeSurface(texte);
    TTF_CloseFont(police);
}

void afficher (Image p, SDL_Surface *screen)
{
SDL_BlitSurface(p.img,&p.pos2,screen,&p.pos1);
}     
void load_images1(Image2 images1[]) {
    images1[0].filename1 = "oiseau4.png";
    images1[1].filename1 = "oiseau3.png";
    images1[2].filename1 = "oiseau2.png";
    images1[3].filename1 = "oiseau1.png";
    for (int i = 0; i < 4; i++) {
        images1[i].surface = IMG_Load(images1[i].filename1);
        if (images1[i].surface == NULL) {
            fprintf(stderr, "Erreur lors du chargement de l'image %s : %s\n", images1[i].filename1, SDL_GetError());
            exit(EXIT_FAILURE);
        }
    }
    
}
void load_images3(Image3 images4[]) {
    images4[0].filename3 = "flag2.png";
    images4[1].filename3 = "flag3.png";
    images4[2].filename3 = "flag4.png";
    images4[3].filename3 = "flag5.png";
    images4[4].filename3 = "flag6.png";
    images4[5].filename3 = "flag7.png";
    for (int i = 0; i < 6; i++) {
        images4[i].surface = IMG_Load(images4[i].filename3);
        if (images4[i].surface == NULL) {
            fprintf(stderr, "Erreur lors du chargement de l'image %s : %s\n", images4[i].filename3, SDL_GetError());
            exit(EXIT_FAILURE);
        }
    }
    
}

 
void displayText(Text t,SDL_Surface * screen)
{
t.surfaceTexte = TTF_RenderText_Solid(t.font,t.scoreText,t.textcolor );
SDL_BlitSurface(t.surfaceTexte , NULL , screen, &t.position);
}
void scrolling(background *b,int direction)
{
   int avancement =30;
    if (direction ==1 )
    {
        if (b->camera1.x < 6500)
        {
            b->camera1.x += avancement;
        }
    }
    if (direction == 2)
    {
        if (b->camera1.x > 0)
        {
            b->camera1.x -= avancement;
        }
    }
    if (direction == 3)
    {
        if (b->camera1.y > 0)
        {
            b->camera1.y -= avancement;
        }
    }
    if (direction == 4 )
    {
        if (b->camera1.y <750 /*-600*/ )
        {
            b->camera1.y += avancement;
        }
    }       
}
void scrolling3(background *b3,int direction)
{
   int avancement =30;
    if (direction ==1 )
    {
        if (b3->camera1.x < 6500)
        {
            b3->camera1.x += avancement;
        }
    }
    if (direction == 2)
    {
        if (b3->camera1.x > 0)
        {
            b3->camera1.x -= avancement;
        }
    }
    if (direction == 3)
    {
        if (b3->camera1.y > 0)
        {
            b3->camera1.y -= avancement;
        }
    }
    if (direction == 4 )
    {
        if (b3->camera1.y <750 /*-600*/ )
        {
            b3->camera1.y += avancement;
        }
    }       
}
void scrolling4(background *b4,int direction)
{
   int avancement =30;
    if (direction ==1 )
    {
        if (b4->camera1.x < 6500)
        {
            b4->camera1.x += avancement;
        }
    }
    if (direction == 2)
    {
        if (b4->camera1.x > 0)
        {
            b4->camera1.x -= avancement;
        }
    }
    if (direction == 3)
    {
        if (b4->camera1.y > 0)
        {
            b4->camera1.y -= avancement;
        }
    }
    if (direction == 4 )
    {
        if (b4->camera1.y <750 /*-600*/ )
        {
   
          b4->camera1.y += avancement;
        }
    }       
}
void musiquebref_click(Mix_Chunk *music,int volume){
	Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);
	music=Mix_LoadWAV("click_sfx_1.wav");
	Mix_PlayChannel(-1,music,0);
	Mix_VolumeChunk(music,volume);
}

void liberer_musiquebref(Mix_Chunk *music){//segmentation fault
	Mix_FreeChunk(music);
}
