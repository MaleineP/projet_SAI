#include "tp4.h"
#include "objets.h"

float angle=0.0;
point eye;
point sHead;
point mvt;
void affichage();
void Animer();
void GererClavier(unsigned char touche, int x, int y);
void rotationSerpent(float x);

int main(int argc, char* argv[]){
    eye.x = -20; eye.y = 0; eye.z = 10;
    sHead.x = 0; sHead.y = 0; sHead.z = 1.8;
    
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
    gluLookAt(eye.x, eye.y, eye.z, 0, 0, 0, 0, 0, 1);

    // Plan de départ
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(-200,-100,0);
    glVertex3f(-200,100,0);
    glVertex3f(200,100,0);
    glVertex3f(200,-100,0);
    glEnd();

    // le serpent
    serpent(sHead.x, sHead.y, sHead.z);
    
    glutIdleFunc(Animer);
    glutKeyboardFunc(GererClavier);

    glFlush();
}

void Animer(){
    mvt.x = 0.01;
    sHead.x += mvt.x;
    glutPostRedisplay();
}

void GererClavier(unsigned char touche, int x, int y){

    switch(touche){
    case 'z' : sHead.x += mvt.x; break; // ne marche pas
    case 'q' : angle = 0.1;
        sHead.x = (cos(angle)*sHead.x)+(-sin(angle)*sHead.y);
        sHead.y = (sin(angle)*sHead.x)+(cos(angle)*sHead.y);
        break;
    case 's' : sHead.x += mvt.x; break; // ne marche pas
    case 'd' : angle = -0.1;
        sHead.x = (cos(angle)*sHead.x)+(-sin(angle)*sHead.y);
        sHead.y = (sin(angle)*sHead.x)+(cos(angle)*sHead.y);
        break;
    }
}

void rotationSerpent(float x){
}