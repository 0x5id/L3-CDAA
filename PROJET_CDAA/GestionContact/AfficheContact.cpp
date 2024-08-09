#include "AfficheContact.h"
#include "ui_AfficheContact.h"
#include <QPixmap>
#include <QMessageBox>

/*!
 * \file AfficheContact.cpp
 * \brief Classe qui permet l'affichage des informations d'un contact et de pouvoir interagir avec ce dit contact.
 * L'utilisateur vas ici pouvoir observer les informations du contact avec un affichage de sa photo comprise,
 * l'affichage des interactions se dérouleras dans un QTableWidget ci-dessous.
 *
 * L'utilisateur aura accès aux différentes actions réalisable avec un contact, c'est à dire la modification,
 * la suppression, et l'ajout d'une interaction via les bouttons à disposition,
 * ces trois bouttons vont emmettre chacun des signaux différents pour appeller leurs interfaces respectives et sortir de cette interface.
 *
 * L'utilisateur a accès aux interactions du contact qui seront répartis sous forme de liste,
 * lorsque celui-ci clique sur une interaction deux bouttons grisés seront désormais utilisables,
 * le boutton supprimmer interaction ainsi que le boutton afficher interaction,
 * le boutton interaction vas effectuer un changement de table dans l'interface et afficher seulement l'interaction selectionnée pour laisser
 * place à une plus grande interface dans le cas ou l'interaction se trouve être longue ou contiendrait de nombreux Todos.
 * \class AfficheContact
 */

/*!
 * \brief AfficheContact::AfficheContact
 * Constructeur de la Classe Affiche Contact.
 * Les signaux des bouttons sont initialisées, ainsi que les préférences d'affichage des différentes tables.
 * \param parent
 */

AfficheContact::AfficheContact(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AfficheContact)
{
    ui->setupUi(this);

    // initialisation de la variable Interaction qui prend la valeur des interactions selectionnées.
    // initialisation de la Table qui contiendra l'affichage d'une seule interaction séléctionnée.
    selectedInteraction = new Interaction();
    TableInteractionSeule = new QTableWidget;

    // on ajoute la table à notre Widget dans le layout prévu pour les deux tables différentes.
    this->ui->LayoutTable->addWidget(TableInteractionSeule);
    this->TableInteractionSeule->hide();

    // on connect les différents bouttons à leurs slots respectifs.
    connect(this->ui->BSupprContact,SIGNAL(clicked()),this,SLOT(SupprimeContact()));
    connect(this->ui->BModifierContact,SIGNAL(clicked()),this,SLOT(ModifContact()));
    connect(this->ui->BAjoutInteraction,SIGNAL(clicked()),this,SLOT(AjtInteraction()));

    connect(this->ui->BAfficheInteraction,SIGNAL(clicked()),this,SLOT(AfficheInteraction()));
    connect(this->ui->BSupprInteraction,SIGNAL(clicked()),this,SLOT(SupprInteraction()));

    // on ajoute les préférences à l'affichage de la table contenant toute les interaction du contact.
    this->ui->TableInteractionContact->setSelectionBehavior( QAbstractItemView::SelectRows );
    this->ui->TableInteractionContact->setSelectionMode( QAbstractItemView::SingleSelection );
    this->ui->TableInteractionContact->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->ui->TableInteractionContact->verticalHeader()->setVisible(false);
    this->ui->TableInteractionContact->setColumnCount(3);

    QTableWidgetItem *col1 = new QTableWidgetItem("Date");
    this->ui->TableInteractionContact->setHorizontalHeaderItem(0, col1);
    QTableWidgetItem *col2 = new QTableWidgetItem("Interaction");
    this->ui->TableInteractionContact->setHorizontalHeaderItem(1, col2);
    QTableWidgetItem *col3 = new QTableWidgetItem("Todo");
    this->ui->TableInteractionContact->setHorizontalHeaderItem(2, col3);

    // on connect le signal emit quand on clique sur une interaction pour transferer cette interaction dans une variable globale.
    connect(this->ui->TableInteractionContact, SIGNAL(cellClicked(int,int)), this, SLOT(onInteractionClique(int,int)));

    // on ajoute les préférences à l'affichage de la table contenant l'interaction séléctionnée.
    this->TableInteractionSeule->setColumnCount(1);
    this->TableInteractionSeule->setRowCount(3);
    this->TableInteractionSeule->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    this->TableInteractionSeule->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->TableInteractionSeule->horizontalHeader()->setVisible(false);
    QTableWidgetItem *lin1 = new QTableWidgetItem("Date");
    this->TableInteractionSeule->setVerticalHeaderItem(0, lin1);
    QTableWidgetItem *lin2 = new QTableWidgetItem("Interaction");
    this->TableInteractionSeule->setVerticalHeaderItem(1, lin2);
    QTableWidgetItem *lin3 = new QTableWidgetItem("Todo");
    this->TableInteractionSeule->setVerticalHeaderItem(2, lin3);
    this->TableInteractionSeule->resizeRowsToContents();
    this->TableInteractionSeule->setWordWrap(true);



}

