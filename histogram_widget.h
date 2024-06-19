#pragma once

#include <QWidget>
#include <QPainter>
#include <QMap>
#include <QString>
#include <QStringList>
#include <QColor>
#include <QList>
#include <QDebug>
#include <QVector>
#include <vector>

class HistogramWidget : public QWidget
{
    Q_OBJECT
public:
    explicit HistogramWidget(QWidget *parent = nullptr);
   ~HistogramWidget();

    void setImage(const QImage& _image);
    void setHistogram(const std::vector<double>& _redHistogram,
                        const std::vector<double>& _greenHistogram,
                        const std::vector<double>& _blueHistogram);
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    void drawHistogram(QPainter &painter,
                       const std::vector<double> &histogram,
                       int width, 
                       int height, 
                       const QColor &color, 
                       const QString &title, 
                       int xOffset);
    
    void calcHistogram(const QImage& image);
    void normalizedHist(const std::vector<int> &histogram, std::vector<double> &normalizedHist);

private:
    std::vector<double> mRedHistogram;
    std::vector<double> mGreenHistogram;
    std::vector<double> mBlueHistogram;

    int mMaxValue;
};

