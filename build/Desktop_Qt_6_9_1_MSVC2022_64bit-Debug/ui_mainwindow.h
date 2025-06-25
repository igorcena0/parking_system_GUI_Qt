/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *btnWjazd;
    QPushButton *btnPlatnosc;
    QPushButton *btnWyjazd;
    QPushButton *btnAdmin;
    QFrame *line;
    QTableWidget *tableMiejsca;
    QTextEdit *textStatusMain;
    QLabel *label;
    QLabel *labelZegar;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(643, 509);
        MainWindow->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #f0f0f0;\n"
"    border: 1px solid #aaa;\n"
"    border-radius: 5px;\n"
"    padding: 6px 12px;\n"
"}\n"
"\n"
"QTextEdit {\n"
"    background-color: #fff;\n"
"    border: 1px solid #ccc;\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        btnWjazd = new QPushButton(centralwidget);
        btnWjazd->setObjectName("btnWjazd");
        btnWjazd->setGeometry(QRect(360, 110, 211, 41));
        QFont font;
        font.setPointSize(12);
        btnWjazd->setFont(font);
        btnPlatnosc = new QPushButton(centralwidget);
        btnPlatnosc->setObjectName("btnPlatnosc");
        btnPlatnosc->setGeometry(QRect(360, 160, 211, 41));
        btnPlatnosc->setFont(font);
        btnWyjazd = new QPushButton(centralwidget);
        btnWyjazd->setObjectName("btnWyjazd");
        btnWyjazd->setGeometry(QRect(360, 210, 211, 41));
        btnWyjazd->setFont(font);
        btnAdmin = new QPushButton(centralwidget);
        btnAdmin->setObjectName("btnAdmin");
        btnAdmin->setGeometry(QRect(360, 260, 211, 41));
        btnAdmin->setFont(font);
        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setGeometry(QRect(70, 180, 118, 3));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        tableMiejsca = new QTableWidget(centralwidget);
        if (tableMiejsca->columnCount() < 2)
            tableMiejsca->setColumnCount(2);
        tableMiejsca->setObjectName("tableMiejsca");
        tableMiejsca->setGeometry(QRect(40, 190, 231, 251));
        tableMiejsca->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        tableMiejsca->setAlternatingRowColors(true);
        tableMiejsca->setSelectionMode(QAbstractItemView::SelectionMode::NoSelection);
        tableMiejsca->setColumnCount(2);
        tableMiejsca->verticalHeader()->setVisible(false);
        textStatusMain = new QTextEdit(centralwidget);
        textStatusMain->setObjectName("textStatusMain");
        textStatusMain->setGeometry(QRect(300, 320, 321, 121));
        textStatusMain->setFont(font);
        textStatusMain->setFrameShape(QFrame::Shape::StyledPanel);
        textStatusMain->setFrameShadow(QFrame::Shadow::Sunken);
        textStatusMain->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        textStatusMain->setReadOnly(true);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(150, 20, 401, 51));
        QFont font1;
        font1.setPointSize(18);
        label->setFont(font1);
        labelZegar = new QLabel(centralwidget);
        labelZegar->setObjectName("labelZegar");
        labelZegar->setGeometry(QRect(90, 90, 201, 61));
        QFont font2;
        font2.setPointSize(28);
        labelZegar->setFont(font2);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 643, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        btnPlatnosc->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btnWjazd->setText(QCoreApplication::translate("MainWindow", "Wjazd pojazdu", nullptr));
        btnPlatnosc->setText(QCoreApplication::translate("MainWindow", "P\305\202atno\305\233\304\207", nullptr));
        btnWyjazd->setText(QCoreApplication::translate("MainWindow", "Wyjazd pojazdu", nullptr));
        btnAdmin->setText(QCoreApplication::translate("MainWindow", "Panel administratora", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "P\305\202atny parking bezobs\305\202ugowy", nullptr));
        labelZegar->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
