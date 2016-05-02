#ifndef ESGLVIEW_H
#define ESGLVIEW_H

#include <QGLWidget>
#include <QWidget>

class ESGLView : public QGLWidget
{

public:

    ESGLView(QWidget* parent = NULL);

    ~ESGLView();

protected:

  void initializeGL();

  void paintGL();

  void resizeGL( int width, int height );

};

#endif // ESGLVIEW_H
