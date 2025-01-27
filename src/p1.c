#include<stdio.h>
#include<math.h>
#include<GL/glut.h>
void Draw(){
GLfloat x1=120,y1=50,x2=350,y2=300;
GLfloat x,y,dx,dy,p,m,temp;

glClear(GL_COLOR_BUFFER_BIT);
m=(y2-y1)/(x2-x1);

if(fabs(m)<1){
    if(x1>x2){
        temp=x1;
        x1=x2;
        x2=temp;
        temp=y1;
        y1=y2;
        y2=temp;
    }
    dx=fabs(x2-x1);
    dy=fabs(y2-y1);
    x=x1;
    y=y1;
    p=2*dy-dx;
    while(x<=x2){
        glBegin(GL_POINTS);
        glVertex2f(x,y);
        glEnd();
        x=x+1;
        if(p>=0){
            if(m>=1){
                y=y+1;
            }
            else{
                y=y-1;
            }
            p=p+2*dy-2*dx;
        }
        else{
            y=y;
            p=p+2*dy;
        }
    }
}

if(fabs(m)>=1){
    if(y1>y2){
        temp=x1;
        x1=x2;
        x2=temp;
        temp=y1;
        y1=y2;
        y2=temp;
    }
    dx=fabs(x2-x1);
    dy=fabs(y2-y1);
    x=x1;
    y=y1;
    p=2*dx-dy;
    while(y<=y2){
        glBegin(GL_POINTS);
        glVertex2f(x,y);
        glEnd();
        y=y+1;
        if(p>=0){
            if(m>=1){
                x=x+1;
            }
            else{
                x=x-1;
            }
            p=p+2*dx-2*dy;
        }
        else{
            x=x;
            p=p+2*dx;
        }
    }
}
glFlush();
}

void MyInit(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,500,0,500);
    glMatrixMode(GL_MODELVIEW);
    glClearColor(1,1,1,1);
    glColor3f(1,0,0);
}

int main(int argC, char *argV[]){
    glutInit(&argC,argV);
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Lab1:");
    MyInit();
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}