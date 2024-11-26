#include "historywidget.h"
#include "ui_historywidget.h"
#include "App.h"
#include <QString>

HistoryWidget::HistoryWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HistoryWidget)
{
    ui->setupUi(this);

    buttons[0] = ui->reading1;
    buttons[1] = ui->reading2;
    buttons[2] = ui->reading3;
    buttons[3] = ui->reading4;
    buttons[4] = ui->reading5;
    buttons[5] = ui->reading6;
    buttons[6] = ui->reading7;
    buttons[7] = ui->reading8;
    buttons[8] = ui->reading9;
    buttons[9] = ui->reading10;

    for (int i = 0; i < 10; ++i) {
        connect(buttons[i], SIGNAL (released()), this, SLOT (showCharts()));
    }

    connect(ui->chartButton, SIGNAL (released()), this, SLOT (showChart()));
    connect(ui->circleButton, SIGNAL (released()), this, SLOT (showCircle()));
    connect(ui->backButton, SIGNAL (released()), this, SLOT (pressBack()));

    ui->chartLabel->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->circleLabel->setAttribute(Qt::WA_TransparentForMouseEvents);
}

HistoryWidget::~HistoryWidget()
{
    delete ui;
}

void HistoryWidget::reload() {
    ui->stackedWidget->setCurrentIndex(0);
    int i = 0;

    if (App::user() != nullptr) {
        for (const std::string& time : App::user()->readingTimes) {
            QString text = QString::fromStdString(time);
            buttons[i]->setText(text);
            buttons[i++]->setVisible(true);
        }
    }

    for (; i < 10; ++i) { buttons[i]->setVisible(false); }
    showChart();
}

void HistoryWidget::showCharts() {
    ui->stackedWidget->setCurrentIndex(1);
}

void HistoryWidget::showChart() {
    ui->chartLabel->setVisible(true);
    ui->circleLabel->setVisible(false);
}

void HistoryWidget::showCircle() {
    ui->circleLabel->setVisible(true);
    ui->chartLabel->setVisible(false);
}

void HistoryWidget::pressBack() { reload(); }
