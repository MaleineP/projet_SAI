#include "grille.h"

int interrupteur = 0;
int angle=0;
int vie=3000;
time_t score;
int nb_e_tue = 0;
float speedmod;
point eye;
point sHead;
point mvt;
point vision;
void affichage();
void Animer();
void GererClavier(unsigned char touche, int x, int y);
int collision_snake();
void attaque_snake();

int main(int argc, char* argv[]){
    score = time(NULL);
    speedmod = 1;
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
    if(interrupteur == 0 ) {
        vision.x = sHead.x-3*(cos(angle*2*PI/360)); vision.y = sHead.y-3*(sin(angle*2*PI/360)); vision.z = sHead.z;
    }
    if(interrupteur == 1 ) {
        if(angle == 0) {
            vision.x = sHead.x+20*(cos(angle*2*PI/360)); vision.y = sHead.y+2*(sin(angle*2*PI/360)); vision.z = sHead.z+20;
        }
        if(angle == 45 || angle == -315) {
            vision.x = sHead.x+20*(cos(angle*2*PI/360)); vision.y = sHead.y+20*(sin(angle*2*PI/360)); vision.z = sHead.z+20;
        }
        if(angle == 90 || angle == -270) {
            vision.x = sHead.x+2*(cos(angle*2*PI/360)); vision.y = sHead.y+20*(sin(angle*2*PI/360)); vision.z = sHead.z+20;
        }
        if(angle == 135 || angle == -225) {
            vision.x = sHead.x+20*(cos(angle*2*PI/360)); vision.y = sHead.y+20*(sin(angle*2*PI/360)); vision.z = sHead.z+20;
        }
        if(angle == 180 || angle == -180) {
            vision.x = sHead.x+20*(cos(angle*2*PI/360)); vision.y = sHead.y+2*(sin(angle*2*PI/360)); vision.z = sHead.z+20;
        }
        if(angle == 225 || angle == -135) {
            vision.x = sHead.x+20*(cos(angle*2*PI/360)); vision.y = sHead.y+20*(sin(angle*2*PI/360)); vision.z = sHead.z+20;
        }
        if(angle == 270 || angle == -90) {
            vision.x = sHead.x+2*(cos(angle*2*PI/360)); vision.y = sHead.y+20*(sin(angle*2*PI/360)); vision.z = sHead.z+20;
        }
        if(angle == 315 || angle == -45) {
            vision.x = sHead.x+20*(cos(angle*2*PI/360)); vision.y = sHead.y+20*(sin(angle*2*PI/360)); vision.z = sHead.z+20;
        }
    }
    gluLookAt(vision.x, vision.y, vision.z, eye.x, eye.y, eye.z, 0, 0, 1);

    // Affichage du score 
    if(interrupteur == 1){
      GLvoid *font_style = GLUT_BITMAP_TIMES_ROMAN_24;
      int scorevar = time(NULL)-score;
      int j=0;
      while(scorevar > 9){
        int l = scorevar%10;
        glutBitmapCharacter(font_style, 48+l);
        j++;
        scorevar /= 10;
      }
      switch(angle){
          case 0 : glRasterPos3f(sHead.x+j,sHead.y+2,sHead.z+1.7);
          case 45 : case -315 : glRasterPos3f(sHead.x+j*1.5,sHead.y+2,sHead.z+1.7);
          case 90 : case -270 : glRasterPos3f(sHead.x+j*1.5,sHead.y+2,sHead.z+1.7);
          case 135 : case -225 : glRasterPos3f(sHead.x+j*1.5,sHead.y+2,sHead.z+1.7);
          case 180 : case -180 : glRasterPos3f(sHead.x+2,sHead.y+j,sHead.z+1.7);
          case 225 : case -135 : glRasterPos3f(sHead.x+j*1.5,sHead.y+2,sHead.z+1.7);
          case 270 : case -90 : glRasterPos3f(sHead.x+2,sHead.y+j*1.5,sHead.z+1.7);
          case 315 : case -45 : glRasterPos3f(sHead.x+j*1.5,sHead.y+2,sHead.z+1.7);
      }
      glutBitmapCharacter(font_style, 48+scorevar);
    }
    afficher_grille(jeu);
    
    glPushMatrix();
    glTranslatef(sHead.x, sHead.y, 0);
    glRotatef(angle, 0, 0, 1);
    glTranslatef(-sHead.x, -sHead.y, 0);
    if(vie>2000) serpent(sHead.x, sHead.y, sHead.z+1.8, 0.1, 0.5, 0.2);
    if(vie>1000 && vie <=2000) serpent(sHead.x, sHead.y, sHead.z+1.8, 1.0, 0.5, 0.0);
    if(vie>0 && vie <= 1000) serpent(sHead.x, sHead.y, sHead.z+1.8, 1.0, 0.0, 0.0);
    glPopMatrix();
    
    glutKeyboardFunc(GererClavier);
    glutIdleFunc(Animer);

    glFlush();
}

