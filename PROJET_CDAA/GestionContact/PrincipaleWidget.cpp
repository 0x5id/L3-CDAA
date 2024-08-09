#include "PrincipaleWidget.h"
#include "qobjectdefs.h"
#include "ui_PrincipaleWidget.h"
#include "QDebug"
#include <QTableWidgetItem>

/*!
 * \file PrincipaleWidget.cpp
 * \brief Classe qui génère le Widget principale.
 * PrincipaleWidget est le Widget principale qui vas servir à l'affichage de toutes les interfaces enfant ,
 * l'utilisateur lui aura toujours un oeil sur la liste de contact tandis qu'il pourra intéragir avec ces mêmes contacts,
 * il pourra par la même occasion rechercher des contact dans cette liste par des critères ou bien par intervalles de dates.
 *
 * Ce Widget évite de changer complétement la fenêtre ou bien d'en ouvrir une nouvelle extérieur à l'application
 * chaque fois qu'il est nécessaire et apporte une fluidité et une compléxité moindre à l'application,
 * de ce fait ce Widget sera le seul à communiquer directement avec la Base de donnée,
 * il se chargera de recevoir les signaux des Widgets enfants puis les renvoyer vers la base de donnée tout en ajustant les affichages lorsque nécessaire.
 *
 * Ce widget permet donc la recherche dans une liste de contact , l'affichage de la liste de contact
 * et permet la communication avec les Widget enfants et la BDD comme :
 * - l'ajout de contact
 * - la modification de contact
 * - l'affichage des informations du contact
 * - l'ajout d'une interaction à un contact
 * - l'affichage des interactions de tout les contacts
 *
 * \class PrincipaleWidget
 */

/*!
 * \brief PrincipaleWidget::PrincipaleWidget
 * Constucteur de la classe PrincipaleWidget.
 * Initialisation des QWidget enfants qui seront affichés à la demande de l'utilisateur via des bouttons et signaux.
 * Ajout de ces QWidjet au layout prévu à leurs emplacement et on met leurs état visible à false.
 * Initialisation des signaux / slot qui servent à la recherche par intervalle de Date.
 * Initialisation du Combobox qui sert à la recherche par mot clé dans la liste de contact.
 * Initialisation des signaux / slot qui communiquent entre et avec tout les QWidget enfants.
 * \param parent
 */

