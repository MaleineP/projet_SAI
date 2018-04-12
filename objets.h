#include "tp4.h"
#include <time.h>

typedef struct buisson{
  GLdouble radius;
  point p;
}buisson;

typedef struct maison{
  int longueur;
  int largeur;
  int hauteur;
  point p;
}maison;

typedef struct tronc{
  int hauteur;
  int rayon;
}tronc;

typedef struct tete{
  GLdouble radius;
  int rayon;
  int hauteur;
}tete;

typedef struct arbre{
  tronc t;
  int type;// 0:normal; 1:pin
  tete feuille;
  point p;
}arbre;

typedef struct objet{
  buisson b;
  maison m;
  arbre a;
  int type; // 1 = buisson; 2 = maison; 3 = arbre; 0 = vide
}objet;

buisson buisson_crea(float x, float y, float z);
void affiche_buisson(buisson b);

maison maison_crea(float x, float y, float z);
void affiche_maison(maison m);

arbre arbre_crea(float x, float y, float z);
void affiche_arbre(arbre a);

void pin(float x, float y, float z);

void serpent(int x, int y, int z);

