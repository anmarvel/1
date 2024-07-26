#include<stdio.h>
#include<math.h>
#include<GL/glut.h>

GLfloat d;
GLfloat rX=0,rY=0;

void Spin(){
    d=d+0.1;
    if(d>360)
    d=0;
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
    for(i=0;i<3;i++){
        np[i][0]=p[i][0]*cos(r)-p[i][1]*sin(r)-rX*cos(r)+rY*sin(r)+rX;
        np[i][1]=p[i][0]*sin(r)+p[i][1]*cos(r)-rX*sin(r)-rY*cos(r)+rY;
    }
    glColor3f(0,1,0);
    glBegin(GL_LINE_LOOP);
    glVertex2fv(np[0]);
    glVertex2fv(np[1]);
    glVertex2fv(np[2]);
    glEnd();
    glFlush();
}

int main(int argC, char *argV[]){
    printf("Enter the number of coordinates:");
    scanf("%f%f",&rX,&rY);
    scanf("%f",&d);
    glutInit(&argC,argV);
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Lab3:");
    glutDisplayFunc(Draw);
    glutIdleFunc(Spin);
    glutMainLoop();
    return 0;
}
