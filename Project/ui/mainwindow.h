#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "App.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void reloadTab(int);

private:
    Ui::MainWindow *ui;
    App app;
};
#endif // MAINWINDOW_H
