#include "windowaddcal.h"
#include<QString>
#include<QMessageBox>
#include<QPushButton>
#include<QFile>
#include<QDebug>
#include<QObject>

WindowAddCal::WindowAddCal(QWidget *parent)
    : QDialog(parent)
{
    ui.setupUi(this);
    setWindowTitle("Dados do Cal");
    connect(ui.buttonBox, SIGNAL (accepted()), this, SLOT (saveDataAndAccept()));
    connect(ui.buttonBox, SIGNAL (rejected()), this, SLOT (reject()));


//    QPushButton *button = new QPushButton();
//    button->setText("Apply");

/*    QFile data("output.txt");
    // open file
    if (!data.open(QFile::WriteOnly | QFile::Truncate)) {

        qDebug() << "Can't open file";

//        return 1; // deu erro
    }
    // attach file to QTextStream
    QTextStream out(&data);
*/

}

// ao sair do campo curso, executar o seguinte:
void WindowAddCal::on_form_curso_editingFinished()
{
    QString input = ui.form_curso->text();
    QMessageBox msgBox;
        msgBox.setText("Curso escolhido: "+input);
        //msgBox.exec();
//    ui.form_disciplina->setText(input); //passa string para outro campo
}
void WindowAddCal::saveDataAndAccept()
{
    curso = ui.form_curso->text();
    disciplina = ui.form_disciplina->text();
    accept();
}
