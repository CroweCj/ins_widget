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
private:
	HistogramWidget* mpHistogramWidget;
};

