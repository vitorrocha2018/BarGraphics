#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets>
#include <QtCharts>
#include <QtSql>
#include <QtPrintSupport/QPrinter>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);

    void paintEvent(QPixmap pix);
    void loadData();
    void savePDF(QString filename);

private:
    QtCharts::QChartView *chartView;
    QtCharts::QBarSeries *barSeries;
};

#endif // WIDGET_H
