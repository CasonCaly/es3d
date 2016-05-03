#include "ESGLView.h"

ESGLView::ESGLView(QWidget* parent):QGLWidget(parent, 0, 0)
{

}

 ESGLView::~ESGLView()
{

}

void ESGLView::initializeGL()
{
    this->makeCurrent();
    this->initializeOpenGLFunctions();
    m_program.initWithShaderPath("Simple.vert", "Simple.frag");
}

void ESGLView::paintGL()
{
    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void ESGLView::resizeGL(int width, int height )
{

}

