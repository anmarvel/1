#include<stdio.h>
#include<GL/glut.h>
#include<math.h>

GLfloat rx=0,rx=0;
GLfloat d;

void Spin(){
    d=d+0.1;
    if(d>360){
        d=0;
    }
    glutPostRedisplay();
}

void Draw(){
    GLfloat p[3][2]={{-0.5,0},{0.5,0},{0,0.6}};
    GLfloat np[3][2],r;
    int i;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
    glBegin(GL_LINE_LOOP);
    glVertex2fv(p[0]);
    glVertex2fv(p[1]);
    glVertex2fv(p[2]);
    glEnd();

    r=d*3.14/180;
    np[i][0]=p[i][0]*cos(r)-p[i][1]*sin(r)-rX*cos(r)
}