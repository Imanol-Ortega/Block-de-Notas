#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cerrar.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class cerrar;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
     MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
         bool sis = true;
         cerrar pd;
protected:
    void closeEvent(QCloseEvent *e);

public slots:
    void on_actionAbrir_triggered();

    void on_actionGuardar_como_triggered();

    void on_actionCopiar_triggered();

    void on_actionCortar_triggered();

    void on_actionPegar_triggered();

    void on_actionAcerca_de_triggered();

    void on_actionQuitar_triggered();

    void on_actionColor_triggered();

    void on_actionTipo_triggered();

    void on_actionColor_2_triggered();

    void on_actionImprimir_triggered();

    void on_actionDeshacer_triggered();

    void on_actionRehacer_triggered();

private:
    Ui::MainWindow *ui;
    QString pal,nombre;

    bool si = true;


};
#endif // MAINWINDOW_H
