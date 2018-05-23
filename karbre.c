#include "karbre.h"

karbre kArbreVide(){
    karbre A = (karbre)malloc(sizeof(arbre_struct));
    A->element = 0;
    A->fils = (karbre*)malloc(k*sizeof(karbre));
    return A;
}

karbre kConsArbre(int e, karbre a1, ...){
    int i;
    va_list params;
    karbre A = kArbreVide();
    A->element = e;    
    va_start(params, a1);
    for(i=0; i<k && !kEstVide(a1); i++, a1 = va_arg(params, karbre)){
        A->fils[i] = a1;
    }
    va_end(params);
    return A;
}

karbre kFils(int ieme, karbre A){
    return A->fils[ieme];
}

int kRacine(karbre A){
    return A->element;
}

int kEstVide(karbre A){
    return A == NULL;
}

void kAfficher(karbre A){
    int i;
    if(kEstVide(A)){
        printf(" ");
    }
    else{
        printf("%d ", A->element);
        for(i=0; i<k; i++){
            kAfficher(kFils(i, A));
        }
    }
}