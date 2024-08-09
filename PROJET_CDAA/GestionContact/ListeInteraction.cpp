#include "ListeInteraction.h"
#include "ui_ListeInteraction.h"

/*!
 * \file ListeInteraction.cpp
 * \brief Classe qui permet l'affichage de la liste d'interaction de tout les contacts dans le Widget principale.
 * Le tableau est initialisé avec cinq colonnes : nom , prenom , date , interaction , todo.
 * On récupère la liste de contact puis on parcour à l'aide de boucle les contact , les interactions et les todo pour
 * les inserer dans des TableWidgetItem.
 *
 * On ajoute à cela une méthode de recherche par intervalles de dates et par mot clés / critères.
 * Pour se faire à chaque entrée on raffraichit la liste de contact en prenant en compte d'afficher les interactions qui correspondent au citères de recherche.
 * les interactions non correspondantes sont ignorées et donc pas générer lors du raffraichissement.
 * \class ListeInteraction
 */

/*!
 * \brief ListeInteraction::ListeInteraction
 * Constructeur de la classe ListeInteraction.
 * Initialisation des variables, ajustement de l'affichage du tableau d'interactions
 * connexion des signaux/slots pour envoyer des signaux à chaque entrée de recherche.
 * \param parent
 */

ListeInteraction::ListeInteraction(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ListeInteraction)
{
    ui->setupUi(this);

    connect(this,SIGNAL(refreshList()),this,SLOT(RefreshList()));

    this->ui->TableInteraction->setSelectionBehavior( QAbstractItemView::SelectRows );
    this->ui->TableInteraction->setSelectionMode( QAbstractItemView::SingleSelection );
    this->ui->TableInteraction->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->ui->TableInteraction->verticalHeader()->setDefaultSectionSize(50);
    this->ui->TableInteraction->horizontalHeader()->setDefaultSectionSize(300);
    this->ui->TableInteraction->verticalHeader()->setVisible(false);
    this->ui->TableInteraction->setColumnCount(5);
    this->ui->TableInteraction->horizontalHeader()->setSectionResizeMode(4 ,QHeaderView::Stretch);

    QTableWidgetItem *col1 = new QTableWidgetItem("Nom");
    this->ui->TableInteraction->setHorizontalHeaderItem(0, col1);
    QTableWidgetItem *col2 = new QTableWidgetItem("Prenom");
    this->ui->TableInteraction->setHorizontalHeaderItem(1, col2);
    QTableWidgetItem *col3 = new QTableWidgetItem("Date");
    this->ui->TableInteraction->setHorizontalHeaderItem(2, col3);
    QTableWidgetItem *col4 = new QTableWidgetItem("Interaction");
    this->ui->TableInteraction->setHorizontalHeaderItem(3, col4);
    QTableWidgetItem *col5 = new QTableWidgetItem("Todo");
    this->ui->TableInteraction->setHorizontalHeaderItem(4, col5);

    Cal = new QCalendarWidget();

    connect(this->ui->BouttonDateA,SIGNAL(clicked()),this,SLOT(ChoixDateA()));
    connect(this->ui->BouttonDateB,SIGNAL(clicked()),this,SLOT(ChoixDateB()));
    connect(Cal,SIGNAL(selectionChanged()),this,SLOT(ActuLigneDate()));

    this->ui->LigneDateA->setText("01/01/2000");
    this->ui->LigneDateB->setText("31/12/2100");
    Cal->setDateRange(QDate::fromString("01/01/2000",QString("dd/MM/yyyy")), QDate::fromString("31/12/2100",QString("dd/MM/yyyy") ));

    this->ui->CritereCB->addItem("Aucun");
    this->ui->CritereCB->addItem("Nom Contact");
    this->ui->CritereCB->addItem("Prenom Contact");
    this->ui->CritereCB->addItem("Date Interaction");
    this->ui->CritereCB->addItem("Contenu Interaction");
    this->ui->CritereCB->addItem("Contenu Todo");


    connect(this->ui->RechercheLine, SIGNAL(textChanged(QString)), this, SLOT(RefreshList()));
    connect(this->ui->CritereCB, SIGNAL(currentTextChanged(QString)), this, SLOT(RefreshList()));
}


/*!
 * \brief ListeInteraction::~ListeInteraction
 * Destructeur de la classe ListeInteraction.
 */

