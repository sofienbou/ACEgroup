/*#ifndef FICHES_H
#define FICHES_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "connection.h"

class fiches
{

    //Constructeurs
    fiches();
    fiches(int,QString,float,QString,int);

    //Getters
    int getID(){return id;}
    QString getfonction(){return  fonction;}
    float getsalaire(){return salaire;}
    QString getdateE(){return dateE;}
    int getnum(){return nba;}

    //fonctionalités de bases relatives a l'entité Employés
    bool ajouter_f();
    QSqlQueryModel *afficher_f();
    bool supprimer_f(int);
    //bool modifier();
    //bool verif_id(QString);
    //bool verif_nom(QString);
    //bool verif_email(QString);


private:
     int id,nba;
     QString fonction,dateE;
     float salaire ;
    bool v;


};

#endif // FICHES_H
*/
