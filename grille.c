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
      case 4 : affiche_ennemi(o.e);  jeu[i][j].e = deplacer_ennemi(o.e); break;
      case 5 : affiche_bonus(o.bn); break;
      }

    }
  }
}


void ajouter_bouboule(){
  int rx, ry, bouboule = 1;
  float fx, fy;
  for(rx = rand()%(LONGUEUR/30); bouboule; rx = (rx+1)%(LONGUEUR/30)){
    for(ry = rand()%(LARGEUR/30); bouboule;rx = (ry+1)%(LARGEUR/30)){
      if(jeu[rx][ry].type == 0){
	jeu[rx][ry].type = 5;
	fx = rand()%(LONGUEUR/30) + rx*30;
	fy = rand()%(LARGEUR/30) + ry*30;
	jeu[rx][ry].bn = creer_bonus(fx, fy, 0, rand()%2);
	bouboule = 0;
      }
    }
  }
}

void ajouter_ennemis(){
  int rx, ry, ennemi = 1;
  float fx, fy;
  for(rx = rand()%(LONGUEUR/30); ennemi; rx = (rx+1)%(LONGUEUR/30)){
    for(ry = rand()%(LARGEUR/30); ennemi;rx = (ry+1)%(LARGEUR/30)){
      if(jeu[rx][ry].type == 0 && (rx != 1 && ry != 1)){
	jeu[rx][ry].type = 4;
	fx = rand()%(LONGUEUR/30) + rx*30;
	fy = rand()%(LARGEUR/30) + ry*30;
	jeu[rx][ry].e = creer_ennemi(fx, fy, 0);
	ennemi = 0;
      }
    }
  }

}


ennemi deplacer_ennemi(ennemi e){
  int x, y, fx, fy, alea; objet o;
  if(e.p.x-1 <= 0)
    e.p.x+=0.5;
  if(e.p.x+1 >= LONGUEUR)
    e.p.x-=0.5;
  if(e.p.y -1 <= 0)
    e.p.y+=0.5;
  if(e.p.y + 1 >= LARGEUR)
    e.p.y-=0.5;
  x = e.p.x/30;
  y = e.p.y/30;
  o = jeu[x][y];
  switch(o.type){
  case 1:
    if(o.b.p.x + o.b.radius > e.p.x-1)
      e.p.x+=0.5;
    if(o.b.p.x - o.b.radius < e.p.x+1)
      e.p.x-=0.5;
    if(o.b.p.y + o.b.radius > e.p.y-1)
      e.p.y+=0.5;
    if(o.b.p.y - o.b.radius < e.p.y+1)
      e.p.y-=0.5;
    break;

  case 2:
    if(o.m.p.x < e.p.x-1)
      e.p.x+=0.5;
    if(o.m.p.x + o.m.longueur > e.p.x+1)
      e.p.x-=0.5;
    if(o.m.p.y < e.p.y-1)
      e.p.y+=0.5;
    if(o.m.p.y + o.m.largeur > e.p.y+1)
      e.p.y-=0.5;
    break;

  case 3:
    if(o.a.p.x - o.a.t.rayon < e.p.x-1)
      e.p.x+=0.5;
    if(o.a.p.x + o.a.t.rayon > e.p.x+1)
      e.p.x-=0.5;
    if(o.a.p.y - o.a.t.rayon < e.p.y-1)
      e.p.y+=0.5;
    if(o.a.p.y + o.a.t.rayon > e.p.y+1)
      e.p.y-=0.5;
    break;

  default : alea = rand()%2;
    switch(alea){
    case 0 : e.p.x+= 0.5; break;
    case 1 : e.p.x-= 0.5; break;
    }
    alea = rand()%2;
    switch(alea){
    case 0 : e.p.y+= 0.5; break;
    case 1 : e.p.y-= 0.5; break;
    }
    break;
  }
  fx = e.p.x/30; fy = e.p.y/30;
  if((fx != x || fy != y) && jeu[fx][fy].type == 0){
    jeu[x][y].type = 0;
    jeu[fx][fy].type = 4;
    jeu[fx][fy].e = e;
  }
  return e;
}
