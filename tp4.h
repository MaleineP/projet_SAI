#include "tp3.h"
#include "karbre.h"

#define N 2

int posCubeBoule(point psommet, point ssommet, point centreB, int rayon);
karbre boule2arbre(point c, int r);
karbre boule2arbre_bis(point c, int r, point d, point e);
karbre intersection(karbre A1, karbre A2);
