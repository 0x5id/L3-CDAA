#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <GestionnaireContact.h>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>


/*!
 * \file mainwindow.cpp
 * \brief Classe qui génère le MainWindow.
 * Le MainWindow vas servir en plus de receuillir de Widget principale à pouvoir générer un fichier JSON qui contient les contacts
 * et afficher les logs dans la fenêtre prévue à cet effet dans le Widget principale.
 * \class mainwindow
 */


/*!
 * \brief MainWindow::MainWindow
 * Contructeur de la classe MainWindow
 * Initialisation de Widget principale et connexion des SIGNAUX / SLOTS.
 * \param parent
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    // initialisation de Widget principale et insertion au MainWindow
    PrinWidget = new PrincipaleWidget();
    this->ui->MainLayout->addWidget(PrinWidget);


    // permet de récuperer dans la variable globale la liste des contact pour générer ensuite le fichier JSON
    connect(this->PrinWidget, SIGNAL(setContacts(GestionnaireContact)),this,SLOT(getContacts(GestionnaireContact)));

    // bouttons du menu permettant de lancer la creation du fichier JSON et l'affichage des logs dans le Widget principale.
    connect(this->ui->AExporterJSON,SIGNAL(triggered()),this,SLOT(ExporterJson()));
    connect(this->ui->AAfficheLogs,SIGNAL(triggered()),this->PrinWidget,SLOT(onAfficheLogs()));



    // signal emit au Widget principale pour rafraichir cette même fenêtre avec les contacts dans la BDD.
    connect(this, SIGNAL(RefreshContacts()), this->PrinWidget, SLOT(RefreshListeContact()));
    emit RefreshContacts();

}


/*!
 * \brief MainWindow::~MainWindow
 * Destructeur de la class MainWindow
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/*!
 * \brief MainWindow::getContacts
 * Méthode ( Slot ) qui récupère en paramètre la liste de contact envoyé par signaux et la charge dans la variable globale de cette classe.
 * \param GestC
 */
void MainWindow::getContacts(GestionnaireContact GestC){
    Gc = GestC;
}

/*!
 * \brief MainWindow::ExporterJson
 * Méthode qui permet de générer un fichier JSON.
 * On demande dans un premier temps à l'utilisateur de choisir un répertoire,
 * on vient ensuite créer les QJsonArray et QJsonObject necessaires et on parcour la liste de contacts via une boucle,
 * dans cette même boucle on parcour les interactions de chaque contact via une autre boucle,
 * puis dans cette deuxième boucle on parcour la liste des Todos de chaque interaction à l'aide d'une troisième boucle.
 *
 * On ajout les informations récupérées dans nos Array puis on les insert dans le fichier JSON.
 *
 */

void MainWindow::ExporterJson()
{
    QString chemin = QFileDialog::getExistingDirectory(this, tr("Sélectionner un répertoire"), QDir::homePath());

        if (!chemin.isEmpty()) {




            QJsonArray listeContact;
            QJsonObject contactListe;
            QJsonArray contactsArray;

            for (const auto& contact : Gc.getLstContacts()) {

                QJsonObject contactObject;
                contactObject.insert("Nom",QString::fromStdString(contact->getNom()));
                contactObject.insert("Prenom",QString::fromStdString(contact->getPrenom()));
                contactObject.insert("Entreprise",QString::fromStdString(contact->getEntreprise()));
                contactObject.insert("Mail",QString::fromStdString(contact->getMail()));
                contactObject.insert("Telephone",QString::fromStdString(contact->getTelephone()));
                contactObject.insert("Date",QString::fromStdString(contact->getDate().toString()));
                contactObject.insert("Photo",QString::fromStdString(contact->getPhoto()));





                QJsonArray interactionsArray;


                for (const auto& interaction : contact->getLstInteractions()) {
                    QJsonObject interactionObject;
                    interactionObject.insert("Contenu",QString::fromStdString(interaction->getContenu()));
                    interactionObject.insert("Date",QString::fromStdString(interaction->getDate().toString()));


                    QJsonArray todosArray;


                    for (const auto& todo : interaction->getLstTodo()) {
                        QJsonObject todoObject;
                        todoObject.insert("Contenu",QString::fromStdString(todo->getContenu()));
                        todoObject.insert("Date",QString::fromStdString(todo->getDate().toString()));


                        todosArray.append(todoObject);
                    }

                    interactionObject.insert("Todos",todosArray);
                    interactionsArray.append(interactionObject);
                }

                contactObject.insert("Interactions",interactionsArray);
                contactsArray.append(contactObject);


            }

            contactListe.insert("Contacts",contactsArray);
            listeContact.append(contactListe);

            QJsonDocument jsonDocument(listeContact);


            QFile file(chemin + "/GestionContact.json");
            if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                QTextStream out(&file);
                out << jsonDocument.toJson();
                file.close();
            }
        }


}

