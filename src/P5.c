#include<stdio.h>
#include<math.h>
#include<GL/glut.h>

GLfloat d=0;
char a;
void Spin(){
    d=d+1;
    if(d>360){
        d=0;
    }
    glutPostRedisplay();
}

void Face(GLfloat A[3],GLfloat B[3],GLfloat C[3],GLfloat D[3]){
    glBegin(GL_QUADS);
    glVertex3fv(A);
    glVertex3fv(B);
    glVertex3fv(C);
    glVertex3fv(D);

    glEnd();
}

void Cube(GLfloat P1[3],GLfloat P2[3],GLfloat P3[3],GLfloat P4[3],GLfloat P5[3],GLfloat P6[3],GLfloat P7[3],GLfloat P8[3]){
    glColor3f(1,0,0);
    Face(P1,P2,P3,P4);
    glColor3f(0,1,0);
    Face(P5,P6,P7,P8);
    glColor3f(0,0,1);
    Face(P1,P5,P8,P4);
    glColor3f(1,1,0);
    Face(P2,P6,P7,P3);
    glColor3f(1,0,1);
    Face(P1,P2,P6,P5);
    glColor3f(0,1,1);
    Face(P1,P3,P7,P8);
}

void Draw(){
    GLfloat v[8][3]={
        {-0.5,-0.5,-0.5},
        {0.5,-0.5,-0.5},
        {0.5,0.5,-0.5},
        {-0.5,0.5,-0.5},
        {-0.5,-0.5,0.5},
        {0.5,-0.5,0.\\\\\\\\\\\\\\\
        {-0.5,0.5,0.5}
    };
    GLfloat nv[8][3],r;
    int i;
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    r=d*3.14/180;
    if(a=='z'||a=='Z'){
        for(i=0;i<8;i++){
            nv[i][0]=v[i][0]*cos(r)-v[i][1]*sin(r);
            nv[i][1]=v[i][0]*sin(r)+v[i][1]*cos(r);
            nv[i][2]=v[i][2];
        }
    }
    if(a=='y'||a=='Y'){
        for(i=0;i<8;i++){
            nv[i][0]=v[i][0]*cos(r)+v[i][2]*sin(r);
            nv[i][1]=v[i][1];
            nv[i][2]=-v[i][0]*sin(r)+v[i][2]*cos(r);
        }
    }
    if(a=='x'||a=='X'){
        for(i=0;i<8;i++){
            nv[i][0]=v[i][0];
            nv[i][1]=v[i][1]*cos(r)-v[i][2]*sin(r);
            nv[i][2]=v[i][1]*sin(r)+v[i][2]*cos(r);
        }
    }

    Cube(nv[0],nv[1],nv[2],nv[3],nv[4],nv[5],nv[6],nv[7]);
    glutSwapBuffers();
}
int main(int argC, char *argV[]){
    printf("Enter the number of division:");
    scanf("%c",&a);
    glutInit(&argC,argV);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Lab3:");
    glutDisplayFunc(Draw);
    glutIdleFunc(Spin);
    glutMainLoop();
    return 0;
}

