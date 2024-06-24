#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QSlider>
#include <QPushButton>

class ImageParamsWidget : public QWidget
{
    Q_OBJECT

public:
    ImageParamsWidget(QWidget *parent = nullptr);
    ~ImageParamsWidget();

private slots:
    void onExposureSliderValueChanged(int value);
    void onContrastSliderValueChanged(int value);
    void onBrightnessSliderValueChanged(int value);
    void onReloadImageClicked();

private:
    QGridLayout* mpGridLayout;
    QSlider* mpExposureSlider;
    QSlider* mpContrastSlider;
    QSlider* mpBrightnessSlider;
    QPushButton* mpReloadImage;


};