/********************************************************************************
** Form generated from reading UI file 'radotechwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RADOTECHWIDGET_H
#define UI_RADOTECHWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RadotechWidget
{
public:
    QFrame *frame;
    QProgressBar *battery;
    QLabel *device;
    QPushButton *power;
    QPushButton *drain;
    QPushButton *charge;

    void setupUi(QWidget *RadotechWidget)
    {
        if (RadotechWidget->objectName().isEmpty())
            RadotechWidget->setObjectName(QString::fromUtf8("RadotechWidget"));
        RadotechWidget->resize(750, 700);
        frame = new QFrame(RadotechWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 750, 700));
        frame->setStyleSheet(QString::fromUtf8("background-color: gray;\n"
"border: 1px solid black;"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        battery = new QProgressBar(frame);
        battery->setObjectName(QString::fromUtf8("battery"));
        battery->setGeometry(QRect(690, 200, 40, 300));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(battery->sizePolicy().hasHeightForWidth());
        battery->setSizePolicy(sizePolicy);
        QFont font;
        font.setBold(true);
        font.setItalic(false);
        font.setKerning(true);
        battery->setFont(font);
        battery->setAutoFillBackground(false);
        battery->setStyleSheet(QString::fromUtf8("border: none;\n"
"background-color: black;\n"
"color: white;"));
        battery->setValue(100);
        battery->setAlignment(Qt::AlignmentFlag::AlignCenter);
        battery->setTextVisible(true);
        battery->setOrientation(Qt::Orientation::Vertical);
        battery->setInvertedAppearance(false);
        device = new QLabel(frame);
        device->setObjectName(QString::fromUtf8("device"));
        device->setGeometry(QRect(130, 70, 391, 611));
        device->setStyleSheet(QString::fromUtf8("border: 0px;"));
        device->setPixmap(QPixmap(QString::fromUtf8(":/images/device.png")));
        device->setScaledContents(true);
        power = new QPushButton(frame);
        power->setObjectName(QString::fromUtf8("power"));
        power->setGeometry(QRect(324, 117, 50, 50));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(power->sizePolicy().hasHeightForWidth());
        power->setSizePolicy(sizePolicy1);
        power->setMinimumSize(QSize(50, 50));
        power->setMaximumSize(QSize(50, 50));
        power->setCursor(QCursor(Qt::PointingHandCursor));
        power->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        power->setStyleSheet(QString::fromUtf8("border: 0px;\n"
"background-color: transparent;\n"
"padding-top: 50px;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/power.png"), QSize(), QIcon::Normal, QIcon::Off);
        power->setIcon(icon);
        power->setIconSize(QSize(321, 321));
        drain = new QPushButton(frame);
        drain->setObjectName(QString::fromUtf8("drain"));
        drain->setGeometry(QRect(70, 50, 100, 32));
        charge = new QPushButton(frame);
        charge->setObjectName(QString::fromUtf8("charge"));
        charge->setGeometry(QRect(70, 140, 100, 32));

        retranslateUi(RadotechWidget);

        QMetaObject::connectSlotsByName(RadotechWidget);
    } // setupUi

    void retranslateUi(QWidget *RadotechWidget)
    {
        RadotechWidget->setWindowTitle(QCoreApplication::translate("RadotechWidget", "Form", nullptr));
        device->setText(QString());
        power->setText(QString());
        drain->setText(QCoreApplication::translate("RadotechWidget", "drain", nullptr));
        charge->setText(QCoreApplication::translate("RadotechWidget", "charge", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RadotechWidget: public Ui_RadotechWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RADOTECHWIDGET_H
