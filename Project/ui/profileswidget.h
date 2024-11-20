#ifndef PROFILESWIDGET_H
#define PROFILESWIDGET_H

#include <QWidget>
#include <QPushButton>
#include "Profile.h"
#include <vector>

namespace Ui {
class ProfilesWidget;
}

class ProfilesWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ProfilesWidget(QWidget *parent = nullptr);
    ~ProfilesWidget();
    void reload();

private slots:
    void edit();

private:
    Ui::ProfilesWidget *ui;
    QPushButton* buttons[6];
    std::vector<Profile*> users;
};

#endif // PROFILESWIDGET_H
