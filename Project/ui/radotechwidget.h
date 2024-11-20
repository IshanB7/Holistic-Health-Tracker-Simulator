#ifndef RADOTECHWIDGET_H
#define RADOTECHWIDGET_H

#include <QWidget>
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

private slots:
    void decreaseBattery();
    void togglePower();
    void drainBattery();
    void chargeBattery();

private:
    Ui::RadotechWidget *ui;
    Radotech radotech;
    void initAll();
};

#endif // RADOTECHWIDGET_H
