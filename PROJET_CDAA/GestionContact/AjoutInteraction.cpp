#include "AjoutInteraction.h"
#include "ui_AjoutInteraction.h"

/*!
 * \file AjoutInteraction.cpp
 * \brief Classe qui permet l'affichage du formulaire d'ajout d'interaction.
 *
 * L'utilisateur vas entrer dans le formulaire le contenu de l'interaction qu'il veut créer.
 * Il dispose d'une ligne pour insérer la date d'interaction, et d'un bloc pour le contenu.
 *
 * Si l'utilisateur n'entre pas de date , l'interaction sera à la date du jour de création de celle-ci,
 * quant au contenu l'interaction n'est pas créee si elle n'a pas de contenu.
 *
 * Pour l'ajout de Todo à la même manière que l'interaction l'utilisateur dispose de deux lignes supplémentraires,
 * une ligne pour la date du Todo et une autre pour le contenu du todo.
 *
 * Une fois que l'utilisateur à entrée les informations du Todo , il lui faut appuyer sur un boutton " Valider Todo "
 * pour ajouter ce todo à une liste globale à la classe de Todo, à chaque ajout de Todo cette liste est raffraichit
 * puis affichée dans un QTextEdit non editable pour que l'utilisateur ai un visuel sur la liste.
 *
 * Si l'utilisateur regrette son ajout il dispose d'un boutton pour supprimer le dernier Todo de la liste ,
 * le problème est que si l'utilisateur veut supprimer le todo x , il devra supprimer avant ça tout les todo qui le suivent.
 *
 * Une fois celà fait lors de la validation d'interaction une première étape de vérification est lancée.
 * L'étape va vérifier dans un premier temps si chaque entrée du formulaire n'est pas vide,
 * dans le cas ou une entrée est vide un message d'erreur s'affiche au dessus de l'entrée en question.
 * Dans un second temps à l'aide de regex on vas vérifier si le format entré par l'utilisateur est correct,
 * un regex va vérifier le text basiques.
 * un regex vas vérifier le format de date qui est jj/mm/aaaa.
 * Dans le cas ou un regex n'est pas respecté alors un message d'erreur s'affiche au dessus de l'entrée.
 * Si les deux vérifications sont respectée,
 * on vas insérer les valeurs qui se trouvent dans les entrées dans l'interaction , et on insère la liste globale à la classe de Todos dans l'interaction.
 *
 * On envoie un signal contenant l'interaction vers le Widget principale qui renverra ce signal avec en plus le contact séléctionné vers la BDD pour l'ajouter.
 *
 * L'utilisateur à la possibilité de nettoyer le formulaire avec le boutton " Annuler ",
 * il a aussi la possibilité de retourner sur l'affiche du contact avec le boutton " Retour ".
 * \class AjoutInteraction
 */


/*!
 * \brief AjoutInteraction::AjoutInteraction
 * Constructeur de la classe AjoutInteraction.
 * Initialisation de la variable globale
 * Connexion des signaux/slots
 * \param parent
 */

AjoutInteraction::AjoutInteraction(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AjoutInteraction)
{
    ui->setupUi(this);

    // signal emit lorsque l'utilisateur clique sur le boutton " Retour " , ainsi résulte à la fermeture de la page
    connect(this->ui->BRetour,SIGNAL(clicked()),this,SLOT(FermeFormulaire()));
    // signal emit lorsque l'utilisateur clique sur " Valider ", ainsi on commence la vérification du contenu des entrées.
    connect(this->ui->BValideInteraction,SIGNAL(clicked()),this,SLOT(VerificationInteraction()));
    // signal emit lorsque l'utilisateur clique sur " Annuler ", ce qui produit un nettoyage des entrées.
    connect(this->ui->BAnnuleInteraction,SIGNAL(clicked()),this,SLOT(AnnuleFormInteraction()));
    // signal emit par certaine méthodes , ce qui produit le nettoyage des entrées de l'application.
    connect(this,SIGNAL(clearForm()),this,SLOT(AnnuleFormInteraction()));
    // signal emit lorsque l'utilisateur clique sur " Supprimer le dernier Todo ", ainsi on retire le dernier Todo de la liste de Todos globale
    connect(this->ui->BSupprTodo,SIGNAL(clicked()),this,SLOT(SupprimeTodoList()));
    // signal emit lorsque l'utilisateur clique sur " Ajouter Todo " ,
    // ainsi le contenu dans les entrées pour créer le todo sont récupérer, insérées dans un nouveau Todo qu'on ajoute par la suite à la liste de Todos
    connect(this->ui->BAjoutTodo,SIGNAL(clicked()),this,SLOT(AjoutTodoList()));
    // signal emit par la méthode de vérification lorsque la vérification est sans erreur pour procéder à l'ajout de l'interaction au contact.
    connect(this,SIGNAL(ValidInteraction()),this,SLOT(ValideInteraction()));

    contact = new Contact;



}

