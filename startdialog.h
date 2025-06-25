#ifndef STARTDIALOG_H
#define STARTDIALOG_H

#pragma once

#include <QDialog>

namespace Ui {
class StartDialog;
}

class StartDialog : public QDialog {
    Q_OBJECT

public:
    explicit StartDialog(QWidget *parent = nullptr);
    ~StartDialog();

    int getLiczbaMiejsc() const;
    double getStawka() const;
    void onStartClicked();

private:
    Ui::StartDialog *ui;
};


#endif // STARTDIALOG_H
