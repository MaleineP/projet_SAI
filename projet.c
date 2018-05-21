#include "grille.h"

int interrupteur = 0;
int angle=0;
float speedmod=1.0;
point eye;
point sHead;
point mvt;
point vision;
void affichage();
void Animer();
void GererClavier(unsigned char touche, int x, int y);
void rotationSerpent(float x);

int main(int argc, char* argv[]){
  creer_grille();
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
  vision.x = sHead.x-2*cos(angle); vision.y = sHead.y-2*cos(angle); vision.z = sHead.z;
  gluLookAt(vision.x, vision.y, vision.z, eye.x, eye.y, eye.z, 0, 0, 1);

  afficher_grille(jeu);
    
  glPushMatrix();
  glTranslatef(sHead.x, sHead.y, 0);
  glRotatef(angle, 0, 0, 1);
  glTranslatef(-sHead.x, -sHead.y, 0);
  serpent(sHead.x, sHead.y, sHead.z+1.8);
  glPopMatrix();
    
  glutKeyboardFunc(GererClavier);
  glutIdleFunc(Animer);

  glFlush();
}

void Animer(){
  switch(angle){
  case 0 : mvt.x = -0.01*speedmod; mvt.y = 0;
  eye.x = sHead.x - 20; eye.y = sHead.y;
  break;
  case 45 : case -315 : mvt.x = -0.01*(sqrt(2)/2)*speedmod; mvt.y = -0.01*(sqrt(2)/2)*speedmod;
  eye.x = sHead.x - 20; eye.y = sHead.y - 20;
  break;
  case 90 : case -270 : mvt.x = 0; mvt.y = -0.01*speedmod;
  eye.x = sHead.x ; eye.y = sHead.y - 20;
  break;
  case 135 : case -225 : mvt.x = 0.01*(sqrt(2)/2)*speedmod; mvt.y = -0.01*(sqrt(2)/2)*speedmod;
  eye.x = sHead.x + 20; eye.y = sHead.y - 20;
  break;
  case 180 : case -180 : mvt.x = 0.01*speedmod; mvt.y = 0;
  eye.x = sHead.x + 20; eye.y = sHead.y;
  break;
  case 225 : case -135 : mvt.x = 0.01*(sqrt(2)/2)*speedmod; mvt.y = 0.01*(sqrt(2)/2)*speedmod;
  eye.x = sHead.x + 20; eye.y =  sHead.y + 20;
  break;
  case 270 : case -90 : mvt.x = 0; mvt.y = 0.01*speedmod;
  eye.x = sHead.x; eye.y = sHead.y + 20;
  break;
  case 315 : case -45 : mvt.x = -0.01*(sqrt(2)/2)*speedmod; mvt.y = 0.01*(sqrt(2)/2)*speedmod;
  eye.x = sHead.x - 20; eye.y =  sHead.y + 20;
  break;
  default : break;
  }
  if(interrupteur == 1) {
  	vision.x = sHead.x+20*cos(angle); vision.y = sHead.y+20*cos(angle); vision.z = 20; 
  	//gluLookAt(sHead.x+20*cos(angle), sHead.y+20*cos(angle), 20, sHead.x, sHead.y, sHead.z, 0, 0, 1);
  }
  if(interrupteur == 0){
  	vision.x = sHead.x-3	*cos(angle); vision.y = sHead.y-3*cos(angle); vision.z = sHead.z; 
  	gluLookAt(sHead.x-3*cos(angle), sHead.y-3*cos(angle), sHead.z, sHead.x, sHead.y, sHead.z, 0, 0, 1);
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
  		case 's' : interrupteur = 1;
    	break;
  		case 'z' :interrupteur = 0;
    	break;
 	}
 	glutPostRedisplay();
}