#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employes.h"
//#include "fiches.h"
#include<QMessageBox>
#include "QPushButton"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableView_empl->setModel(tmpEmpl.afficher());
  //  ui->tableView_fiche->setModel(tmpFiche.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::on_pushButton_ajouter_clicked()
{
    int id=ui->lineEdit->text().toInt();
    QString nom=ui->lineEdit_2->text();
    QString prenom=ui->lineEdit_3->text();
    QString adresse=ui->lineEdit_4->text();
    QString dateN=ui->lineEdit_5->text();
    int numero=ui->lineEdit_6->text().toInt();

    Employes e(id,nom, prenom,adresse, dateN,numero);
    bool test=e.ajouter(); //inserer l'objet fournisseur instancié dans le table etudiant et recuperer la valeur de retour de query.exec()
    if(test) //si requete exeecutee ==>QMessageBox::information
     {
        ui->tableView_empl->setModel(tmpEmpl.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("ajout effectué\n""Click Cancek to exit"),QMessageBox::Cancel);
     }
    else //si requete non effectuee==>QMessageBox::critical
    {
      QMessageBox::critical(nullptr,QObject::tr("Not Ok"),QObject::tr("Ajout non effectuée.\n""Click Cancel to exit."),QMessageBox::Cancel);
}
}



void MainWindow::on_pushButton_2_clicked()
{

    int id=ui->lineEdit_7->text().toInt();
        bool test=tmpEmpl.supprimer(id);
        if(test)
        {
            ui->tableView_empl->setModel(tmpEmpl.afficher());
            QMessageBox::information(nullptr,QObject::tr("Suppression"),
                    QObject::tr("suppresion avec succes.\n""click cancel to exit."),QMessageBox::Cancel);
        }
        else{
            QMessageBox::critical(nullptr,QObject::tr("suppression"),
                                  QObject::tr("suppression echoue .\n""Click cancel to exit."),QMessageBox::Cancel);

        }

}




void MainWindow::on_pushButton_modif_clicked()
{
    /*button sound
         player->setMedia(QUrl::fromLocalFile("C:/Users/LENOVO/Downloads/click.mp3"));
         player->play();
         qDebug()<<player ->errorString();
*/
         int id=ui -> lineEdit_16->text().toInt();
         QString nom=ui->lineEdit_17->text();
         QString  prenom=ui->lineEdit_18->text();
        QString adresse=ui->lineEdit_19->text();
         QString dateN=ui->lineEdit_20->text();
        int numero=ui->lineEdit_21->text().toInt();

         Employes e(id,nom,prenom,adresse,dateN,numero);
      bool test=e.modifier(id);
   if(test)
   {
       ui->tableView_empl->setModel(tmpEmpl.afficher());//refresh
       QMessageBox::information(nullptr,QObject::tr("modifier"),
                QObject::tr("Modification avec succes.\n"
                            "click cancel to exit."),QMessageBox::Cancel);

   }
   else
       QMessageBox::critical(nullptr,QObject::tr("modifier"),
                             QObject::tr("Modification echoue! .\n"
                                         "Click cancel to exit."),QMessageBox::Cancel);
}


/*
void MainWindow::on_pushButton_modi_clicked()
{
   int id=ui->lineEdit_7->text().toInt();
    ui->tableView_empl->setModel(tmpEmpl.recherche(id));
    //button sound
       player->setMedia(QUrl::fromLocalFile("C:/Users/LENOVO/Downloads/click.mp3"));
        player->play();
        qDebug()<<player ->errorString();
}
*/