/*!
 * \brief AfficheContact::~AfficheContact
 * Destructeur de la Classe AfficheContact.
 * Les signaux des bouttons sont initialisées, ainsi que les préférences d'affichage des différentes tables.
 * \param parent
 */

AfficheContact::~AfficheContact()
{
    delete ui;
}

/*!
 * \brief AfficheContact::RefreshAffiche
 * Méthode ( slot ) qui permet de rafraichir l'interface en fonction du contact selectionnée dans la liste de contact du Widget principale.
 * on transfert le contact dans une variable globale à la classe pour faciliter les autres méthodes de la class,
 * on va ensuite procéder à l'affichage des informations dans des Qlabels, l'affichage de l'image s'effectura grace a un Qimage et QPixmap.
 *
 * Une fois l'affichage des informations principales du contact éffectué, on procède à l'affichage des interactions,
 * on affect un nombre de lignes égal au nombre d'interactions que possède le contact et dans une boucle on vas generer pour chaque interaction
 * une nouvelle ligne que l'on vas inserer dans le tableau avec les informations contenu dans les interactions, une seconde boucle imbriquée dans la première
 * vas permettre d'acceder au todos de chaque interactions et de les ajouter dans un string pour à la fin les affichées dans la 3 eme colonne de l'interaction.
 *
 * On ajuste ensuite l'affichage du tableau après insertion de tout les informations.
 *
 * On initialise ensuite le tableau de l'ensemble des interaction comme étant affiché par défaut.
 * \param contact
 */

void AfficheContact::RefreshAffiche(Contact* contact){
    if (contact) {

       c = contact;

        this->ui->LabelNom->setText(QString::fromStdString(contact->getNom()));
        this->ui->LabelPrenom->setText(QString::fromStdString(contact->getPrenom()));
        this->ui->LabelEntreprise->setText(QString::fromStdString(contact->getEntreprise()));
        this->ui->LabelMail->setText(QString::fromStdString(contact->getMail()));
        this->ui->LabelTelephone->setText(QString::fromStdString(contact->getTelephone()));
        this->ui->LabelDate->setText(QString::fromStdString(contact->getDate().toString()));

        if(QString::compare(QString::fromStdString(contact->getPhoto()), QString()) != 0){

            bool valid = image.load(QString::fromStdString(contact->getPhoto()));
            if(valid){
                image = image.scaledToWidth(ui->LabelPhotoAff->width(), Qt::SmoothTransformation);
                ui->LabelPhotoAff->setPixmap(QPixmap::fromImage(image));
            }


            else {
                qDebug() << "Erreur : Impossible de charger l'image.";
            }


        }

        int row = 0;
        this->ui->TableInteractionContact->setRowCount(contact->getLstInteractions().size());


        for (Interaction *interaction : contact->getLstInteractions()) {

                QTableWidgetItem *dateItem = new QTableWidgetItem(QString::fromStdString(interaction->getDate().toString()));
                this->ui->TableInteractionContact->setItem(row, 0, dateItem);

                QTableWidgetItem *contenuItem = new QTableWidgetItem(QString::fromStdString(interaction->getContenu()));
                this->ui->TableInteractionContact->setItem(row, 1, contenuItem);


                std::list<Todo *> todos = interaction->getLstTodo();
                QString todosString;

                for (Todo *todo : todos) {
                                todosString += "@Todo " + QString::fromStdString(todo->getContenu()) + " @Date " + QString::fromStdString(todo->getDate().toString()) + "; ";
                }


                QTableWidgetItem *todosItem = new QTableWidgetItem(todosString);

                this->ui->TableInteractionContact->setItem(row, 2, todosItem);

                ++row;

        }



    }

    this->ui->TableInteractionContact->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
    this->ui->TableInteractionContact->setColumnWidth(1, 230);
    this->ui->TableInteractionContact->horizontalHeader()->setMaximumSectionSize(400);

    this->ui->BAfficheInteraction->setEnabled(false);
    this->ui->BSupprInteraction->setEnabled(false);

    if(this->ui->BAfficheInteraction->text() == QString("Afficher Tableau")){
        this->ui->BAfficheInteraction->setText(QString("Afficher Interaction"));
        this->TableInteractionSeule->setVisible(false);
        this->ui->TableInteractionContact->setVisible(true);
    }

}

