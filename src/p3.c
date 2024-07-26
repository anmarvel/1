#include<stdio.h>
#include<math.h>
#include<GL/glut.h>

int n;

void Triangle(GLfloat A[],GLfloat B[],GLfloat C[]){
    glBegin(GL_TRIANGLES);
    glVertex2fv(A);
    glVertex2fv(B);
    glVertex2fv(C);
    glEnd();
}

void Tetra(GLfloat P1[],GLfloat P2[],GLfloat P3[],GLfloat P4[]){
    glColor3f(1,1,1);
    Triangle(P1,P2,P3);
    glColor3f(0,0,1);
    Triangle(P1,P2,P4);
    glColor3f(1,0,0);
    Triangle(P2,P3,P4);
    glColor3f(1,1,1);
    Triangle(P1,P4,P3);
}

void Div(GLfloat P1[],GLfloat P2[],GLfloat P3[],GLfloat P4[],int n){
    GLfloat P12[3],P23[3],P31[3],P14[3],P24[3],P34[3];
    if(n>0){
        P12[0]=(P1[0]+P2[0])/2;
        P12[1]=(P1[1]+P2[1])/2;
        P12[2]=(P1[2]+P2[2])/2;

        P23[0]=(P2[0]+P3[0])/2;
        P23[1]=(P2[1]+P3[1])/2;
        P23[2]=(P2[2]+P3[2])/2;

        P31[0]=(P3[0]+P1[0])/2;
        P31[1]=(P3[1]+P1[1])/2;
        P31[2]=(P3[2]+P1[2])/2;

        P14[0]=(P1[0]+P4[0])/2;
        P14[1]=(P1[1]+P4[1])/2;
        P14[2]=(P1[2]+P4[2])/2;

        P24[0]=(P2[0]+P4[0])/2;
        P24[1]=(P2[1]+P4[1])/2;
        P24[2]=(P2[2]+P4[2])/2;

        P34[0]=(P3[0]+P4[0])/2;
        P34[1]=(P3[1]+P4[1])/2;
        P34[2]=(P3[2]+P4[2])/2;

        Div(P1,P12,P31,P14,n-1);
        Div(P12,P2,P23,P24,n-1);
        Div(P31,P23,P3,P34,n-1);
        Div(P14,P24,P34,P4,n-1);
    }
    else
    Tetra(P1,P2,P3,P4);
}

void Display(){
    GLfloat v[4][3]={
        {-0.75,-0.5,-0.5},
        {0.75,-0.5,-0.5},
        {0,0.5,-0.5},
        {0,-0.1,0.5}
    };
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    Div(v[0],v[1],v[2],v[3],n);
    glutSwapBuffers();
}


int main(int argC, char *argV[]){
    printf("Enter the number of division:");
    scanf("%d",&n);
    glutInit(&argC,argV);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Lab3:");
    glutDisplayFunc(Display);
    glutMainLoop();
    return 0;
}
