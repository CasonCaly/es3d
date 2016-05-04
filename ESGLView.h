#ifndef ESGLVIEW_H
#define ESGLVIEW_H

#include <QGLWidget>
#include <QWidget>
#include <QWindow>
#include <QOpenGLFunctions>
#include <QOpenGLContext>
#include "ESProgram.h"
#include "ESBuffer.h"

class ESGLView : public QGLWidget , protected QOpenGLFunctions
{

public:

    ESGLView(QWidget* parent = NULL);

    ~ESGLView();

protected:

  void initializeGL();

  void paintGL();

  void resizeGL( int width, int height );

  void applyOrtho(float maxX, float maxY);

protected:

  QOpenGLContext* m_context;

  ESProgram m_program;

  ESBuffer m_renderBuffer;

  ESBuffer m_frameBuffer;
};

#endif // ESGLVIEW_H
