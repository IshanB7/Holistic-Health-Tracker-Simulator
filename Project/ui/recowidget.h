#ifndef RECOWIDGET_H
#define RECOWIDGET_H

#include <QWidget>
#include <QPushButton>


namespace Ui {
class RecoWidget;
}

class RecoWidget : public QWidget
{
    Q_OBJECT
//Its basic -no Comment JW
public:
    explicit RecoWidget(QWidget *parent = nullptr);
    ~RecoWidget();
    void reload();
    QString allAdvice(int);


private slots:
    void save();
    void cancel();



private:
    Ui::RecoWidget *ui;

};

#endif // RECOWIDGET_H
