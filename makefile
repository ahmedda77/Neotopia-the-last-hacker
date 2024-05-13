prog: menu.o ennemi.o minimap.o perso.o background.o enigme.o
	gcc menu.o ennemi.o minimap.o perso.o background.o enigme.o -o prog -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -g

menu.o: menu.c
	gcc -c menu.c -g

ennemi.o: ennemi.c
	gcc -c ennemi.c -g

minimap.o: minimap.c
	gcc -c minimap.c -g

perso.o: perso.c
	gcc -c perso.c -g

background.o: background.c
	gcc -c background.c -g

enigme.o: enigme.c
	gcc -c enigme.c -g

