#include "ESGLView.h"
#include <math.h>
#include <QGLFormat>


ESGLView::ESGLView(QWidget* parent):QGLWidget(parent, 0, 0)
{

}

 ESGLView::~ESGLView()
{

}

 void ESGLView::setExample(ESExample* example)
 {
     m_example = example;
     if(m_example)
        m_example->setParent(this);
 }

void ESGLView::initializeGL()
{
    this->makeCurrent();
    this->initializeOpenGLFunctions();

   if(m_example)
   {
       m_example->init();
   }
}

void ESGLView::paintGL()
{
    if(m_example)
        m_example->paint();
}

void ESGLView::resizeGL(int width, int height )
{
    glViewport(0, 0, width, height);
}

