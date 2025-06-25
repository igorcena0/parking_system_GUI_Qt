/********************************************************************************
** Form generated from reading UI file 'startdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTDIALOG_H
#define UI_STARTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_StartDialog
{
public:
    QLabel *label;
    QLabel *label_2;
    QPushButton *btnStart;
    QLineEdit *lineEditLiczbaMiejsc;
    QLineEdit *lineEditStawka;

    void setupUi(QDialog *StartDialog)
    {
        if (StartDialog->objectName().isEmpty())
            StartDialog->setObjectName("StartDialog");
        StartDialog->resize(433, 310);
        StartDialog->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #f0f0f0;\n"
"    border: 1px solid #aaa;\n"
"    border-radius: 5px;\n"
"    padding: 6px 12px;\n"
"}\n"
"\n"
"QTextEdit {\n"
"    background-color: #fff;\n"
"    border: 1px solid #ccc;\n"
"}\n"
""));
        label = new QLabel(StartDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 90, 171, 41));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        label_2 = new QLabel(StartDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(50, 130, 241, 41));
        label_2->setFont(font);
        btnStart = new QPushButton(StartDialog);
        btnStart->setObjectName("btnStart");
        btnStart->setGeometry(QRect(150, 220, 131, 51));
        QFont font1;
        font1.setPointSize(12);
        btnStart->setFont(font1);
        lineEditLiczbaMiejsc = new QLineEdit(StartDialog);
        lineEditLiczbaMiejsc->setObjectName("lineEditLiczbaMiejsc");
        lineEditLiczbaMiejsc->setGeometry(QRect(320, 90, 51, 31));
        lineEditStawka = new QLineEdit(StartDialog);
        lineEditStawka->setObjectName("lineEditStawka");
        lineEditStawka->setGeometry(QRect(320, 135, 51, 31));
        lineEditStawka->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #f0f0f0;\n"
"    border: 1px solid #aaa;\n"
"    border-radius: 5px;\n"
"    padding: 6px 12px;\n"
"}\n"
"\n"
"QTextEdit {\n"
"    background-color: #fff;\n"
"    border: 1px solid #ccc;\n"
"}\n"
""));

        retranslateUi(StartDialog);

        QMetaObject::connectSlotsByName(StartDialog);
    } // setupUi

    void retranslateUi(QDialog *StartDialog)
    {
        StartDialog->setWindowTitle(QCoreApplication::translate("StartDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("StartDialog", "Liczba miejsc:", nullptr));
        label_2->setText(QCoreApplication::translate("StartDialog", "Stawka za  godzin\304\231 (z\305\202):", nullptr));
        btnStart->setText(QCoreApplication::translate("StartDialog", "Rozpocznij", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartDialog: public Ui_StartDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTDIALOG_H
