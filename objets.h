#include "tp4.h"
#include <time.h>

#define LONGUEUR 600
#define LARGEUR 300

typedef struct ennemi{
  point p;
}ennemi;

typedef struct bonus{
  point p;
  int type; // 0 = vitesse, 1 = vie
}bonus;

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
  ennemi e;
  bonus bn;
  int type; // 1 = buisson; 2 = maison; 3 = arbre; 0 = vide; 4 = ennemi; 5 = bonus
}objet;


objet creer_objet(int x, int y);

bonus creer_bonus(float x, float y, float z, int type);
void affiche_bonus(bonus bn);

ennemi creer_ennemi(float x, float y, float z);
void affiche_ennemi(ennemi e);

buisson buisson_crea(float x, float y, float z);
void affiche_buisson(buisson b);

maison maison_crea(float x, float y, float z);
void affiche_maison(maison m);

arbre arbre_crea(float x, float y, float z);
void affiche_arbre(arbre a);

void pin(float x, float y, float z);

void serpent(int x, int y, int z, float c1, float c2, float c3);

