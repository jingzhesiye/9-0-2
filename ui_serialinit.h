/********************************************************************************
** Form generated from reading UI file 'serialinit.ui'
**
** Created: Mon Oct 26 15:25:00 2015
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIALINIT_H
#define UI_SERIALINIT_H

#include <./SpecialUI/sizepbtn.h>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SerialInit
{
public:
    QGridLayout *gridLayout;
    QComboBox *cbox_SerialSelect;
    SizePbtn *pbtn_Sure;

    void setupUi(QWidget *SerialInit)
    {
        if (SerialInit->objectName().isEmpty())
            SerialInit->setObjectName(QString::fromUtf8("SerialInit"));
        SerialInit->resize(400, 73);
        SerialInit->setStyleSheet(QString::fromUtf8("QComboBox\n"
"{\n"
"        border-image: url(:/pic/baseCboxBackGround.png);\n"
"}\n"
"\n"
"QComboBox::drop-down\n"
"{\n"
"     subcontrol-origin: padding;\n"
"     subcontrol-position: top right;\n"
"     width: 32px;\n"
" }\n"
"\n"
"QComboBox::down-arrow\n"
"{\n"
"        border-image: url(:/pic/CBoxArrow.png);\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"     border: 2px solid #32435E;\n"
"     selection-background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0 #506B79,\n"
"                                 stop: 1.0 #0D95A6);\n"
"/*\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0 #1B2534, stop: 0.4 #010101,\n"
"                                 stop: 0.5 #000101, stop: 1.0 #1F2B3C);\n"
"*/\n"
"/*\n"
"background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgba(134,170,255,60%), stop:1 rgba(255, 255, 255, 60%));\n"
"*/\n"
"        border-image: url(:/pic/TitleBar3.png);\n"
"\n"
"}"));
        gridLayout = new QGridLayout(SerialInit);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        cbox_SerialSelect = new QComboBox(SerialInit);
        cbox_SerialSelect->setObjectName(QString::fromUtf8("cbox_SerialSelect"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cbox_SerialSelect->sizePolicy().hasHeightForWidth());
        cbox_SerialSelect->setSizePolicy(sizePolicy);

        gridLayout->addWidget(cbox_SerialSelect, 0, 0, 1, 1);

        pbtn_Sure = new SizePbtn(SerialInit);
        pbtn_Sure->setObjectName(QString::fromUtf8("pbtn_Sure"));
        sizePolicy.setHeightForWidth(pbtn_Sure->sizePolicy().hasHeightForWidth());
        pbtn_Sure->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pbtn_Sure, 0, 1, 1, 1);


        retranslateUi(SerialInit);

        QMetaObject::connectSlotsByName(SerialInit);
    } // setupUi

    void retranslateUi(QWidget *SerialInit)
    {
        SerialInit->setWindowTitle(QApplication::translate("SerialInit", "Form", 0, QApplication::UnicodeUTF8));
        pbtn_Sure->setText(QApplication::translate("SerialInit", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SerialInit: public Ui_SerialInit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIALINIT_H
