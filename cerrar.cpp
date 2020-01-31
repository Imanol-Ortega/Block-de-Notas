#include "cerrar.h"
#include "ui_cerrar.h"
#include "mainwindow.h"
#include <QtGui/qevent.h>


cerrar::cerrar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cerrar)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::WindowTitleHint | Qt::CustomizeWindowHint);

}

cerrar::~cerrar(){
    delete ui;
}

/*void cerrar::closeEvent(QCloseEvent *ev)
{
    v = false;


}
*/
void cerrar::on_pushButton_clicked(){
    can = true;
    close();
}

void cerrar::on_pushButton_2_clicked(){
       MainWindow p;
       p.on_actionGuardar_como_triggered();
       this->close();
}

void cerrar::on_pushButton_3_clicked(){

    can = false;
    this->close();



}

