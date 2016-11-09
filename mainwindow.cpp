#include "mainwindow.h"
#include<QProcess>
#include <QCoreApplication>
#include<QDir>
#include <QDebug>
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Create the button, make "this" the parent
    m_button = new QPushButton("Compilar", this);
    // set size and location of the button
    m_button->setGeometry(QRect(QPoint(3, 3),
    QSize(100, 50)));

    // Connect button signal to appropriate slot
    connect(m_button, SIGNAL (released()), this, SLOT (handleButton()));
}

void MainWindow::handleButton()
{
    // change the text
    m_button->setText("Pronto!");
    // resize button
    //m_button->resize(100,100);
    QProcess *process = new QProcess(this);
    QString program = "pdflatex";
    QString path = QDir().absolutePath()+"/a.tex";
    //qInfo(path_);
    process->startDetached(program, QStringList() << path);
}
