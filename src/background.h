
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>


typedef struct 
{
    SDL_Rect pos;
    SDL_Surface * url ;
}image1;
typedef struct
{

    SDL_Surface *image;
    SDL_Rect camera1;
    SDL_Rect pos;
    

} background;
typedef struct 
{
    SDL_Rect pos1;
    SDL_Rect pos2;
    SDL_Surface * img ;
}Image;
typedef struct
{    
     int score;
     int temps;
     char playername[20];
}scoreinfo;
typedef struct
{
Mix_Music * bg_music;
}Music;
typedef struct
{
	SDL_Rect position;
	TTF_Font *font;
	SDL_Surface *surfaceTexte;
	SDL_Color textcolor;
	char text [40];
	char scoreText[20];
}Text;
typedef struct {
    char *filename;
    SDL_Surface *surface;
    
} Image1;
typedef struct {
    char *filename1;
    SDL_Surface *surface;
    SDL_Rect posoiseau;
} Image2;
typedef struct {
    char *filename3;
    SDL_Surface *surface;
    SDL_Rect posflag;
} Image3;
typedef struct{
	SDL_Surface *txt;
	SDL_Rect pos;
	SDL_Color color;
	TTF_Font *font;
	char tempsText[20];
}texte;
void initialiser_text(texte* text,char* font,float size,int r,int g,int b,int x,int y);
void afficher_text(SDL_Surface* screen,texte text,char* message);
void free_text(texte text);
void initialise_img(image1 *A,char* path,int x,int y);
void afficher1 (image1 A, SDL_Surface *screen);
void initbouton(Image *Back);
void liberer (image1 A);
void bestScore(char *filename, scoreinfo trois[]);
void initBack(background *b);
void initBack3(background *b3);
void initBack1(background *b1);
void initBack2(background *b2);
void initBack4(background *b4);
void initback(Image *Back);
void initText(Text *t);
void playMusic(Music *m);
void load_images(Image1 images[]);
void load_images1(Image2 images1[]);
void load_images3(Image3 images4[]);
void displayBack(SDL_Surface *screen, background *b);
void displayBack3(SDL_Surface *screen,background *b3);
void displayBack1(SDL_Surface *screen,background *b1);
void displayBack2(SDL_Surface *screen,background *b2);
void displayBack4(SDL_Surface *screen,background *b4);
void InitMusic(Music *m);
void afficher (Image p, SDL_Surface *screen);
void scrolling(background *b,int direction);
void scrolling1(background *b1,int direction);
void scrolling2(background *b2,int direction);
void scrolling3(background *b3,int direction);
void scrolling4(background *b4,int direction);
void displayText(Text t ,SDL_Surface *screen);
void afficher_score(scoreinfo trois[3], SDL_Surface *screen);
void saveScore( scoreinfo s,char *filename );
void freeText(Text A);
void free_images(Image1 images[]);
void free_images1(Image2 images1[]);
void free_images3(Image3 images4[]);
void musiquebref_click(Mix_Chunk *music,int volume);
void liberer_musiquebref(Mix_Chunk *music);
