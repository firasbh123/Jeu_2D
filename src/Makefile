prog:main.o background.o perso.o ennemy.o enigme5.o serie.o
	gcc main.o background.o perso.o ennemy.o enigme5.o serie.o -o prog -g -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
main.o:main.c
	gcc -c main.c -o main.o -g 
background.o:background.c background.h
	gcc -c background.c -o background.o -g 
perso.o:perso.c perso.h
	gcc -c perso.c -o perso.o -g 
ennemy.o:ennemy.c ennemy.h
	gcc -c ennemy.c -o ennemy.o -g 
enigme5.o:enigme5.c enigme5.h
	gcc -c enigme5.c -o enigme5.o -g 
serie.o:serie.c serie.h
	gcc -c serie.c -o serie.o -g 
 

