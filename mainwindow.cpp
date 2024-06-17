#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QImage image;
    image.load("E:/code/ins_widget/src_code/ins_widget/test_image/1.bmp");

    ui->widget->setImage(image);

    QObject::connect(ui->widget, &ImageViewWidget::sig_hover_pos_update, this, [=](qreal x, qreal y, QRgb color){
        ui->label_pos->setText(QString("x: %1, y: %2").arg(x).arg(y));
        ui->label_pixel_val->setText(QString("r: %1, g: %2, b: %3").arg(qRed(color)).arg(qGreen(color)).arg(qBlue(color)));
    });

   
}

MainWindow::~MainWindow()
{
    delete ui;
}