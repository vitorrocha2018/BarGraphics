#include "widget.h"
#include <QtPrintSupport/QPrinter>
#include <QPdfWriter>
using namespace QtCharts;



Widget::Widget(QWidget *parent) : QWidget(parent)
{

    auto layout = new QBoxLayout(QBoxLayout::LeftToRight, this);

    chartView = new QChartView();
    barSeries = new QBarSeries(this);
    auto axisY = new QValueAxis(this);
    auto axisX = new QBarCategoryAxis(this);

    axisX->append(QStringList {"Valor", "Valor Pago", "Valor Descontado"});
    axisY->setTickCount(5);
    axisY->setRange(0.0, 100);
    axisY->setLabelFormat("%.2f");

    chartView->chart()->setAxisX(axisX);
    chartView->chart()->setAxisY(axisY);
    auto barSet = new QBarSet("Barras",this);

    *barSet << 50 << 70 << 80;

    barSeries->append(barSet);

//    loadData();

    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->chart()->setTitle("<h2>Teste Bars</h2>");
    chartView->chart()->addSeries(barSeries);
    chartView->chart()->legend()->setAlignment(Qt::AlignBottom);
    chartView->chart()->legend()->setFont(QFont("Arial", 9));


    layout->addWidget(chartView);
    QPixmap pix = chartView->grab();
    paintEvent(pix);

}

void Widget::paintEvent(QPixmap pix)
{
QPdfWriter pdf("/home/agit/nometeste.pdf");
pdf.setPageSize(QPagedPaintDevice::A4);
QPainter painter(&pdf);
painter.scale(5.0, 5.0);
painter.drawPixmap(QRect(-20, 200, 1960, 2250), QPixmap(pix));
painter.end();




//  QPrinter printer(QPrinter::HighResolution);
//  printer.setOutputFormat(QPrinter::PdfFormat);
//  printer.setOutputFileName("/home/agit/teste.pdf");
//}

//void Widget::savePDF(QString filename)
//{
// QPdfWriter writer(filename);
// writer.setPageSize(QPagedPaintDevice::A4);
// writer.setPageMargins(QMargins(30,30,30,30));

// QPainter painter(&writer);
// painter.
}



//void Widget::loadData()
//{
//    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

//    db.setHostName("localhost");
//    db.setUserName("root");
//    db.setDatabaseName("escola");

//    Q_ASSERT(db.open());

//    QSqlQuery query("SELECT * FROM aluno", db);

//    Q_ASSERT(query.exec());

//    while(query.next())
//    {
//        QString nome = query.value("nome").toString();
//        double nota1 = query.value("nota1").toDouble();
//        double nota2 = query.value("nota2").toDouble();
//        double nota3 = query.value("nota3").toDouble();
//        double nota4 = query.value("nota4").toDouble();

//        auto barSet = new QBarSet(nome, this);

//        *barSet << nota1 << nota2 << nota3 << nota4 << (nota1 + nota2 + nota3 + nota4) / 4;

//        barSeries->append(barSet);
//    }
//}
