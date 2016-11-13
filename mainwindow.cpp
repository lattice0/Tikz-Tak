#include "mainwindow.h"
#include<QProcess>
#include<QCoreApplication>
#include<QMessageBox>
#include<QDir>
#include <QDebug>
#include <string>

MainWindow::MainWindow(QWidget *parent)
{
    setupUi(this);
    // Connect button signal to appropriate slot
    connect(compileButton, SIGNAL (released()), this, SLOT (compileFile()));
    connect(algumaCoisaButton, SIGNAL (released()), this, SLOT (algumaCoisa()));
}

void MainWindow::compileFile()
{
    // change the text
    compileButton->setText("Pronto!");

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
