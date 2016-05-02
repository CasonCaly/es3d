#include "MainWindow.h"
#include "ui_mainwindow.h"
#include "ESGLView.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ESGLView* glView = new ESGLView(this);
    glView->setGeometry(0, 0, 800, 600);
}

MainWindow::~MainWindow()
{
    delete ui;
}


