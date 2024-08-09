#include "BaseDeDonnee.h"
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QtSql/QSqlQuery>
#include <QSql>
#include "Date.h"
#define DBFILEPATH "../GestionContact/BDDfichier/BDDGestion.sqlite"
#include <sstream>


/*!
 * \file BaseDeDonnee.cpp
 * \brief Classe qui permet de créer toute les requêtes avec la Base de données nécessaire à l'application.
 * La classe vas permettre de réaliser tout type d'action necessaires au fonctionnement de l'application.
 * En commençant par la création des différentes tables à l'ouverture de la BDD dans le cas ou les tables pour X raisons n'existent pas,
 * il s'y trouve chaque slots correspondant à la manipulation de données de l'application soit:
 * - l'ajout de contact
 * - la modification de contact
 * - la suppression de contact
 * - l'ajout d'interaction ( comprend les Todo )
 * - la suppression d'interaction ( comprend les Todo )
 * - la récupération de la liste de contact ( comprend les interactions et les Todos )
 *
 * mise à part la récupération de liste de contact , chaque slot une fois la requête éxecutée vas écrire dans la table de logs
 *  le type de requête éxecutée avec les information qui corresponde à la requête ainsi que la date de l'execution.
 * \class BaseDeDonnee
 */

/*!
 * \brief BaseDeDonnee::BaseDeDonnee
 * Constructeur de la classe BaseDeDonnee
 * ouverture de la BDD si elle n'est pas déjà ouverte.
 * \param parent
 */

BaseDeDonnee::BaseDeDonnee(QObject *parent) : QObject(parent)
{

    connect(this,SIGNAL(CoBDD()),this,SLOT(ConnexionBDD()));
    connect(this,SIGNAL(CrTables()),this,SLOT(CreationTables()));
    connect(this,SIGNAL(SuppTables()),this,SLOT(SuppressionTables()));


    if(!db.isOpen())
    {
        emit CoBDD();
       // emit SuppTables();
        emit CrTables();
    };


}

/*!
 * \brief BaseDeDonnee::~BaseDeDonnee
 * Destructeur de la classe BaseDeDonnee
 * fermeture de la BDD.
 * \param parent
 */
BaseDeDonnee::~BaseDeDonnee()
{

        db.close();

}

/*!
 * \brief BaseDeDonnee::ConnexionBDD
 *
 * Connexion à la BDD
 */

void BaseDeDonnee::ConnexionBDD(){

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(DBFILEPATH);


    if(db.open())
    {
        qDebug() << "Connexion BDD ok";
    }

    else
    {
        qDebug() << "Pas de connexion BDD !";
    }
}

/*!
 * \brief BaseDeDonnee::CreationTables
 * Création des tables Contact,Interaction,Todo,Logs.
 * La Table Contact comporte comme attribus :
 * - Nom
 * - Prenom
 * - Entreprise
 * - Mail
 * - Photo
 * - Date
 *
 * qui sont tous stoquées sous forme de string, le Mail est l'id du contact car un mail est unique.
 *
 * La Table Interaction comporte comme attribus :
 * - InterID
 * - Cid
 * - Contenu
 * - Date
 *
 * qui sont tous stoquées sous forme de string sauf InterId, InterId est l'id de l'interaction qui est auto incrémenté lors de l'insertion d'une interaction.
 * Le Cid lui est une référence à l'id de la table Contact soit au Mail ainsi un lien est crée entre le contact et ses interactions.
 *
 * La Table Todo comporte comme attribus :
 * - TodoID
 * - Iid
 * - Contenu
 * - Date
 *
 * qui sont tous stoquées sous forme de string sauf TodoId, TodoId est l'id du todo qui est auto incrémenté lors de l'insertion d'un todo.
 * Le Iid lui est une référence à l'id de la table Interaction soit a l'InterId ainsi un lien est crée entre l'interaction et ses todos.
 *
 * La Table Logs comporte comme attribus :
 * - Contenu
 * - Date
 */

