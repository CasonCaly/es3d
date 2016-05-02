#include "ESGLView.h"

ESGLView::ESGLView(QWidget* parent):QGLWidget(parent, 0, 0)
{

}

 ESGLView::~ESGLView()
{

}

void ESGLView::initializeGL()
{
//    QGLFormat glFormat;
//    glFormat.setVersion(2, 0);
//    glFormat.setProfile(QGLFormat::CoreProfile);
//    this->setFormat(glFormat);

}

void ESGLView::paintGL()
{
    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void ESGLView::resizeGL( int width, int height )
{

}