PrincipaleWidget::PrincipaleWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PrincipaleWidget)
{
     ui->setupUi(this);

   // initialisation des Widgets
     selectedContact= new Contact;
     afficheContactUI = new AfficheContact();
     ajtContact = new AjoutContact();
     afficheLogs = new QTextEdit();
     mdfContact = new ModifContact();
     ajtInteraction = new AjoutInteraction();
     listeInteraction = new ListeInteraction();




    // ajout de tout les Widgets au layout du widget Principale

     this->ui->Main_tableLayout->addWidget(afficheContactUI);
     this->ui->Main_tableLayout->addWidget(ajtContact);
     this->ui->Main_tableLayout->addWidget(mdfContact);
     this->ui->Main_tableLayout->addWidget(ajtInteraction);
     this->ui->Main_tableLayout->addWidget(listeInteraction);
     this->ui->Main_tableLayout->addWidget(afficheLogs);
     this->ajtInteraction->hide();
     this->ajtContact->hide();
     this->mdfContact->hide();
     this->afficheContactUI->hide();
     this->afficheLogs->hide();
     this->listeInteraction->hide();

     this->afficheLogs->setReadOnly(true);



     //https://doc.qt.io/qt-6/qdate.html
     //https://doc.qt.io/qt-6/qcalendarwidget.html

     // initialisation du calendrier pour la recherche de date ainsi que les signaux de leurs bouttons
     // et des line edit qui contiennent les valeurs de ces dates

     Cal = new QCalendarWidget();

     connect(this->ui->BouttonDateA,SIGNAL(clicked()),this,SLOT(ChoixDateA()));
     connect(this->ui->BouttonDateB,SIGNAL(clicked()),this,SLOT(ChoixDateB()));
     connect(this->Cal,SIGNAL(selectionChanged()),this,SLOT(ActuLigneDate()));

     this->ui->LigneDateA->setText("01/01/2000");
     this->ui->LigneDateB->setText("31/12/2100");
     this->Cal->setDateRange(QDate::fromString("01/01/2000",QString("dd/MM/yyyy")), QDate::fromString("31/12/2100",QString("dd/MM/yyyy") ));

     // initialisation des différents criteres de recherche

     this->ui->CritereCB->addItem("Aucun");
     this->ui->CritereCB->addItem("Nom");
     this->ui->CritereCB->addItem("Prenom");
     this->ui->CritereCB->addItem("Entreprise");
     this->ui->CritereCB->addItem("Mail");
     this->ui->CritereCB->addItem("Telephone");
     this->ui->CritereCB->addItem("Date");




    // permet de raffraichir la liste de contact en émétant un signal à la BDD
    // la BDD emet la liste de contact et on la charge dans un variable globale.
     connect(this, SIGNAL(RefreshGC()), &BaseDD,SLOT(getToutContacts()));
     connect(&BaseDD, SIGNAL(RefreshGC(GestionnaireContact)), this, SLOT(RefreshGestionnaireContact(GestionnaireContact)));

    // permet de raffrachir la liste de contact dans le QTableWidget avec la liste de contact
     connect(this, SIGNAL(RefreshContacts()), this, SLOT(RefreshListeContact()));

    // signaux qui permettent de rafraichir la liste de contact en fonction de la recherche et du critère
     connect(this->ui->RechercheLine, SIGNAL(textChanged(QString)), this, SLOT(RefreshListeContact()));
     connect(this->ui->CritereCB, SIGNAL(currentTextChanged(QString)), this, SLOT(RefreshListeContact()));

    //permet d'afficher le QTableWidget Liste Interaction
     connect(this->ui->AfficheInters,SIGNAL(clicked()),this,SLOT(onAfficheIntersClicked()));
    // permet de raffraichir la liste d'interaction dans le QTableWidget Liste Interaction
     connect(this, SIGNAL(RefreshListInter(GestionnaireContact)), this->listeInteraction,SLOT(RefreshListInter(GestionnaireContact)));

    // permet de mettre à jour les logs , signal émit à la BDD
    // la BDD renvoie un signal avec la liste de string qui contiennent les logs
     connect(this, SIGNAL(getLogs()), &BaseDD, SLOT(getLogs()));
     connect(&BaseDD, SIGNAL(RefreshLogsBDD(std::list<QString>)), this, SLOT(RefreshLogs(std::list<QString>)));

    // apparition des fenêtres Ajout Contact sur le Widget Principale
    // on vas cacher toute les autres fenêtres si dans le cas ou l'une d'elle est ouverte
     connect(this->ui->AjoutContact,SIGNAL(clicked()),this,SLOT(onAjoutContactClicked()));
    // verification mail existant ajout contact
     connect(this->ajtContact, SIGNAL(VerifMail(QString,std::string)),&BaseDD,SLOT(VerifMail(QString,std::string)));
     connect(&BaseDD, SIGNAL(mailVerificationAjout(bool)),this->ajtContact,SLOT(ValideMail(bool)));
    // envoie de signale depuis le widget d'ajout contact vers la BDD pour ajouter le contact
    // rafraichissement de la liste de contact
     connect(this->ajtContact,SIGNAL(BDDAjoutContact(Contact)),this,SLOT(BDD_AjoutContact(Contact)));
     connect(this, SIGNAL(BaseDDAjtContact(Contact)),&BaseDD,SLOT(AjtContact(Contact)));
     connect(this->ajtContact,SIGNAL(UIListeContactRefresh()),this,SLOT(RefreshListeContact()));



    // signal emis lorsque l'on clique sur un contact
    // on vas cacher toute les autres fenêtres si dans le cas ou l'une d'elle est ouverte
    // on ouvre la fenêtre Affiche Contact
    // la fenêtre est rafraichie avec les données du contact selectionné
     connect(this->ui->CtctListe, SIGNAL(cellClicked(int,int)), this, SLOT(onContactClique(int,int)));
     connect(this,SIGNAL(RefreshAffiche(Contact*)),this->afficheContactUI,SLOT(RefreshAffiche(Contact*)));


    // signal émis lorsque l'on clique sur le boutton "modifier contact" dans la fenêtre Affiche Contact
    // on vas cacher toute les autres fenêtres si dans le cas ou l'une d'elle est ouverte
    // on ouvre la fenêtre Modif Contact
     connect(this->afficheContactUI,SIGNAL(ModificationContact()),this,SLOT(onModificationContact()));
    // la page de modification est chargée avec les données du contact pour éviter de réecrire les données qu'on ne touche pas
     connect(this, SIGNAL(initModifContact(Contact*)),this->mdfContact,SLOT(initModifContact(Contact*)));
    // verification mail existant modification contact
     connect(this->mdfContact, SIGNAL(VerifMail(QString,std::string)),&BaseDD,SLOT(VerifMail(QString,std::string)));
     connect(&BaseDD, SIGNAL(mailVerificationModif(bool)),this->mdfContact,SLOT(ValideMail(bool)));
    // on envoie les données du contact que l'on change et celle du contact que le veut pour modifier la BDD
     connect(this->mdfContact,SIGNAL(BDDModifContact(Contact,Contact)),this,SLOT(BDD_ModifContact(Contact,Contact)));
     connect(this,SIGNAL(BaseDDMdfContact(Contact,Contact)),&BaseDD,SLOT(MdfContact(Contact,Contact)));
    // une fois fait on raffraichi la liste de contact
     connect(this->mdfContact,SIGNAL(UIListeContactRefresh()),this,SLOT(RefreshListeContact()));
    // ce signal est emit dans le cas ou on arrête notre modification
    // la page Modif Contact se ferme pour laisser place à Affiche Contact.
     connect(this->mdfContact,SIGNAL(AnnuleModif()),this,SLOT(onAnnulationModif()));

    // signal émis lorsque l'on clique sur le boutton "Ajouter Interaction" dans la fenêtre Affiche Contact
    // on vas cacher toute les autres fenêtres si dans le cas ou l'une d'elle est ouverte
    // on ouvre la fenêtre Ajout Interaction
     connect(this->afficheContactUI,SIGNAL(AjoutInteraction()),this,SLOT(onAjoutInteraction()));
    // dans le cas ou on valide l'interaction on emet l'interaction dans un signal vers la bdd avec le contact
    // afin d'ajouter l'interaction au bon contact.
     connect(this->ajtInteraction,SIGNAL(BDDAjoutInteraction(Interaction)),this,SLOT(BDD_AjoutInteraction(Interaction)));
     connect(this,SIGNAL(BaseDDAjtInteraction(Contact,Interaction)),&BaseDD,SLOT(AjtInteraction(Contact,Interaction)));
    // une fois fait on rafraichit la page
     connect(this,SIGNAL(refreshInteractionForm(Contact*)),this->ajtInteraction,SLOT(refreshInteractionForm(Contact*)));
    // signal emit dans le cas on ou annule l'ajout , la fenêtre est fermée pour laisse place à Affiche Contact
     connect(this->ajtInteraction,SIGNAL(AnnuleAjoutInteraction()),this,SLOT(onAnnulationInteraction()));

    // signal envoyé lors de la demande de suppression d'un contact
     connect(this->afficheContactUI,SIGNAL(SuppressionContact()),this,SLOT(BDD_SupprContact()));
     connect(this,SIGNAL(BaseDDSuppressionContact(Contact)),&BaseDD,SLOT(SuppressionContact(Contact)));

    //signal envoyé lors de la demande de suppression d'une interaction d'un contact
     connect(this->afficheContactUI,SIGNAL(SuppressionInteraction(Interaction,std::string)),this,SLOT(BDD_SupprInteraction(Interaction,std::string)));
     connect(this,SIGNAL(BaseDDSuppressionInteraction(Interaction,std::string)),&BaseDD,SLOT(SuppressionInteraction(Interaction,std::string)));

}


