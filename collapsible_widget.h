#pragma once

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

class CollapsibleWidget : public QWidget
{
	Q_OBJECT
public:
	CollapsibleWidget(QWidget* _parent = nullptr);
	virtual ~CollapsibleWidget();

	void set_content_widget(QWidget* _content);

	virtual void set_image(const QImage& _image);
protected:
	void slot_collaps_widget();
protected:
	QPushButton* mpCollapsibleBtn;
	QVBoxLayout* mMainLayout;
	QWidget* mpContentWidget;
};

class HistogramWidget;
class HistogramCollapsibleWidget : public CollapsibleWidget
{
	Q_OBJECT
public:
	HistogramCollapsibleWidget(QWidget* _parent = nullptr);
	virtual ~HistogramCollapsibleWidget();

	void set_image(const QImage& _image) override;
private:
	HistogramWidget* mpHistogramWidget;
};