void Animer(){
    int collision; // 0 si pas de collision, 1 sinon
    collision = collision_snake();
    if(collision == 0){
        switch(angle){
        case 0 : mvt.x = -0.02*speedmod; mvt.y = 0;
            eye.x = sHead.x - 10; eye.y = sHead.y;
            break;
        case 45 : case -315 : mvt.x = -0.02*(cos(angle*2*PI/360))*speedmod; mvt.y = -0.02*(sin(angle*2*PI/360))*speedmod;
            eye.x = sHead.x - 10; eye.y = sHead.y - 10;
            break;
        case 90 : case -270 : mvt.x = 0; mvt.y = -0.02*speedmod;
            eye.x = sHead.x ; eye.y = sHead.y - 10;
            break;
        case 135 : case -225 : mvt.x = -0.02*(cos(angle*2*PI/360))*speedmod; mvt.y = -0.02*(sin(angle*2*PI/360))*speedmod;
            eye.x = sHead.x + 10; eye.y = sHead.y - 10;
            break;
        case 180 : case -180 : mvt.x = 0.02*speedmod; mvt.y = 0;
            eye.x = sHead.x + 10; eye.y = sHead.y;
            break;
        case 225 : case -135 : mvt.x = -0.02*(cos(angle*2*PI/360))*speedmod; mvt.y = -0.02*(sin(angle*2*PI/360))*speedmod;
            eye.x = sHead.x + 10; eye.y =  sHead.y + 10;
            break;
        case 270 : case -90 : mvt.x = 0; mvt.y = 0.02*speedmod;
            eye.x = sHead.x; eye.y = sHead.y + 10;
            break;
        case 315 : case -45 : mvt.x = -0.02*(cos(angle*2*PI/360))*speedmod; mvt.y = -0.02*(sin(angle*2*PI/360))*speedmod;
            eye.x = sHead.x - 10; eye.y =  sHead.y + 10;
            break;
        default : break;
        }
        sHead.x += mvt.x;
        sHead.y += mvt.y;
    }
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
    case 'x' : attaque_snake();
        break;
    case 'p' : sHead.x=50; sHead.y =50; 
        break;
    }
}


