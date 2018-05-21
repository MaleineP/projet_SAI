#include "grille.h"

grille grille_de_jeu;
int angle=0;
point eye;
point sHead;
point mvt;
void affichage();
void Animer();
void GererClavier(unsigned char touche, int x, int y);
void rotationSerpent(float x);

int main(int argc, char* argv[]){
  grille_de_jeu = creer_grille();
  eye.x = 20; eye.y = 0; eye.z = 10;
  sHead.x = 0; sHead.y = 0; sHead.z = 1.8;
    
  srand(time(NULL));
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

  gluPerspective(75, 1, 0.5, 1000);
  gluLookAt(eye.x, eye.y, eye.z, sHead.x, sHead.y, sHead.z, 0, 0, 1);

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
  case 0 : mvt.x = -0.01; break;
  case 45 : case -315 : mvt.x = -0.01*(sqrt(2)/2); mvt.y = -0.01*(sqrt(2)/2); break;
  case 90 : case -270 : mvt.y = -0.01; break;
  case 135 : case -225 : mvt.x = 0.01*(sqrt(2)/2); mvt.y = -0.01*(sqrt(2)/2); break;
  case 180 : case -180 : mvt.x = 0.01; break;
  case 225 : case -135 : mvt.x = 0.01*(sqrt(2)/2); mvt.y = 0.01*(sqrt(2)/2); break;
  case 270 : case -90 : mvt.y = 0.01; break;
  case 315 : case -45 : mvt.x = -0.01*(sqrt(2)/2); mvt.y = 0.01*(sqrt(2)/2); break;
  default : mvt.x = -0.01*(mvt.x*cos(angle)+mvt.y*(-sin(angle)));
    mvt.y = -0.01*(mvt.x*sin(angle)+mvt.y*cos(angle));
    break;
  }
  sHead.x += mvt.x;
  sHead.y += mvt.y;
  glutPostRedisplay();
}

void GererClavier(unsigned char touche, int x, int y){

  switch(touche){
  case 'q' : angle += 45;
    if(angle >=360) angle = 0;
    break;
  case 'd' : angle += -45;
    if(angle <= -360) angle = 0;
    break;
  }
}
