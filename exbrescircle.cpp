#include<GL/glut.h>
#include<iostream>
using namespace std;


int r;
int xc = 320, yc = 240;

void plot_point(int x, int y)
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
}


void bresenham_circle(int r)
{
  int x=0,y=r;
  float pk=(5.0/4.0)-r;


  plot_point(x,y);
  int k;

  while(x < y)
  {
    x = x + 1;
    if(pk < 0)
      pk = pk + 2*x+1;
    else
    {
      y = y - 1;
      pk = pk + 2*(x - y) + 1;
    }
    plot_point(x,y);
  }
  glFlush();
}

void concentric_circles(void)
{

  glClear(GL_COLOR_BUFFER_BIT);

  int radius1 = r;
  bresenham_circle(radius1);
 
}

void Init()
{
  
  glClearColor(1.0,1.0,1.0,0);
  
  glColor3f(0.0,0.0,0.0);
 
  gluOrtho2D(0 , 640 , 0 , 480);
}

int main(int argc, char **argv)
{
  cout<<"\nEnter Radius: ";
  cin>>r;
  glutInit(&argc,argv);
 
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 
  glutInitWindowPosition(0,0);
  glutInitWindowSize(640,480);

  glutCreateWindow("bresenham_circle");
 
  Init();

  glutDisplayFunc(concentric_circles);

  glutMainLoop();
  return 0;
}

