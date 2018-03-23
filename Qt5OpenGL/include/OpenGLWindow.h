#ifndef OPENGLWINDOW_H_
#define OPENGLWINDOW_H_

#include <QOpenGLWindow>
#include <vector>
#include "Types.h"

class OpenGLWindow : public QOpenGLWindow
{
  Q_OBJECT
  public :
    OpenGLWindow();
    void paintGL()  override;
    void initializeGL() override;
    void resizeGL(int _w, int _h) override;
    void keyPressEvent(QKeyEvent *) override;
    void timerEvent(QTimerEvent *) override;
    ~OpenGLWindow();
    void drawCube(Vec3 _pos, Vec3 _scale, Vec3 _colour);

    std::vector<Cube> m_cube;

};




#endif
