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
    void save();
    void deleteProfile();
    void addProfile();
    void select();
    void cancel();
    void checkNums();

private:
    Ui::ProfilesWidget *ui;
    QPushButton* buttons[6];
    QPushButton* currentButtons[5];
    std::vector<Profile*> users;
    Profile* user;
};

#endif // PROFILESWIDGET_H