void BaseDeDonnee::CreationTables(){
    QSqlQuery query;
    //TABLE CONTACT
    QString str = "CREATE TABLE IF NOT EXISTS CONTACT("
                "Nom TEXT NOT NULL,"
                "Prenom TEXT NOT NULL,"
                "Entreprise TEXT NOT NULL,"
                "Mail TEXT PRIMARY KEY NOT NULL,"
                "Telephone TEXT NOT NULL,"
                "Photo TEXT,"
                "Date TEXT NOT NULL"
                ");";
    if(!query.exec(str))
        qDebug() << "La creation de la table CONTACT a echoue";
    else
        qDebug() << "La table CONTACT a ete cree.";

    //TABLE INTERACTION
    str = "CREATE TABLE IF NOT EXISTS INTERACTION("
        "InterID INTEGER PRIMARY KEY AUTOINCREMENT,"
        "Cid INTEGER NOT NULL,"
        "Contenu TEXT NOT NULL,"
        "Date TEXT NOT NULL,"
        "FOREIGN KEY (Cid) REFERENCES CONTACT (Mail)"
        ");";
    if(!query.exec(str))
        qDebug() << "La creation de la table INTERACTION a echoue";
    else
        qDebug() << "La table INTERACTION a ete cree.";

    //TABLE TODO
    str = "CREATE TABLE IF NOT EXISTS TODO("
        "TodoID INTEGER PRIMARY KEY AUTOINCREMENT,"
        "Iid INTEGER NOT NULL,"
        "Contenu TEXT NOT NULL,"
        "Date TEXT NOT NULL,"
        "FOREIGN KEY (Iid) REFERENCES INTERACTION (InterID)"
        ");";
    if(!query.exec(str))
        qDebug() << "La creation de la table TODO a echoue";
    else
        qDebug() << "La table TODO a ete cree.";




    //TABLE LOGS
    str = "CREATE TABLE IF NOT EXISTS LOGS("
        "Contenu TEXT NOT NULL,"
        "Date TEXT NOT NULL"
        ");";
    if(!query.exec(str))
        qDebug() << "La creation de la table LOGS a echoue";
    else
        qDebug() << "La table LOGS a ete cree.";


}

/*!
 * \brief BaseDeDonnee::SuppressionTables
 * Méthode ( slot )  qui permet de supprimer les tables dans la BDD.
 * Cette méthode n'est pas créée pour l'application mais pour nous faciliter la tache au développement,
 * durant les multiple modifications de table il était plus simple d'appeler cette méthode car de toute manière les tables sont recrées si inexistantes.
 */

void BaseDeDonnee::SuppressionTables(){
    QSqlQuery query;
    QString r = "DROP TABLE CONTACT;";
    QString r2 = "DROP TABLE INTERACTION;";
    QString r3 = "DROP TABLE TODO;";
    QString r4 = "DROP TABLE LOGS;";
    if(!query.exec(r)&&!query.exec(r2)&&!query.exec(r3)&&!query.exec(r4)){
        qDebug()<< " La suppression des tables a echoue ";
    }
    else{
        qDebug()<< " Les tables ont ete suprimmees  ";
    }
}


/*!
 * \brief BaseDeDonnee::AjtContact
 * Méthode ( slot ) qui permet l'ajout d'un contact, on récupère en paramètre le contact emit dans le signal par le Widget principale et on l'intègre à la table.
 * On insère dans les logs l'ajout de contact.
 * \param contact
 */
void BaseDeDonnee::AjtContact(Contact contact){
    QSqlQuery query;


    query.prepare("INSERT INTO CONTACT(Nom, Prenom, Entreprise, Mail, Telephone, Photo, Date) VALUES(:n, :p, :e, :m, :t, :ph, :d);");
    query.bindValue(":n", QString::fromStdString(contact.getNom()));
    query.bindValue(":p", QString::fromStdString(contact.getPrenom()));
    query.bindValue(":e", QString::fromStdString(contact.getEntreprise()));
    query.bindValue(":m", QString::fromStdString(contact.getMail()));
    query.bindValue(":t", QString::fromStdString(contact.getTelephone()));
    query.bindValue(":ph", QString::fromStdString(contact.getPhoto()));
    query.bindValue(":d", QString::fromStdString(contact.getDate().toString()));
    if(!query.exec()){
        qDebug() << "Impossible d'ajouter un contact !";
    }
    else{
        qDebug() << "Contact a ete cree";
        QSqlQuery logQuery;
        std::string logMsg;
        Date date;
        logMsg = "Creation d'un nouveau contact : " + contact.getNom() + " " + contact.getPrenom() +
                 "\n" + "ID : " + contact.getMail();
        logQuery.prepare("INSERT INTO LOGS (Contenu, Date) VALUES (:contenu, :date )");
        logQuery.bindValue(":contenu", QString::fromStdString(logMsg));
        logQuery.bindValue(":date", QString::fromStdString(date.toString()));
        logQuery.exec();
    }

}

