#include<GL/glut.h>

void init(void){
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0,200.0,0.0,150.0);
}
void lines(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2i(180,15);
    glVertex2i(100,45);
    glVertex2i(125,145);
    glVertex2i(75,90);
    glVertex2i(167,299);
    glEnd();
    glFlush();
}
int main(int argC,char *argV[]){
    glutInit(&argC,argV);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(50,100);
    glutInitWindowSize(400,300);
    glutCreateWindow("Points");
    init();
    glutDisplayFunc(lines);
    glutMainLoop();
    return 0;
}