#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"employes.h"
#include "fiches.h"
#include<QSqlQueryModel>
#include<QDebug>
#include "QPushButton"
#include <QPainter>
#include <QtPrintSupport/QPrinter>
#include <QPrintDialog>
#include <QDebug>
#include <QPrinter>
#include <QTextDocument>
#include<QFileDialog>
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableView_empl->setModel(tmpEmpl.afficher());
    ui->tableView_fiche->setModel(tmp.afficherF());
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
  //  button sound
         /*player->setMedia(QUrl::fromLocalFile("C:/Users/LENOVO/Downloads/click.mp3"));
         player->play();
         qDebug()<<player ->errorString();*/

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




void MainWindow::on_pushButton_modi_clicked()
{


    Employes e;
    e.recherche(ui);
}



void MainWindow::on_radioButton_clicked()
{
    ui->tableView_empl->setModel(tmpEmpl.trierA());
    //button sound
       /* player->setMedia(QUrl::fromLocalFile("C:/Users/LENOVO/Downloads/click.mp3"));
        player->play();
        qDebug()<<player ->errorString();*/
}


void MainWindow::on_radioButton_2_clicked()
{
    ui->tableView_empl->setModel(tmpEmpl.trierZ());
    //button sound
      /*  player->setMedia(QUrl::fromLocalFile("C:/Users/LENOVO/Downloads/click.mp3"));
        player->play();
        qDebug()<<player ->errorString();*/
}



void MainWindow::on_pushButton_imprimer_clicked()
{

        QPrinter rd;
        QPrintDialog d(&rd,this);
        d.setWindowTitle("Print livre");
        d.addEnabledOption(QAbstractPrintDialog::PrintSelection);
        if(d.exec() != QDialog::Accepted)
            return;

}

void MainWindow::on_pushButton_pdf_clicked()
{
    QString fileName =QFileDialog::getSaveFileName((QWidget*)0,"Export PDF",QString(),"*pdf");
    if(QFileInfo(fileName).suffix().isEmpty()){fileName.append(".pdf");}
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);
    QTextDocument doc ;
    QSqlQuery q;
    q.prepare("SELECT * FROM Employes");
    q.exec();
    QString pdf="<br> <h1 style='color:red'> LISTE DES EMPLOYES <br></h1>\n <br> <table> <tr> <th>id </th> <th>nom </th>    </tr>  ";

    while (q.next()) {
        pdf= pdf+ "<br> <tr> <td>"+ q.value(0).toString()+" " + q.value(1).toString() +"</td> <td>" +q.value(2).toString() +"  ""  " "</td> <td>"+q.value(3).toString()+"</td> ";
        }
    doc.setHtml(pdf);
    doc.setPageSize(printer.pageRect().size()); //This is necessary if you want to hide the page number
    doc.print(&printer);

}


void MainWindow::on_pushButton_ajout_fiches_clicked()
{
    int idf=ui->lineEdit_8->text().toInt();
    QString fonction=ui->lineEdit_9->text();
    int salaire=ui->lineEdit_10->text().toInt();
    QString dateE=ui->lineEdit_11->text();
    int nba=ui->lineEdit_12->text().toInt();


    Fiches f(idf, fonction,salaire, dateE,nba);
    bool test=f.ajouterF(); //inserer l'objet fournisseur instancié dans le table etudiant et recuperer la valeur de retour de query.exec()
    if(test) //si requete exeecutee ==>QMessageBox::information
     {
        ui->tableView_fiche->setModel(tmp.afficherF());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("ajout effectué\n""Click Cancek to exit"),QMessageBox::Cancel);
     }
    else //si requete non effectuee==>QMessageBox::critical
    {
      QMessageBox::critical(nullptr,QObject::tr("Not Ok"),QObject::tr("Ajout non effectuée.\n""Click Cancel to exit."),QMessageBox::Cancel);
}
}


void MainWindow::on_pushButton_supp_fiches_clicked()
{
        int idf=ui->lineEdit_supp->text().toInt();
        bool test=tmp.supprimerF(idf);
        if(test)
        {
            ui->tableView_fiche->setModel(tmp.afficherF());
            QMessageBox::information(nullptr,QObject::tr("Suppression"),
                    QObject::tr("suppresion avec succes.\n""click cancel to exit."),QMessageBox::Cancel);
        }
        else{
            QMessageBox::critical(nullptr,QObject::tr("suppression"),
                                  QObject::tr("suppression echoue .\n""Click cancel to exit."),QMessageBox::Cancel);

        }
}

void MainWindow::on_pushButton_modif_fiche_clicked()
{
    int idf=ui -> lineEdit_22->text().toInt();
    QString fonction=ui->lineEdit_23->text();
    int  salaire=ui->lineEdit_24->text().toInt();
   QString dateE=ui->lineEdit_25->text();
   // QString dateN=ui->lineEdit_20->text();
   int nba=ui->lineEdit_26->text().toInt();

    Fiches f(idf,fonction,salaire,dateE,nba);
 bool test=f.modifierF(idf);
if(test)
{
  ui->tableView_fiche->setModel(tmp.afficherF());//refresh
  QMessageBox::information(nullptr,QObject::tr("modifier"),
           QObject::tr("Modification avec succes.\n"
                       "click cancel to exit."),QMessageBox::Cancel);

}
else
  QMessageBox::critical(nullptr,QObject::tr("modifier"),
                        QObject::tr("Modification echoue! .\n"
                                    "Click cancel to exit."),QMessageBox::Cancel);
}

