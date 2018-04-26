#include "objets.h"


objet creer_objet(int x, int y){
  float fx, fy;
  int alea;
  objet o = malloc(sizeof(objet));
  fx = rand()%30 + x*30;
  fy = rand()%30 + y*30;
  alea = rand()%10;
  switch(alea){
  case 1 : o.type = 1; o.b = buisson_crea(fx, fy, 0); break;
  case 2 : o.type = 2; o.m = maison_crea(fx, fy, 0); break;
  case 3 : o.type = 3; o.a = arbre_crea(fx, fy, 0); break;
  default : o.type = 0;
  }
  return o;
}


buisson buisson_crea(float x, float y, float z){
  GLdouble radius = rand()%10+4;
  buisson b;
  b.radius = radius;
  b.p.x = x;
  b.p.y = y;
  b.p.z = z;
  return b;
}

void affiche_buisson(buisson b){
  
  glPushMatrix();
  
  glTranslatef(b.p.x, b.p.y, b.p.z);
  glColor3f(0.01, 0.5, 0.08);
  
  GLUquadric *myQuad;
  GLint slices, stacks;
  
  myQuad=gluNewQuadric();
  slices = stacks = 10;
  gluSphere( myQuad , b.radius , slices , stacks  );
  
  glPopMatrix();
}

maison maison_crea(float x, float y, float z){
  maison m;
  int longueur, largeur, hauteur;
  longueur = rand()%20+5;
  largeur = rand()%20+5;
  hauteur = rand()%30+5;
  m.longueur = longueur;
  m.largeur = largeur;
  m.hauteur = hauteur;
  m.p.x = x;
  m.p.y = y;
  m.p.z = z;
  return m;
}

void affiche_maison(maison m){
  
  glBegin(GL_QUADS);

  glColor3f(0.4, 0.3, 0.2);
  
  glVertex3f(m.p.x, m.p.y, m.p.z);
  glVertex3f(m.p.x+m.longueur, m.p.y, m.p.z);
  glVertex3f(m.p.x+m.longueur, m.p.y, m.p.z+m.hauteur);
  glVertex3f(m.p.x, m.p.y, m.p.z+m.hauteur);

  glVertex3f(m.p.x+m.longueur, m.p.y, m.p.z);
  glVertex3f(m.p.x+m.longueur, m.p.y+m.largeur, m.p.z);
  glVertex3f(m.p.x+m.longueur, m.p.y+m.largeur, m.p.z+m.hauteur);
  glVertex3f(m.p.x+m.longueur, m.p.y, m.p.z+m.hauteur);

  glVertex3f(m.p.x+m.longueur, m.p.y+m.largeur, m.p.z);
  glVertex3f(m.p.x, m.p.y+m.largeur, m.p.z);
  glVertex3f(m.p.x, m.p.y+m.largeur, m.p.z+m.hauteur);
  glVertex3f(m.p.x+m.longueur, m.p.y+m.largeur, m.p.z+m.hauteur);

  glVertex3f(m.p.x, m.p.y+m.largeur, m.p.z);
  glVertex3f(m.p.x, m.p.y, m.p.z);
  glVertex3f(m.p.x, m.p.y, m.p.z+m.hauteur);
  glVertex3f(m.p.x, m.p.y+m.largeur, m.p.z+m.hauteur);

  glColor3f(0.5, 0, 0);
  glVertex3f(m.p.x+m.longueur, m.p.y, m.p.z+m.hauteur);
  glVertex3f(m.p.x+m.longueur, m.p.y+m.largeur, m.p.z+m.hauteur);
  glVertex3f(m.p.x+(m.p.x+m.longueur)/2, m.p.y+m.largeur, m.p.z+m.hauteur+5);
  glVertex3f(m.p.x+(m.p.x+m.longueur)/2, m.p.y, m.p.z+m.hauteur+5);

  glVertex3f(m.p.x, m.p.y, m.p.z+m.hauteur);
  glVertex3f(m.p.x, m.p.y+m.largeur, m.p.z+m.hauteur);
  glVertex3f(m.p.x+(m.p.x+m.longueur)/2, m.p.y+m.largeur, m.p.z+m.hauteur+5);
  glVertex3f(m.p.x+(m.p.x+m.longueur)/2, m.p.y, m.p.z+m.hauteur+5);

  glEnd();
 
  glBegin(GL_TRIANGLES);
  
  glVertex3f(m.p.x, m.p.y, m.p.z+m.hauteur);
  glVertex3f(m.p.x+m.longueur, m.p.y, m.p.z+m.hauteur);
  glVertex3f(m.p.x+(m.p.x+m.longueur)/2, m.p.y, m.p.z+m.hauteur+5);

  glVertex3f(m.p.x, m.p.y+m.largeur, m.p.z+m.hauteur);
  glVertex3f(m.p.x+m.longueur, m.p.y+m.largeur, m.p.z+m.hauteur);
  glVertex3f(m.p.x+(m.p.x+m.longueur)/2, m.p.y+m.largeur, m.p.z+m.hauteur+5);

  glEnd();

  
}

