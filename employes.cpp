#include "employes.h"

Employes::Employes()
{
id=0;
nom="";
prenom="";
adresse="";
dateN="";
numero=0;

Connection c;
bool v=c.createconnect();
}

Employes::Employes(int id_em,QString nom_em,QString prenom_em,QString adresse_em,QString dateN_em,int num)
{
    this->id=id_em;
    this->nom=nom_em;
    this->prenom=prenom_em;
    this->adresse=adresse_em;
    this->dateN=dateN_em;
    this->numero=num;
}

bool Employes::ajouter(){
    QSqlQuery query ;
    QString res=QString::number(id);
    QString res1=QString::number(numero);
    query.prepare("INSERT INTO Employes (ID, NOM, PRENOM,DATEN,ADRESSE,NUMERO)" "VALUES(:id,:nom,:prenom,:dateN,:adresse,:numero)");
    query.bindValue(":id",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":adresse",adresse);
    query.bindValue(":dateN",dateN);
    query.bindValue(":numero",res1);
    return query.exec();

}


QSqlQueryModel * Employes::afficher()
 {
      QSqlQueryModel *model=new QSqlQueryModel();
      model->setQuery("select * from Employes");
      model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
      model->setHeaderData(3,Qt::Horizontal,QObject::tr("Date de naissance"));
      model->setHeaderData(4,Qt::Horizontal,QObject::tr("Adresse"));
      model->setHeaderData(5,Qt::Horizontal,QObject::tr("Numéro"));


      return model;
}

///supprimer employe
bool Employes::supprimer(int idd)//ide
{
    QSqlQuery query;
    QString res= QString::number(idd);//ids ide
    query.prepare("Delete from Employes where   id = :id ");//id id
    query.bindValue(":id", res);//id ids
    return  query.exec();
}


///modifier employe
bool Employes::modifier(int idd)
{
    QSqlQuery query;
    QString res=QString::number(idd);

    query.prepare("UPDATE Employes SET ID= :id , nom= :nom , prenom = :prenom , dateN = :dateN , numero = :numero WHERE ID= :id");
   // query.bindValue(":cin", ids);
    query.bindValue(":id",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":adresse",adresse);
    query.bindValue(":dateN",dateN);
    query.bindValue(":numero",numero);

    return query.exec();

}
/*
QSqlQueryModel * Employes::recherche(int id)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from Employes where ID LIKE '"+id+"%' or nom LIKE '"+nom+"%' or prenom LIKE '"+prenom+"%' or  adresse LIKE '"+adresse+"%' or dateN LIKE '"+dateN+"%',or numero LIKE '"+numero+"%' ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Date de naissance"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Adresse"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Numéro"));

    return model;
}
*/
