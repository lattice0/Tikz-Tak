#ifndef WINDOWADDCAL_H
#define WINDOWADDCAL_H

#include"QWidget"
#include"ui_windowaddcal.h"

class WindowAddCal : public QDialog
{
    Q_OBJECT

public:
    WindowAddCal(QWidget *parent = 0);

private slots:
    //void on_inputSpinBox1_valueChanged(int value);
    //void on_inputSpinBox2_valueChanged(int value);

    void on_form_curso_editingFinished();

private:
    Ui::Dialog ui;
};

#endif // WINDOWADDCAL_H
