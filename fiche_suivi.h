#ifndef FICHES_H
#define FICHE_SUIVI_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "connection.h"

class fiche_suivi
{
public:

    //Constructeurs
    fiche_suivi();
    fiche_suivi(int,QString,float,QString,int);

    //Getters

    int getID_fiche(){return  idF;}
    QString getfonction(){return fonction;}
    float get_salaire(){return salaire;}
    QString getdate_embauche(){return dateE;}
    int getnb_absc(){return nb;}

    //fonctionalités de bases relatives a l'entité Employés
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(int);
    bool modifier(int);

private:
    int idF,nb;
    QString fonction,dateE;
    float salaire;
};

#endif // FICHES_H
