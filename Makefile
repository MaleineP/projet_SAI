
prog : tp1.o tp3.o tp4.o karbre.o objets.o grille.o
	gcc -Wall projet.c objets.o grille.o tp4.o karbre.o tp3.o tp1.o -o snake -lglut -lGLU -lGL -lm

grille : objet.o
	gcc -Wall -c grille.c

objets :
	gcc -Wall -c objets.c

tp4 : tp3.o
	gcc -Wall -c tp4.c

karbre :
	gcc -Wall -c karbre.c

tp3 :
	gcc -Wall -c tp3.c

tp1 :
	gcc -Wall -c tp1.c


clean :                                                                         
	rm -rf snake *~ *.o