/*!
 * \brief PrincipaleWidget::~PrincipaleWidget
 * Destructeur de la classe PrincipaleWidget.
 */

PrincipaleWidget::~PrincipaleWidget()
{
    delete ui;
}

/*!
 * \brief PrincipaleWidget::onContactClique
 * Méthode(slot) qui permet de récuperer le contact sur lequel on clique dans la liste de contact.
 * Comme paramètre row qui est la valeur de la ligne selectionnée.
 * Le signal qui permet de recuperer la ligne oblige aussi un second paramètre pour la colonne mais n'étant pas nécessaire on est pas obliger de l'initialiser.
 * une fois cliqué sur le contact le signal envoie la valeur de la ligne ( row ) ce qui nous permet d'aller récuperer l'id de l'item
 * du contact qui est dans une colonne cachée,
 * l'ID récupéré est tout simplement l'index de la ligne du contact.
 * L'id du contact à la ligne 3 est 3.
 *
 * On utilise une méthode pour cherche le contact dans la variable liste de contact globale à la classe grace à l'id qu'on vient de récuperer.
 * On utilise cette méthode car la liste de contact de l'application est généré dans l'ordre de la variable liste de contact.
 *
 * une fois qu'on a le contact on le charge dans une variable contact global qui servira au actions réalisable avec ce même contact ,
 * comme sa suppression , son affichage , sa modification.....
 *
 * Par la suite on envoie un signal pour rafraichir le Widget enfant Affiche Contact avec dans le signal le contact qu'on vient de récuperer.
 * Ainsi l'affiche contact affichera les information de ce contact.
 *
 * On fini par afficher l'affiche contact dans le Label prévu à son emplacement et on ferme toute fenêtre succeptible d'être ouverte à ce moment là.
 *
 * \param row
 */