/*!
 * \brief AjoutInteraction::~AjoutInteraction
 * Destructeur de la classe AjoutInteraction
 */


AjoutInteraction::~AjoutInteraction()
{
    delete ui;
}

/*!
 * \brief AjoutInteraction::refreshInteractionForm
 * Méthode ( slot ) qui permet d'acutaliser le formulaire au nom du contact séléctionné.
 * On récupère le signal émis par le Widget principale avec dedans le contact séléctionné par l'utilisateur,
 * on charge le contact dans la variable grlobale de la classe pour faciliter les autres méthodes.
 *
 * On change le Label au dessus de la page pour afficher le nom du contact auquel l'utilisateur est entrain de créer une interaction.
 * \param selectedContact
 */

void AjoutInteraction::refreshInteractionForm(Contact * selectedContact){
    if(selectedContact){
        this->ui->LabelContact->setText("Ajout Interaction : "+QString::fromStdString(selectedContact->getNom()) + " " + QString::fromStdString(selectedContact->getPrenom()));
        contact = selectedContact;
    }


}

/*!
 * \brief AjoutInteraction::FermeFormulaire
 * Méthode ( slot ) qui permet de fermer le formulaire d'ajout d'interaction.
 * L'utilisateur vas pouvoir annuler et fermer le formulaire en envoyant un signal au Widget principale.
 * Le formulaire sera par la suite nettoyé.
 */

void AjoutInteraction::FermeFormulaire(){
    emit AnnuleAjoutInteraction();
    emit clearForm();
}


/*!
 * \brief AjoutInteraction::VerificationInteraction
 * Méthode (slot) qui commence la vérification des entrées du formulaire.
 * On utilise une seconde méthode ( VerificationChamp() ) qui return true dans le cas ou une entrée à aucune erreur.
 * dans le cas ou on a aucune erreur on emit un signal pour demander à la BDD si le mail entré existe déjà dans la BDD
 * dans le cas ou on a des erreur , la même méthode qui vérifie si return la valeur de vérification ( VerificationChamp() ) se charge d'afficher les erreurs.
 */


void AjoutInteraction::VerificationInteraction(){


    std::regex reg("^[a-zA-Z0-9].*");
    std::regex regDate(("^(|^(0[1-9]|[1-2][0-9]|3[0-1])/(0[1-9]|1[0-2])/\\d{4})$"));


    QString vide = "<span style='color: red;'> Veuillez remplir cette case.</span>";
    QString errRegex = "<span style='color: red;'> Le format est incorrect.</span>";




    if (VerificationChamp(this->ui->LigneDateInteraction,this->ui->LigneContenuInteraction, this->ui->LabelInteraction, reg, regDate, vide, errRegex,  "Contenu Interaction :"))
    {
        emit ValidInteraction();
    }
    else{
        VerificationChamp(this->ui->LigneDateInteraction,this->ui->LigneContenuInteraction, this->ui->LabelInteraction, reg, regDate,vide, errRegex,  "Contenu Interaction :");
    }
}