int collision_snake(){
    int x, y; objet o; float fx, fy;
    x = sHead.x/30;
    y = sHead.y/30;
    o = jeu[x][y];
    switch(angle){
    case 0 : fx = sHead.x-0.02*speedmod; fy = sHead.y;
        break;
    case 45 : case -315 : fx = sHead.x -0.02*(cos(PI/4))*speedmod; fy = sHead.y-0.02*(sin(PI/4))*speedmod;
        break;
    case 90 : case -270 : fx = sHead.x; fy = sHead.y -0.02*speedmod;
        break;
    case 135 : case -225 : fx = sHead.x+0.02*(cos(PI/4))*speedmod; fy = sHead.y -0.02*(sin(PI/4))*speedmod;
        break;
    case 180 : case -180 : fx = sHead.x+0.02*speedmod; fy = sHead.y;
        break;
    case 225 : case -135 : fx = sHead.x+0.02*(cos(PI/4))*speedmod; fy = sHead.y+0.02*(sin(PI/4))*speedmod;
        break;
    case 270 : case -90 : fx = sHead.x; fy = sHead.y+0.02*speedmod;
        break;
    case 315 : case -45 : fx = sHead.x -0.02*(cos(PI/4))*speedmod; fy =sHead.y+ 0.02*(sin(PI/4))*speedmod;
        break;
    }
    switch(o.type){
    case 1:
      if(o.b.p.x + o.b.radius >= fx && o.b.p.x - o.b.radius <= fx && o.b.p.y + o.b.radius >= fy && o.b.p.y - o.b.radius <= fy){
	vie--;
	if(vie <= 0){ printf("partie terminée\n"); printf("Votre score est de %ld secondes\n", time(NULL) - score); printf("Nombre d'ennemis tué : %d\n", nb_e_tue); exit(0);}
	return 1;
      }
        else
            return 0;
    case 2:
        if(o.m.p.x <= fx && o.m.p.x + o.m.longueur >= fx && o.m.p.y <= fy && o.m.p.y + o.m.largeur >= fy){
	vie--;
	if(vie <= 0){ printf("partie terminée\n"); printf("Votre score est de %ld secondes\n", time(NULL) - score); printf("Nombre d'ennemis tué : %d\n", nb_e_tue); exit(0);}
            return 1;
	}
        else
            return 0;
    case 3:
        if(o.a.p.x - o.a.t.rayon <= fx && o.a.p.x + o.a.t.rayon >= fx && o.a.p.y - o.a.t.rayon <= fy && o.a.p.y + o.a.t.rayon >= fy){
	vie--;
	if(vie <= 0){ printf("partie terminée\n"); printf("Votre score est de %ld secondes\n", time(NULL) - score); printf("Nombre d'ennemis tué : %d\n", nb_e_tue); exit(0);}
            return 1;
	}
        else
            return 0;
    case 4:
        if(o.e.p.x - 3 <= fx && o.e.p.x + 3 >= fx && o.e.p.y -3 <= fy && o.e.p.y + 3 >= fy){
            vie-=100;
            if(vie <= 0){ printf("partie terminée\n"); printf("Votre score est de %ld secondes\n", time(NULL) - score); printf("Nombre d'ennemis tué : %d\n", nb_e_tue); exit(0);}
            return 1;
        }
        else
            return 0;
    case 5:
        if(o.bn.p.x -2 <= fx && o.bn.p.x + 2 >= fx && o.bn.p.y -2 <= fy && o.bn.p.y + 2 >= fy){
            switch(o.bn.type){
            case 0: speedmod*=1.2; break;
            case 1: speedmod*=1.2; if(vie < 2900) vie+=250; break;
            }
            jeu[x][y].type = 0; ajouter_bouboule();
        }
        return 0;
    default :
        if(fx <= 0 || fx >= LONGUEUR || fy <= 0 || fy >= LARGEUR){
	vie--;
	if(vie == 0){ printf("partie terminée\n"); printf("Votre score est de %ld secondes\n", time(NULL) - score); printf("Nombre d'ennemis tué : %d\n", nb_e_tue); exit(0);}
            return 1;
	}
        else
            return 0;
    } 

}

void attaque_snake(){
    int fx=0, fy=0, x, y;
    switch(angle){
    case 0 : fx=-1;
        break;
    case 45 : case -315 : fx = -1; fy = -1;
        break;
    case 90 : case -270 : fy = -1;
        break;
    case 135 : case -225 : fx = 1; fy = -1;
        break;
    case 180 : case -180 : fx = 1;
        break;
    case 225 : case -135 : fx = 1; fy = 1;
        break;
    case 270 : case -90 : fy = 1;
        break;
    case 315 : case -45 : fx = -1; fy = 1;
        break;
    default : break;
    }
    x = sHead.x/30; y = sHead.y/30;
    if(x >=0 && x < LONGUEUR/30 && y >=0 && y < LARGEUR/30){
        if(jeu[x][y].type == 4){
            jeu[x][y].type = 0;
            nb_e_tue++;
            ajouter_ennemis();
        }
        else{
            if(x+fx >=0 && x+fx < LONGUEUR/30 && y+fy >=0 && y+fy < LARGEUR/30){
                if(jeu[x+fx][y+fy].type == 4){
                    jeu[x+fx][y+fy].type= 0;
                    ajouter_ennemis();
                    nb_e_tue++;
                }
            }
        }
    }
}
