#ifndef EMPLOYES_H
#define EMPLOYES_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "ui_mainwindow.h"
#include<QString>
#include<QSqlDatabase>

#include "connection.h"
class Employes

{

public:

    //Constructeurs
    Employes();
    Employes(int,QString,QString,QString,QString,int);

    //Getters
    int getID(){return id;}
    QString getnom(){return  nom;}
    QString getprenom(){return prenom;}
    QString getadresse(){return adresse;}
    QString getdate_naissance(){return dateN;}
    int getnum(){return numero;}

    //fonctionalités de bases relatives a l'entité Employés
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(int);
    bool modifier(int);
    void recherche(Ui::MainWindow *ui);
    QSqlQueryModel * trierA();
    QSqlQueryModel * trierZ();


private:
     int id;
     QString nom,prenom,adresse,dateN;
     int numero;
     bool v;
};

#endif