/*!
 * \brief AjoutInteraction::VerificationChamp
 * Méthode ( slot ) qui vérifie si les champs possèdent des erreurs.
 * en paramètre on à
 * \param champ : QLineEdit d'entré du formulaire.
 * \param label : associé au QLineEdit qui indique le type d'entrée et change de text en fonction des erreurs présentes.
 * \param reg : regex imposé à la vérification en fonction de l'entrée.
 * \param vide : message d'erreur indiquant que l'entrée est vide.
 * \param errRegex : message d'erreur inquant que le format est incorrect.
 * \param labelText : string initial du QLabel , permet de changer la valeur de celui ci sans perdre la valeur initiale.
 *
 * On vérifie donc le texte en entré qui il correcpond au regex , si c'est le cas
 * on vérifie si le QLabel de l'entrée ne possède pas son texte initial , ex pour le Contenu interaction : " Contenu Interaction : "
 * si le QLabel n'a pas son texte initial c'est que l'entrée précédente avait un erreur, on change donc le text pour retirer le text d'erreur.
 *
 * On vérifie donc que le texte en entré ne soit pas vide
 * on vérifie si le QLabel de l'entrée possède pas déjà le message d'erreur vide , pour éviter d'ajouter une nouvelle fois le message d'erreur par dessus
 * si le QLabel n'a pas son texte d'erreur vide alors on lui change son texte , ex pour l'interaction " Contenu Interaction : Contenu : Veuillez remplire cette case. "
 *
 * On vérifie donc le texte en entré qui il correcpond au regex , si ce n'est pas le cas
 * on vérifie si le QLabel de l'entrée possède pas déjà le message d'erreur regex , pour éviter d'ajouter une nouvelle fois le message d'erreur par dessus
 * si le QLabel n'a pas son texte d'erreur de regex alors on lui change son texte , ex pour l'interaction " Contenu Interaction : Contenu : Le format est incorrect."
 *
 *
 * \return false : dans le cas ou une vérification contient une erreur.
 * \return true : dans le cas ou une vérification contient aucune erreur.
 */

bool AjoutInteraction::VerificationChamp(QLineEdit* champ,QTextEdit* champ2, QLabel* label, const std::regex& reg,const std::regex& regDate, const QString& vide, const QString& errRegex, const QString& labelText) {
    QString text = labelText;



    if (champ2->toPlainText().isEmpty()) {
        text += " Contenu : " + vide;
        label->setText(text);
        return false;
    }



    if (!std::regex_match(champ->text().toStdString(), regDate) || !std::regex_match(champ2->toPlainText().toStdString(), reg)) {
        if (!std::regex_match(champ->text().toStdString(), regDate)) {
            text += " Date : " + errRegex;
        }
        if (!std::regex_match(champ2->toPlainText().toStdString(), reg)) {
            text += " Contenu : " + errRegex;
        }
        label->setText(text);
        return false;
    }

    if (label->text() != labelText) {
        label->setText(labelText);
    }
    return true;
}


/*!
 * \brief AjoutInteraction::ValideInteraction
 * Méthodde ( slot ) qui lance la création et l'insertion de l'interaction dans le contact.
 * On vas lire chaque todo de la liste de Todo dans une boucle et vérifier si ils possèdent du contenu dans leurs variable Date,
 * Si ce n'est pas le cas on leurs met la date du jour.
 *
 * On fait aussi la même chose en vérifiant le contenu de la date de l'interaction ,
 * si celui ci est vide on créer une nouvelle interaction avec la date du jour, on y insère son contenu en entrée dans sa variable contenu
 * et on fini par ajouter la liste de Todos.
 *
 * Dans le cas ou la variable date n'est pas vide,
 * on y insère la date en entrée dans sa variable date , on y insère le contenu en entrée dans sa variable contenu
 * et on fini par ajouter la liste de Todos
 *
 * On fini par emit un signal au Widget principale avec à l'interieure l'interaction.
 * On nettoie par la suite le formulaire avec un signal.
 */

void AjoutInteraction::ValideInteraction(){

    for (Todo* todo : gt.getLstTodos()) {
        if (todo->getDate().toString().empty()) {
            todo->setDate(Date());
        }
    }



    if(!this->ui->LigneDateInteraction->text().isEmpty()){
        Interaction inter = Interaction(
            this->ui->LigneContenuInteraction->toPlainText().toStdString(),
            toDate(this->ui->LigneDateInteraction->text().toStdString()),
            gt.getLstTodos()
            );
        emit BDDAjoutInteraction(inter);
        emit clearForm();

    }else{
        Date date;
        Interaction inter = Interaction(
            this->ui->LigneContenuInteraction->toPlainText().toStdString(),
            date,
            gt.getLstTodos()
            );
        emit BDDAjoutInteraction(inter);
        emit clearForm();
    }



    qDebug()<< "Creation interaction.";
}

