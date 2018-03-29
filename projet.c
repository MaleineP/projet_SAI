#include "tp4.h"

float angle=0.0;
point eye;
matrice_plan R;
matrice_plan tmp;
point sHead;
point mvt;
void affichage();
void Animer();
void GererClavier();

int main(int argc, char* argv[]){
    eye.x = -6; eye.y = 0; eye.z = 5;
    sHead.x = -2.01; sHead.y = 0; sHead.z = 1.8;
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH);

    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("Fenetre du TP6");

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
    glBegin(GL_POLYGON);
    glColor3f(0.1, 0.5, 0.2);
    glVertex3f(sHead.x+0.01, sHead.y-2, sHead.z-1.7);
    glVertex3f(sHead.x+10.01, sHead.y-2, sHead.z-1.7);
    glVertex3f(sHead.x+14.01, sHead.y, sHead.z-0.8);
    glVertex3f(sHead.x+10.01, sHead.y+2, sHead.z-1.7);
    glVertex3f(sHead.x+0.01, sHead.y+2, sHead.z-1.7);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.1, 0.5, 0.2);
    glVertex3f(sHead.x+0.01, sHead.y-2, sHead.z-1.7);
    glVertex3f(sHead.x+10.01, sHead.y-2, sHead.z-1.7);
    glVertex3f(sHead.x+14.01, sHead.y, sHead.z-0.8);
    glVertex3f(sHead.x+10.01, sHead.y+2, sHead.z+0.2);
    glVertex3f(sHead.x+0.01, sHead.y+2, sHead.z+0.2);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.1, 0.5, 0.2);
    glVertex3f(sHead.x+0.01, sHead.y+2, sHead.z-1.7);
    glVertex3f(sHead.x+10.01, sHead.y+2, sHead.z-1.7);
    glVertex3f(sHead.x+14.01, sHead.y, sHead.z-0.8);
    glVertex3f(sHead.x+10.01, sHead.y+2, sHead.z+0.2);
    glVertex3f(sHead.x+0.01, sHead.y+2, sHead.z+0.2);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.1, 0.5, 0.2);
    glVertex3f(sHead.x+0.01, sHead.y-2, sHead.z+0.2);
    glVertex3f(sHead.x+10.01, sHead.y-2, sHead.z+0.2);
    glVertex3f(sHead.x+14.01, sHead.y, sHead.z-0.8);
    glVertex3f(sHead.x+10.01, sHead.y+2, sHead.z+0.2);
    glVertex3f(sHead.x+0.01, sHead.y+2, sHead.z+0.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.1, 0.5, 0.2);
    glVertex3f(sHead.x+0.01, sHead.y-2, sHead.z-1.7);
    glVertex3f(sHead.x+0.01, sHead.y+2, sHead.z-1.7);
    glVertex3f(sHead.x+0.01, sHead.y+2, sHead.z+0.2);
    glVertex3f(sHead.x+0.01, sHead.y-2, sHead.z+0.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0, 0, 1);
    glVertex3f(sHead.x, sHead.y+1.6, sHead.z+0.2);
    glVertex3f(sHead.x, sHead.y+1.6, sHead.z-0.4);
    glVertex3f(sHead.x, sHead.y+1, sHead.z-0.4);
    glVertex3f(sHead.x, sHead.y+1, sHead.z+0.2);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0, 0, 1);
    glVertex3f(sHead.x, sHead.y-1.0, sHead.z+0.2);
    glVertex3f(sHead.x, sHead.y-1.0, sHead.z-0.4);
    glVertex3f(sHead.x, sHead.y-1.6, sHead.z-0.4);
    glVertex3f(sHead.x, sHead.y-1.6, sHead.z+0.2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(sHead.x, sHead.y+0.9, sHead.z-0.8);
    glVertex3f(sHead.x, sHead.y+0.7, sHead.z-0.8);
    glVertex3f(sHead.x, sHead.y+0.8, sHead.z-1.6);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(sHead.x, sHead.y-0.9, sHead.z-0.8);
    glVertex3f(sHead.x, sHead.y-0.7, sHead.z-0.8);
    glVertex3f(sHead.x, sHead.y-0.8, sHead.z-1.6);
    glEnd();
    
    glutIdleFunc(Animer);
    glutKeyboardFunc(GererClavier);

    glFlush();
}

void Animer(){
    mvt.x=-0.1;
    sHead.x+=mvt.x;
    glutPostRedisplay();
}

void GererClavier(unsigned char touche, int x, int y){
    switch(touche){
    case 'z' : mvt.x=-0.1; break;
    }
}