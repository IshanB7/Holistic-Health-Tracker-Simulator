#ifndef HISTORYWIDGET_H
#define HISTORYWIDGET_H

#include <QWidget>
#include <QPushButton>

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
    // void showBody();
    void pressBack();

private:
    Ui::HistoryWidget *ui;
    QPushButton* buttons[10];
};

#endif // HISTORYWIDGET_H
