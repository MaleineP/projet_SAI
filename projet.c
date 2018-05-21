#include "grille.h"

grille grille_de_jeu;
int angle=0;
float speedmod=1.0;
point eye;
point sHead;
point mvt;
void affichage();
void Animer();
void GererClavier(unsigned char touche, int x, int y);
void rotationSerpent(float x);

int main(int argc, char* argv[]){
  grille_de_jeu = creer_grille();
  sHead.x = 50; sHead.y = 50; sHead.z = 1.8;
    
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH);

  glutInitWindowSize(800, 800);
  glutInitWindowPosition(100, 100);

  glutCreateWindow("Solid Snek");

  glEnable(GL_DEPTH_TEST);
  glutDisplayFunc(affichage);

  glutMainLoop();
  return 0;
}
void affichage(){
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  eye.z = sHead.z;
  gluPerspective(75, 1, 0.5, 1000);
  gluLookAt(sHead.x-1*(cos(angle)), sHead.y-1*(sin(angle)), sHead.z, eye.x, eye.y, eye.z, 0, 0, 1);

  afficher_grille(grille_de_jeu);
    
  glPushMatrix();
  glTranslatef(sHead.x, sHead.y, 0);
  glRotatef(angle, 0, 0, 1);
  glTranslatef(-sHead.x, -sHead.y, 0);
  serpent(sHead.x, sHead.y, sHead.z+1.8);
  glPopMatrix();
    
  glutIdleFunc(Animer);
  glutKeyboardFunc(GererClavier);

  glFlush();
}

void Animer(){
  mvt.x = 0; mvt.y =0;
  switch(angle){
  case 0 : mvt.x = -0.01*speedmod;
  eye.x = sHead.x - 20; eye.y = sHead.y;
  break;
  case 45 : case -315 : mvt.x = -0.01*(sqrt(2)/2)*speedmod; mvt.y = -0.01*(sqrt(2)/2)*speedmod;
  eye.x = (sHead.x - 20)*(sqrt(2)/2); eye.y = (sHead.y-20)*(sqrt(2)/2);
  break;
  case 90 : case -270 : mvt.y = -0.01*speedmod;
  eye.x = sHead.x ; eye.y = sHead.y-20;
  break;
  case 135 : case -225 : mvt.x = 0.01*(sqrt(2)/2)*speedmod; mvt.y = -0.01*(sqrt(2)/2)*speedmod;
  eye.x = (sHead.x + 20)*(sqrt(2)/2); eye.y = (sHead.y-20)*(sqrt(2)/2);
  break;
  case 180 : case -180 : mvt.x = 0.01*speedmod;
  eye.x = sHead.x + 20; eye.y = sHead.y;
  break;
  case 225 : case -135 : mvt.x = 0.01*(sqrt(2)/2)*speedmod; mvt.y = 0.01*(sqrt(2)/2)*speedmod;
  //eye.x = -(sHead.x + 20)*(sqrt(2)/2); eye.y = -(sHead.y+20)*(sqrt(2)/2);
  break;
  case 270 : case -90 : mvt.y = 0.01*speedmod;
  eye.x = sHead.x; eye.y = sHead.y+20;
  break;
  case 315 : case -45 : mvt.x = -0.01*(sqrt(2)/2)*speedmod; mvt.y = 0.01*(sqrt(2)/2)*speedmod;
  //eye.x = (sHead.x + 20)*(sqrt(2)/2); eye.y = -(sHead.y+20)*(sqrt(2)/2);
  break;
  default : break;
  }
  sHead.x += mvt.x;
  sHead.y += mvt.y;
  glutPostRedisplay();
}

void GererClavier(unsigned char touche, int x, int y){

  switch(touche){
  case 'q' : angle += 90;
    if(angle >=360) angle = 0;
    break;
  case 'd' : angle += -90;
    if(angle <= -360) angle = 0;
    break;
  }
}
