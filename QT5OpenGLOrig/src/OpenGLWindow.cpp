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

OpenGLWindow::OpenGLWindow()
{

  setTitle("My First OpenGL Window in Qt :)");

}

void OpenGLWindow::keyPressEvent( QKeyEvent *_key )
{

  switch( _key->key() )
  {

    case Qt::Key_Escape : QApplication::exit(EXIT_SUCCESS);
    break;
    case Qt::Key_W :
      glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    break;
    case Qt::Key_S :
      glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    break;

  }

  update();

}

void OpenGLWindow::paintGL()
{

  glClear(GL_COLOR_BUFFER_BIT |
          GL_DEPTH_BUFFER_BIT);

  drawCube( 1, 1, 1 );

  /*
  glBegin(GL_TRIANGLES);

    glColor3f( 1, 1, 1 );
    glVertex3f( -1, -1, 0 );
    glColor3f( 1, 0, 0 );
    glVertex3f( 0, 1, 0 );
    glColor3f( 0, 0, 1 );
    glVertex3f( 1, -1, 0 );

    glColor3f( 1, 1, 1 );
    glVertex3f( -1, -1, 1 );
    glVertex3f( 0, 1, 1 );
    glVertex3f( 1, -1, 1 );

    glColor3f( 1, 0, 0 );
    glVertex3f( -1, -1, -1 );
    glVertex3f( 0, 1, -1 );
    glVertex3f( 1, -1, -1 );

  glEnd();
  */

  update();

}

void OpenGLWindow::initializeGL()
{

  glClearColor( 0.3, 0.7, 0.4, 1 );

  auto w = width();
  auto h = height();

  glMatrixMode( GL_PROJECTION );
  gluPerspective( 45.0, (double)w/h,
                  0.5, 10.0);
  glMatrixMode( GL_MODELVIEW );
  gluLookAt( 2, 2, 2, 0, 0, 0, 0, 1, 0 );

  glViewport( 0, 0, w, h );
  glEnable( GL_DEPTH_TEST );
  glEnable( GL_NORMALIZE );

}

void OpenGLWindow::resizeGL( int _w, int _h )
{

}

void OpenGLWindow::drawCube( GLfloat _w, GLfloat _h, GLfloat _d )
{

  float w2 = _w/2.0f;
  float h2 = _h/2.0f;
  float d2 = _d/2.0f;

  glBegin(GL_TRIANGLES);
    //Front face
    glColor3f( 1, 1, 1 );
    glVertex3f(-w2, -h2, d2);
    glVertex3f(w2, -h2, d2);
    glVertex3f(-w2, h2, d2);

    glVertex3f(-w2, h2, d2);
    glVertex3f(w2, h2, d2);
    glVertex3f(w2, -h2, d2);

    //Left face
    glColor3f( 0, 0, 0 );
    glVertex3f(w2, h2, d2);
    glVertex3f(w2, -h2, d2);
    glVertex3f(w2, -h2, -d2);

    glVertex3f(w2, h2, -d2);
    glVertex3f(w2, h2, d2);
    glVertex3f(w2, -h2, -d2);

    //Top face
    glColor3f( 0.5, 0.5, 0.5 );
    glVertex3f(-w2, h2, -d2);
    glVertex3f(-w2, h2, d2);
    glVertex3f(w2, h2, d2);

    glVertex3f(w2, h2, -d2);
    glVertex3f(-w2, h2, -d2);
    glVertex3f(w2, h2, d2);

  glEnd();

}

OpenGLWindow::~OpenGLWindow()
{

}
