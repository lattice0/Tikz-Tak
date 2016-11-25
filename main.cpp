#include "mainwindow.h"

#include<QApplication>
#include<QTranslator>
//#include<QString>
#include <fstream>

int main(int argc, char *argv[])
{
    std::ofstream outfile;

    outfile.open("a.tex", std::ios_base::trunc);

    outfile << "\\documentclass[12pt]{article}"
               "\\begin{document}"
               "Hello world!"
               "\\end{document}";
    outfile.close();

    QApplication app(argc, argv);

    QTranslator translator;
    translator.load("tikz-tak_en");
    app.installTranslator(&translator);

//    if (translator.load(QLocale(), QLatin1String("tikz-tak"), QLatin1String("_"), QLatin1String(":/translations")))
//            app.installTranslator(&translator);

    MainWindow *mainWindow = new MainWindow;

    // status bar
    mainWindow->statusBar()->setMinimumHeight(22);
    mainWindow->statusBar()->setSizeGripEnabled(false);
    mainWindow->statusBar()->setStyleSheet(
                "QStatusBar QLabel { border-left: 1px solid grey; margin-right: 1px; }"
                );

    // nao funciona com tr()
    QLabel *statusWelcomeMSG = new QLabel("foo");
////    QString temp0 = QString(tr("Bem-vindo ao %1 (calendar)")).arg(TIKZTAK);
//    statusWelcomeMSG-> setText(tr("Bem-vindo!"));
    QString compilationDateTime = QString(("v%3 compilado em %1 %2")).arg(__DATE__).arg(__TIME__).arg(VERSAO);
//    QString *temp1 = new QString("Carregado em ");
//    QString *temp2 = new QString(QDate::currentDate().toString(Qt::SystemLocaleDate));
//    QLabel *statusDateTime = new QLabel();
//    statusDateTime-> setText(temp1->append(temp2)); // not used yet
    QLabel *statusBuilt = new QLabel();
    statusBuilt->setText(compilationDateTime);
    QLabel *statusBlank = new QLabel();

    mainWindow->statusBar()->addWidget(statusWelcomeMSG);
    mainWindow->statusBar()->addPermanentWidget(statusBuilt);
    mainWindow->statusBar()->addWidget(statusBlank,2);

//    mainWindow->statusBar()->showMessage(("aqui!!!!"));
    mainWindow->show();


    return app.exec();
}