/*!
 * \brief AjoutInteraction::AnnuleFormInteraction
 * Méthode ( slot ) qui permet de vider toute les entrées du formulaire.
 * La méthode est appelée par signaux lors de la création de l'interaction et lorsque l'utilisateur ferme le formulaire.
 */

void AjoutInteraction::AnnuleFormInteraction(){
    this->ui->LigneEnsembleTodo->clear();
    this->ui->LigneDateTodo->clear();
    this->ui->LigneContenuTodo->clear();
    this->ui->LigneContenuInteraction->clear();
    this->ui->LigneDateInteraction->clear();
    gt.clear();

}


/*!
 * \brief AjoutInteraction::AjoutTodoList
 * Méthode ( slot )  qui permet d'ajouter les todos que l'utilisateur entre dans le formulaire à une liste de todos
 * qui sera ajoutée à la fin à l'interaction.
 *
 * On crée un nouveau Todo vide auquel on ajoute la date donnée par l'utilisateur,
 * si l'utilisateur n'ajoute pas de date alors on donne au todo la date du jour.
 * On récuère le contenu dans le QLineEdit " contenu todo " puis on l'ajoute au todo fraichement créée.
 *
 * Dans le cas ou l'tulisateur à sauter une ligne dans le contenu le Todo resemblera a " Blabla\nBlabla "
 * on parcour le contenu à l'aide d'une boucle et on change les saut de ligne par des espace résultant à
 * " Blabla Blabla "
 *
 * On ajoute finalement le Todo à la liste de todos qui est la variable globale de la classe et on l'affiche dans un QTextEdit non editable
 * afin que l'utilisateur puisse voir le contenu de la liste de todo.
 *
 * On fini par clear les entrées pour créer le todo.
 */

void AjoutInteraction::AjoutTodoList(){
    Todo* todo = new Todo;
    std::string contenu;

    if(!this->ui->LigneDateTodo->text().isEmpty()){
        todo->setDate(toDate(this->ui->LigneDateTodo->text().toStdString()));
    }

    contenu = this->ui->LigneContenuTodo->toPlainText().toStdString();

        for(size_t i = 0; i < contenu.size(); ++i) {
        if (contenu[i] == '\n') {

                contenu[i] = ' ';

        }
    }

    todo->setContenu(contenu);
    gt.addTodo(todo);
    this->ui->LigneEnsembleTodo->setText(QString::fromStdString(gt.toString()));


    this->ui->LigneContenuTodo->clear();
    this->ui->LigneDateTodo->clear();
}


/*!
 * \brief AjoutInteraction::SupprimeTodoList
 * Méthode ( slot ) non optimale qui permet de supprimer le dernier todo de la liste
 * L'utilisateur à la possibilité de supprimer le dernier todo contenu dans la liste de todo
 * Ainsi il pourra se corriger si il change d'avis.
 *
 * Problème:
 * Dans une liste de 10 Todos si l'utilisateur veut supprimer le premier il devra supprimer les 9 todos qui suivent le premier.
 *
 * On actualise le QTextEdit qui affiche la liste de Todo à chaque suppression.
 */
void AjoutInteraction::SupprimeTodoList(){
    gt.deleteLastTodo();
    this->ui->LigneEnsembleTodo->setText(QString::fromStdString(gt.toString()));
}



/*!
 * \brief AjoutInteraction::toDate
 * Méthode qui permet de transformer une date sous forme de string entrée en paramètre en une date de type Date
 * et de la return.
 * ( ref Class Date )
 * \param date
 * \return d
 */



Date AjoutInteraction::toDate(const std::string date){
    Date* d = new Date(01,01,2000);
    std::istringstream ss(date);
    char slash;
    int jour, mois, annee;

    ss >>  jour >> slash >> mois >> slash >> annee;
    d->setDate(jour,mois,annee);

    return *d;

}
