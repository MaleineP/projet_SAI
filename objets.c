#include "objets.h"

void buisson(int x, int y, int z){
  
  glPushMatrix();
  
  glTranslatef(x,y,z);
  glColor3f(0.01, 0.5, 0.08);
  
  GLUquadric *myQuad;
  GLdouble radius = rand()%10+4;
  GLint slices, stacks;
  
  myQuad=gluNewQuadric();
  slices = stacks = 10;
  gluSphere( myQuad , radius , slices , stacks  );
  
  glPopMatrix();
}

void immeuble(int x, int y, int z){
  int hauteur, largeur;
  hauteur = rand()%50+10;
  largeur = rand()%20+5;
  
  glColor3f(0.5, 0.3, 0.2);
  
  glBegin(GL_QUADS);

  glVertex3f(x, y, z);
  glVertex3f(x+largeur, y, z);
  glVertex3f(x+largeur, y, z+hauteur);
  glVertex3f(x, y, z+hauteur);

  glVertex3f(x+largeur, y, z);
  glVertex3f(x+largeur, y+largeur, z);
  glVertex3f(x+largeur, y+largeur, z+hauteur);
  glVertex3f(x+largeur, y, z+hauteur);

  glVertex3f(x+largeur, y+largeur, z);
  glVertex3f(x, y+largeur, z);
  glVertex3f(x, y+largeur, z+hauteur);
  glVertex3f(x+largeur, y+largeur, z+hauteur);

  glVertex3f(x, y, z);
  glVertex3f(x, y+largeur, z);
  glVertex3f(x, y+largeur, z+hauteur);
  glVertex3f(x, y, z+hauteur);

  glVertex3f(x,y,z+hauteur);
  glVertex3f(x+largeur, y, z+hauteur);
  glVertex3f(x+largeur, y+largeur, z+hauteur);
  glVertex3f(x, y+largeur, z+hauteur);
 
  glEnd();

  
}

void arbre(int x, int y, int z){
  int hauteur, rayon, alea;
  hauteur = rand()%20+5;
  rayon = hauteur/5;
  alea = rand()%2;
  
  glPushMatrix();

  
  glTranslatef(x,y,z);
  
  GLUquadric* params;
  
  params = gluNewQuadric();
  
  glColor3f(0.47, 0.27, 0.12);
  
  gluCylinder(params, rayon, 0, hauteur, 20, 1);

  switch(alea){
  case 0: buisson(x, y, z+hauteur); break;
  case 1: pin(x,y,z+hauteur); break;
  default: pin(x,y,z+hauteur); break;
  }
  
  glPopMatrix();
  
}

void pin(int x, int y, int z){
  int rayon = rand()%5+2;
  int hauteur = rand()%10+4;
  GLUquadric* params;
  params = gluNewQuadric();
  
  glPushMatrix();
  glTranslatef(x,y,z);
  
  glColor3f(0.01, 0.25, 0.08);
  gluCylinder(params, rayon, 0, hauteur, 20, 1);

  glPopMatrix();
}
