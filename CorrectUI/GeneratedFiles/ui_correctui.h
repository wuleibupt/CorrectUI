/********************************************************************************
** Form generated from reading UI file 'correctui.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CORRECTUI_H
#define UI_CORRECTUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CorrectUIClass
{
public:
    QWidget *centralWidget;
    QFrame *frame;
    QPushButton *clearButtom;
    QPushButton *loadImageButton;
    QListWidget *imageNameList;
    QFrame *frame_2;
    QPushButton *loadParameterButton;
    QLineEdit *pathEdit;
    QPushButton *correctButton;
    QLabel *showImageLabel;
    QLabel *showImageLabel1;
    QLabel *label;
    QLineEdit *parmEdit;

    void setupUi(QMainWindow *CorrectUIClass)
    {
        if (CorrectUIClass->objectName().isEmpty())
            CorrectUIClass->setObjectName(QStringLiteral("CorrectUIClass"));
        CorrectUIClass->resize(1395, 571);
        centralWidget = new QWidget(CorrectUIClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(10, 10, 211, 331));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        clearButtom = new QPushButton(frame);
        clearButtom->setObjectName(QStringLiteral("clearButtom"));
        clearButtom->setGeometry(QRect(10, 10, 71, 23));
        loadImageButton = new QPushButton(frame);
        loadImageButton->setObjectName(QStringLiteral("loadImageButton"));
        loadImageButton->setGeometry(QRect(130, 10, 75, 23));
        imageNameList = new QListWidget(frame);
        imageNameList->setObjectName(QStringLiteral("imageNameList"));
        imageNameList->setGeometry(QRect(10, 40, 191, 281));
        frame_2 = new QFrame(centralWidget);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(10, 340, 211, 81));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        loadParameterButton = new QPushButton(frame_2);
        loadParameterButton->setObjectName(QStringLiteral("loadParameterButton"));
        loadParameterButton->setGeometry(QRect(10, 10, 191, 23));
        pathEdit = new QLineEdit(frame_2);
        pathEdit->setObjectName(QStringLiteral("pathEdit"));
        pathEdit->setGeometry(QRect(10, 50, 191, 20));
        correctButton = new QPushButton(centralWidget);
        correctButton->setObjectName(QStringLiteral("correctButton"));
        correctButton->setGeometry(QRect(20, 470, 181, 61));
        showImageLabel = new QLabel(centralWidget);
        showImageLabel->setObjectName(QStringLiteral("showImageLabel"));
        showImageLabel->setGeometry(QRect(230, 10, 580, 540));
        showImageLabel->setFrameShape(QFrame::Box);
        showImageLabel1 = new QLabel(centralWidget);
        showImageLabel1->setObjectName(QStringLiteral("showImageLabel1"));
        showImageLabel1->setGeometry(QRect(830, 10, 580, 540));
        showImageLabel1->setFrameShape(QFrame::Box);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 431, 61, 21));
        parmEdit = new QLineEdit(centralWidget);
        parmEdit->setObjectName(QStringLiteral("parmEdit"));
        parmEdit->setGeometry(QRect(82, 430, 121, 20));
        CorrectUIClass->setCentralWidget(centralWidget);

        retranslateUi(CorrectUIClass);

        QMetaObject::connectSlotsByName(CorrectUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *CorrectUIClass)
    {
        CorrectUIClass->setWindowTitle(QApplication::translate("CorrectUIClass", "CorrectUI", 0));
        clearButtom->setText(QApplication::translate("CorrectUIClass", "\346\270\205\347\251\272", 0));
        loadImageButton->setText(QApplication::translate("CorrectUIClass", "\345\257\274\345\205\245\345\233\276\345\203\217", 0));
        loadParameterButton->setText(QApplication::translate("CorrectUIClass", "\345\257\274\345\205\245\350\247\222\345\272\246\345\217\202\346\225\260", 0));
        correctButton->setText(QApplication::translate("CorrectUIClass", "\347\237\253\346\255\243", 0));
        showImageLabel->setText(QString());
        showImageLabel1->setText(QString());
        label->setText(QApplication::translate("CorrectUIClass", "\345\233\276\345\203\217\347\263\273\346\225\260a", 0));
    } // retranslateUi

};

namespace Ui {
    class CorrectUIClass: public Ui_CorrectUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CORRECTUI_H
