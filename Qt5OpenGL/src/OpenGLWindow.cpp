#include "OpenGLWindow.h"
#include <QKeyEvent>
#include <QApplication>
#ifdef __APPLE__
  #include <OpenGL/OpenGL.h>
  #include <glu.h>
#else
  #include <GL/gl.h>
  #include <GL/glu.h>
#endif

#include <vector>
#include <iostream>

OpenGLWindow::OpenGLWindow()
{
  setTitle("My first OpenGL Window in Qt");
}

OpenGLWindow::~OpenGLWindow()
{

}

void OpenGLWindow::drawCube(Vec3 _pos, Vec3 _scale, Vec3 _colour)
{

  std::vector<GLfloat> vertices = {
                         -1,1,-1,1,1,-1,1,-1,-1, -1,1,-1,-1,-1,-1,1,-1,-1, //back
                         -1,1,1,1,1,1,1,-1,1, -1,-1,1, 1,-1,1,-1,1,1,  //front
                         -1,1,-1, 1,1,-1, 1,1,1, -1,1,1, 1,1,1, -1,1,-1, // top
                         -1,-1,-1, 1,-1,-1, 1,-1,1, -1,-1,1, 1,-1,1, -1,-1,-1, // bottom
                         -1,1,-1,-1,1,1,-1,-1,-1, -1,-1,-1,-1,-1,1,-1,1,1, // left
                         1,1,-1,1,1,1,1,-1,-1, 1,-1,-1,1,-1,1,1,1,1, // left
                         };

  _colour.colour();
  glPushMatrix();
    _pos.translate();
    _scale.scale();
    glBegin(GL_TRIANGLES);
      for(size_t i=0; i<vertices.size(); i+=3)
      {
        glVertex3f(vertices[i],vertices[i+1],vertices[i+2]);
      }
    glEnd();
  glPopMatrix();

}


void OpenGLWindow::paintGL()
{

  glClear(GL_COLOR_BUFFER_BIT |
          GL_DEPTH_BUFFER_BIT);

  /*
  drawCube(
          Vec3{1.0f,1.0f,1.0f},
          Vec3{0.5f,0.5f,0.5f},
          Vec3{1.0f,0.5f,0.5f}
          );

  drawCube(m_cube.m_pos,
           m_cube.m_scale,
           m_cube.m_colour);

  */

  for( auto c : m_cube )
  {

    drawCube(c.m_pos,
             c.m_scale,
             c.m_colour);

  }

}
void OpenGLWindow::initializeGL()
{

  glClearColor(0.0f , 0.f, 0.0f , 1);

  auto w=width();
  auto h=height();
  glMatrixMode(GL_PROJECTION);
  gluPerspective(45.0,(double)w/h,
                 0.5,10.0);
  glMatrixMode(GL_MODELVIEW);
  gluLookAt(4,4,4,0,0,0,0,1,0);

  glViewport(0,0,w,h);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_NORMALIZE);

  //m_cube.m_dir.m_y = 0.01f;

  for(int i = 0; i < 100; ++i)
  {

    float x = -0.01 * (float)rand() / RAND_MAX;
    float y = -0.01 * (float)rand() / RAND_MAX;
    float z = -0.01 * (float)rand() / RAND_MAX;

    Cube c;

    c.m_dir.m_x = x;
    c.m_dir.m_y = y;
    c.m_dir.m_z = z;

    m_cube.push_back(c);

  }

  startTimer(10);

}

void OpenGLWindow::resizeGL(int _w, int _h)
{

}


void OpenGLWindow::keyPressEvent(QKeyEvent *_key)
{

  switch (_key->key())
  {

    case Qt::Key_Escape :
      QApplication::exit(EXIT_SUCCESS);
    break;
    case Qt::Key_W :
      glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    break;
    case Qt::Key_S :
      glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    break;

  }

  update();

}

void OpenGLWindow::timerEvent( QTimerEvent * )
{

  //std::cout<<"Tick\n";
  //m_cube.m_pos += m_cube.m_dir;

  for( auto &c : m_cube )
  {

    c.m_pos += c.m_dir;

  }

  update();

}



