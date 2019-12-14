/********************************************************************************
** Form generated from reading UI file 'shortcuthelper.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHORTCUTHELPER_H
#define UI_SHORTCUTHELPER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShortcutHelper
{
public:
    QListWidget *listWidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QListWidget *listWidget_2;
    QListWidget *listWidget_3;

    void setupUi(QWidget *ShortcutHelper)
    {
        if (ShortcutHelper->objectName().isEmpty())
            ShortcutHelper->setObjectName(QString::fromUtf8("ShortcutHelper"));
        ShortcutHelper->resize(1200, 800);
        listWidget = new QListWidget(ShortcutHelper);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(30, 50, 291, 691));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(8);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\271\346\255\243\351\273\221\344\275\223\347\256\200\344\275\223"));
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        font.setKerning(true);
        listWidget->setFont(font);
        listWidget->setMouseTracking(false);
        listWidget->setFocusPolicy(Qt::NoFocus);
        listWidget->setContextMenuPolicy(Qt::DefaultContextMenu);
        listWidget->setLayoutDirection(Qt::LeftToRight);
        listWidget->setFrameShape(QFrame::NoFrame);
        listWidget->setFrameShadow(QFrame::Plain);
        listWidget->setLineWidth(0);
        listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        listWidget->setAutoScroll(true);
        listWidget->setAutoScrollMargin(12);
        listWidget->setProperty("showDropIndicator", QVariant(false));
        listWidget->setMovement(QListView::Free);
        label = new QLabel(ShortcutHelper);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(1050, 760, 101, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\226\271\346\255\243\351\273\221\344\275\223\347\256\200\344\275\223"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setWeight(50);
        label->setFont(font1);
        label->setFocusPolicy(Qt::NoFocus);
        label_2 = new QLabel(ShortcutHelper);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(1070, 170, 81, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\226\271\346\255\243\351\273\221\344\275\223\347\256\200\344\275\223"));
        font2.setPointSize(12);
        label_2->setFont(font2);
        label_3 = new QLabel(ShortcutHelper);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(1050, 690, 151, 41));
        label_3->setFont(font2);
        label_4 = new QLabel(ShortcutHelper);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(1050, 730, 151, 31));
        label_4->setFont(font2);
        label_5 = new QLabel(ShortcutHelper);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(460, 10, 801, 31));
        label_5->setFont(font2);
        label_5->setLayoutDirection(Qt::LeftToRight);
        listWidget_2 = new QListWidget(ShortcutHelper);
        listWidget_2->setObjectName(QString::fromUtf8("listWidget_2"));
        listWidget_2->setGeometry(QRect(350, 50, 291, 691));
        sizePolicy.setHeightForWidth(listWidget_2->sizePolicy().hasHeightForWidth());
        listWidget_2->setSizePolicy(sizePolicy);
        listWidget_2->setFont(font);
        listWidget_2->setMouseTracking(false);
        listWidget_2->setFocusPolicy(Qt::NoFocus);
        listWidget_2->setContextMenuPolicy(Qt::DefaultContextMenu);
        listWidget_2->setLayoutDirection(Qt::LeftToRight);
        listWidget_2->setFrameShape(QFrame::NoFrame);
        listWidget_2->setFrameShadow(QFrame::Plain);
        listWidget_2->setLineWidth(0);
        listWidget_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget_2->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        listWidget_2->setAutoScroll(true);
        listWidget_2->setAutoScrollMargin(12);
        listWidget_2->setProperty("showDropIndicator", QVariant(false));
        listWidget_2->setMovement(QListView::Free);
        listWidget_3 = new QListWidget(ShortcutHelper);
        listWidget_3->setObjectName(QString::fromUtf8("listWidget_3"));
        listWidget_3->setGeometry(QRect(670, 50, 321, 691));
        sizePolicy.setHeightForWidth(listWidget_3->sizePolicy().hasHeightForWidth());
        listWidget_3->setSizePolicy(sizePolicy);
        listWidget_3->setFont(font);
        listWidget_3->setMouseTracking(false);
        listWidget_3->setFocusPolicy(Qt::NoFocus);
        listWidget_3->setContextMenuPolicy(Qt::DefaultContextMenu);
        listWidget_3->setLayoutDirection(Qt::LeftToRight);
        listWidget_3->setFrameShape(QFrame::NoFrame);
        listWidget_3->setFrameShadow(QFrame::Plain);
        listWidget_3->setLineWidth(0);
        listWidget_3->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget_3->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget_3->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        listWidget_3->setAutoScroll(true);
        listWidget_3->setAutoScrollMargin(12);
        listWidget_3->setProperty("showDropIndicator", QVariant(false));
        listWidget_3->setMovement(QListView::Free);

        retranslateUi(ShortcutHelper);

        QMetaObject::connectSlotsByName(ShortcutHelper);
    } // setupUi

    void retranslateUi(QWidget *ShortcutHelper)
    {
        ShortcutHelper->setWindowTitle(QCoreApplication::translate("ShortcutHelper", "ShortcutHelper", nullptr));
        label->setText(QCoreApplication::translate("ShortcutHelper", "\344\275\234\350\200\205:liuser", nullptr));
        label_2->setText(QCoreApplication::translate("ShortcutHelper", "\344\277\235\347\225\231\345\214\272", nullptr));
        label_3->setText(QCoreApplication::translate("ShortcutHelper", "QQ735083049", nullptr));
        label_4->setText(QCoreApplication::translate("ShortcutHelper", "\346\234\211\351\227\256\351\242\230\346\254\242\350\277\216\345\217\215\351\246\210", nullptr));
        label_5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ShortcutHelper: public Ui_ShortcutHelper {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHORTCUTHELPER_H
