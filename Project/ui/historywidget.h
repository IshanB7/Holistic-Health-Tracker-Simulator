#ifndef HISTORYWIDGET_H
#define HISTORYWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QFrame>
#include <QLabel>
#include <math.h>
#include <QPainterPath>
#include <QPainter>
#include <QVector2D>
#include <QDebug>
namespace Ui {
class HistoryWidget;
}

class HistoryWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HistoryWidget(QWidget *parent = nullptr);
    ~HistoryWidget();
    void reload();

private slots:
    void showCharts();
    void showChart();
    void showCircle();
    void showBody();
    void pressBack();
    void setPointsPainter(QPainterPath*,int);
    void setReading();
private:
    Ui::HistoryWidget *ui;
    QPushButton* buttons[10];
    QFrame* points[24];
    QLabel* labels[24];
    std::array<std::pair<int, int>, 24> reading;
    void setPoints();
};

#endif // HISTORYWIDGET_H
