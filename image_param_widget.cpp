#include "image_param_widget.h"

ImageParamsWidget::ImageParamsWidget(QWidget *parent) 
    : QWidget(parent)
{
    // 初始化界面元素
    mpGridLayout = new QGridLayout(this);
    mpGridLayout->setContentsMargins(0, 0, 0, 0);
    mpGridLayout->setSpacing(0);

    QLabel* pExposureLabel = new QLabel("Exposure:", this);
    mpExposureSlider = new QSlider(Qt::Horizontal, this);
    mpExposureSlider->setMinimum(-5);
    mpExposureSlider->setMaximum(5);
    mpExposureSlider->setTickPosition(QSlider::TicksBothSides);
    mpExposureSlider->setTickInterval(10);
    mpGridLayout->addWidget(pExposureLabel, 0, 0);
    mpGridLayout->addWidget(mpExposureSlider, 0, 1);

    QLabel* pContrastLabel = new QLabel("Contrast:", this);
    mpContrastSlider = new QSlider(Qt::Horizontal, this);
    mpContrastSlider->setMinimum(-5);
    mpContrastSlider->setMaximum(5);
    mpContrastSlider->setTickPosition(QSlider::TicksBothSides);
    mpContrastSlider->setTickInterval(10);
    mpGridLayout->addWidget(pContrastLabel, 1, 0);
    mpGridLayout->addWidget(mpContrastSlider, 1, 1);

    QLabel* pBrightnessLabel = new QLabel("Brightness:", this);
    mpBrightnessSlider = new QSlider(Qt::Horizontal, this);
    mpBrightnessSlider->setMinimum(-5);
    mpBrightnessSlider->setMaximum(5);
    mpBrightnessSlider->setTickPosition(QSlider::TicksBothSides);
    mpBrightnessSlider->setTickInterval(10);
    mpGridLayout->addWidget(pBrightnessLabel, 2, 0);
    mpGridLayout->addWidget(mpBrightnessSlider, 2, 1);

    
}

ImageParamsWidget::~ImageParamsWidget()
{
}

