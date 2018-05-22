#include "objets.h"

#define LONGUEUR 600
#define LARGEUR 300

typedef objet** grille;

grille jeu;

void creer_grille();
void afficher_grille();
void ajouter_ennemis();
void ajouter_bouboule();
ennemi deplacer_ennemi(ennemi e);
