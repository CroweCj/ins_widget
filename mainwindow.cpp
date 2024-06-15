#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QImage image;
    image.load("/home/insnex/10T/code/ins_widget/test_image/1.bmp");

    ui->widget->setImage(image);
}

MainWindow::~MainWindow()
{
    delete ui;
}