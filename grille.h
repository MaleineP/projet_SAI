#include "objets.h"


typedef objet** grille;

grille jeu;

void creer_grille();
void afficher_grille();
void ajouter_ennemis();
void ajouter_bouboule();
ennemi deplacer_ennemi(ennemi e, int x, int y);
