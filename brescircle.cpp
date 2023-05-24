#include<GL/glut.h>
#include<iostream>
using namespace std;

int r;

void plotpoints(int x,int y)
{
	glBegin(GL_POINTS);
  glVertex2i(340+x, 240+y);
  glVertex2i(340+x, 240-y);
  glVertex2i(340+y, 240+x);
  glVertex2i(340+y, 240-x);
  glVertex2i(340-x, 240-y);
  glVertex2i(340-y, 240-x);
  glVertex2i(340-x, 240+y);
  glVertex2i(340-y, 240+x);
  glEnd();
	glFlush();
}

void bresenham()
{
	float d;
	d = (5.0/4.0)*r;
	
	int x,y;
	x=0;
	y=r;
	
	
  while(x < y)
  {
    x = x + 1;
    if(d < 0)
      d = d + 2*x+1;
    else
    {
      y = y - 1;
      d = d + 2*(x - y) + 1;
    }
    plotpoints(x,y);
  }	
	
	/*
	do
	{
	x++;
        if(d<0)
        {
          d=d + 2*x+1;
          
        }
        else
        {
        	y--;
          d= d + 2*(x + y) + 1;
	}
	plotpoints(x,y);
	}while(x<y);*/
}
void init()
{
	glClearColor(1,1,1,0);
	glColor3f(1,0,0);
	gluOrtho2D(0,640,0,480);
	glClear(GL_COLOR_BUFFER_BIT);
}
int main(int argc, char**argv){
	cout<<"\nEnter Radius: ";
	cin>>r;
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	
	glutInitWindowPosition(100,100);
	glutInitWindowSize(1000,480);
	glutCreateWindow("Circle");
	init();
	glutDisplayFunc(bresenham);
	glutMainLoop();
	return 0;
}
