#include "fiche_suivi.h"

fiche_suivi::fiche_suivi()
{

idF=0;
fonction="";
salaire=0;
dateE="";
nb=0;
Connection c;
bool v=c.createconnect();
}

fiche_suivi::fiche_suivi(int id,QString fonction_em,float salaire_em,QString dateE_em,int nb_em)
{
    this->idF=id;
    this->fonction=fonction_em;
    this->salaire=salaire_em;
    this->dateE=dateE_em;
    this->nb=nb_em;

}

bool fiche_suivi::ajouter(){
    QSqlQuery query ;
    QString res=QString::number(idF);
    QString res1=QString::number(nb);
    QString res2=QString::number(salaire);
    query.prepare("INSERT INTO fiche_suivi VALUES(:res,:fonction,:salaire,:dateE,:nb)");
    query.bindValue(":res",res);
    query.bindValue(":fonction",fonction);
    query.bindValue(":salaire",res2);
    query.bindValue(":dateE",dateE);
    query.bindValue(":nb",res1);
    return query.exec();

}


QSqlQueryModel * fiche_suivi::afficher()
 {
      QSqlQueryModel *model=new QSqlQueryModel();
      model->setQuery("select * from fiche_suivi");
      model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant_fiche"));
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("fonction"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("salaire"));
      model->setHeaderData(3,Qt::Horizontal,QObject::tr("Date d'embauche"));
      model->setHeaderData(4,Qt::Horizontal,QObject::tr("nb d'absence"));



      return model;


}
/*

bool Employes::supprimer(int res)
{
    QSqlQuery query;
    QString ids= QString::number(res);
    query.prepare("Delete from employe where ID = :id ");
    query.bindValue(":id", res);
    return    query.exec();
}
*/
