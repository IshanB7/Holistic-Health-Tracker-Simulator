#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "App.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    app(App())
{
    ui->setupUi(this);
    ui->tabWidget->setCurrentIndex(0);
    ui->measure->reload();
    connect(ui->tabWidget, SIGNAL (currentChanged(int)), this, SLOT (reloadTab(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::reloadTab(int i) {
    ui->measure->reload();
    if (i == 1) ui->profiles->reload();
    else if (i == 2) ui->history->reload();
    else if(i==3) ui->recomen->reload();
}
