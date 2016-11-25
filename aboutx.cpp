#include "aboutx.h"
#include "ui_aboutx.h"
#include "mainwindow.h"
#include <QString>

AboutDlg::AboutDlg(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::AboutDlg)
{
    ui->setupUi(this);
    setWindowTitle(QString(tr("Sobre %1 versao %2")).arg(TIKZTAK).arg(VERSAO));
    ui->tw_tabs->setCurrentIndex(0);

    // about tab
    ui->textBrowser->setHtml(
                QString(
                    tr("<p align=\"center\"><span style=\"font-size:20pt; font-weight:600;\">%1<sup>(calendar)</sup><br/>"
                    "<span style=\"font-size:12pt;\">Vers&atilde;o v%2</span></span><br/>")).arg(TIKZTAK).arg(VERSAO)
              + tr("Criador de calend&aacute;rios<br/>GUI para o pacote L<sup>A</sup>T<sub>E</sub>X <code>tikz-tak.sty</code><br>")
              + QString(
                    tr("<p align=\"center\">Desenvolvido por<br>%1 e %2<br/><span style=\"font-size:8pt;\">Copyright (C) 2016</span><br/></p>")).arg(THIAGO).arg(LUCAS)
              + tr("<p align=\"center\">Compilado em %1 %2<br>com Qt Vers&atilde;o %3").arg(__DATE__).arg(__TIME__).arg(qVersion())
              );

    // author tab
    ui->groupBox_thiago->setTitle(THIAGO);
    ui->label_17->setText(QString("<a href=\"http://%1\">%1</a>").arg(THIAGOWEB));
    ui->label_19->setText(QString("<a href=\"mailto:%1\">%1</a>").arg(THIAGOEMAIL));

    ui->groupBox_lucas->setTitle(LUCAS);
    ui->label_2->setText(QString("<a href=\"http://%1\">%1</a>").arg(LUCASWEB));
    ui->label_6->setText(QString("<a href=\"mailto:%1\">%1</a>").arg(LUCASEMAIL));

    // libraries tab
    ui->label->setText(QString(tr("%1 foi construído com as seguintes bibliotecas:")).arg(TIKZTAK));
    ui->label_11->setText(qVersion());


}

AboutDlg::~AboutDlg()
{
    delete ui;
}

//void AboutDlg::on_pushButton_clicked()
//{
//    close();
//}
