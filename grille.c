#include "grille.h"

void creer_grille(){
  int i,j, rx, ry, ennemi = 1, bouboule = 1;
  srand(time(NULL));
  jeu = malloc(sizeof(objet*) * LONGUEUR/30);
  for(i=0; i < LONGUEUR/30; i++){
    jeu[i] = malloc(sizeof(objet) * LARGEUR/30);
  }

  for(i=0; i < LONGUEUR/30; i++){
    for(j=0; j < LARGEUR/30; j++){
      
      jeu[i][j] = creer_objet(i, j);
      
    }
  }
  ajouter_ennemis();
  ajouter_bouboule();

}


void afficher_grille(){
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
      case 4 : affiche_ennemi(o.e); deplacer_ennemi(o.e); break;
      case 5 : affiche_bonus(o.bn); break;
      }

    }
  }
}


void ajouter_bouboule(){
  int rx, ry, bouboule = 1, compteur = 0;
  float fx, fy;
  rx = rand()%LONGUEUR/30;
  ry = rand()%LARGEUR/30;
  while(bouboule){
    compteur++;
    if(compteur == 30)
      bouboule = 0;
    if(jeu[rx][ry].type == 0){
      jeu[rx][ry].type = 5;
      fx = rand()%30 + rx*30;
      fy = rand()%30 + ry*30;
      jeu[rx][ry].bn = creer_bonus(fx, fy, 0, compteur%2);
      bouboule = 0;
    }
    rx++; ry++;
    rx%=30;
    ry%=30;
  }

  
}

void ajouter_ennemis(){
  int rx, ry, ennemi = 1, compteur = 0;
  float fx, fy;
  rx = rand()%LONGUEUR/30;
  ry = rand()%LARGEUR/30;
  while(ennemi){
    compteur++;
    if(compteur == 30)
      ennemi = 0;
    if(jeu[rx][ry].type == 0){
      jeu[rx][ry].type = 4;
      fx = rand()%30 + rx*30;
      fy = rand()%30 + ry*30;
      jeu[rx][ry].e = creer_ennemi(fx, fy, 0);
      ennemi = 0;
    }
    rx++; ry++;
    rx = rx%(LONGUEUR/30);
    ry = ry%(LARGEUR/30);
  }
}


void deplacer_ennemi(ennemi e){
  int x, y, alea; objet o;
  if(e.p.x-1 <= 0)
    e.p.x+=0.1;
  if(e.p.x+1 >= LONGUEUR)
    e.p.x-=0.1;
  if(e.p.y -1 <= 0)
    e.p.y+=0.1;
  if(e.p.y + 1 >= LARGEUR)
    e.p.y-=0.1;
  x = e.p.x/30;
  y = e.p.y/30;
  o = jeu[x][y];
  switch(o.type){
  case 1:
    if(o.b.p.x + o.b.radius >= e.p.x-1)
      e.p.x+=0.1;
    if(o.b.p.x - o.b.radius <= e.p.x+1)
      e.p.x-=0.1;
    if(o.b.p.y + o.b.radius >= e.p.y-1)
      e.p.y+=0.1;
    if(o.b.p.y - o.b.radius <= e.p.y+1)
      e.p.y-=0.1;
    break;

  case 2:
    if(o.m.p.x <= e.p.x-1)
      e.p.x+=0.1;
    if(o.m.p.x + o.m.longueur >= e.p.x+1)
      e.p.x-=0.1;
    if(o.m.p.y <= e.p.y-1)
      e.p.y+=0.1;
    if(o.m.p.y + o.m.largeur >= e.p.y+1)
      e.p.y-=0.1;
    break;

  case 3:
    if(o.a.p.x - o.a.t.rayon <= e.p.x-1)
      e.p.x+=0.1;
    if(o.a.p.x + o.a.t.rayon >= e.p.x+1)
      e.p.x-=0.1;
    if(o.a.p.y - o.a.t.rayon <= e.p.y-1)
      e.p.y+=0.1;
    if(o.a.p.y + o.a.t.rayon >= e.p.y+1)
      e.p.y-=0.1;
    break;

  default : alea = rand()%2;
    switch(alea){
    case 0 : e.p.x+= 0.1; break;
    case 1 : e.p.x-= 0.1; break;
    }
    alea = rand()%2;
    switch(alea){
    case 0 : e.p.y+= 0.1; break;
    case 1 : e.p.y-= 0.1; break;
    }
    break;
  }
  if(e.p.x/30 != x || e.p.y/30 != y){
    jeu[x][y].type = 0;
    x =e.p.x/30; y = e.p.y/30;
    jeu[x][y].type = 4;
    jeu[x][y].e = e;
  }
}
