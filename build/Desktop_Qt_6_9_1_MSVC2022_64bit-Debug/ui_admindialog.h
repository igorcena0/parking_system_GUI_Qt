/********************************************************************************
** Form generated from reading UI file 'admindialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINDIALOG_H
#define UI_ADMINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_AdminDialog
{
public:
    QDialogButtonBox *buttonBox;
    QPushButton *btnZmienStawke;
    QPushButton *btnDodajAbonenta;
    QPushButton *pushButton;
    QPushButton *btnPokazZajete;
    QPushButton *btnPokazWolne;
    QPushButton *btnPokazHistorie;
    QTextEdit *textEditWynik;
    QLabel *label;

    void setupUi(QDialog *AdminDialog)
    {
        if (AdminDialog->objectName().isEmpty())
            AdminDialog->setObjectName("AdminDialog");
        AdminDialog->resize(548, 352);
        AdminDialog->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        buttonBox = new QDialogButtonBox(AdminDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(320, 310, 201, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        btnZmienStawke = new QPushButton(AdminDialog);
        btnZmienStawke->setObjectName("btnZmienStawke");
        btnZmienStawke->setGeometry(QRect(300, 40, 211, 31));
        QFont font;
        font.setPointSize(11);
        btnZmienStawke->setFont(font);
        btnZmienStawke->setStyleSheet(QString::fromUtf8(""));
        btnDodajAbonenta = new QPushButton(AdminDialog);
        btnDodajAbonenta->setObjectName("btnDodajAbonenta");
        btnDodajAbonenta->setGeometry(QRect(300, 90, 211, 41));
        btnDodajAbonenta->setFont(font);
        pushButton = new QPushButton(AdminDialog);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(300, 150, 211, 41));
        pushButton->setFont(font);
        btnPokazZajete = new QPushButton(AdminDialog);
        btnPokazZajete->setObjectName("btnPokazZajete");
        btnPokazZajete->setGeometry(QRect(20, 160, 201, 41));
        btnPokazZajete->setFont(font);
        btnPokazWolne = new QPushButton(AdminDialog);
        btnPokazWolne->setObjectName("btnPokazWolne");
        btnPokazWolne->setGeometry(QRect(20, 218, 201, 41));
        btnPokazWolne->setFont(font);
        btnPokazHistorie = new QPushButton(AdminDialog);
        btnPokazHistorie->setObjectName("btnPokazHistorie");
        btnPokazHistorie->setGeometry(QRect(20, 278, 201, 41));
        btnPokazHistorie->setFont(font);
        textEditWynik = new QTextEdit(AdminDialog);
        textEditWynik->setObjectName("textEditWynik");
        textEditWynik->setGeometry(QRect(240, 210, 271, 91));
        textEditWynik->setReadOnly(true);
        label = new QLabel(AdminDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 50, 261, 61));
        QFont font1;
        font1.setPointSize(16);
        label->setFont(font1);

        retranslateUi(AdminDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, AdminDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AdminDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AdminDialog);
    } // setupUi

    void retranslateUi(QDialog *AdminDialog)
    {
        AdminDialog->setWindowTitle(QCoreApplication::translate("AdminDialog", "Dialog", nullptr));
        btnZmienStawke->setText(QCoreApplication::translate("AdminDialog", "Zmiana stawki", nullptr));
        btnDodajAbonenta->setText(QCoreApplication::translate("AdminDialog", "Dodaj abonenta (nr rej)", nullptr));
        pushButton->setText(QCoreApplication::translate("AdminDialog", "Usu\305\204 abonenta (nr rej)", nullptr));
        btnPokazZajete->setText(QCoreApplication::translate("AdminDialog", "Poka\305\274 zaj\304\231te miejsca", nullptr));
        btnPokazWolne->setText(QCoreApplication::translate("AdminDialog", "Poka\305\274 wolne miejsca", nullptr));
        btnPokazHistorie->setText(QCoreApplication::translate("AdminDialog", "Poka\305\274 histori\304\231 bilet\303\263w", nullptr));
        label->setText(QCoreApplication::translate("AdminDialog", "Panel Administratora", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminDialog: public Ui_AdminDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINDIALOG_H
