/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *save_exit_btn;
    QPushButton *left_btn;
    QPushButton *down_btn;
    QPushButton *right_btn;
    QPushButton *up_btn;
    QPushButton *exit_btn;
    QPushButton *stop_btn;
    QLabel *label;
    QLabel *score_label;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(501, 302);
        Widget->setMinimumSize(QSize(0, 0));
        Widget->setMaximumSize(QSize(501, 302));
        Widget->setStyleSheet(QStringLiteral("background-color: rgb(0, 121, 0);"));
        save_exit_btn = new QPushButton(Widget);
        save_exit_btn->setObjectName(QStringLiteral("save_exit_btn"));
        save_exit_btn->setGeometry(QRect(350, 240, 51, 28));
        save_exit_btn->setStyleSheet(QStringLiteral("background-color: rgb(255, 170, 0);"));
        left_btn = new QPushButton(Widget);
        left_btn->setObjectName(QStringLiteral("left_btn"));
        left_btn->setGeometry(QRect(340, 140, 31, 31));
        left_btn->setStyleSheet(QStringLiteral("background-color: rgb(255, 170, 0);"));
        down_btn = new QPushButton(Widget);
        down_btn->setObjectName(QStringLiteral("down_btn"));
        down_btn->setGeometry(QRect(390, 180, 31, 31));
        down_btn->setStyleSheet(QStringLiteral("background-color: rgb(255, 170, 0);"));
        right_btn = new QPushButton(Widget);
        right_btn->setObjectName(QStringLiteral("right_btn"));
        right_btn->setGeometry(QRect(440, 140, 31, 31));
        right_btn->setStyleSheet(QStringLiteral("background-color: rgb(255, 170, 0);"));
        up_btn = new QPushButton(Widget);
        up_btn->setObjectName(QStringLiteral("up_btn"));
        up_btn->setGeometry(QRect(390, 100, 31, 31));
        up_btn->setStyleSheet(QStringLiteral("background-color: rgb(255, 170, 0);"));
        exit_btn = new QPushButton(Widget);
        exit_btn->setObjectName(QStringLiteral("exit_btn"));
        exit_btn->setGeometry(QRect(420, 240, 51, 28));
        exit_btn->setStyleSheet(QStringLiteral("background-color: rgb(255, 170, 0);"));
        stop_btn = new QPushButton(Widget);
        stop_btn->setObjectName(QStringLiteral("stop_btn"));
        stop_btn->setGeometry(QRect(380, 140, 51, 31));
        stop_btn->setStyleSheet(QStringLiteral("background-color: rgb(255, 170, 0);"));
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(360, 30, 61, 41));
        label->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font: 75 italic 12pt \"Times New Roman\";"));
        score_label = new QLabel(Widget);
        score_label->setObjectName(QStringLiteral("score_label"));
        score_label->setGeometry(QRect(430, 40, 61, 41));
        score_label->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font: 75 italic 9pt \"Times New Roman\";"));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        save_exit_btn->setText(QApplication::translate("Widget", "menu", Q_NULLPTR));
        left_btn->setText(QApplication::translate("Widget", "\342\206\220", Q_NULLPTR));
        down_btn->setText(QApplication::translate("Widget", "\342\206\223", Q_NULLPTR));
        right_btn->setText(QApplication::translate("Widget", "\342\206\222", Q_NULLPTR));
        up_btn->setText(QApplication::translate("Widget", "\342\206\221", Q_NULLPTR));
        exit_btn->setText(QApplication::translate("Widget", "exit", Q_NULLPTR));
        stop_btn->setText(QApplication::translate("Widget", "start", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "<html><head/><body><p>score:</p></body></html>", Q_NULLPTR));
        score_label->setText(QApplication::translate("Widget", "<html><head/><body><p><span style=\" font-size:12pt;\">0</span><br/></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
