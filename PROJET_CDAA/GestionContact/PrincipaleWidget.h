#ifndef PRINCIPALEWIDGET_H
#define PRINCIPALEWIDGET_H

#include <QWidget>
#include <QTableView>
#include <AjoutContact.h>
#include <AjoutInteraction.h>
#include <AfficheContact.h>
#include <ModifContact.h>
#include <ListeInteraction.h>
#include <QCalendarWidget>
#include <QTableWidgetItem>

/*!
 * @file PrincipaleWidget.h
 * @brief Classe qui permet de générer le Widget Principale
 * L'interface vas permettre d'accèder à toutes les fonctionnalités de notre application hormis celles dans le mainwindow,
 * tout ça par le biais de Widget enfants qui s'afficheront dans un espace prévu à leurs affichage.
 * L'utilisateur pourras donc jongler entre les fonctionnalitées sans changer entièrement la page ou bien sans ouvrir de fenêtre supplémentaires,
 * ainsi une certaine fluidité et facilité de manipulation est conservée.
 * @var bool DateAB;
 * @var int contactId;
 * @var AjoutContact* ajtContact;
 * @var AfficheContact* afficheContactUI;
 * @var ModifContact* mdfContact;
 * @var AjoutInteraction* ajtInteraction;
 * @var ListeInteraction* listeInteraction;
 * @var QCalendarWidget* Cal;
 * @var BaseDeDonnee BaseDD;
 * @var GestionnaireContact Gc;
 * @var Contact * selectedContact;
 * @var QTextEdit * afficheLogs;
 */

namespace Ui {
class PrincipaleWidget;
}

class PrincipaleWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PrincipaleWidget(QWidget *parent = nullptr);
    ~PrincipaleWidget();

    bool DateAB;
    int contactId;

    Ui::PrincipaleWidget *ui;
    AjoutContact* ajtContact;
    AfficheContact* afficheContactUI;
    ModifContact* mdfContact;
    AjoutInteraction* ajtInteraction;
    ListeInteraction* listeInteraction;
    QCalendarWidget* Cal;
    BaseDeDonnee BaseDD;
    GestionnaireContact Gc;
    Contact * selectedContact;
    QTextEdit * afficheLogs;

public slots:
    void onAjoutContactClicked();
    void onAfficheIntersClicked();
    void ChoixDateA();
    void ChoixDateB();
    void ActuLigneDate();
    void RefreshListeContact();
    void onModificationContact();
    void onAjoutInteraction();
    void onAnnulationModif();
    void onAnnulationInteraction();
    void BDD_AjoutContact(Contact contact);
    void BDD_ModifContact(Contact contact1,Contact contact2);
    void BDD_SupprContact();
    void BDD_AjoutInteraction(Interaction inter);
    void BDD_SupprInteraction(Interaction inter, std::string mail);
    void onAfficheLogs();
    void RefreshLogs(std::list<QString> logListe);
    void onContactClique(int row,int);
    void RefreshGestionnaireContact(GestionnaireContact GestC);

signals:
    void RefreshContacts();
    void getLogs();
    void RefreshGC();
    void RefreshAffiche(Contact * selectedContact);
    void RefreshListInter(GestionnaireContact Gc);
    void refreshInteractionForm(Contact * selectedContact);
    void initModifContact(Contact * selectedContact);
    void BaseDDAjtContact(Contact contact);
    void BaseDDMdfContact(Contact contact1, Contact contact2);
    void BaseDDAjtInteraction(Contact selectedContact,Interaction inter);
    void BaseDDSuppressionInteraction(Interaction inter, std::string mail);
    void BaseDDSuppressionContact(Contact selectedContact);
    void setContacts(GestionnaireContact GestC);


};

#endif // PRINCIPALEWIDGET_H
