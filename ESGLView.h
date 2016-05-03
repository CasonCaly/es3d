#ifndef ESGLVIEW_H
#define ESGLVIEW_H

#include <QGLWidget>
#include <QWidget>
#include <QWindow>
#include <QOpenGLFunctions>
#include <QOpenGLContext>
#include "ESProgram.h"

class ESGLView : public QGLWidget , protected QOpenGLFunctions
{

public:

    ESGLView(QWidget* parent = NULL);

    ~ESGLView();

protected:

  void initializeGL();

  void paintGL();

  void resizeGL( int width, int height );

protected:

  QOpenGLContext* m_context;

  ESProgram m_program;

};

#endif // ESGLVIEW_H
