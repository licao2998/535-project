/********************************************************************************
** Form generated from reading UI file 'infowidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFOWIDGET_H
#define UI_INFOWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InfoWidget
{
public:
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *InfoWidget)
    {
        if (InfoWidget->objectName().isEmpty())
            InfoWidget->setObjectName(QStringLiteral("InfoWidget"));
        InfoWidget->resize(200, 150);
        InfoWidget->setMinimumSize(QSize(200, 150));
        InfoWidget->setMaximumSize(QSize(200, 150));
        InfoWidget->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label = new QLabel(InfoWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 40, 111, 31));
        pushButton = new QPushButton(InfoWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(50, 100, 93, 28));
        pushButton->setStyleSheet(QStringLiteral(""));

        retranslateUi(InfoWidget);

        QMetaObject::connectSlotsByName(InfoWidget);
    } // setupUi

    void retranslateUi(QWidget *InfoWidget)
    {
        InfoWidget->setWindowTitle(QApplication::translate("InfoWidget", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("InfoWidget", "<html><head/><body><p>GAME OVER</p></body></html>", Q_NULLPTR));
        pushButton->setText(QApplication::translate("InfoWidget", "OK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class InfoWidget: public Ui_InfoWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOWIDGET_H
