#include "radotechwidget.h"
#include "ui_radotechwidget.h"
#include <QGraphicsColorizeEffect>
#include <QColor>

RadotechWidget::RadotechWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RadotechWidget)
    , radotech(Radotech(this))
{
    ui->setupUi(this);
    ui->battery->setValue(radotech.battery);
    connect(ui->power, SIGNAL (released()), this, SLOT (togglePower()));
    connect(ui->drain, SIGNAL (released()), this, SLOT (drainBattery()));
    connect(ui->charge, SIGNAL (released()), this, SLOT (chargeBattery()));
    connect(ui->pointButton, SIGNAL (released()), this, SLOT (readPoint()));
    connect(ui->simulateButton, SIGNAL (released()), this, SLOT (simulate()));
    // Set up the timer to drain the battery
    connect(&batteryDrainTimer, SIGNAL (timeout()), this, SLOT (decreaseBattery()));
    batteryDrainTimer.setInterval(2000); // Bettery will drain by 1% every 2 seconds
    batteryDrainTimer.start();
}

RadotechWidget::~RadotechWidget()
{
    delete ui;
}
/*
    decreaseBattery: update the battery value
    togglePower: turns  the wdiget on and changes the colour to reflect it
    drainBattery: slowly decrease the battery pertenceage when it is one
    chargeBattery: set charge to 100%
    toggelSkin: if widget is touching the skin
*/
void RadotechWidget::decreaseBattery() {
    if (radotech.isOn && radotech.battery > 0) {
        radotech.battery -= 1;
        ui->battery->setValue(radotech.battery);
    }

    if (radotech.battery == 0) togglePower();
}

void RadotechWidget::togglePower() {
    if (!radotech.isOn && radotech.battery > 0) {
        radotech.isOn = true;
    } else {
        radotech.isOn = false;
        radotech.onSkin = false;
    }

    setColor();
}

void RadotechWidget::drainBattery() {
    if (radotech.battery > 10) {
        radotech.battery = 10;
        ui->battery->setValue(10);
        setColor();
    }
}

void RadotechWidget::chargeBattery() {
    radotech.battery = 100;
    ui->battery->setValue(100);
    setColor();
}

void RadotechWidget::setColor() {
    QGraphicsColorizeEffect* effect = new QGraphicsColorizeEffect();
    if (radotech.isOn && radotech.battery <= 10) {
        effect->setColor(QColor(255, 0, 0));
    } else if (radotech.isOn) {
        effect->setColor(QColor(255, 122, 0));
    } else {
        effect->setColor(QColor(0,0,0));
    }
    ui->power->setGraphicsEffect(effect);
}

void RadotechWidget::setPointLabel(std::string pointName) {
    ui->pointButton->setText(QString::fromStdString(pointName));
    ui->pointButton->setEnabled(pointName != "");
}

void RadotechWidget::readPoint() { radotech.onSkin = true; }

void RadotechWidget::simulate() {
    radotech.simulate = ui->simulateButton->isChecked();
    radotech.onSkin = false;
}
