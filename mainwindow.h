#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "windowaddcal.h"
#include "ui_mainwindow.h"

class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
public slots:
    void compileFile();
    void algumaCoisa();
    void insertCalendar();
    void on_sair_released();
private:
    Ui::MainWindow *ui;
    WindowAddCal *addCalendar;
};

#endif // MAINWINDOW_H
