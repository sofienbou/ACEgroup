#include "fiches.h"
fiches::fiches()

{

id=0;

fonction="";

salaire=0;

dateE="";

nba=0;

Connection c;
bool v=c.createconnect();
}

fiches::fiches(int id,QString fonction,float salaire,QString dateE,int nba)
{

  this->id=id;

  this->fonction=fonction;

  this->salaire=salaire;

    this->dateE=dateE;

    this->nba=nba;

}



bool  fiches::ajouter()
{

QSqlQuery query;

QString res= QString::number(id);

query.prepare("INSERT INTO fiches  VALUES (:res,:fonction,:salaire,:dateE,:nba)");

query.bindValue(":res", res);

query.bindValue(":fonction", fonction);

query.bindValue(":salaire", salaire);

query.bindValue(":dateE", dateE);

query.bindValue(":nba", nba);



return    query.exec();

}



QSqlQueryModel * fiches::afficher()
 {
      QSqlQueryModel *model=new QSqlQueryModel();
      model->setQuery("select * from Employes");
      model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("fonction"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("salaire"));
      model->setHeaderData(3,Qt::Horizontal,QObject::tr("DateE"));
      model->setHeaderData(5,Qt::Horizontal,QObject::tr("Nba"));


      return model;
}

bool fiches::supprimer(int idd)//ide
{
    QSqlQuery query;
    QString res= QString::number(idd);//ids ide
    query.prepare("Delete from Employes where   id = :id ");//id id
    query.bindValue(":id", res);//id ids
    return  query.exec();
}


