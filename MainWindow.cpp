#include "MainWindow.h"
#include "ui_mainwindow.h"
#include "core/ESGLView.h"
#include "example/ESHelloArrow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ESExample* example = new ESHelloArrow();

    ESGLView* glView = new ESGLView(this);
    glView->setExample(example);

    glView->setGeometry(0, 0, 800, 600);
}

MainWindow::~MainWindow()
{
    delete ui;
}