void PrincipaleWidget::onContactClique(int row,int)
{

    QTableWidgetItem *idItem = this->ui->CtctListe->item(row, 1);
    if (idItem) {
        QString id = idItem->text();
        contactId = id.toInt();

        selectedContact = Gc.getContactAt(contactId);

        emit RefreshAffiche(selectedContact);

        if(!this->afficheContactUI->isVisible()){
            this->afficheContactUI->setVisible(true);
            this->ajtContact->setVisible(false);
            this->mdfContact->setVisible(false);
            this->ajtInteraction->setVisible(false);
            this->listeInteraction->setVisible(false);
            this->afficheLogs->setVisible(false);

        }

    }
}


/*!
 * \brief PrincipaleWidget::onAjoutContactClicked
 * Méthode ( slot ) qui permet d'afficher le formulaire d'ajout de contact.
 * Lorsque l'utilisateur appuie sur le boutton " Ajout Contact " dans le Widget principale , le Widget principale va faire appraitre la fenêtre
 * et va fermer toute fenêtre succeptible d'être ouverte à ce moment là.
 */

void PrincipaleWidget::onAjoutContactClicked()
{

    if(!this->ajtContact->isVisible()){
        this->ajtContact->setVisible(true);
        this->mdfContact->setVisible(false);
        this->listeInteraction->setVisible(false);
        this->afficheContactUI->setVisible(false);
        this->ajtInteraction->setVisible(false);
        this->afficheLogs->setVisible(false);
    }



}


/*!
 * \brief PrincipaleWidget::onModificationContact
 * Méthode ( slot ) qui permet d'afficher le formulaire de modification de contact.
 * Lorsque l'utilisateur appuie sur le boutton " Modification " dans le Widget enfant AfficheContact , le Widget principale va faire appraitre la fenêtre
 * et va fermer toute fenêtre succeptible d'être ouverte à ce moment là.
 * On va aussi emit un signal pour actualiser le formulaire au nom du contact séléctionné.
 */

void PrincipaleWidget::onModificationContact()
{

    emit initModifContact(selectedContact);

    if(!this->mdfContact->isVisible()){
        this->mdfContact->setVisible(true);
        this->ajtContact->setVisible(false);
        this->listeInteraction->setVisible(false);
        this->afficheContactUI->setVisible(false);
        this->ajtInteraction->setVisible(false);
        this->afficheLogs->setVisible(false);
    }


}

/*!
 * \brief PrincipaleWidget::onAjoutInteraction
 * Méthode ( slot ) qui permet d'afficher le formulaire d'ajout d'interaction.
 * Lorsque l'utilisateur appuie sur le boutton " Ajouter Interaction " dans le Widget enfant AfficheContact , le Widget principale va faire appraitre la fenêtre
 * et va fermer toute fenêtre succeptible d'être ouverte à ce moment là.
 * On va aussi emit un signal pour actualiser le formulaire au nom du contact séléctionné.
 */

void PrincipaleWidget::onAjoutInteraction()
{
    emit refreshInteractionForm(selectedContact);
    if(!this->ajtInteraction->isVisible()){


        this->ajtInteraction->setVisible(true);
        this->mdfContact->setVisible(false);
        this->ajtContact->setVisible(false);
        this->listeInteraction->setVisible(false);
        this->afficheContactUI->setVisible(false);
        this->afficheLogs->setVisible(false);
    }
}


/*!
 * \brief PrincipaleWidget::onAnnulationModif
 * Méthode ( slot ) qui permet à l'utilisateur de fermer le formulaire de modification.
 * Dans le cas ou l'utilisateur appuie sur le boutton " Annuler " dans le Widget enfant ModifContact,
 * le Widget principale va ouvrir de nouveau le Widget enfant AfficheContact comme pour créer un retour en arrière
 * et va fermer toute fenêtre succeptible d'être ouverte à ce moment là y compris ModifContact.
 */

void PrincipaleWidget::onAnnulationModif()
{
    if(this->mdfContact->isVisible()){
        this->afficheContactUI->setVisible(true);
        this->mdfContact->setVisible(false);
        this->ajtContact->setVisible(false);
        this->listeInteraction->setVisible(false);
        this->ajtInteraction->setVisible(false);
        this->afficheLogs->setVisible(false);
    }
}

/*!
 * \brief PrincipaleWidget::onAnnulationInteraction
 * Méthode ( slot ) qui permet à l'utilisateur de fermer le formulaire d'ajout d'interaction.
 * Dans le cas ou l'utilisateur appuie sur le boutton " Retour " dans le Widget enfant AjoutInteraction,
 * le Widget principale va ouvrir de nouveau le Widget enfant AfficheContact comme pour créer un retour en arrière
 * et va fermer toute fenêtre succeptible d'être ouverte à ce moment là y compris AjoutInteraction.
 */

