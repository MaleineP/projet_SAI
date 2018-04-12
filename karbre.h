#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define PMAX 10
#define k 8
#define BLANC 1
#define NOIR 2

typedef struct struct_arbre{
    int element;
    struct struct_arbre** fils;
}arbre_struct;

typedef arbre_struct* karbre;

karbre kArbreVide();
karbre kConsArbre(int e, karbre a1, ...);
karbre kFils(int ieme, karbre A);
int kRacine(karbre A);
int kEstVide(karbre A);
void kAfficher(karbre A);
