
prog : objets.c
	gcc -Wall projet.c -o snake -lglut -lGLU -lGL

objets.o : objets.c
	gcc -Wall objets.c -c

clean :                                                                         
	rm -rf snake *~ *.o