/*!
 * \brief BaseDeDonnee::AjtInteraction
 *  Méthode ( slot ) qui permet l'ajout d'une interaction, on récupère en paramètre l'interaction  emit dans le signal ainsi que le contact a qui l'interaction est destinée
 *  par le Widget principale et on l'intègre à la table.
 *  On récupère l'adresse mail du contact qui sera le Cid de l'interaction,
 *  si l'interaction possède des todo on les récupère à l'aide d'une boucle et on les inserts en prenant comme Iid l'InterId de leurs interaction
 *
 * On insère dans les logs l'ajout d'interaction.
 * \param contact
 * \param inter
 */

void BaseDeDonnee::AjtInteraction(Contact contact,Interaction inter){
    QSqlQuery query;
    query.prepare("INSERT INTO Interaction (Cid, Contenu, Date) VALUES (:cid, :contenu, :date);");
    query.bindValue(":cid",  QString::fromStdString(contact.getMail()));
    query.bindValue(":contenu",  QString::fromStdString(inter.getContenu()));
    query.bindValue(":date",  QString::fromStdString(inter.getDate().toString()));

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'ajout de l'interaction ";
    } else {



    int interactionId = query.lastInsertId().toInt();
    int nbTodo = 0;

    for (Todo* todo : inter.getLstTodo()) {
        QSqlQuery todoQuery;
        todoQuery.prepare("INSERT INTO TODO (Iid, Contenu, Date) VALUES (:iid, :contenu, :date);");
        todoQuery.bindValue(":iid", interactionId);
        todoQuery.bindValue(":contenu",  QString::fromStdString(todo->getContenu()));
        todoQuery.bindValue(":date",  QString::fromStdString(todo->getDate().toString()));

        nbTodo++;
        if (!todoQuery.exec()) {
            qDebug() << "Erreur lors de l'ajout du Todo :" ;
             }
        }

         qDebug() << "Interaction creee avec succes pour le contact" << contact.getNom();


         QSqlQuery logQuery;
         std::string logMsg;
         Date date;
         logMsg = "Creation d'une nouvelle interaction pour : " + contact.getNom() + " " + contact.getPrenom() +
                  "\n" + "ID : " + contact.getMail() +
                  "\n" + "interaction : " + inter.getContenu() +
                  "\n" + "l'interaction comporte " + std::to_string(nbTodo) + " todos.";
         logQuery.prepare("INSERT INTO LOGS (Contenu, Date) VALUES (:contenu, :date )");
         logQuery.bindValue(":contenu", QString::fromStdString(logMsg));
         logQuery.bindValue(":date", QString::fromStdString(date.toString()));
         logQuery.exec();
    }
}

/*!
 * \brief BaseDeDonnee::MdfContact
 * Méthode (slot) qui permet de modifier un contact.
 * On récupère en paramètre le contact1 qui est le contact à modifier et le contact2 qui est le contact par lequel on remplace le contact1,
 * on update les attributs du contact1 avec ceux du contact2.
 *
 * Dans le cas ou on change l'adresse mail, on vas venir changer le Cid des interactions du contact mofiée afin que la liaison contact/interaction reste la même.
 *
 * On insère dans les logs la modification de contact.
 * \param contact1
 * \param contact2
 */

