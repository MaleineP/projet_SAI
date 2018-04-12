#include "tp4.h"

int posCubeBoule(point psommet, point ssommet, point centreB, int rayon){
    // cas où le cube est inclut ou inscrit dans la boule
    if( (psommet.x >= (centreB.x-rayon)) && (ssommet.x <= (centreB.x+rayon)) )
        if( (psommet.y >= (centreB.y-rayon)) && (ssommet.y <= (centreB.y+rayon)) )
            if( (psommet.z >= (centreB.z-rayon)) && (ssommet.z <= (centreB.z+rayon)) )
                return 0;
    
    // on vérifie que le 2nd point soit inférieur au centre - rayon
    if( (ssommet.x < (centreB.x-rayon)) )
        return 1;
    
    if( (ssommet.y < (centreB.y-rayon)) )
        return 1;

    if( (ssommet.z < (centreB.z-rayon)) )
        return 1;
    // idem pour le 1er point avec centre + rayon
    if( (psommet.x > (centreB.x+rayon)) )
        return 1;
    
    if( (psommet.y > (centreB.y+rayon)) )
        return 1;

    if( (psommet.z > (centreB.z+rayon)) )
        return 1;

    // tous les autres cas
    return 2;
}

karbre boule2arbre(point c, int r){
    point psommet, ssommet;
    psommet.x = 0; psommet.y = 0; psommet.z = 0;
    ssommet.x = pow(2, N); ssommet.y = pow(2, N); ssommet.z = pow(2, N);
    return boule2arbre_bis(c, r, psommet, ssommet);
}

karbre boule2arbre_bis(point c, int r, point psommet, point ssommet){
    point p1, s1, p2, s2, p3, s3, p4, s4, p5, s5, p6, s6, p7, s7, p8, s8;
    karbre A = kArbreVide();
    int position = posCubeBoule(psommet, ssommet, c, r);
    switch(position){
    case 0 : A->element = NOIR; break;
    case 1 : A->element = BLANC; break;
    default :
        p1.x = psommet.x + (ssommet.x/2); p1.y = psommet.y + (ssommet.y)/2; p1.z = psommet.z;
        s1.x = ssommet.x; s1.y =  ssommet.y; s1.z = psommet.z + (ssommet.z/2);
        p2.x = psommet.x + (ssommet.x/2); p2.y = psommet.y; p2.z = psommet.z;
        s2.x = ssommet.x; s2.y = psommet.y + (ssommet.y/2); s2.z = psommet.z + (ssommet.z/2);
        p3.x = psommet.x; p3.y = psommet.y; p3.z = psommet.z;
        s3.x = psommet.x + (ssommet.x/2); s3.y = psommet.y + (ssommet.y/2); s3.z = psommet.z + (ssommet.z/2);
        p4.x = psommet.x; p4.y = psommet.y + (ssommet.y/2); p4.z = psommet.z;
        s4.x = psommet.x + (ssommet.x/2); s4.y = ssommet.y; s4.z = psommet.z + (ssommet.z/2);
        p5.x = psommet.x + (ssommet.x/2); p5.y = psommet.y + (ssommet.y/2); p5.z = psommet.z + (ssommet.z/2);
        s5.x = ssommet.x; s5.y = ssommet.y; s5.z = ssommet.z;
        p6.x = psommet.x + (ssommet.x/2); p6.y = psommet.y; p6.z = psommet.z + (ssommet.z/2);
        s6.x = ssommet.x; s6.y = psommet.y + (ssommet.y/2); s6.z = ssommet.z;
        p7.x = psommet.x; p7.y = psommet.y; p7.z = psommet.z + (ssommet.z/2);
        s7.x = psommet.x + (ssommet.y/2); s7.y = psommet.y + (ssommet.y/2); s7.z = ssommet.z;
        p8.x = psommet.x; p8.y = psommet.y + (ssommet.y/2); p8.z = psommet.z + (ssommet.z/2);
        s8.x = psommet.x + (ssommet.x/2); s8.y = ssommet.y; s8.z = psommet.z + (ssommet.z/2);
        A = kConsArbre( 0 , boule2arbre_bis(c, r, p1, s1), boule2arbre_bis(c, r, p2, s2), boule2arbre_bis(c, r, p3, s3), boule2arbre_bis(c, r, p4, s4), boule2arbre_bis(c, r, p5, s5), boule2arbre_bis(c, r, p6, s6), boule2arbre_bis(c, r, p7, s7), boule2arbre_bis(c, r, p8, s8));
        break;
    }
    return A;
}

karbre intersection(karbre A1, karbre A2){
	
}
