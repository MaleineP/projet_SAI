#include "objets.h"

#define LONGUEUR 400
#define LARGEUR 200

typedef objet** grille;

grille jeu;

void creer_grille();
void afficher_grille();
void ajouter_ennemis();
void ajouter_bouboule();
