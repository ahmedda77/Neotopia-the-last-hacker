prog:fonction.o main.o 
	gcc fonction.o main.o -o prog -g -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer
main.o:main.c 
	gcc -c main.c -g
fonction.o:fonction.c 
	gcc -c fonction.c -g
