/********************************************************************************
** Form generated from reading UI file 'choose.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSE_H
#define UI_CHOOSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_choose
{
public:
    QLabel *label;
    QLabel *label_2;
    QGroupBox *groupBox;
    QRadioButton *map1Rb;
    QRadioButton *map2Rb;
    QRadioButton *map3Rb;
    QGroupBox *groupBox_2;
    QRadioButton *easyRb;
    QRadioButton *medRb;
    QRadioButton *hardRb;
    QPushButton *startbtn;
    QPushButton *retBtn;

    void setupUi(QWidget *choose)
    {
        if (choose->objectName().isEmpty())
            choose->setObjectName(QStringLiteral("choose"));
        choose->resize(499, 304);
        choose->setMinimumSize(QSize(0, 0));
        choose->setMaximumSize(QSize(800, 480));
        choose->setAutoFillBackground(false);
        label = new QLabel(choose);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 60, 72, 15));
        label_2 = new QLabel(choose);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 160, 72, 15));
        groupBox = new QGroupBox(choose);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(120, 20, 351, 80));
        groupBox->setAutoFillBackground(true);
        map1Rb = new QRadioButton(groupBox);
        map1Rb->setObjectName(QStringLiteral("map1Rb"));
        map1Rb->setGeometry(QRect(0, 40, 115, 19));
        map2Rb = new QRadioButton(groupBox);
        map2Rb->setObjectName(QStringLiteral("map2Rb"));
        map2Rb->setGeometry(QRect(100, 40, 115, 19));
        map3Rb = new QRadioButton(groupBox);
        map3Rb->setObjectName(QStringLiteral("map3Rb"));
        map3Rb->setGeometry(QRect(200, 40, 115, 19));
        groupBox_2 = new QGroupBox(choose);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(120, 130, 351, 80));
        easyRb = new QRadioButton(groupBox_2);
        easyRb->setObjectName(QStringLiteral("easyRb"));
        easyRb->setGeometry(QRect(0, 30, 115, 19));
        medRb = new QRadioButton(groupBox_2);
        medRb->setObjectName(QStringLiteral("medRb"));
        medRb->setGeometry(QRect(100, 30, 115, 19));
        hardRb = new QRadioButton(groupBox_2);
        hardRb->setObjectName(QStringLiteral("hardRb"));
        hardRb->setGeometry(QRect(200, 30, 115, 19));
        startbtn = new QPushButton(choose);
        startbtn->setObjectName(QStringLiteral("startbtn"));
        startbtn->setGeometry(QRect(100, 240, 93, 28));
        retBtn = new QPushButton(choose);
        retBtn->setObjectName(QStringLiteral("retBtn"));
        retBtn->setGeometry(QRect(260, 240, 93, 28));

        retranslateUi(choose);

        QMetaObject::connectSlotsByName(choose);
    } // setupUi

    void retranslateUi(QWidget *choose)
    {
        choose->setWindowTitle(QApplication::translate("choose", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("choose", "Map:", Q_NULLPTR));
        label_2->setText(QApplication::translate("choose", "Level:", Q_NULLPTR));
        groupBox->setTitle(QString());
        map1Rb->setText(QApplication::translate("choose", "map1", Q_NULLPTR));
        map2Rb->setText(QApplication::translate("choose", "map2", Q_NULLPTR));
        map3Rb->setText(QApplication::translate("choose", "map3", Q_NULLPTR));
        groupBox_2->setTitle(QString());
        easyRb->setText(QApplication::translate("choose", "easy", Q_NULLPTR));
        medRb->setText(QApplication::translate("choose", "medium", Q_NULLPTR));
        hardRb->setText(QApplication::translate("choose", "hard", Q_NULLPTR));
        startbtn->setText(QApplication::translate("choose", "start", Q_NULLPTR));
        retBtn->setText(QApplication::translate("choose", "back", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class choose: public Ui_choose {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSE_H
