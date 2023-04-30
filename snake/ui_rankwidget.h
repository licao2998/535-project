/********************************************************************************
** Form generated from reading UI file 'rankwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RANKWIDGET_H
#define UI_RANKWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RankWidget
{
public:
    QTreeWidget *treeWidget;
    QPushButton *pushButton;

    void setupUi(QWidget *RankWidget)
    {
        if (RankWidget->objectName().isEmpty())
            RankWidget->setObjectName(QStringLiteral("RankWidget"));
        RankWidget->resize(300, 180);
        treeWidget = new QTreeWidget(RankWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setGeometry(QRect(0, 0, 300, 180));
        treeWidget->header()->setDefaultSectionSize(150);
        pushButton = new QPushButton(RankWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(90, 140, 93, 28));

        retranslateUi(RankWidget);

        QMetaObject::connectSlotsByName(RankWidget);
    } // setupUi

    void retranslateUi(QWidget *RankWidget)
    {
        RankWidget->setWindowTitle(QApplication::translate("RankWidget", "Form", Q_NULLPTR));
        pushButton->setText(QApplication::translate("RankWidget", "OK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RankWidget: public Ui_RankWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RANKWIDGET_H
