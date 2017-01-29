#include "mainwindow.h"
#include "windowaddcal.h"
#include "aboutx.h"
#include "about.h"
#include <fstream>
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
    connect(compileButton, SIGNAL (released()), this, SLOT (compileFile()));
    //connect(algumaCoisaButton, SIGNAL (released()), this, SLOT (algumaCoisa()));
    connect(insertCalendarButton, SIGNAL (released()), this, SLOT (insertCalendar()));
    connect(about, SIGNAL (released()), this, SLOT (fc_about()));
    connect(action_about_Qt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
    connect(action_addCal, SIGNAL(triggered()),this, SLOT(insertCalendar()));

}

void MainWindow::compileFile()
{
    std::ofstream outfile;

    outfile.open("a.tex", std::ios_base::trunc);

    outfile << std::string("\\documentclass[12pt]{article}")+
               "\\begin{document}"+
               "Hello world!"+" Curso escolhido: "+curso.toStdString()+" disciplina: "+disciplina.toStdString()+
               "\\end{document}";
    outfile.close();
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
   if(myWindow->exec())
   {
       QString Opt1, Opt2, Opt3;
       //myWindow->GetOptions(Opt1, Opt2, Opt3);
       //DoSomethingWithThoseBooleans (Opt1, Opt2, Opt3);
       curso = myWindow->curso;
       disciplina = myWindow->disciplina;
       /*
       QMessageBox msgBox;
           msgBox.setText("Curso escolhido: "+myWindow->curso);
           msgBox.exec();
       */
   }
}

// redefinicao do close() para confirmacao
void MainWindow::closeEvent(QCloseEvent *event)
{
//    QMessageBox::StandardButton dialogExit;
//    dialogExit = QMessageBox::warning(this,
//               tr("Confirmação de Saída"),
//               tr("Deseja realmente fechar o %1? Projetos não salvos serão perdidos.").arg(TIKZTAK),
//             QMessageBox::Ok | QMessageBox::Cancel);
//    if( dialogExit == QMessageBox::Ok) {
//        close();
//    } else {
//        event->ignore();
//    }
    close();
}

void MainWindow::on_sair_released(){
    close();
}

void MainWindow::fc_about()
{
   AboutDlg* myAboutx = new AboutDlg();

   myAboutx->show();
}