void PrincipaleWidget::onAnnulationInteraction(){
    if(this->ajtInteraction->isVisible()){
        this->afficheContactUI->setVisible(true);
        this->mdfContact->setVisible(false);
        this->ajtContact->setVisible(false);
        this->listeInteraction->setVisible(false);
        this->ajtInteraction->setVisible(false);
        this->afficheLogs->setVisible(false);
    }
}

/*!
 * \brief PrincipaleWidget::onAfficheIntersClicked
 * Méthode ( slot ) qui permet d'afficher la liste d'interaction de tout les contacts.
 * Lorsque l'utilisateur appuie sur le boutton " Afficher les interactions " dans le Widget principale ,
 * le Widget principale va faire appraitre la fenêtre listeInteraction
 * et va fermer toute fenêtre succeptible d'être ouverte à ce moment là.
 */


void PrincipaleWidget::onAfficheIntersClicked()
{
    if(!this->listeInteraction->isVisible())
    {
    this->listeInteraction->setVisible(true);
    this->ajtContact->setVisible(false);
    this->mdfContact->setVisible(false);
    this->afficheContactUI->setVisible(false);
    this->ajtInteraction->setVisible(false);
    this->afficheLogs->setVisible(false);
    }

}

/*!
 * \brief PrincipaleWidget::onAfficheLogs
 * Méthode ( slot ) qui permet d'afficher les logs de l'application.
 * Lorsque l'utilisateur appuie sur le boutton Action " Afficher les logs " dans le Menu du MainWindow ,
 * le MainWindow envoie un signal au Widget principale pour lancer cette méthode.
 * le Widget principale va faire appraitre la fenêtre afficheLogs
 * et va fermer toute fenêtre succeptible d'être ouverte à ce moment là.
 *
 * on emit un signal à la BDD pour aller récuperer les logs,
 * la BDD renverra ensuite un signal pour raffraichir l'affichage des logs grace au slot RefreshLogs(std::list<QString> logListe).
 */

void PrincipaleWidget::onAfficheLogs(){
    if(!this->afficheLogs->isVisible()){
    this->afficheLogs->setVisible(true);
    this->afficheContactUI->setVisible(false);
    this->ajtContact->setVisible(false);
    this->mdfContact->setVisible(false);
    this->ajtInteraction->setVisible(false);
    this->listeInteraction->setVisible(false);

    }

    emit getLogs();

}





/*!
 * \brief PrincipaleWidget::BDD_AjoutContact
 * Méthode ( Slot ) qui envoie un signal à la BDD pour créer un contact.
 * Lorsque l'utilisateur créer son contact sur l'interface AjoutContact,
 * un signal contenant le contact à créer est envoyé pour executer ce slot qui,
 * va simplement envoyer ce même signal à la BDD.
 * \param contact
 */

void PrincipaleWidget::BDD_AjoutContact(Contact contact){
    emit BaseDDAjtContact(contact);
}

/*!
 * \brief PrincipaleWidget::BDD_ModifContact
 * Méthode ( Slot ) qui envoie un signal à la BDD pour modifier un contact.
 * Lorsque l'utilisateur créer modifie son contact sur l'interface ModifContact,
 * un signal contenant le contact1 qui est le contact à modifier et le contact2 qui est le contact par lequel le remplacer est envoyé pour executer ce slot qui,
 * va simplement envoyer ce même signal à la BDD.
 * \param contact1
 * \param contact2
 */
void PrincipaleWidget::BDD_ModifContact(Contact contact1,Contact contact2){
    emit BaseDDMdfContact(contact1,contact2);
}

/*!
 * \brief PrincipaleWidget::BDD_SupprContact
 * Méthode ( Slot ) qui envoie un signal à la BDD pour supprimmer un contact.
 * Lorsque l'utilisateur supprimme son contact sur l'interface AfficheContact,
 * un signal  est envoyé pour executer ce slot,
 * on va envoyer un signal à la BDD qui contient le contact actuellement selectionné.
 * On va par la suite rafraichir la liste de contacts et on ferme l'AfficheContact.
 */
void PrincipaleWidget::BDD_SupprContact(){
     emit BaseDDSuppressionContact(*selectedContact);
     emit RefreshContacts();

     this->afficheContactUI->setVisible(false);
}