void BaseDeDonnee::MdfContact(Contact contact1, Contact  contact2) {
    QSqlQuery query;

    qDebug() << "c1 :" <<contact1.getNom();
    qDebug() << "c2 :" <<contact2.getNom();

    query.prepare("UPDATE CONTACT SET Nom = :n, Prenom = :p, Entreprise = :e, Mail = :m, Telephone = :t, Photo = :ph, Date = :d WHERE Mail = :oldMail;");
    query.bindValue(":n", QString::fromStdString(contact2.getNom()));
    query.bindValue(":p", QString::fromStdString(contact2.getPrenom()));
    query.bindValue(":e", QString::fromStdString(contact2.getEntreprise()));
    query.bindValue(":m", QString::fromStdString(contact2.getMail()));
    query.bindValue(":t", QString::fromStdString(contact2.getTelephone()));
    query.bindValue(":ph", QString::fromStdString(contact2.getPhoto()));
    query.bindValue(":d", QString::fromStdString(contact2.getDate().toString()));
    query.bindValue(":oldMail", QString::fromStdString(contact1.getMail()));


    if (!query.exec()) {
        qDebug() << "Impossible de mettre a jour le contact !";
    }

    if (contact1.getMail() != contact2.getMail()) {
        query.prepare("UPDATE Interaction SET Cid = :newMail WHERE Cid = :oldMail");
        query.bindValue(":newMail", QString::fromStdString(contact2.getMail()));
        query.bindValue(":oldMail", QString::fromStdString(contact1.getMail()));

        if (!query.exec()) {
            qDebug() << "Impossible de mettre à jour l'Interaction du contact modifie !";
        } else {
            qDebug() << "Interaction du contact modifie a ete mise a jour";
        }

    } else {
        qDebug() << "Contact a ete mis a jour";


        QSqlQuery logQuery;
        std::string logMsg;
        Date date;
        logMsg = "Modification du contact : \n"
                  + contact1.getNom() + " " + contact1.getPrenom() +
                 "\n" + contact1.getEntreprise() +
                 "\n" + contact1.getMail() +
                 "\n" + contact1.getTelephone() +
                 "\n" + contact1.getPhoto() +
                 "\n" + contact1.getPhoto() +
                 "\n" + contact1.getDate().toString() +
                 "\n" +
                 "\n" +
                 "Contact apres modification : \n"
                 + contact2.getNom() + " " + contact2.getPrenom() +
                 "\n" + contact2.getEntreprise() +
                 "\n" + contact2.getMail() +
                 "\n" + contact2.getTelephone() +
                 "\n" + contact2.getPhoto() +
                 "\n" + contact2.getPhoto() +
                 "\n" + contact2.getDate().toString();



        logQuery.prepare("INSERT INTO LOGS (Contenu, Date) VALUES (:contenu, :date )");
        logQuery.bindValue(":contenu", QString::fromStdString(logMsg));
        logQuery.bindValue(":date", QString::fromStdString(date.toString()));
        logQuery.exec();

    }
}

/*!
 * \brief BaseDeDonnee::SuppressionContact
 * Méthode (slot) qui prend en paramètre le contact à supprimer.
 * on récupère le mail du contact et on supprime le contact possèdant le mail ainsi que toute les interactions liée à ce contact et leurs todos.
 *
 * On insère dans les logs la suppression de contact.
 * \param contact
 */

void BaseDeDonnee::SuppressionContact(Contact contact){
    QSqlQuery query;

    query.prepare("DELETE FROM TODO WHERE Iid IN (SELECT InterID FROM INTERACTION WHERE Cid = :mail)");
    query.bindValue(":mail", QString::fromStdString(contact.getMail()));
    query.exec();

    query.prepare("DELETE FROM INTERACTION WHERE Cid = :mail");
    query.bindValue(":mail", QString::fromStdString(contact.getMail()));
    query.exec();

    query.prepare("DELETE FROM CONTACT WHERE Mail = :mail");
    query.bindValue(":mail", QString::fromStdString(contact.getMail()));
    if(!query.exec()){

        qDebug() << "Erreur Suppression : La suppression du contact "+ contact.getNom()+  contact.getPrenom()+"a echoue";
    }
    else
    {
         qDebug() << "Suppression : Le contact "+ contact.getNom()+  contact.getPrenom()+"a ete supprime";

        QSqlQuery logQuery;
        std::string logMsg;
        Date date;
        logMsg = "Supression du contact : " + contact.getNom() + " " + contact.getPrenom() + " et de ses interactions.";
        logQuery.prepare("INSERT INTO LOGS (Contenu, Date) VALUES (:contenu, :date )");
        logQuery.bindValue(":contenu", QString::fromStdString(logMsg));
        logQuery.bindValue(":date", QString::fromStdString(date.toString()));
        logQuery.exec();

    }


};

