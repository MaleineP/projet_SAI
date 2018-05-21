#include "grille.h"


grille creer_grille(){
  int i,j;
  grille jeu = malloc(sizeof(objet*) * LONGUEUR/30);
  for(i=0; i < LONGUEUR/30; i++){
    jeu[i] = malloc(sizeof(objet) * LARGEUR/30);
  }

  for(i=0; i < LONGUEUR/30; i++){
    for(j=0; j < LARGEUR/30; j++){

      jeu[i][j] = creer_objet(i, j);
      
    }
  }
  

  return jeu;
}


void afficher_grille(grille jeu){
  int i, j;
  objet o;
  //bords de la map
  glColor3f(0.7, 0.7, 0.7);

  glBegin(GL_QUADS);

  glVertex3f(0,0,0);
  glVertex3f(LONGUEUR,0,0);
  glVertex3f(LONGUEUR,0,500);
  glVertex3f(0,0,500);

  glVertex3f(LONGUEUR,0,0);
  glVertex3f(LONGUEUR,LARGEUR,0);
  glVertex3f(LONGUEUR,LARGEUR,500);
  glVertex3f(LONGUEUR,0,500);

  glVertex3f(0,LARGEUR,0);
  glVertex3f(0,LARGEUR,500);
  glVertex3f(0,0,500);
  glVertex3f(0,0,0);
  
  glVertex3f(0,LARGEUR,0);
  glVertex3f(0,LARGEUR,500);
  glVertex3f(LONGUEUR,LARGEUR,500);
  glVertex3f(LONGUEUR,LARGEUR,0);

  glColor3f(0.3, 0.5, 0.2);

  glVertex3f(0,0,0);
  glVertex3f(0,LARGEUR,0);
  glVertex3f(LONGUEUR,LARGEUR,0);
  glVertex3f(LONGUEUR,0,0);

  glEnd();

  //affichage des objets
  for(i = 0; i < LONGUEUR/30; i++){
    for(j = 0; j < LARGEUR/30; j++){
      
      o = jeu[i][j];
      switch(o.type){
      case 1 : affiche_buisson(o.b); break;
      case 2 : affiche_maison(o.m); break;
      case 3 : affiche_arbre(o.a); break;
      }

    }
  }
}