/*!
 * \brief PrincipaleWidget::BDD_AjoutInteraction
 * Méthode ( Slot ) qui envoie un signal à la BDD pour créer une interaction à un contact.
 * Lorsque l'utilisateur créer son interaction sur l'interface AfficheContact du contact séléctionné,
 * un signal contenant l'interaction à créer est envoyé pour executer ce slot qui,
 * va simplement renvoyer ce même signal mais avec le contact séléctionné en plus à la BDD.
 *
 * On va par la suite rafraichir la liste de contacts,
 * et on ferme le formulaire AjoutInteraction et l'AfficheContact.
 * \param inter
 */
void PrincipaleWidget::BDD_AjoutInteraction(Interaction inter){
     emit BaseDDAjtInteraction(*selectedContact,inter);

     emit RefreshContacts();

     this->afficheContactUI->setVisible(false);
     this->ajtInteraction->setVisible(false);
     this->listeInteraction->setVisible(true);
}

/*!
 * \brief PrincipaleWidget::BDD_SupprInteraction
 * Méthode ( Slot ) qui envoie un signal à la BDD pour supprimmer une interaction à un contact.
 * Lorsque l'utilisateur supprimme son interaction sur l'interface AfficheContact du contact séléctionné,
 * un signal contenant l'interaction à supprimer ainsi que le mail est envoyé pour executer ce slot qui,
 * va simplement renvoyer ce même signal à la BDD.
 *
 * On va par la suite rafraichir la liste de contacts,
 * on réactualise le contact séléctionné pour raffraichir sa page.
 * \param inter
 * \param mail
 */
void PrincipaleWidget::BDD_SupprInteraction(Interaction inter,std::string mail){
    emit BaseDDSuppressionInteraction(inter,mail);
    emit RefreshContacts();

    selectedContact = Gc.getContactAt(contactId);

    emit RefreshAffiche(selectedContact);
}






/*!
 * \brief PrincipaleWidget::RefreshListeContact
 * Méthode ( slot ) qui raffraichit la liste de contact visuel de l'application.
 * Dans un premier temps on récupère dans les variables QDate les valeurs dans insérées dans les QLineEdit auquels ils sont liés.
 * Dans un second temps on récupère dans les variables le critère séléctionné dans le combo box ainsi que le mot clé inséré dans la ligne de recherche.
 *
 * On emit un signal RefreshGC() à la BDD pour récuperer la liste de contact actuelle,
 * celle-ci sera placé dans la variable globale à la classe " Gc " qui est une liste de contact.
 *
 * On emit un signal RefreshListInter(Gc) contenant Gc notre fraiche liste de contact pour raffraichir
 * la liste de toutes les interactions de touts contacts.
 *
 * On raffraichit le QLabel destinné à afficher le nombre de contacts actuel dans la liste de contact.
 *
 * Par la suite on vas changer les préférences d'affichage du QTableWidget qui va contenir la liste de contact.
 *
 * On commence désormais la création de QTableWidgetItem pour chaque contact correspondant aux critères de recherches
 * en parcourant la liste de contact à l'aide d'une boucle.
 *
 * On charge dans un QTableWidgetItem la photo de profil du contact , ainsi que son nom prénom,
 * chaque QTableWidgetItem possède une deuxième colonne cachée qui contient l'index du  n ieme contact de la liste
 * entre autre si le contact numéro 3 de variable Gc est affiché , alors son QTableWidgetItem aura l'id 3,
 * si le contact suivant est le numéro 25 alors son QTableWidgetItem aura l'id 25.
 * étant donné que l'ont affiche que le nom prénom si on a deux contacts similaires on risque d'avoir des problèmes,
 * donc dans la liste de contact on selectionne le n eme contact de Gc pour les actions que l'utilisateur fera , d'ou l'utilité de l'index.
 *
 * Si le contact correspond à la recherche de l'utilisateur on valide la création du QTableWidgetItem et on l'intègre à la liste.
 * On actualise de nouveau le nombre de contacts présent dans la liste après recherche, et on modifie encore une fois les préférences
 * de la table pour qu'elle s'ajuste au contenu.
 *
 */

