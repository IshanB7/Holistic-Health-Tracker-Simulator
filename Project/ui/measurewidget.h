#ifndef MEASUREWIDGET_H
#define MEASUREWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QFrame>
#include <QString>

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
    QTimer measureTimeout;
    QTimer measureTimer;
    void initMeasure();
    void setPoints();
    QFrame* points[24];
    std::string pointNames[12];
    std::string pointSides[2];
    std::array<int, 24> reading;
    int pointNum;
    void sendNextPoint();
};

#endif // MEASUREWIDGET_H