/*!
 * \brief AfficheContact::SupprimeContact
 * Méthode ( slot ) qui permet la suppression du contact.
 * Une fenêtre de confirmation est créer afin d'éviter une suppréssion faite par inadvertance.
 * Si l'utilisateur confirme, on emet un signal au Widget principale pour communiquer avec la BDD.
 */

void AfficheContact::SupprimeContact()
{

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation de suppression", "Êtes-vous sûr de vouloir supprimer ce contact ?", QMessageBox::Yes | QMessageBox::No);

if (reply == QMessageBox::Yes) {
emit SuppressionContact();
qDebug() << "Le contact à été supprimé.";

 } else {

 qDebug() << "La suppresion à été annulée.";
 return;
 }

}

/*!
 * \brief AfficheContact::ModifContact
 * Méthode ( slot ) qui permet l'affichage de la fenêtre ModifContact.
 * la méthode emet un signal au Widget principale qui vas se charger d'interchanger les fenêtres entre elles.
 */

void AfficheContact::ModifContact()
{
        emit ModificationContact();
}

/*!
 * \brief AfficheContact::AjtInteraction
 * Méthode ( slot ) qui permet l'affichage de la fenêtre AjoutInteraction.
 * la méthode emet un signal au Widget principale qui vas se charger d'interchanger les fenêtres entre elles.
 */

void AfficheContact::AjtInteraction()
{
        emit AjoutInteraction();
}


/*!
 * \brief AfficheContact::AfficheInteraction
 * Méthode ( slot ) qui une fois que l'on a cliqué sur l'interaction suivit du boutton "Afficher Interaction" va changer
 * le tableau actuel qui est le tableau qui affiche toute les interactions par le tableau qui n'en affiche qu'une à la fois.
 *
 * une fois la méthode lancée on commence par verifier l'état du tableau affiché, si le texte du boutton est "Afficher Interaction" alors le tableau actuel contient les listes,
 * dans ce cas on va changer le texte dans le boutton afin d'écrire "Afficher Tableau" soit le tableau initial ( boutton pour réaficher la liste des interactions).
 * on change ensuite l'affichage des tableaux et une fois cela fait on vas venir charger les informations de l'interaction dans 3 lignes différentes,
 * une ligne pour la date de l'interaction, la seconde pour le contenu et la troisième pour l'ensemble des todo dans l'interaction que l'on vas venir chercher grace a une boucle
 * ainsi qu'un string dans lequel on stoque tout les todos à la suite.
 *
 * une fois cela fait on ajoute donc les items a leurs lignes respectives.
 *
 * la vérification d'état possède un else qui dans le cas ou le tableau d'interaction unique est affiché on vas revenir au tableau initial et changer le texte du boutton
 * en "Afficher Interaction" de nouveau.
 *
 */

void AfficheContact::AfficheInteraction()
{
        if(selectedInteraction){

            if(this->ui->BAfficheInteraction->text() == QString("Afficher Interaction")){
                this->ui->BAfficheInteraction->setText(QString("Afficher Tableau"));
                this->TableInteractionSeule->setVisible(true);
                this->ui->TableInteractionContact->setVisible(false);

                QTableWidgetItem *dateItem = new QTableWidgetItem(QString::fromStdString(selectedInteraction->getDate().toString()));
                this->TableInteractionSeule->setItem(0, 0, dateItem);


                QTableWidgetItem *contenuItem = new QTableWidgetItem(QString::fromStdString(selectedInteraction->getContenu()));
                this->TableInteractionSeule->setItem(1, 0, contenuItem);



                QString todosString;

                std::list<Todo *> todos = selectedInteraction->getLstTodo();
                for (Todo *todo : todos) {
                                todosString += "@Todo " + QString::fromStdString(todo->getContenu()) + " @Date " + QString::fromStdString(todo->getDate().toString()) + "; " + "\n";

                }

                QTableWidgetItem *todItem = new QTableWidgetItem(todosString);
                todItem->setTextAlignment(Qt::AlignTop | Qt::AlignLeft);
                this->TableInteractionSeule->setItem(2, 0, todItem);

                this->TableInteractionSeule->verticalHeader()->setSectionResizeMode(2,QHeaderView::Stretch);
                this->TableInteractionSeule->resizeRowToContents(0);
                this->TableInteractionSeule->resizeRowToContents(1);


            }

            else if(this->ui->BAfficheInteraction->text() == QString("Afficher Tableau")){
                this->ui->BAfficheInteraction->setText(QString("Afficher Interaction"));
                this->TableInteractionSeule->setVisible(false);
                this->ui->TableInteractionContact->setVisible(true);
            }
        }
}