ListeInteraction::~ListeInteraction()
{
    delete ui;
}

/*!
 * \brief ListeInteraction::RefreshListInter
 * Méthode ( slot ) qui reçoit en paramètre la liste de contacts et l'insère dans la variable globale de la classe
 * on raffraichit ensuite la liste d'interaction.
 * \param Gc
 */

void ListeInteraction::RefreshListInter(GestionnaireContact Gc){
    GestC = Gc;
    emit refreshList();
}

/*!
 * \brief ListeInteraction::RefreshList
 * Méthode (slot) qui permet de rafraichir la liste d'interactions.
 * Dans un premier temps on récupère dans les variables QDate les valeurs dans insérées dans les QLineEdit auquels ils sont liés.
 * Dans un second temps on récupère dans les variables le critère séléctionné dans le combo box ainsi que le mot clé inséré dans la ligne de recherche.
 *
 * On démarre ensuite une boucle pour determiner le nombre d'interaction total et ainsi initialiser le nombre de ligne qui nous faut à notre tableau.
 *
 * On fois celà fait on actualise le nombre d'interaction dans le QLabel prévue à celà.
 *
 * On commence désormais la création de QTableWidgetItem pour chaque interaction correspondant aux critères de recherche.
 *
 * Si l'interaction correspond à la recherche de l'utilisateur on valide la création du QTableWidgetItem et on l'intègre à la liste.
 * On actualise de nouveau le nombre d'intéractions présent dans la liste après recherche, et on modifie encore une fois les préférences
 * de la table pour qu'elle s'ajuste au contenu.
 */

void ListeInteraction::RefreshList(){


    this->ui->TableInteraction->clearContents();
    QDate dateA = QDate::fromString(this->ui->LigneDateA->text(), QString("dd/MM/yyyy"));
    QDate dateB = QDate::fromString(this->ui->LigneDateB->text(), QString("dd/MM/yyyy"));

    QString critereIndex = this->ui->CritereCB->currentText();
    QString texteFiltre = this->ui->RechercheLine->text().toLower();





    int totalInteractions = 0;


    for (const Contact* contact : GestC.getLstContacts()) {
        totalInteractions += contact->getLstInteractions().size();
    }
    this->ui->TableInteraction->setRowCount(totalInteractions);

    this->ui->NbInteractionLabel->setText("Nombre d'Interactions : " +QString::number(totalInteractions));




    int row = 0;


    for (const Contact* contact : GestC.getLstContacts()) {


        for (const Interaction* interaction : contact->getLstInteractions()) {

            QDate interactionDate = QDate::fromString(QString::fromStdString(interaction->getDate().toString()), "dd/MM/yyyy");


            std::string critereInteraction;

            std::string dateInteraction = QString::fromStdString(interaction->getDate().toString()).toStdString();
            std::string nomContact = QString::fromStdString(contact->getNom()).toLower().toStdString();
            std::string prenomContact = QString::fromStdString(contact->getPrenom()).toLower().toStdString();
            std::string contenuInteraction = QString::fromStdString(interaction->getContenu()).toLower().toStdString();
            std::string contenuTodo;
            for(const Todo* todo : interaction->getLstTodo()){
              contenuTodo += QString::fromStdString(todo->getContenu()).toLower().toStdString();
            }


            if (critereIndex == "Aucun") {
                std::list<std::string> criteres = {dateInteraction, nomContact, prenomContact, contenuInteraction, contenuTodo};

                critereInteraction = dateInteraction+" "+nomContact+" "+prenomContact+" "+contenuInteraction+" "+contenuTodo;
            } else if (critereIndex == "Date Interaction") {
                this->ui->RechercheLine->setPlaceholderText(QString("Ex : jj/mm/aaaa"));
                critereInteraction = dateInteraction;
            } else if (critereIndex == "Nom Contact") {
                this->ui->RechercheLine->setPlaceholderText(QString("Ex : Dupont"));
                critereInteraction = nomContact;
            } else if (critereIndex == "Prenom Contact") {
                this->ui->RechercheLine->setPlaceholderText(QString("Ex : Phillipe"));
                critereInteraction = prenomContact;
            } else if (critereIndex == "Contenu Interaction") {
                this->ui->RechercheLine->setPlaceholderText(QString("Ex : blablabla"));
                critereInteraction = contenuInteraction;
            } else if (critereIndex == "Contenu Todo") {
                this->ui->RechercheLine->setPlaceholderText(QString("Ex : blablabla"));
                critereInteraction = contenuTodo;
            }





            if (interactionDate.isValid() && (interactionDate >= dateA && interactionDate <= dateB) && critereInteraction.find(texteFiltre.toStdString()) != std::string::npos) {

                QTableWidgetItem* nomItem = new QTableWidgetItem(QString::fromStdString(contact->getNom()));
            this->ui->TableInteraction->setItem(row, 0, nomItem);

            QTableWidgetItem* prenomItem = new QTableWidgetItem(QString::fromStdString(contact->getPrenom()));
            this->ui->TableInteraction->setItem(row, 1, prenomItem);

            QTableWidgetItem* dateItem = new QTableWidgetItem(QString::fromStdString(interaction->getDate().toString()));
            this->ui->TableInteraction->setItem(row, 2, dateItem);

            QTableWidgetItem* contenuItem = new QTableWidgetItem(QString::fromStdString(interaction->getContenu()));
            this->ui->TableInteraction->setItem(row, 3, contenuItem);

            QString todosString;

            for (const Todo* todo : interaction->getLstTodo()) {
                todosString += "@Todo " + QString::fromStdString(todo->getContenu()) + " @Date " + QString::fromStdString(todo->getDate().toString()) + "; ";
            }


            QTableWidgetItem* todosItem = new QTableWidgetItem(todosString);
            this->ui->TableInteraction->setItem(row, 4, todosItem);

            ++row;

            }

        }

        this->ui->NbInteractionLabel->setText("Nombre d'Interactions : " +QString::number(row));
    }
this->ui->TableInteraction->setRowCount(row);
    this->ui->TableInteraction->resizeRowsToContents();
    this->ui->TableInteraction->resizeColumnToContents(0);
    this->ui->TableInteraction->resizeColumnToContents(1);
    this->ui->TableInteraction->resizeColumnToContents(2);
}

