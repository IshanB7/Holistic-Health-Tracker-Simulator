#ifndef MEASUREWIDGET_H
#define MEASUREWIDGET_H

#include <QWidget>

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

private:
    Ui::MeasureWidget *ui;
};

#endif // MEASUREWIDGET_H