void PrincipaleWidget::RefreshListeContact()
{
    if(this->mdfContact->isVisible()){
        this->mdfContact->setVisible(false);
    }

     this->ui->CtctListe->clearContents();

     QDate dateA = QDate::fromString(this->ui->LigneDateA->text(), QString("dd/MM/yyyy"));
     QDate dateB = QDate::fromString(this->ui->LigneDateB->text(), QString("dd/MM/yyyy"));

     QString critereIndex = this->ui->CritereCB->currentText();
     QString texteFiltre = this->ui->RechercheLine->text().toLower();


     int index=0;


     emit RefreshGC();


     emit RefreshListInter(Gc);

     this->ui->NbContactLabel->setText(QString::fromStdString(Gc.getSize()));


     this->ui->CtctListe->setSelectionBehavior( QAbstractItemView::SelectRows );
     this->ui->CtctListe->setSelectionMode( QAbstractItemView::SingleSelection );
     this->ui->CtctListe->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
     this->ui->CtctListe->setEditTriggers(QAbstractItemView::NoEditTriggers);
     this->ui->CtctListe->verticalHeader()->setDefaultSectionSize(50);
     this->ui->CtctListe->horizontalHeader()->setDefaultSectionSize(50);
     this->ui->CtctListe->verticalHeader()->setVisible(false);
     this->ui->CtctListe->setColumnCount(2);
     this->ui->CtctListe->hideColumn(1);
     this->ui->CtctListe->setHorizontalHeaderLabels({"Contact"});

     int row = 0;


     this->ui->CtctListe->setRowCount(Gc.getNbContact());

     for (const auto& contact : Gc.getLstContacts()) {



        QDate contactDate = QDate::fromString(QString::fromStdString(contact->getDate().toString()), "dd/MM/yyyy");


        std::string critereContact;

        std::string nom = QString::fromStdString(contact->getNom()).toLower().toStdString();
        std::string prenom = QString::fromStdString(contact->getPrenom()).toLower().toStdString();
        std::string entreprise = QString::fromStdString(contact->getEntreprise()).toLower().toStdString();
        std::string mail = QString::fromStdString(contact->getMail()).toLower().toStdString();
        std::string telephone = QString::fromStdString(contact->getTelephone()).toStdString();
        std::string date = QString::fromStdString(contact->getDate().toString()).toStdString();

        if (critereIndex == "Aucun") {
            std::list<std::string> criteres = {nom, prenom, entreprise, mail, telephone, date};

          critereContact = nom+" "+prenom+" "+entreprise+" "+mail+" "+telephone+" "+date;
        } else if (critereIndex == "Nom") {
            this->ui->RechercheLine->setPlaceholderText(QString("Ex : Dupont"));
            critereContact = nom;
        } else if (critereIndex == "Prenom") {
            this->ui->RechercheLine->setPlaceholderText(QString("Ex : Jean"));
            critereContact = prenom;
        } else if (critereIndex == "Entreprise") {
            this->ui->RechercheLine->setPlaceholderText(QString("Ex : LeClerc"));
            critereContact = entreprise;
        } else if (critereIndex == "Mail") {
            this->ui->RechercheLine->setPlaceholderText(QString("Ex : Jean.Dupont@hotmail.com"));
            critereContact = mail;
        } else if (critereIndex == "Telephone") {
            this->ui->RechercheLine->setPlaceholderText(QString("Ex : 06 ou +33"));
            critereContact = telephone;
        } else if (critereIndex == "Date") {
            this->ui->RechercheLine->setPlaceholderText(QString("Ex : jj/mm/aaaa"));
            critereContact = date;
        }

        if (contactDate.isValid() && (contactDate >= dateA && contactDate <= dateB) && critereContact.find(texteFiltre.toStdString()) != std::string::npos) {
            QTableWidgetItem *nomPrenomItem = new QTableWidgetItem(QString::fromStdString(contact->getNom() + " " + contact->getPrenom()));
            QTableWidgetItem *Id = new QTableWidgetItem(QString::number(index));


            if (QString::compare(QString::fromStdString(contact->getPhoto()), QString()) != 0) {
                QImage image;
                bool valid = image.load(QString::fromStdString(contact->getPhoto()));

                if (valid) {

                    nomPrenomItem->setData(Qt::DecorationRole, image.scaled(50, 50));
                } else {
                    qDebug() << "Erreur : Impossible de charger l'image.";
                }
            }

            this->ui->CtctListe->setItem(row, 0, nomPrenomItem);
            this->ui->CtctListe->setItem(row, 1, Id);

            row++;

        }
        index++;
     }

     this->ui->CtctListe->setRowCount(row);
     this->ui->CtctListe->setIconSize(QSize(50, 50));
     this->ui->CtctListe->setColumnWidth(0, 50);
}





/*!
 * \brief PrincipaleWidget::RefreshLogs
 * Méthode ( slot ) qui permet de d'écrire dans le QTextEdit afficheLogs les logs venant de la BDD.
 * Lorsque la BDD renvoie un signal avec dans celui-ci la liste de logs dans le Widget principale,
 * c'est ce slot qui est executé.
 *
 * On récupère en paramètre la liste de logs sous forme de QString;
 *
 * On clear dans un premier temps le QTextEdit pour eviter de réecrire les mêmes logs à la suite,
 * on ajoute ensuite le titre " LOGS " comme pour définir le début,
 * on parcour ensuite la liste de QString pour en ajouter le contenu dans le QTextEdit en séparant chaque QString par 3 sauts de ligne.
 * \param logListe
 */

