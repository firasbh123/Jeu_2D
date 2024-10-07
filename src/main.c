#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "background.h"
#include "perso.h"
#include "enigme5.h"
#include <stdio.h>   
#include <unistd.h>  
#include <fcntl.h>  
#include <errno.h>   
#include <termios.h>  
#include <string.h>  
#include <sys/ioctl.h>
#include <stdint.h>
#include "serie.h" 



int main()
{
    
    SDL_Event event;
    SDL_Surface *screen,*image;
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    screen = SDL_SetVideoMode(1000,750, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN);
    Mix_Chunk *clk;
    Mix_Music *music;
    int continuer = 1;
    int test2=1;
    int test3=1;
    int test4=1;
    int test5=1;
    int test6=1;
    int w1=1;
    int w2=1;
    int w3=1;
    int w4=1;
    int w5=1;
    int w6=1;
    int w7=1;
    int w8=1;
    int c=1;
    int c1=1;
    int c2=1;
    int r1=1;
    int a1=0;
    int a2=0;
    int a3=0;
    int a4=0;
     int a5=0;
     int y=0;
    int a6=0;
    int a7=0;
    int a8=0;
    int done=0;
    int l1=0;
    int l2=0;
    int l3=0;
    int l4=0;
    image1 back1;
    image1 gagne;
    image1 player1;
    image1 players2;
    image1 player11;
    image1 players22;
    image1 bouton1;
     image1 vie;
     image1 vie2;
     image1 vie1;
     image1 lost;
     image1 eco;
     image1 gaea;
     Image bouton;
      image1 stage1;
    image1 stage22;
    image1 stage3;
    image1 play;
    image1 settings;
    image1 quit;
    image1 play1;
    image1 settings1;
    image1 quit1;
     int an=1;
     int k=0;int done1=1;
      initialise_img(&gagne,"gagne.png",0,0);
    initialise_img(&back1,"b.png",0,0);
    initialise_img(&player1,"1 PLAYER.png",40,100);
    initialise_img(&players2,"2 players.png",40,180);
    initialise_img(&player11,"1player.png",38,100);
    initialise_img(&players22,"2PLAYERS.png",40,180);
    initialise_img(&bouton1,"bouton1.png",32,268);
    initialise_img(&vie,"vie3.png",700,20);
    initialise_img(&vie2,"vie2.png",700,20);
     initialise_img(&vie1,"vie1.png",700,20);
     initialise_img(&lost,"lost.png",0,0);
     initialise_img(&stage1,"stage1.png",280,100);
    initialise_img(&stage22,"stage22.png",280,180);
    initialise_img(&stage3,"stage3.png",280,268);
    initialise_img(&play,"play.png",60,100);
    initialise_img(&settings,"settings.png",60,180);
    initialise_img(&quit,"quit.png",60,268);
    initialise_img(&play1,"play1.png",60,95);
    initialise_img(&settings1,"settings1.png",60,180);
    initialise_img(&quit1,"quit1.png",60,268);
    initbouton(&bouton);
     initialise_img(&eco,"eco.png",230,200);
    initialise_img(&gaea,"gaea.png",570,200);
    scoreinfo trois[255]={0};
    int current_image = 0;
    int num_images = 3;
    Image1 images[3];
    int current_image1 = 0;
    int num_images1 = 4;
    Image2 images1[4];
    int current_image3 = 0;
    int num_images3 = 6;
    Image3 images4[6];
    TTF_Init();
    SDL_EnableKeyRepeat(1, 0);
    background b;
    background b1;
     background b2;
     background b3;
     background b4;
    Image back;
    Text t;
    texte t1;
    texte t2;
    texte t3;  
     texte ecoo; 
     texte gaeaa;  
     texte time;
    Music m;
    scoreinfo s;
    s.score =0 ;
    s.temps =0;
    int test=1;

    bestScore("score.txt", trois);
    initBack(&b);
    initBack1(&b1);
    initBack2(&b2);
    initBack3(&b3);
    initBack4(&b4);
    initback(&back);
    InitMusic(&m);  
    initText(&t); 
    initialiser_text(&t1,"Ubuntu-B.ttf",50,0,0,0,450,17);
    initialiser_text(&t2,"Ubuntu-B.ttf",50,0,0,0,450,17);
    initialiser_text(&t3,"Ubuntu-B.ttf",50,0,0,0,450,17 );
    initialiser_text(&ecoo,"Ubuntu-B.ttf",50,0,0,0,270,160);
    initialiser_text(&gaeaa,"Ubuntu-B.ttf",50,0,0,0,580,160); 
    initialiser_text(&time,"Ubuntu-B.ttf",60,0,0,0,17,70);           
    load_images(images);
    load_images1(images1);
    load_images3(images4);
    Personne player,joueur1,joueur2;
    initPerso(&player);
    initlise_matrice(&player);
    initPerso1(&joueur1);
    initlise_matrice1(&joueur1);
    initPerso2(&joueur2);
    initlise_matrice2(&joueur2);
    Ennemie en;
    initEnnemi (&en) ;
   
    int KeyHeld[323]={0}; 
     
      playMusic(&m); 
       player.action=0;
    int score = 100;
    SDL_WM_SetCaption("SDL Game", NULL);
    Enigme e;
    e.selected = -1;
    int one = 0;

    geneerEnigme(&e, "questions.txt");
    initilisationimagebackground(&e.backgro);
    initilisation_animation(&e.anim);
    e.anim.screen = screen;
    int diplayscore = 0;
    int newscore = 0;

 perso p, p2;
  p.current_level = 2;
  p.hp = 2;
  strcpy(p.name, "ranim");
  p.score = 400;
  backgro b22, b222;
 b22.x_pos = 6000;
  b22.y_pos = 0; 
      load(&p2, &b222, "save.txt", "ranim");
          // afficher laod
          printf("name: %s\n", p2.name);
          printf("HP: %d\n", p2.hp);
          printf("Score: %d\n", p2.score);
          printf("Current level: %d\n", p2.current_level);
          printf("X position: %d\n", b222.x_pos);
          printf("Y position: %d\n", b222.y_pos);
          //tester la fonction save
          savegame(p, b22, "save.txt");  
    Uint32 t_prev2, t_prev1, t_prev3;
    char buffer[100];                   // un buffer
    int i;
    uint8_t val1='6';
    uint8_t val2='5';
    uint8_t val3='11';
    uint8_t val4='12';
    int fd = serialport_init("/dev/ttyUSB0",9600); 
    while (continuer)
    {   
         afficher1 (back1,screen);
         afficher1 (play,screen);
         afficher1 (settings,screen);
         afficher1 (quit,screen); 
         while (SDL_PollEvent(&event))
        {
            
            switch (event.type)
            {
            case SDL_QUIT:

                continuer = 0;
                
                break;
                 
             case SDL_MOUSEMOTION:
                if (( event.motion.y<=153 && event.motion.y>=100) &&(event.motion.x<=153 && event.motion.x>=40))
                {
                w6=0;
                }
                else
                {
                w6=1;
                }
                if (( event.motion.y<=233 && event.motion.y>=180) &&(event.motion.x<=150 && event.motion.x>=40))
                {
                w7=0;
                }
                else
                {
                w7=1;
                }
                if ( (event.motion.y<=317 && event.motion.y>=268) && (event.motion.x<=151 && event.motion.x>=40))
                {
                w8=0;
                }
                else
                {
                w8=1;
                }
                break;
              case SDL_MOUSEBUTTONDOWN:
                if ( ( event.motion.y<=153 && event.motion.y>=100) &&(event.motion.x<=153 && event.motion.x>=40))  {musiquebref_click(clk,25);w5=0;}
                if ( (event.motion.y<=317 && event.motion.y>=268) && (event.motion.x<=151 && event.motion.x>=40)){continuer=0;}
                break;
            }
         }
         if(w6==0)
         {
              afficher1 (play1,screen);
         }
         if(w7==0)
         {
              afficher1 (settings1,screen);
         }
         if(w8==0)
         {
              afficher1 (quit1,screen);
         }
         if(w5==0)
         {  
         afficher1 (back1,screen);
         afficher1 (player1,screen);
         afficher1 (players2,screen);
         afficher(bouton,screen);
        
              
        while (SDL_PollEvent(&event))
        {
            
            switch (event.type)
            {
            case SDL_QUIT:

                continuer = 0;
                 saveScore(s,"score.txt");
                break;
                 
             case SDL_MOUSEMOTION:
                if (( event.motion.y<=171 && event.motion.y>=100) &&(event.motion.x<=240 && event.motion.x>=40))
                {
                test2=0;
                }
                else
                {
                test2=1;
                }
                if (( event.motion.y<=253 && event.motion.y>=180) &&(event.motion.x<=240 && event.motion.x>=40))
                {
                test3=0;
                }
                else
                {
                test3=1;
                }
                if ( (event.motion.y<=333 && event.motion.y>=270) && (event.motion.x<=240 && event.motion.x>=40))
                {
                test5=0;
                }
                else
                {
                test5=1;
                }
                break;
              case SDL_MOUSEBUTTONDOWN:
                if ( ( event.motion.y<=171 && event.motion.y>=100) &&(event.motion.x<=240 && event.motion.x>=40))  {/*test4=0;*/c=0;}
                if ( ( event.motion.y<=253 && event.motion.y>=180) &&(event.motion.x<=240 && event.motion.x>=40) &&c==1)  {test6=0;}
                if ( (event.motion.y<=333 && event.motion.y>=270) && (event.motion.x<=240 && event.motion.x>=40) &&c==1)  {test=0;}
                break;
            }
         }
        
         if(test2==0)
         {
              afficher1 (player11,screen);
         }
         if(test3==0)
         {
              afficher1 (players22,screen);
         }
         if(test5==0)
         {
              afficher1 (bouton1,screen);
         }
         if(c==0)
         {
         SDL_PollEvent(&event);
         afficher1 (back1,screen);
         afficher1 (stage1,screen);
         afficher1 (stage22,screen);
         afficher1 (stage3,screen);
         if(event.key.keysym.sym==SDLK_ESCAPE){c=1;}
         
                switch (event.type)
            { 
                 case SDL_MOUSEBUTTONDOWN:
                if ( ( event.motion.y<=171 && event.motion.y>=100) &&(event.motion.x<=480 && event.motion.x>=280 )) 
                {c1=0;
                
                }
                if ( ( event.motion.y<=251 && event.motion.y>=180) &&(event.motion.x<=480 && event.motion.x>=280)) 
                {
                w1=0;
                
                }
                if ( ( event.motion.y<=339 && event.motion.y>=268) &&(event.motion.x<=480 && event.motion.x>=280)) 
                {
                w2=0;
                
                }
                break;
                }
                
                if(c1==0)
         {
         //SDL_PollEvent(&event);
         afficher1 (back1,screen);
         afficher1 (eco,screen);
         afficher1 (gaea,screen);
         afficher_text(screen,ecoo,"ECO");
         afficher_text(screen,gaeaa,"GAEA");
         switch (event.type)
            { 
                 case SDL_MOUSEBUTTONDOWN:
                if ( ( event.motion.y<=600 && event.motion.y>=200) &&(event.motion.x<=425 && event.motion.x>=230)) 
                {test4=0;}
                
                break;
                }
         if(event.key.keysym.sym==SDLK_ESCAPE){ c1=1;}
         }
         else{c1=1;}
         if(w1==0 )
         {
         
         afficher1 (back1,screen);
         afficher1 (eco,screen);
         afficher1 (gaea,screen);
         afficher_text(screen,ecoo,"ECO");
         afficher_text(screen,gaeaa,"GAEA");
         
         switch (event.type)
            { 
                 case SDL_MOUSEBUTTONDOWN:
                if ( ( event.motion.y<=600 && event.motion.y>=252) &&(event.motion.x<=425 && event.motion.x>=230)) 
                {w3=0;}
                
                break;
                }
         if(event.key.keysym.sym==SDLK_ESCAPE){ w1=1;}
         }else{w1=1;}
         if(w2==0 )
         {
         
         afficher1 (back1,screen);
         afficher1 (eco,screen);
         afficher1 (gaea,screen);
         afficher_text(screen,ecoo,"ECO");
         afficher_text(screen,gaeaa,"GAEA");
         
         switch (event.type)
            { 
                 case SDL_MOUSEBUTTONDOWN:
                if ( ( event.motion.y<=600 && event.motion.y>=340) &&(event.motion.x<=425 && event.motion.x>=230)) 
                {w4=0;}
                
                break;
                }
         if(event.key.keysym.sym==SDLK_ESCAPE){ w2=1;}
         }else{w2=1;}
         }
         
         else{c=1;}
        if(test==0){
        //SDL_PollEvent(&event);
        afficher(back,screen);
        afficher_score(trois, screen);
        SDL_Flip(screen);
        if(event.key.keysym.sym==SDLK_ESCAPE){ test=1;}
        }
         if(test6==0){
         displayBack1(screen,&b1);
         displayBack2(screen,&b2);
         afficher_perso2(joueur2, screen);
         afficher_perso1(joueur1, screen);
         if(r1==1)
         {
         if(KeyHeld[SDLK_RIGHT])
         {
         scrolling1(&b1,1);
         
                 		 joueur2.action = 1;  
        		 animerPerso2(&joueur2); 
         }
          if(KeyHeld[SDLK_LEFT])
         {
         scrolling1(&b1,2);
         
         joueur2.direction = 1;
                joueur2.action = 1;
            MovePerso2(&joueur2);
            animerPerso2(&joueur2);
         }
          if(KeyHeld[SDLK_UP])
         {
         scrolling1(&b1,3);  
         }
          if(KeyHeld[SDLK_DOWN])
         {
         scrolling1(&b1,4);  
         }
         if(KeyHeld[SDLK_h])
         {
         
         joueur2.direction = 0;
         joueur2.action = 1;  
            MovePerso2(&joueur2);
            animerPerso(&joueur2); 
         }
          if(KeyHeld[SDLK_d])
         {
         scrolling2(&b2,5);
         
         joueur1.action = 1;  
        		 animerPerso1(&joueur1); 
         }
          if(KeyHeld[SDLK_q])
         {        
         joueur1.direction = 1;
                joueur1.action = 1;
            MovePerso1(&joueur1);
            animerPerso1(&joueur1); 
         }
          if(KeyHeld[SDLK_z])
         {
         scrolling2(&b2,7);   
         }
          if(KeyHeld[SDLK_s])
         {
         scrolling2(&b2,8);   
         }
         if(KeyHeld[SDLK_g])
         {
         
         joueur1.direction = 0;
          joueur1.action = 1;  
            MovePerso(&joueur1);
            animerPerso(&joueur1); 
         }
         }
        //SDL_PollEvent(&event);
        
            switch (event.type)
            {
           
                case SDL_KEYDOWN:{
                r1=1;
		        KeyHeld[event.key.keysym.sym]=1;
		        break;}
		case SDL_KEYUP:{
		r1=0;
		        KeyHeld[event.key.keysym.sym]=0;
		        break;}
            }
           
            if(event.key.keysym.sym==SDLK_n){ test6=1;}
           
          test4=1;
         
         }       
         if(w4==0)
         {
         //SDL_PollEvent(&event);        
         displayBack4(screen,&b4);
          afficher_perso(player, screen); 
          afficher1 (vie,screen);
          
            animerPerso(&player);
            afficher_text(screen,t1,"STAGE3");
            
          
             if((b4.camera1.x>=0)&&(b4.camera1.x<6500)){
             s.temps++;
             SDL_Delay(50);}
            switch (event.type)
            {
            case SDL_KEYDOWN:

                switch (event.key.keysym.sym)
                {

                case SDLK_RIGHT:
                    scrolling4(&b4,1); 
                    if(b4.camera1.x<6500){
        		s.score++; 
        		 player.action = 1;  
        		 animerPerso(&player);    		
        	}
        	                  
                    break;
                case SDLK_m:
                if((b4.camera1.x>=0) &&( b4.camera1.x<=7400)&&(b4.camera1.y>=0) &&( b4.camera1.y<=470)){
        	player.direction = 0;
                player.action = 1;  
            MovePerso(&player);
            animerPerso(&player);
            }
                  
                break;
                case SDLK_LEFT:
                    scrolling4(&b4,2); 
                    if((b4.camera1.x>=0) &&( b.camera1.x<=7500)&&(b4.camera1.y>=0) &&( b4.camera1.y<=470)){
                    player.direction = 1;
                player.action = 1;
            MovePerso(&player);
            animerPerso(&player);
                
        	}
        	                 
                    break;

                /*case SDLK_DOWN:
                    /*scrolling(&b,4);                   
                    break;*/

                case SDLK_UP:
                    scrolling4(&b4,3); 
                    break;
                     case SDLK_SPACE:
                    if((b4.camera1.x>=0) &&( b4.camera1.x<=7500)&&(b4.camera1.y>=0) &&( b4.camera1.y<=470)){
                     player.saut = 1;
                     
          saut(&player);
            MovePerso(&player);
                     
        	}
        	                  
                    break;
                }
                break;
             case SDL_KEYUP:
                switch (event.key.keysym.sym)
                {

                case SDLK_RIGHT:
                    scrolling4(&b4,0); 
                case SDLK_m:
                if((b4.camera1.x>=0) &&( b4.camera1.x<=7400)&&(b4.camera1.y>=0) &&( b4.camera1.y<=470)){
                    player.action = 0;}                                   
                    break;
                case SDLK_LEFT:
                    scrolling4(&b4,0);
                    if((b4.camera1.x>=0) &&( b4.camera1.x<=7500)&&(b4.camera1.y>=0) &&( b4.camera1.y<=470)){
                    player.action = 0;}
                    break;
             
                case SDLK_DOWN:
                    scrolling4(&b4,0);
                    break;

                case SDLK_UP:
                    scrolling4(&b4,0);
                   
                    break;
                    case SDLK_SPACE:
                    if((b4.camera1.x>=0) &&( b4.camera1.x<=7500)&&(b4.camera1.y>=0) &&( b4.camera1.y<=470)){
                     player.saut = 0;
                     player.action = 0;
                      saut(&player);
                      }
                     break;

                }
                break;              
           }
           /*if((b.camera1.x>=2100)&&(b.camera1.x<=3100)){
           afficherentity(e ,screen);
           update_entity(&e);
          if ((player.posperso.x + player.posperso. w< e.pos_entity. x) || (player.posperso.x> e.pos_entity. x + e.pos_entity. w) ||
(player.posperso.y +player.posperso.h< e.pos_entity. y) || (player.posperso.y> e.pos_entity. y + e.pos_entity. h ))
   	   {an=gestion(&e);} 
   	   if(an){afficherentity(e ,screen);}
   	   }*/
   	   /*else
   	   {
   	   a7=1;
   	   }
           }
           if(a7==1)
           {
           afficher1 (vie,screen);
           }*/
           if((b4.camera1.x>=1000)&&(b4.camera1.x<=2000)){
           afficherEnnemi (en ,screen);
           update_ennemie (&en,&player);
         
           if ((player.posperso.x + player.posperso. w< en.pos_ennemie. x) || (player.posperso.x> en.pos_ennemie. x + en.pos_ennemie. w) ||
(player.posperso.y + player.posperso.h< en.pos_ennemie. y) || (player.posperso.y> en.pos_ennemie. y + en.pos_ennemie. h ))
   	   {a1=0;
   	   }
   	   else
   	   {
   	   done1=1;
   	   done=1;
   	   a2=1;
   	   a1=1;
   	   
   	   
   	   }  	   
           }
           if(a1==1)
           {
           afficher1 (vie2,screen);
           }
           if(a2==1)
           {
           afficher1 (vie2,screen);
           }
           
           
           if(done==1)
           {
          
           
           
           /*afficher1 (back1,screen);*/
           /*l1=1;
           l2=1;
           l3=1;
           l4=1;*/
           /*if(l2==1)
           {*/
            /*if(l1==1)
            {*/
            /*if(l3==1)
            {*/
            if (SDL_GetTicks()/*- t_prev1*/>40) 
            {
            if (e.solved != 0)
            {
                diplayscore = 1;
            }
            SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
            afficherEnigme(e, screen);

              animerpuzzle(&e);
              
         }
            /*} */ 
            
            /*}  
            else{l3=0;}*/
              /*else{l1=0;}*/
       /*if(l4==1)
       {*/
        if (e.solved != 0 && SDL_GetTicks()>400/*- t_prev1>20*/ || diplayscore == 1) 
        {

            afficherEnigme(e, screen);
            if (e.solved == 1 && score != newscore)
            {
                score++;
            }
            else if (e.solved != 1 && score != newscore)
            {
                score--;
            }
            afficher_newscore(score, screen, e.newscore);
            
        }
       
        /*}
        else{l4=0;}*/
      SDL_PollEvent(&event);   
            switch(event.type)
            {
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                case SDLK_RETURN:
                    if ((e.selected + 1) == e.solution)
                    {
                        e.solved = 1;
                        newscore = score + 100;
                    }
                    else
                    {
                        e.solved = 2;
                        if (score > 100)
                            newscore = score - 100;
                    }
                    break;
               /* case SDLK_ESCAPE:
                    done = 1;
                    break;*/
                case SDLK_UP:
                   if (e.solved == 0  && SDL_GetTicks()>150/*- t_prev1> 150*/ ) 
                    {
                        e.selected = next_button(e.selected, 0, 2);
                        afficherEnigme(e, screen);
                       
                       
                    }
                     
                    break;
                    
                case SDLK_DOWN:
                    if ( e.solved == 0 && SDL_GetTicks() >150/*- t_prev1 >150*/) // temporisation ded 150ms
                    {
                        e.selected = next_button(e.selected, 2, 2);
                        afficherEnigme(e, screen);
                    
                    }
                     
                    break;
                    
                }
                break;
           
        
        }
        
        
        /*}
        else{l1=0;}*/
        /*}
         else{l2=0;}*/
       if(event.key.keysym.sym==SDLK_k){ done=0;
            }
        }
        else{done=0;}
           
         
           if((b4.camera1.x>=3500)&&(b4.camera1.x<=4500)){
           afficherEnnemi (en ,screen);
           update_ennemie (&en,&player);
          if ((player.posperso.x + player.posperso. w< en.pos_ennemie. x) || (player.posperso.x> en.pos_ennemie. x + en.pos_ennemie. w) ||
(player.posperso.y +player.posperso.h< en.pos_ennemie. y) || (player.posperso.y> en.pos_ennemie. y + en.pos_ennemie. h ))
   	   {a3=0;} 
   	   else
   	   {a3=1;
   	   a4=1;
   	   } 	   
           }
           if(a3==1)
           {
           afficher1 (vie1,screen);
           }
           if(a4==1)
           {
           afficher1 (vie1,screen);
           }
           if((b4.camera1.x>=5000)&&(b4.camera1.x<=6000)){
           afficherEnnemi (en ,screen);
           update_ennemie (&en,&player);
          if ((player.posperso.x + player.posperso. w< en.pos_ennemie. x) || (player.posperso.x> en.pos_ennemie. x + en.pos_ennemie. w) ||
(player.posperso.y +player.posperso.h< en.pos_ennemie. y) || (player.posperso.y> en.pos_ennemie. y + en.pos_ennemie. h ))
   	   {a5=0;} 
   	   else
   	   {a5=1;
   	   a6=1;
   	   
   	   } 	   
           }          
           if(a5==1)
           {
           afficher1 (lost,screen);
           }
           if(a6==1)
           {
           afficher1 (lost,screen);
           }
          
           if((b4.camera1.x>=6000)&&(b4.camera1.x<=7500)){
        	images4[current_image3].posflag.x=600;
           images4[current_image3].posflag.y=590;
           SDL_BlitSurface(images4[current_image3].surface, NULL, screen,&images4[current_image3].posflag);
        current_image3++;
        SDL_Delay(50);        
        if (current_image3 >= num_images3) {
            current_image3 = 0;}}
         if((b4.camera1.x>=6500)&&(b4.camera1.x<=7500)){
        if(player.posperso.x>images4[current_image3].posflag.x+20)
        {
        y=1;
        }
        else{y=0;}
        if(y==1)
        {
         afficher1 (gagne,screen);
        }	
         }  
        
        	if((b4.camera1.x>=2000)&&(b4.camera1.x<=3500)){
        	SDL_BlitSurface(images[current_image].surface, NULL, screen, NULL);
                current_image++; 
                SDL_Delay(50);     
                if (current_image >= num_images) {
                current_image = 0;}}
           
           if((b4.camera1.x>=2500)&&(b4.camera1.x<=4000)){
           images1[current_image1].posoiseau.x=400;
           images1[current_image1].posoiseau.y=40;
           SDL_BlitSurface(images1[current_image1].surface, NULL, screen,&images1[current_image1].posoiseau);
        current_image1++;
        SDL_Delay(50);        
        if (current_image1 >= num_images1) {
            current_image1 = 0;}}
        	 afficher_text(screen,time,time.tempsText);
             sprintf(time.tempsText, "Time : %d s",s.temps);
             	  
             displayText(t,screen);
             sprintf(t.scoreText, "Score : %d", s.score);
             SDL_Flip(screen);
             SDL_Delay(50);
             if(event.key.keysym.sym==SDLK_b){ w4=1;
            }
         }
         if(w3==0)
         {
         displayBack3(screen,&b3);
          afficher_perso(player, screen); 
          afficher1 (vie,screen);
          
            animerPerso(&player);
            afficher_text(screen,t1,"STAGE2");
             
           
             if((b3.camera1.x>=0)&&(b3.camera1.x<6500)){
             s.temps++;
             SDL_Delay(50);}
            switch (event.type)
            {
            case SDL_KEYDOWN:

                switch (event.key.keysym.sym)
                {

                case SDLK_RIGHT:
                    scrolling3(&b3,1); 
                    if(b3.camera1.x<6500){
        		s.score++; 
        		 player.action = 1;  
        		 animerPerso(&player);    		
        	}
        	                  
                    break;
                case SDLK_m:
                if((b3.camera1.x>=0) &&( b3.camera1.x<=7400)&&(b3.camera1.y>=0) &&( b3.camera1.y<=470)){
        	player.direction = 0;
                player.action = 1;  
            MovePerso(&player);
            animerPerso(&player);
            }
                  
                break;
                case SDLK_LEFT:
                    scrolling3(&b3,2); 
                    if((b3.camera1.x>=0) &&( b3.camera1.x<=7500)&&(b3.camera1.y>=0) &&( b3.camera1.y<=470)){
                    player.direction = 1;
                player.action = 1;
            MovePerso(&player);
            animerPerso(&player);
                
        	}
        	                 
                    break;

                /*case SDLK_DOWN:
                    /*scrolling(&b,4);                   
                    break;*/

                case SDLK_UP:
                    scrolling3(&b3,3); 
                    break;
                     case SDLK_SPACE:
                    if((b3.camera1.x>=0) &&( b3.camera1.x<=7500)&&(b3.camera1.y>=0) &&( b3.camera1.y<=470)){
                     player.saut = 1;
                     
          saut(&player);
            MovePerso(&player);
                     
        	}
        	                  
                    break;
                }
                break;
             case SDL_KEYUP:
                switch (event.key.keysym.sym)
                {

                case SDLK_RIGHT:
                    scrolling3(&b3,0); 
                case SDLK_m:
                if((b3.camera1.x>=0) &&( b3.camera1.x<=7400)&&(b3.camera1.y>=0) &&( b3.camera1.y<=470)){
                    player.action = 0;}                                   
                    break;
                case SDLK_LEFT:
                    scrolling3(&b3,0);
                    if((b3.camera1.x>=0) &&( b3.camera1.x<=7500)&&(b3.camera1.y>=0) &&( b3.camera1.y<=470)){
                    player.action = 0;}
                    break;
             
                case SDLK_DOWN:
                    scrolling3(&b3,0);
                    break;

                case SDLK_UP:
                    scrolling3(&b3,0);
                   
                    break;
                    case SDLK_SPACE:
                    if((b3.camera1.x>=0) &&( b3.camera1.x<=7500)&&(b3.camera1.y>=0) &&( b3.camera1.y<=470)){
                     player.saut = 0;
                     player.action = 0;
                      saut(&player);
                      }
                     break;

                }
                break;              
           }
           
           if((b3.camera1.x>=1000)&&(b3.camera1.x<=2000)){
           afficherEnnemi (en ,screen);
           update_ennemie (&en,&player);
         
           if ((player.posperso.x + player.posperso. w< en.pos_ennemie. x) || (player.posperso.x> en.pos_ennemie. x + en.pos_ennemie. w) ||
(player.posperso.y + player.posperso.h< en.pos_ennemie. y) || (player.posperso.y> en.pos_ennemie. y + en.pos_ennemie. h ))
   	   {a1=0;
   	   }
   	   else
   	   {
   	   done1=1;
   	   done=1;
   	   a2=1;
   	   a1=1;
   	   
   	   
   	   }  	   
           }
           if(a1==1)
           {
           afficher1 (vie2,screen);
           }
           if(a2==1)
           {
           afficher1 (vie2,screen);
           }
           
           
           if(done==1)
           {
          
           
           
           /*afficher1 (back1,screen);*/
           /*l1=1;
           l2=1;
           l3=1;
           l4=1;*/
           /*if(l2==1)
           {*/
            /*if(l1==1)
            {*/
            /*if(l3==1)
            {*/
            if (SDL_GetTicks()/*- t_prev1*/>40) 
            {
            if (e.solved != 0)
            {
                diplayscore = 1;
            }
            SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
            afficherEnigme(e, screen);

              animerpuzzle(&e);
              
         }
            /*} */ 
            
            /*}  
            else{l3=0;}*/
              /*else{l1=0;}*/
       /*if(l4==1)
       {*/
        if (e.solved != 0 && SDL_GetTicks()>400/*- t_prev1>20*/ || diplayscore == 1) 
        {

            afficherEnigme(e, screen);
            if (e.solved == 1 && score != newscore)
            {
                score++;
            }
            else if (e.solved != 1 && score != newscore)
            {
                score--;
            }
            afficher_newscore(score, screen, e.newscore);
            
        }
       
        /*}
        else{l4=0;}*/
      SDL_PollEvent(&event);   
            switch(event.type)
            {
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                case SDLK_RETURN:
                    if ((e.selected + 1) == e.solution)
                    {
                        e.solved = 1;
                        newscore = score + 100;
                    }
                    else
                    {
                        e.solved = 2;
                        if (score > 100)
                            newscore = score - 100;
                    }
                    break;
               /* case SDLK_ESCAPE:
                    done = 1;
                    break;*/
                case SDLK_UP:
                   if (e.solved == 0  && SDL_GetTicks()>150/*- t_prev1> 150*/ ) 
                    {
                        e.selected = next_button(e.selected, 0, 2);
                        afficherEnigme(e, screen);
                       
                       
                    }
                     
                    break;
                    
                case SDLK_DOWN:
                    if ( e.solved == 0 && SDL_GetTicks() >150/*- t_prev1 >150*/) // temporisation ded 150ms
                    {
                        e.selected = next_button(e.selected, 2, 2);
                        afficherEnigme(e, screen);
                    
                    }
                     
                    break;
                    
                }
                break;
           
        
        }
        
        
        /*}
        else{l1=0;}*/
        /*}
         else{l2=0;}*/
       if(event.key.keysym.sym==SDLK_k){ done=0;
            }
        }
        else{done=0;}
           
         
           if((b3.camera1.x>=3500)&&(b3.camera1.x<=4500)){
           afficherEnnemi (en ,screen);
           update_ennemie (&en,&player);
          if ((player.posperso.x + player.posperso. w< en.pos_ennemie. x) || (player.posperso.x> en.pos_ennemie. x + en.pos_ennemie. w) ||
(player.posperso.y +player.posperso.h< en.pos_ennemie. y) || (player.posperso.y> en.pos_ennemie. y + en.pos_ennemie. h ))
   	   {a3=0;} 
   	   else
   	   {a3=1;
   	   a4=1;
   	   } 	   
           }
           if(a3==1)
           {
           afficher1 (vie1,screen);
           }
           if(a4==1)
           {
           afficher1 (vie1,screen);
           }
           if((b3.camera1.x>=5000)&&(b3.camera1.x<=6000)){
           afficherEnnemi (en ,screen);
           update_ennemie (&en,&player);
          if ((player.posperso.x + player.posperso. w< en.pos_ennemie. x) || (player.posperso.x> en.pos_ennemie. x + en.pos_ennemie. w) ||
(player.posperso.y +player.posperso.h< en.pos_ennemie. y) || (player.posperso.y> en.pos_ennemie. y + en.pos_ennemie. h ))
   	   {a5=0;} 
   	   else
   	   {a5=1;
   	   a6=1;
   	   
   	   } 	   
           }          
           if(a5==1)
           {
           afficher1 (lost,screen);
           }
           if(a6==1)
           {
           afficher1 (lost,screen);
           }
          
           if((b3.camera1.x>=6000)&&(b3.camera1.x<=7500)){
        	images4[current_image3].posflag.x=600;
           images4[current_image3].posflag.y=590;
           SDL_BlitSurface(images4[current_image3].surface, NULL, screen,&images4[current_image3].posflag);
        current_image3++;
        SDL_Delay(50);        
        if (current_image3 >= num_images3) {
            current_image3 = 0;}}
         if((b3.camera1.x>=6500)&&(b3.camera1.x<=7500)){
        if(player.posperso.x>images4[current_image3].posflag.x+20)
        {
        y=1;
        }
        else{y=0;}
        if(y==1)
        {
         afficher1 (gagne,screen);
        }	
         }  
           afficher_text(screen,time,time.tempsText);
             sprintf(time.tempsText, "Time : %d s",s.temps);
             displayText(t,screen);
             sprintf(t.scoreText, "Score : %d", s.score);
             SDL_Flip(screen);
             SDL_Delay(50);
             if(event.key.keysym.sym==SDLK_b){ w3=1;
            }
            }
            
         if(test4==0)
         {
       
         //SDL_PollEvent(&event);        
         displayBack(screen,&b);
          afficher_perso(player, screen); 
          afficher1 (vie,screen);
          
            animerPerso(&player);
           afficher_text(screen,t1,"STAGE1");
           
             if((b.camera1.x>=0)&&(b.camera1.x<6500)){
             s.temps++;
             
             SDL_Delay(50);}
            switch (event.type)
            {
            case SDL_KEYDOWN:

                switch (event.key.keysym.sym)
                {

                case SDLK_RIGHT:
                    scrolling(&b,1); 
                    if(b.camera1.x<6500){
        		s.score++; 
        		 player.action = 1;  
        		 animerPerso(&player);    		
        	}
        	                  
                    break;
                case SDLK_m:
                if((b.camera1.x>=0) &&( b.camera1.x<=7400)&&(b.camera1.y>=0) &&( b.camera1.y<=470)){
        	player.direction = 0;
                player.action = 1;  
            MovePerso(&player);
            animerPerso(&player);
            }
                  
                break;
                case SDLK_LEFT:
                    scrolling(&b,2); 
                    if((b.camera1.x>=0) &&( b.camera1.x<=7500)&&(b.camera1.y>=0) &&( b.camera1.y<=470)){
                    player.direction = 1;
                player.action = 1;
            MovePerso(&player);
            animerPerso(&player);
                
        	}
        	                 
                    break;

                /*case SDLK_DOWN:
                    /*scrolling(&b,4);                   
                    break;*/

                case SDLK_UP:
                    scrolling(&b,3); 
                    break;
                     case SDLK_SPACE:
                    if((b.camera1.x>=0) &&( b.camera1.x<=7500)&&(b.camera1.y>=0) &&( b.camera1.y<=470)){
                     player.saut = 1;
                     
          saut(&player);
            MovePerso(&player);
                     
        	}
        	                  
                    break;
                }
                break;
             case SDL_KEYUP:
                switch (event.key.keysym.sym)
                {

                case SDLK_RIGHT:
                    scrolling(&b,0); 
                case SDLK_m:
                if((b.camera1.x>=0) &&( b.camera1.x<=7400)&&(b.camera1.y>=0) &&( b.camera1.y<=470)){
                    player.action = 0;}                                   
                    break;
                case SDLK_LEFT:
                    scrolling(&b,0);
                    if((b.camera1.x>=0) &&( b.camera1.x<=7500)&&(b.camera1.y>=0) &&( b.camera1.y<=470)){
                    player.action = 0;}
                    break;
             
                case SDLK_DOWN:
                    scrolling(&b,0);
                    break;

                case SDLK_UP:
                    scrolling(&b,0);
                   
                    break;
                    case SDLK_SPACE:
                    if((b.camera1.x>=0) &&( b.camera1.x<=7500)&&(b.camera1.y>=0) &&( b.camera1.y<=470)){
                     player.saut = 0;
                     player.action = 0;
                      saut(&player);
                      }
                     break;

                }
                break;              
           }
           /*if((b.camera1.x>=2100)&&(b.camera1.x<=3100)){
           afficherentity(e ,screen);
           update_entity(&e);
          if ((player.posperso.x + player.posperso. w< e.pos_entity. x) || (player.posperso.x> e.pos_entity. x + e.pos_entity. w) ||
(player.posperso.y +player.posperso.h< e.pos_entity. y) || (player.posperso.y> e.pos_entity. y + e.pos_entity. h ))
   	   {an=gestion(&e);} 
   	   if(an){afficherentity(e ,screen);}
   	   }*/
   	   /*else
   	   {
   	   a7=1;
   	   }
           }
           if(a7==1)
           {
           afficher1 (vie,screen);
           }*/
           if((b.camera1.x>=1000)&&(b.camera1.x<=2000)){
           afficherEnnemi (en ,screen);
           update_ennemie (&en,&player);
         
           if ((player.posperso.x + player.posperso. w< en.pos_ennemie. x) || (player.posperso.x> en.pos_ennemie. x + en.pos_ennemie. w) ||
(player.posperso.y + player.posperso.h< en.pos_ennemie. y) || (player.posperso.y> en.pos_ennemie. y + en.pos_ennemie. h ))
   	   {a1=0;
   	   }
   	   else
   	   {
   	   done1=1;
   	   done=1;
   	   a2=1;
   	   a1=1;
   	   
   	   
   	   }  	   
           }
           if(a1==1)
           {
           afficher1 (vie2,screen);
           }
           if(a2==1)
           {
           afficher1 (vie2,screen);
           }
           
           
           if(done==1)
           {
          
           
           
           /*afficher1 (back1,screen);*/
           /*l1=1;
           l2=1;
           l3=1;
           l4=1;*/
           /*if(l2==1)
           {*/
            /*if(l1==1)
            {*/
            /*if(l3==1)
            {*/
            if (SDL_GetTicks()/*- t_prev1*/>40) 
            {
            if (e.solved != 0)
            {
                diplayscore = 1;
            }
            SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
            afficherEnigme(e, screen);

              animerpuzzle(&e);
              
         }
            /*} */ 
            
            /*}  
            else{l3=0;}*/
              /*else{l1=0;}*/
       /*if(l4==1)
       {*/
        if (e.solved != 0 && SDL_GetTicks()>400/*- t_prev1>20*/ || diplayscore == 1) 
        {

            afficherEnigme(e, screen);
            if (e.solved == 1 && score != newscore)
            {
                score++;
            }
            else if (e.solved != 1 && score != newscore)
            {
                score--;
            }
            afficher_newscore(score, screen, e.newscore);
            
        }
       
        /*}
        else{l4=0;}*/
      SDL_PollEvent(&event);   
            switch(event.type)
            {
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                case SDLK_RETURN:
                    if ((e.selected + 1) == e.solution)
                    {
                        e.solved = 1;
                        newscore = score + 100;
                    }
                    else
                    {
                        e.solved = 2;
                        if (score > 100)
                            newscore = score - 100;
                    }
                    break;
               /* case SDLK_ESCAPE:
                    done = 1;
                    break;*/
                case SDLK_UP:
                   if (e.solved == 0  && SDL_GetTicks()>150/*- t_prev1> 150*/ ) 
                    {
                        e.selected = next_button(e.selected, 0, 2);
                        afficherEnigme(e, screen);
                       
                       
                    }
                     
                    break;
                    
                case SDLK_DOWN:
                    if ( e.solved == 0 && SDL_GetTicks() >150/*- t_prev1 >150*/) // temporisation ded 150ms
                    {
                        e.selected = next_button(e.selected, 2, 2);
                        afficherEnigme(e, screen);
                    
                    }
                     
                    break;
                    
                }
                break;
           
        
        }
        
        
        /*}
        else{l1=0;}*/
        /*}
         else{l2=0;}*/
       if(event.key.keysym.sym==SDLK_k){ done=0;
            }
        }
        else{done=0;}
           
         
           if((b.camera1.x>=3500)&&(b.camera1.x<=4500)){
           afficherEnnemi (en ,screen);
           update_ennemie (&en,&player);
          if ((player.posperso.x + player.posperso. w< en.pos_ennemie. x) || (player.posperso.x> en.pos_ennemie. x + en.pos_ennemie. w) ||
(player.posperso.y +player.posperso.h< en.pos_ennemie. y) || (player.posperso.y> en.pos_ennemie. y + en.pos_ennemie. h ))
   	   {a3=0;} 
   	   else
   	   {a3=1;
   	   a4=1;
   	   } 	   
           }
           if(a3==1)
           {
           afficher1 (vie1,screen);
           }
           if(a4==1)
           {
           afficher1 (vie1,screen);
           }
           if((b.camera1.x>=5000)&&(b.camera1.x<=6000)){
           afficherEnnemi (en ,screen);
           update_ennemie (&en,&player);
          if ((player.posperso.x + player.posperso. w< en.pos_ennemie. x) || (player.posperso.x> en.pos_ennemie. x + en.pos_ennemie. w) ||
(player.posperso.y +player.posperso.h< en.pos_ennemie. y) || (player.posperso.y> en.pos_ennemie. y + en.pos_ennemie. h ))
   	   {a5=0;} 
   	   else
   	   {a5=1;
   	   a6=1;
   	   
   	   } 	   
           }          
           if(a5==1)
           {
           afficher1 (lost,screen);
           }
           if(a6==1)
           {
           afficher1 (lost,screen);
           }
          
           if((b.camera1.x>=6000)&&(b.camera1.x<=7500)){
        	images4[current_image3].posflag.x=600;
           images4[current_image3].posflag.y=600;
           SDL_BlitSurface(images4[current_image3].surface, NULL, screen,&images4[current_image3].posflag);
        current_image3++;
        SDL_Delay(50);        
        if (current_image3 >= num_images3) {
            current_image3 = 0;}}
         if((b.camera1.x>=6500)&&(b.camera1.x<=7500)){
        if(player.posperso.x>images4[current_image3].posflag.x+20)
        {
        y=1;
        }
        else{y=0;}
        if(y==1)
        {
         afficher1 (gagne,screen);
        }	
         }  
        
 
        	 if((b.camera1.x>=2000)&&(b.camera1.x<=3500)){
        	
        	SDL_BlitSurface(images[current_image].surface, NULL, screen, NULL);
                current_image++; 
                SDL_Delay(50);     
                if (current_image >= num_images) {
                current_image = 0;}}
           
           if((b.camera1.x>=2500)&&(b.camera1.x<=4000)){
           images1[current_image1].posoiseau.x=400;
           images1[current_image1].posoiseau.y=40;
           SDL_BlitSurface(images1[current_image1].surface, NULL, screen,&images1[current_image1].posoiseau);
        current_image1++;
        SDL_Delay(50);        
        if (current_image1 >= num_images1) {
            current_image1 = 0;}}
        		  
             displayText(t,screen);
             afficher_text(screen,time,time.tempsText);
             sprintf(time.tempsText, "Time : %d s",s.temps);
             sprintf(t.scoreText, "Score : %d", s.score);
             SDL_Flip(screen);
             SDL_Delay(50);
             if(event.key.keysym.sym==SDLK_b){ test4=1;
            }
            char buffer[100];                   // un buffer
    int i;
    uint8_t val1='6';
    uint8_t val2='5';
    uint8_t val3='11';
    uint8_t val4='12';
    int fd = serialport_init("/dev/ttyUSB0",9600);
        
   
        //  lecture d'une ligne
        serialport_read_until(fd, buffer, '\r', 99, 10000);

        // suppression de la fin de ligne
        for (i=0 ; buffer[i]!='\r' && i<100 ; i++);
        buffer[i] = 0;
         if(strstr(buffer,"right"))
         {
        // écriture du résultat
        scrolling(&b,1); 
         if(b.camera1.x<6500){
        		s.score++;}                    
        player.action = 1;  
        animerPerso(&player);  
        serialport_writebyte(fd,val1);
         }
         if(strstr(buffer,"left"))
         {
        // écriture du résultat
       player.direction = 1;
       player.action = 1;
       MovePerso(&player);
       animerPerso(&player);
        serialport_writebyte(fd,val2);        
         }
         if(strstr(buffer,"up"))
         {
        // écriture du résultat
       player.direction = 0;
        player.action = 1;  
        MovePerso(&player);
        animerPerso(&player);
        serialport_writebyte(fd,val3);        
         }
         if(strstr(buffer,"down"))
         {
        // écriture du résultat
       player.saut = 1;                     
       saut(&player);
        MovePerso(&player);
        serialport_writebyte(fd,val4);       
         }
    

    // fermeture du port
   
     } 
     if(event.key.keysym.sym==SDLK_ESCAPE){ w5=1;}
     } 
   
    SDL_Flip(screen);
    }
    SDL_FreeSurface(screen);
    SDL_FreeSurface(image);
   freeText(t);
   free_text(t1);
   free_text(t2);
   free_text(t3);
   free_text(ecoo);
   free_text(gaeaa);
   free_images(images);
   load_images1(images1);
    load_images3(images4);
   

    liberer (back1);
    liberer (player1);
    liberer (player11);
    liberer (players22); 
    liberer (play);
    liberer (settings);
    liberer (quit); 
    liberer (play1);
    liberer (settings1);
    liberer (quit1); 
    liberer (stage1);
    liberer (stage22);
    liberer (stage3);   
    liberer (players2);
     liberer (vie2);
    liberer (vie);
    liberer (vie1);
     liberer (lost); 
      liberer (eco);
     liberer (gaea);  
      liberer (gagne);  
    serialport_flush(fd);   
    serialport_close(fd);
    return 0;
}

