#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cerrar.h"
#include <QMessageBox>
#include <QString>
#include <QFileDialog>
#include <QTextStream>
#include <QFile>
#include <QFontDialog>
#include <QColorDialog>
#include <QPrintDialog>
#include <QPrinter>
#include <QCloseEvent>
#include <QDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    setCentralWidget(ui->textEdit);

}

MainWindow::~MainWindow(){

    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *e){


   if(!(ui->textEdit->toPlainText().isEmpty())){

       if(si == true){
                pd.exec();
                if(pd.can == false){
                    e->ignore();
                    qDebug()<<"Si funciona";

                }
        }
        else if(!(pal == ui->textEdit->toPlainText())){
            pd.exec();
        }


    }




}


void MainWindow::on_actionAbrir_triggered(){

   QFile arch;
   QTextStream io;
   QString nomb;
   nomb=QFileDialog::getOpenFileName(this,"Abrir");
   if(nomb.isEmpty()){
       return;
   }
   pal = ui->textEdit->toPlainText();
   arch.setFileName(nomb);
   arch.open(QIODevice::ReadOnly | QIODevice::Text);
   if(!arch.isOpen()){
       QMessageBox::critical(this,"Error",arch.errorString());
       return;
   }

   io.setDevice(&arch);
   ui->textEdit->setText(io.readAll());

   arch.close();
}

void MainWindow::on_actionGuardar_como_triggered(){

    QFile arch;
    QTextStream io;


    nombre = QFileDialog::getSaveFileName(this,"Guardar");
    if(nombre.isEmpty()){
        return;
    }

    pal = ui->textEdit->toPlainText();
    arch.setFileName(nombre);
    arch.open(QIODevice::WriteOnly | QIODevice::Text);
    if(!arch.isOpen()){
        QMessageBox::critical(this,"Error",arch.errorString());
        return;
    }

    io.setDevice(&arch);

    io<<ui->textEdit->toPlainText();
    arch.flush();
    arch.close();
    si = false;
}

void MainWindow::on_actionCopiar_triggered(){

ui->textEdit->copy();

}

void MainWindow::on_actionCortar_triggered(){

ui->textEdit->cut();
}

void MainWindow::on_actionPegar_triggered(){

ui->textEdit->paste();
}

void MainWindow::on_actionAcerca_de_triggered(){

    QString txt;
    txt = "Autor: Imanol Ortega\n";
    txt += "Fecha: 03/01/2020\n";
    txt+= "Gracias por utilizar\neste software para mas informacion\n"
          "ingrese a hhtps://xnxx.com";

    QMessageBox::about(this,"Block de Notas",txt);

}

void MainWindow::on_actionQuitar_triggered(){
    close();
}



void MainWindow::on_actionColor_triggered(){
    QColor option;
   option = QColorDialog::getColor(Qt::blue,this,"Colores");

   ui->textEdit->setTextColor(option);
}

void MainWindow::on_actionTipo_triggered(){
    bool ok;
    QFont fuente;
    fuente = QFontDialog::getFont(&ok,this);
    if(!ok){
        return;
    }
    ui->textEdit->setFontPointSize(fuente.pointSize());
    ui->textEdit->setFontFamily(fuente.family());
}

void MainWindow::on_actionColor_2_triggered(){


    QColor option;
   option = QColorDialog::getColor(Qt::white,this,"Colores");

   ui->textEdit->setPalette(QPalette(option));

}

void MainWindow::on_actionImprimir_triggered(){

    QPrinter *impresora;

    QPrintDialog pd(this);

    if(pd.exec() == QDialog::Rejected){
        return;
    }
    impresora = pd.printer();
    ui->textEdit->print(impresora);

}


void MainWindow::on_actionDeshacer_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionRehacer_triggered()
{
    ui->textEdit->redo();
}
