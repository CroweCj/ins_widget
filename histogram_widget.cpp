#include "histogram_widget.h"
#include <QPainter>
#include <QDebug>

#include <thread>
#include <cmath>

HistogramWidget::HistogramWidget(QWidget * parent  ):
    QWidget(parent)
    , mMaxValue(0)
{
    this->setFixedSize(QSize(400, 300));
    mRedHistogram.resize(256);
    mGreenHistogram.resize(256);
    mBlueHistogram.resize(256);
}

HistogramWidget::~HistogramWidget()
{
}

void HistogramWidget::setImage(const QImage& _image)
{
    std::thread calcThread(&HistogramWidget::calcHistogram, this, _image);
    calcThread.detach();
}

void HistogramWidget::setHistogram(const std::vector<double>& _redHistogram,
                        const std::vector<double>& _greenHistogram,
                        const std::vector<double>& _blueHistogram)
{
    mRedHistogram = _redHistogram;
    mGreenHistogram = _greenHistogram;
    mBlueHistogram = _blueHistogram;
    update();
}

void HistogramWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);

    // 设置背景色为白色
    painter.fillRect(rect(), Qt::white);

    // 设置直方图的参数
    int histogramWidth = width(); // 将控件宽度分成三个部分，每个通道一个部分
    int histogramHeight = height() - 20; // 留出一些空间用于标题等
    // 绘制红色通道直方图
    drawHistogram(painter, mRedHistogram, histogramWidth, histogramHeight, Qt::red, "Red", 0);

    // 绘制绿色通道直方图
    drawHistogram(painter, mGreenHistogram, histogramWidth, histogramHeight, Qt::green, "Green", 0);

    // 绘制蓝色通道直方图
    drawHistogram(painter, mBlueHistogram, histogramWidth, histogramHeight, Qt::blue, "Blue", 0);
}

void HistogramWidget::drawHistogram(QPainter &painter,
                       const std::vector<double> &histogram,
                       int width, 
                       int height, 
                       const QColor &color, 
                       const QString &title, 
                       int xOffset)
{
    // 设置画笔颜色
    painter.setPen(color);

    // 绘制标题
    painter.drawText(xOffset, 15, title);

    // 绘制直方图
    for (int i = 0; i < 256; ++i) {
        int x = xOffset + i * (width / 256.0);
        int y = histogram[i] * height;
        painter.drawLine(x, height, x, y);
    }
}

void HistogramWidget::calcHistogram(const QImage& image)
{
    mMaxValue = 0;
    std::vector<int> redHistogram(256, 0);
    std::vector<int> greenHistogram(256, 0);
    std::vector<int> blueHistogram(256, 0);
    for (int y = 0; y < image.height(); ++y) {
        for (int x = 0; x < image.width(); ++x) {
            QRgb pixel = image.pixel(x, y);

            // 分别获取红、绿、蓝通道的像素值
            int red = qRed(pixel);
            int green = qGreen(pixel);
            int blue = qBlue(pixel);
            if(red > mMaxValue){
                mMaxValue = red;
            }

            if(green > mMaxValue){
                mMaxValue = green;
            }
            if(blue > mMaxValue){
                mMaxValue = blue;
            }
            // 累加各通道的像素数量
            redHistogram[red]++;
            greenHistogram[green]++;
            blueHistogram[blue]++;
        }
    }

    normalizedHist(redHistogram, mRedHistogram);
    normalizedHist(greenHistogram, mGreenHistogram);
    normalizedHist(blueHistogram, mBlueHistogram);

    update();
}

void HistogramWidget::normalizedHist(const std::vector<int> &histogram, std::vector<double> &normalizedHist)
{
    // 计算直方图数据的均值和方差
    // double mean = 0.0;
    // for (int i = 0; i < 256; ++i) {
    //     mean += histogram[i];
    // }
    // mean /= 256.0;

    // double variance = 0.0;
    // for (int i = 0; i < 256; ++i) {
    //     variance += (histogram[i] - mean) * (histogram[i] - mean);
    // }
    // variance /= 256.0;

    // // 标准化直方图数据
    // if (variance > 0.0) {
    //     double stdDeviation = sqrt(variance);
    //     for (int i = 0; i < 256; ++i) {
    //         normalizedHist[i] = (histogram[i] - mean) / stdDeviation;
    //     }
    // }

    int maxVal = *std::max_element(histogram.begin(), histogram.end());
    int minVal = *std::min_element(histogram.begin(), histogram.end());

    // 将直方图数据映射到 [0, 1] 范围
    if (maxVal != minVal) {
        for (int i = 0; i < 256; ++i) {
            normalizedHist[i] = static_cast<double>(histogram[i] - minVal) / (maxVal - minVal);
        }
    }
}



