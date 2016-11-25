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

    setWindowTitle(QString(tr("%1 (calendar) v%2")).arg(TIKZTAK).arg(VERSAO));

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
    QProcess *process = new QProcess(this);
    QString program = "pdflatex";
    QString path = QDir().absolutePath()+"/a.tex";

    process->startDetached(program, QStringList() << path);
}


//void MainWindow::algumaCoisa()
//{
//    QMessageBox::information(
//        this,
//        tr("Tikz-TaK"),
//        tr("Alguma coisa!") );
//}

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
               tr("Deseja realmente fechar o %1? Projetos não salvos serão perdidos.").arg(TIKZTAK),
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

   myAboutx->show();
}