/*!
 * \brief ListeInteraction::ChoixDateA
 * Méthode de choix de date n°1.
 * L'utilisateur lorsqu'il clique sur le boutton de choix de date un QCalendar vas prendre place dans une nouvelle fenêtre.
 * l'utilisateur vas séléctionner une date dans ce calendrier, une fois celà fait un signal est envoyé pour lancer la méthode ActuLigne.
 * La méthode actuligne vas récupérer la date séléctionnée dans le QCalendar pour l'inserer dans la ligne de recherche d'intervale de date n°1.
 * Ici un booleen DateAB qui est global à la classe prend la valeur true, cette valeur permet de vérifier que c'est la séléction de la date n°1 et non pas la n°2.
 */

void ListeInteraction::ChoixDateA()
{
    DateAB = true;
    Cal->setMinimumDate(QDate::fromString("01/01/2000",QString("dd/MM/yyyy"))  );
    Cal->show();
}

/*!
 * \brief ListeInteraction::ChoixDateB
 * Méthode de choix de date n°2.
 * On remarque que le calendrier prend comme valeur minimum la date n°1, pour éviter d'avoir un interval érronné.
 *
 * L'utilisateur lorsqu'il clique sur le boutton de choix de date un QCalendar vas prendre place dans une nouvelle fenêtre.
 * l'utilisateur vas séléctionner une date dans ce calendrier, une fois celà fait un signal est envoyé pour lancer la méthode ActuLigne.
 * La méthode actuligne vas récupérer la date séléctionnée dans le QCalendar pour l'inserer dans la ligne de recherche d'intervale de date n°2.
 * Ici un booleen DateAB qui est global à la classe prend la valeur false, cette valeur permet de vérifier que c'est la séléction de la date n°2 et non pas la n°1.
 */

void ListeInteraction::ChoixDateB()
{
    DateAB = false;
    Cal->setMinimumDate(QDate::fromString(this->ui->LigneDateA->text(),QString("dd/MM/yyyy") ) );
    Cal->show();
}

/*!
 * \brief ListeInteraction::ActuLigneDate
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

void ListeInteraction::ActuLigneDate()
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
    emit refreshList();
}
