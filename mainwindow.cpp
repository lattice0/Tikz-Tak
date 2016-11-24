#include "mainwindow.h"
#include "windowaddcal.h"
#include "aboutx.h"
#include "about.h"

#include<QProcess>
#include<QCoreApplication>
#include<QMessageBox>
#include<QDir>
#include<QDebug>
#include<QCloseEvent>
#include<string>

MainWindow::MainWindow(QWidget *parent)
{
    setAttribute(Qt::WA_DeleteOnClose);
    Q_UNUSED(parent);
    setupUi(this);

    setWindowTitle(QString::fromUtf8("%1 (calendar) v%2").arg(TIKZTAK).arg(VERSAO));

    previewPDF->hide();
    // Connect button signal to appropriate slot
    //connect(compileButton, SIGNAL (released()), this, SLOT (compileFile()));
    //connect(algumaCoisaButton, SIGNAL (released()), this, SLOT (algumaCoisa()));
    connect(insertCalendarButton, SIGNAL (released()), this, SLOT (insertCalendar()));
    connect(about, SIGNAL (released()), this, SLOT (fc_about()));
    connect(action_about_Qt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
    connect(action_addCal, SIGNAL(triggered()),this, SLOT(insertCalendar()));



}

void MainWindow::compileFile()
{
    // change the text
    //compileButton->setText("Pronto!");

    QProcess *process = new QProcess(this);
    QString program = "pdflatex";
    QString path = QDir().absolutePath()+"/a.tex";

    process->startDetached(program, QStringList() << path);
}


void MainWindow::algumaCoisa()
{
    QMessageBox::information(
        this,
        tr("Tikz-TaK"),
        tr("Alguma coisa!") );
}

void MainWindow::insertCalendar()
{
   WindowAddCal* myWindow = new WindowAddCal();
   myWindow->show();
}

// redefinicao do close() para confirmacao
void MainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton dialogExit;
    dialogExit = QMessageBox::warning(this,
               tr("Confirmação de Saída"),
               "Deseja realmente fechar o TikZ-TaK? Projetos não salvos serão perdidos.",
             QMessageBox::Ok | QMessageBox::Cancel);
    if( dialogExit == QMessageBox::Ok) {
        close();
    } else {
        event->ignore();
    }
}

void MainWindow::on_sair_released(){
    close();
}

void MainWindow::fc_about()
{
   AboutDlg* myAboutx = new AboutDlg();
//   About* myAbout = new About();

   myAboutx->show();
//   myAbout->show();
}
