#ifndef ABOUTX_H
#define ABOUTX_H

#include <QDialog>

namespace Ui {
class AboutDlg;
}

class AboutDlg : public QDialog
{
    Q_OBJECT

public:
    explicit AboutDlg(QDialog *parent = 0);
    ~AboutDlg();

private slots:
//    void on_pushButton_clicked();

private:
    Ui::AboutDlg *ui;
};

#endif // ABOUTX_H
