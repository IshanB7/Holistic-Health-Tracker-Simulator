#ifndef MEASUREWIDGET_H
#define MEASUREWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QFrame>

namespace Ui {
class MeasureWidget;
}

class MeasureWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MeasureWidget(QWidget *parent = nullptr);
    ~MeasureWidget();
    void reload();

private slots:
    void pressOk();
    void pressGo();
    void pressMeasure();
    void pressDone();
    void refresh();
    void showNextPoint();

private:
    Ui::MeasureWidget *ui;
    QTimer measureTimeout; //allows to set in constructor
    QTimer measureTimer;
    void initMeasure();
    void setPoints();
    QFrame* points[24];
    std::array<int, 24> reading; //record from getReading and display on graph
    int pointNum;
};

#endif // MEASUREWIDGET_H
