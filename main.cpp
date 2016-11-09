#include "mainwindow.h"

#include <QApplication>
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

    MainWindow mainWindow;
    //mainWindow.showMaximized();
    mainWindow.show();


    return app.exec();
}
