#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "employes.h"
#include "fiches.h"
#include <QMainWindow>

#include <QPainter>
#include <QPrintDialog>
#include <QPrinter>
#include<QDebug>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //void on_pushButton_clicked();

    void on_pushButton_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_lineEdit_cursorPositionChanged(int arg1, int arg2);

    void on_pushButton_ajouter_clicked();

    //void on_pushButton_ajouter_clicked();

    void on_pushButton_2_clicked();

    void on_label_7_linkActivated(const QString &link);

    void on_pushButton_3_clicked();

    void on_pushButton_ajouter_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_modif_clicked();

    void on_pushButton_supp_clicked();

    void on_pushButton_modi_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_pushButton_imprimer_clicked();

    void on_pushButton_pdf_clicked();

    void on_pushButton_ajout_fiches_clicked();

    void on_pushButton_supp_fiches_clicked();

    void on_pushButton_modif_fiche_clicked();

private:
    Ui::MainWindow *ui;

    Employes tmpEmpl;
    Fiches tmp;
};

#endif // MAINWINDOW_H
