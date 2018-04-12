#include "objets.h"

int angle=0;
point eye;
point sHead;
point mvt;
void affichage();
void Animer();
void GererClavier(unsigned char touche, int x, int y);
void rotationSerpent(float x);

int main(int argc, char* argv[]){
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
    gluLookAt(eye.x, eye.y, eye.z, 0, 0, 0, 0, 0, 1);

    // Plan de départ
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(-200,-100,0);
    glVertex3f(-200,100,0);
    glVertex3f(200,100,0);
    glVertex3f(200,-100,0);
    glEnd();
    
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
    mvt.x = 0;
    mvt.y = 0;
    switch(angle){
    case 0 : mvt.x = -0.01; break;
    case 90: case -270 : mvt.y = -0.01; break;
    case 180: case -180 : mvt.x = 0.01; break;
    case 270: case -90 : mvt.y = 0.01; break;
    default : ;
    }
    sHead.x += mvt.x;
    sHead.y += mvt.y;
    glutPostRedisplay();
}

void GererClavier(unsigned char touche, int x, int y){

    switch(touche){
    case 'q' : angle += 10;
        if(angle >=360) angle = 0;
        break;
    case 'd' : angle += -10;
        if(angle <= -360) angle = 0;
        break;
    }
}