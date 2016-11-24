#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define TIKZTAK "TikZ-TaK"
#define VERSAO "0.1"

#define THIAGO "Thiago de Melo"
#define THIAGOWEB "www.rc.unesp.br/tmelo"
#define THIAGOEMAIL "tmelo@rc.unesp.br"

#define LUCAS "Lucas Zanella"
#define LUCASWEB "<insert>"
#define LUCASEMAIL "<insert>"



#include "windowaddcal.h"
#include "ui_mainwindow.h"
#include "aboutx.h"
#include "about.h"

class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
protected:
        void closeEvent(QCloseEvent *event);
public slots:
    void compileFile();
    void algumaCoisa();
    void insertCalendar();
    void on_sair_released();
    void fc_about();
private:
    Ui::MainWindow *ui;
    WindowAddCal *addCalendar;
};

#endif // MAINWINDOW_H