void PrincipaleWidget::RefreshLogs(std::list<QString> logListe){


     afficheLogs->clear();
     afficheLogs->append("LOGS");
     for (const QString &logEntry : logListe) {
        afficheLogs->append("\n\n\n");
        afficheLogs->append(logEntry);
     }
}




/*!
 * \brief PrincipaleWidget::ChoixDateA
 * Méthode de choix de date n°1.
 * L'utilisateur lorsqu'il clique sur le boutton de choix de date un QCalendar vas prendre place dans une nouvelle fenêtre.
 * l'utilisateur vas séléctionner une date dans ce calendrier, une fois celà fait un signal est envoyé pour lancer la méthode ActuLigne.
 * La méthode actuligne vas récupérer la date séléctionnée dans le QCalendar pour l'inserer dans la ligne de recherche d'intervale de date n°1.
 * Ici un booleen DateAB qui est global à la classe prend la valeur true, cette valeur permet de vérifier que c'est la séléction de la date n°1 et non pas la n°2.
 */

void PrincipaleWidget::ChoixDateA()
{
     DateAB = true;
     Cal->setMinimumDate(QDate::fromString("01/01/2000",QString("dd/MM/yyyy"))  );
     Cal->show();
}

/*!
 * \brief PrincipaleWidget::ChoixDateB
 * Méthode de choix de date n°2.
 * On remarque que le calendrier prend comme valeur minimum la date n°1, pour éviter d'avoir un interval érronné.
 *
 * L'utilisateur lorsqu'il clique sur le boutton de choix de date un QCalendar vas prendre place dans une nouvelle fenêtre.
 * l'utilisateur vas séléctionner une date dans ce calendrier, une fois celà fait un signal est envoyé pour lancer la méthode ActuLigne.
 * La méthode actuligne vas récupérer la date séléctionnée dans le QCalendar pour l'inserer dans la ligne de recherche d'intervale de date n°2.
 * Ici un booleen DateAB qui est global à la classe prend la valeur false, cette valeur permet de vérifier que c'est la séléction de la date n°2 et non pas la n°1.
 */

void PrincipaleWidget::ChoixDateB()
{
     DateAB = false;
     Cal->setMinimumDate(QDate::fromString(this->ui->LigneDateA->text(),QString("dd/MM/yyyy") ) );
     Cal->show();
}


/*!
 * \brief PrincipaleWidget::ActuLigneDate
 * Méthode ( slot ) qui va actualiser les lignes de recherche par intervalle de date.
 * On vérifie tout d'abord quelle date à été selectionnée en vérifiant le booleen DateAB,
 * si true alors c'est la date n°1
 * si false alors c'est la date n°2
 * Une fois fait on actualise la date dans les QLineEdit prévu à cet effet.
 * les dates dans ces mêmes QLineEdit seront séléctionnées lors du raffraichissement de la liste.
 *
 * On ajoute une condition ou la date n°2 prend la valeur de la date n°1 si celle-ci est plus grande que la date n°2.
 * On ferme finalement le QCalendar et on emit un signal pour raffraichir la liste.
 */

void PrincipaleWidget::ActuLigneDate()
{
     if(DateAB){
     this->ui->LigneDateA->setText(Cal->selectedDate().toString("dd/MM/yyyy"));
     }
     else{
     this->ui->LigneDateB->setText(Cal->selectedDate().toString("dd/MM/yyyy"));
     }

     if(QDate::fromString(this->ui->LigneDateA->text(),QString("dd/MM/yyyy")) > QDate::fromString(this->ui->LigneDateB->text(),QString("dd/MM/yyyy")))
     this->ui->LigneDateB->setText(this->ui->LigneDateA->text());

     Cal->close();
     emit RefreshContacts();
}


/*!
 * \brief PrincipaleWidget::RefreshGestionnaireContact
 * Méthode ( slot ) qui permet de raffraichir la variable globale de liste de contacts.
 * Lorsque la BDD renvoie un signal dans le Widget principale contenant la liste de contact
 * ce slot s'execute et vas charger la liste de contacts dans la variable globale de la classe liste de contacts
 *
 * la variable globale servira au raffraichissement de la liste dans le Widget principale.
 *
 * On emit un signal qui contient la liste de contact vers le MainWindow,
 * comme ça si l'utilisateur veux créer à tout moment le fichier JSON contenant les informations de chaque contact,
 * la liste de contact sera déjà raffraichit et chargée.
 * \param GestC
 */

void PrincipaleWidget::RefreshGestionnaireContact(GestionnaireContact GestC){
     Gc = GestC;
     emit setContacts(GestC);
}