/*!
 * \brief BaseDeDonnee::SuppressionInteraction
 * Méthode ( slot ) qui récupère en paramètre l'interaction a supprimer ainsi que le mail,
 * le mail vas permettre de d'affirmer que l'interaction supprimée est bien celle du contact choisis et non pas un autre contact avec l'interaction identique.
 * on ompare le contenu de l'interaction avec celles dans la table pour supprimer la bonne.
 *
 * On insère dans les logs la suppresion d'interaction.
 * \param inter
 * \param mail
 */

void BaseDeDonnee::SuppressionInteraction(Interaction inter, std::string mail) {
    QSqlQuery query;
    query.prepare("SELECT InterID FROM INTERACTION WHERE Cid = :mail AND Contenu = :contenu AND Date = :date");
    query.bindValue(":mail", QString::fromStdString(mail));
    query.bindValue(":contenu", QString::fromStdString(inter.getContenu()));
    query.bindValue(":date", QString::fromStdString(inter.getDate().toString()));

    if (query.exec()) {
        while (query.next()) {
            int interID = query.value(0).toInt();
            bool match = true;


            for (Todo* todo : inter.getLstTodo()) {
                QSqlQuery todoQuery;
                todoQuery.prepare("SELECT COUNT(*) FROM TODO WHERE Iid = :interID AND Contenu = :contenu AND Date = :date");
                todoQuery.bindValue(":interID", interID);
                todoQuery.bindValue(":contenu", QString::fromStdString(todo->getContenu()));
                todoQuery.bindValue(":date", QString::fromStdString(todo->getDate().toString()));

                if (todoQuery.exec() && todoQuery.next()) {
                    if (todoQuery.value(0).toInt() == 0) {
                        match = false;
                        break;
                    }
                }
            }

            if (match) {

                QSqlQuery deleteTodoQuery;
                deleteTodoQuery.prepare("DELETE FROM TODO WHERE Iid = :interID");
                deleteTodoQuery.bindValue(":interID", interID);
                deleteTodoQuery.exec();


                QSqlQuery deleteInteractionQuery;
                deleteInteractionQuery.prepare("DELETE FROM INTERACTION WHERE InterID = :interID");
                deleteInteractionQuery.bindValue(":interID", interID);
                deleteInteractionQuery.exec();

                qDebug() << "Interaction et todos supprimés avec succès";
                break;




            }
        }
        QSqlQuery logQuery;
        std::string logMsg;
        Date date;
        logMsg = "Suppression interaction : \n ID : " + mail +
                 "\n" + "interaction : " + inter.getContenu() +
                 "\n" + " ainsi que tout ses todo";
        logQuery.prepare("INSERT INTO LOGS (Contenu, Date) VALUES (:contenu, :date )");
        logQuery.bindValue(":contenu", QString::fromStdString(logMsg));
        logQuery.bindValue(":date", QString::fromStdString(date.toString()));
        logQuery.exec();
    }
    else {
    qDebug() << "Aucune interaction correspondante trouvée";
    }
}



/*!
 * \brief BaseDeDonnee::getToutContacts
 * Méthode ( slot ) qui permet de récuperer dans une liste de contact tout les contacts de la base de données.
 * on parcour toute la base et à chaque contact on l'insert dans la list avec ses interactions et ses todos respectifs.
 *
 * On emet ensuite un signal vers le Widget principale avec dans ce signal la liste de contacts.
 */