/*!
 * \brief AfficheContact::SupprInteraction
 * Méthode ( slot ) qui permet d'emmettre un signal pour la suppression de l'interaction selectionnée, on envoie par la même occasion le mail du contact?
 * le mail du contact sert d'id aux interactions et donc ça nous permet de supprimer l'interaction liée à l'id du contact
 * tout ça sans supprimer des interactions similaires chez d'autres contacts.
 */


void AfficheContact::SupprInteraction()
{
    std::string mail = (this->ui->LabelMail->text()).toStdString();
        emit SuppressionInteraction(*selectedInteraction,mail);
}

/*!
 * \brief AfficheContact::onInteractionClique
 * Méthode ( slot ) qui permet de récuperer l'interaction sur laquelle on clique dans la liste.
 * Comme paramètre row qui est la valeur de la ligne selectionnée.
 * Le signal qui permet de recuperer la ligne oblige aussi un second paramètre pour la colonne mais n'étant pas nécessaire on est pas obliger de l'initialiser.
 * une fois cliqué sur l'interaction le signal envoie la valeur de la ligne ( row ) ce qui nous permet d'aller récuperer les valeur de cette ligne dans des QString,
 * une fois les valeurs récupérée on crée une nouvelle interaction que l'on remplie avec ces valeurs.
 *
 * Encore une fois on récupère les Todo a l'aide d'une boucle et on ajoute une vérification suplémentaire qui vérifie que la liste des todos récupérée est similaire
 * à la liste de todo qu'on essaye de match en parcourant toute les interactions
 *
 * Cette vérification évite que lorsque deux interactions possèdent les mêmes dates et le même contenu mais pas les mêmes todos fasse combiner l'ensemble des todo à l'affichage
 * et selectionne par la même occasion la mauvaise interaction.
 *
 * Pour finir on rend disponible les bouttons " Afficher Interaction " et " Supprimmer Interaction".
 *
 * \param row
 */

void AfficheContact::onInteractionClique(int row,int) {

        if (row >= 0 && row < this->ui->TableInteractionContact->rowCount()) {
            QTableWidgetItem *dateItem = this->ui->TableInteractionContact->item(row, 0);
            QTableWidgetItem *contenuItem = this->ui->TableInteractionContact->item(row, 1);
            QTableWidgetItem *todoItem = this->ui->TableInteractionContact->item(row, 2);



                        QString date = dateItem->text();
                        QString contenu = contenuItem->text();
                        QString todo = todoItem->text();

                        selectedInteraction = new Interaction();
                        selectedInteraction->setDate(toDate(date.toStdString()));
                        selectedInteraction->setContenu(contenu.toStdString());

                        for(Interaction * inter : c->getLstInteractions()){
                            QString todoComplet;
                            for(Todo * todo : inter->getLstTodo()){


                                todoComplet += "@Todo " + QString::fromStdString(todo->getContenu()) + " @Date " + QString::fromStdString(todo->getDate().toString()) + "; ";


                            }
                            if(inter->getContenu() == selectedInteraction->getContenu() &&
                                inter->getDate().toString() == selectedInteraction->getDate().toString() &&
                               todo == todoComplet ){
                                selectedInteraction->setLstTodo(inter->getLstTodo());
                            }

                        }

                        this->ui->BAfficheInteraction->setEnabled(true);
                        this->ui->BSupprInteraction->setEnabled(true);

        }
}

/*!
 * \brief AfficheContact::toDate
 * Méthode qui permet de transformer une date sous forme de string entrée en paramètre en une date de type Date
 * et de la return.
 * ( ref Class Date )
 * \param date
 * \return d
 */


Date AfficheContact::toDate(const std::string date){
        Date* d = new Date(01,01,2000);
        std::istringstream ss(date);
        char slash;
        int jour, mois, annee;

        ss >>  jour >> slash >> mois >> slash >> annee;
        d->setDate(jour,mois,annee);

        return *d;

}

