#ifndef RADOTECHWIDGET_H
#define RADOTECHWIDGET_H

#include <QWidget>
#include <QTimer>
#include "Radotech.h"

namespace Ui {
class RadotechWidget;
}

class RadotechWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RadotechWidget(QWidget *parent = nullptr);
    ~RadotechWidget();
    void setPointLabel(std::string);


private slots:
    void decreaseBattery();
    void togglePower();
    void drainBattery();
    void chargeBattery();
    void readPoint();
    void simulate();

private:
    Ui::RadotechWidget *ui;
    Radotech radotech;
    QTimer batteryDrainTimer; // Timer for draining the battery
    void setColor();

};

#endif // RADOTECHWIDGET_H