void BaseDeDonnee::getToutContacts() {
    GestionnaireContact Gc;

    QSqlQuery queryContact;
    queryContact.exec("SELECT * FROM CONTACT");

    while (queryContact.next()) {
        Contact* contact = new Contact();



        contact->setNom(queryContact.value("Nom").toString().toStdString());
        contact->setPrenom(queryContact.value("Prenom").toString().toStdString());
        contact->setEntreprise(queryContact.value("Entreprise").toString().toStdString());
        contact->setMail(queryContact.value("Mail").toString().toStdString());
        contact->setTelephone(queryContact.value("Telephone").toString().toStdString());
        contact->setPhoto(queryContact.value("Photo").toString().toStdString());

        contact->setDate(toDate(queryContact.value("Date").toString().toStdString()));


        QString contactMail = queryContact.value("Mail").toString();


        QSqlQuery queryInteraction;
        queryInteraction.prepare("SELECT * FROM INTERACTION WHERE Cid = :contactMail");
        queryInteraction.bindValue(":contactMail", contactMail);

        if (queryInteraction.exec()) {
            while (queryInteraction.next()) {
                Interaction* interaction = new Interaction();

                interaction->setContenu(queryInteraction.value("Contenu").toString().toStdString());
                interaction->setDate(toDate(queryInteraction.value("Date").toString().toStdString()));

                int interactionID = queryInteraction.value("InterID").toInt();


                QSqlQuery queryTodo;
                queryTodo.prepare("SELECT * FROM TODO WHERE Iid = :interactionID");
                queryTodo.bindValue(":interactionID", interactionID);

                if (queryTodo.exec()) {
                    while (queryTodo.next()) {
                        Todo* todo = new Todo();

                        todo->setContenu(queryTodo.value("Contenu").toString().toStdString());
                        todo->setDate(toDate(queryTodo.value("Date").toString().toStdString()));

                        interaction->addTodo(todo);
                    }
                }


                contact->AddInteraction(interaction);
            }
        }

        Gc.addContact(contact);
    }


    emit RefreshGC(Gc);
}

/*!
 * \brief BaseDeDonnee::VerifMail
 * Méthode ( slot ) qui est appellée lors de l'ajout d'un contact ou bien de la modification d'un contact.
 * La méthode vérifie si le mail qui est l'id du contact n'est pas déjà présent dans la Base de données.
 * le mail en paramètre est le mail a vérifier et le type correspond au signal qui provient soit de l'ajout contact , soit de la modification contact(donc deux signaux différents).
 *
 * si le type est "ajout" alors on emet un signal pour valider ou non la vérifiaction de mail avec dans ce signal un booleen ( false si le mail existe , true si il existe pas ) .
 * \param mail
 * \param type
 */

void BaseDeDonnee::VerifMail(QString mail,std::string type) {
    QSqlQuery query;
    query.prepare("SELECT Mail FROM CONTACT WHERE Mail = :mail");
    query.bindValue(":mail", mail);

    if (query.exec()) {
        if (query.next()) {
            // Le mail existe
            if(type == "ajout"){
                emit mailVerificationAjout(false);
            } else {
                emit mailVerificationModif(false);
            }

        } else {
            // Le mail existe pas
            if(type == "ajout"){
                emit mailVerificationAjout(true);
            } else {
                emit mailVerificationModif(true);
            }
        }
    } else {

        qDebug() << "Erreur lors de la vérification du mail";
    }
}

/*!
 * \brief BaseDeDonnee::getLogs
 * Méthode (slot) qui permet de récuperer les logs dans une list de string ou chaque string correspond à une ligne de log.
 * on emet ensuite un signal vers le Widget principale pour integrer cette liste au tableau de logs.
 */
void BaseDeDonnee::getLogs(){
    QSqlQuery query("SELECT Date, Contenu FROM LOGS");
    std::list<QString> logListe;

    while (query.next()) {
        QString date = query.value("Date").toString();
        QString contenu = query.value("Contenu").toString();
        QString log = date + ": \n\n" + contenu;
        logListe.push_back(log);
    }


    emit RefreshLogsBDD(logListe);
}


/*!
 * \brief BaseDeDonnee::toDate
 * Méthode qui permet de transformer une date sous forme de string entrée en paramètre en une date de type Date
 * et de la return.
 * ( ref Class Date )
 * \param date
 * \return d
 */

Date BaseDeDonnee::toDate(const std::string date){
    Date* d = new Date(01,01,2000);
    std::istringstream ss(date);
    char slash;
    int jour, mois, annee;

    ss >>  jour >> slash >> mois >> slash >> annee;
    d->setDate(jour,mois,annee);

    return *d;

}

