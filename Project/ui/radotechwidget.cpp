#include "radotechwidget.h"
#include "ui_radotechwidget.h"
#include <QTimer>
#include <QGraphicsColorizeEffect>
#include <QColor>

RadotechWidget::RadotechWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RadotechWidget)
    , radotech(Radotech())
{
    ui->setupUi(this);
    initAll();
    connect(ui->power, SIGNAL (released()), this, SLOT (togglePower()));
    connect(ui->drain, SIGNAL (released()), this, SLOT (drainBattery()));
    connect(ui->charge, SIGNAL (released()), this, SLOT (chargeBattery()));
}

void RadotechWidget::initAll() {
    ui->battery->setValue(radotech.battery);
    QTimer* batteryTimer = new QTimer(this);
    connect(batteryTimer, SIGNAL (timeout()), this, SLOT (decreaseBattery()));
    batteryTimer->setInterval(2000);
    batteryTimer->start();
}

RadotechWidget::~RadotechWidget()
{
    delete ui;
}

void RadotechWidget::decreaseBattery() {
    if (radotech.isOn && radotech.battery > 0) {
        radotech.battery -= 1;
        ui->battery->setValue(radotech.battery);
    }

    if (radotech.battery == 0) togglePower();
}

void RadotechWidget::togglePower() {
    QGraphicsColorizeEffect* effect = new QGraphicsColorizeEffect();

    if (!radotech.isOn && radotech.battery > 0) {
        radotech.isOn = true;
        effect->setColor(QColor(255,122,0));
    } else {
        radotech.isOn = false;
        effect->setColor(QColor(0,0,0));
    }

    ui->power->setGraphicsEffect(effect);
}

void RadotechWidget::drainBattery() {
    if (radotech.battery > 1) {
        radotech.battery = 1;
        ui->battery->setValue(1);
    }
}

void RadotechWidget::chargeBattery() {
    radotech.battery = 100;
    ui->battery->setValue(100);
}
