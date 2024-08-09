#ifndef BASEDEDONNEE_H
#define BASEDEDONNEE_H

#include <QObject>
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QSql>
#include <GestionnaireContact.h>

/*!
 * @file BaseDeDonnee.h
 * @brief Classe qui permet de gerer tout les requetes SQL dans l'application.
 * @class BaseDeDonnee
 * @var QSqlDatabase db;
 */

class BaseDeDonnee : public QObject
{

    Q_OBJECT

public:
    BaseDeDonnee(QObject *parent = nullptr);
    ~BaseDeDonnee();

    //méthode
    Date toDate(std::string);

private:
    QSqlDatabase db;

public slots:
    void ConnexionBDD();
    void CreationTables();
    void SuppressionTables();
    void getToutContacts();
    void getLogs();
    void AjtContact(Contact);
    void MdfContact(Contact,Contact);
    void SuppressionContact(Contact);
    void SuppressionInteraction(Interaction,std::string);
    void AjtInteraction(Contact,Interaction);
    void VerifMail(QString mail,std::string type);


signals:
    void CoBDD();
    void SuppTables();
    void CrTables();
    void RefreshLogsBDD(std::list<QString> logListe);
    void RefreshGC(GestionnaireContact Gc);
    void mailVerificationAjout(bool);
    void mailVerificationModif(bool);
};

#endif // BASEDEDONNEE_H