arbre arbre_crea(float x, float y, float z){
  int hauteur, rayon, alea;
  GLdouble radius;
  arbre a;
  hauteur = rand()%20+5;
  rayon = hauteur/5;
  alea = rand()%2;
  a.p.x = x;
  a.p.y = y;
  a.p.z = z;
  a.t.hauteur = hauteur;
  a.t.rayon = rayon;
  a.type = alea;
  if(alea == 1){
    rayon = rand()%5+2;
    hauteur = rand()%10+4;
    a.feuille.rayon = rayon;
    a.feuille.hauteur = hauteur;
  }
  else{
    radius = rand()%10+4;
    a.feuille.radius = radius;
  }
  return a;
}

void affiche_arbre(arbre a){
  
  glPushMatrix();

  
  glTranslatef(a.p.x, a.p.y, a.p.z);
  
  GLUquadric* params;
  
  params = gluNewQuadric();
  
  glColor3f(0.47, 0.27, 0.12);
  
  gluCylinder(params, a.t.rayon, 0, a.t.hauteur, 20, 1);

  switch(a.type){
    
  case 0:
    glPushMatrix();
    glTranslatef(a.p.x, a.p.y, a.p.z + a.t.hauteur);
    glColor3f(0.01, 0.5, 0.08);
  
    GLUquadric *myQuad;
    GLint slices, stacks;
  
    myQuad=gluNewQuadric();
    slices = stacks = 10;
    gluSphere( myQuad , a.feuille.radius , slices , stacks  );
  
    glPopMatrix();
    break;
    
  default:
    params = gluNewQuadric();
  
    glPushMatrix();
    glTranslatef(a.p.x, a.p.y, a.p.z + a.t.hauteur);
  
    glColor3f(0.01, 0.25, 0.08);
    gluCylinder(params, a.feuille.rayon, 0, a.feuille.hauteur, 20, 1);

    glPopMatrix();
    break;
  }
  
  glPopMatrix();
  
}

void serpent(int x, int y, int z){
    glBegin(GL_POLYGON);
    glColor3f(0.1, 0.5, 0.2);
    glVertex3f(x+ 0.01, y -2, z -1.7);
    glVertex3f(x+ 10.01, y -2, z -1.7);
    glVertex3f(x+ 14.01, y , z -0.8);
    glVertex3f(x+ 10.01, y +2, z -1.7);
    glVertex3f(x+ 0.01, y +2, z -1.7);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.1, 0.5, 0.2);
    glVertex3f(x+ 0.01, y -2, z -1.7);
    glVertex3f(x+ 10.01, y -2, z -1.7);
    glVertex3f(x+ 14.01, y , z -0.8);
    glVertex3f(x+ 10.01, y +2, z +0.2);
    glVertex3f(x+ 0.01, y +2, z +0.2);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.1, 0.5, 0.2);
    glVertex3f(x+ 0.01, y +2, z -1.7);
    glVertex3f(x+ 10.01, y +2, z -1.7);
    glVertex3f(x+ 14.01, y , z -0.8);
    glVertex3f(x+ 10.01, y +2, z +0.2);
    glVertex3f(x+ 0.01, y +2, z +0.2);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.1, 0.5, 0.2);
    glVertex3f(x+ 0.01, y -2, z +0.2);
    glVertex3f(x+ 10.01, y -2, z +0.2);
    glVertex3f(x+ 14.01, y , z -0.8);
    glVertex3f(x+ 10.01, y +2, z +0.2);
    glVertex3f(x+ 0.01, y +2, z +0.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.1, 0.5, 0.2);
    glVertex3f(x+ 0.01, y -2, z -1.7);
    glVertex3f(x+ 0.01, y +2, z -1.7);
    glVertex3f(x+ 0.01, y +2, z +0.2);
    glVertex3f(x+ 0.01, y -2, z +0.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0, 0, 1);
    glVertex3f(x , y +1.6, z +0.2);
    glVertex3f(x , y +1.6, z -0.4);
    glVertex3f(x , y +1, z -0.4);
    glVertex3f(x , y +1, z +0.2);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0, 0, 1);
    glVertex3f(x , y -1.0, z +0.2);
    glVertex3f(x , y -1.0, z -0.4);
    glVertex3f(x , y -1.6, z -0.4);
    glVertex3f(x , y -1.6, z +0.2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(x , y +0.9, z -0.8);
    glVertex3f(x , y +0.7, z -0.8);
    glVertex3f(x , y +0.8, z -1.6);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(x , y -0.9, z -0.8);
    glVertex3f(x , y -0.7, z -0.8);
    glVertex3f(x , y -0.8, z -1.6);
    glEnd();
}
