#include<math.h>
#include<stdio.h>
#include<GL/glut.h>

typedef float point2[2];

point2 v[]={{-1.0,-0.58},{1.0,-0.58},{0.0,1.15}};
int n;
void Triangle(point2 a,point2 b, point2 c){
    glBegin(GL_TRIANGLES);
    glVertex2fv(a);
    glVertex2fv(b);
    glVertex2fv(c);
    glEnd();
}

void Divide_Triangle(point2 a, point2 b, point2 c, int m){
    int j;
    point2 v0,v1,v2;
    if(m>0){
    for(j=0;j<2;j++)
    v0[j]=(a[j]+b[j])/2;
    for(j=0;j<2;j++)
    v1[j]=(a[j]+c[j])/2;
    for(j=0;j<2;j++)
    v2[j]=(b[j]+c[j])/2;
    Divide_Triangle(a,v0,v1,m-1);
    Divide_Triangle(c,v1,v2,m-1);
    Divide_Triangle(b,v2,v0,m-1);
    }
    else(Triangle(a,b,c));
}
    
void Display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    Divide_Triangle(v[0],v[1],v[2],n);
    glFlush();
}

void MyInit(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-2,2,-2,2);
    glMatrixMode(GL_MODELVIEW);
    glClearColor(1,1,1,1);
    glColor3f(1,0,0);
}

int main(int argC, char **argV){
    printf("Enter the number of division:");
    scanf("%d",&n);
    glutInit(&argC,argV);
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Lab2:");
    MyInit();
    glutDisplayFunc(Display);
    glutMainLoop();
    return 0;
}