#include "ModifContact.h"
#include "ui_ModifContact.h"
#include <Contact.h>
#include <QMessageBox>
#include <filesystem>
#include <random>

/*!
 * \file ModifContact.cpp
 * \brief Classe qui permet l'affichage du formulaire de modification de contact.
 * L'interface vas être initialement chargée avec les informations de contact selectionnée afin de faciliter la prise en main de l'utilisateur.
 * celà lui permet de changer seuelement ce qu'il veut et non pas devoir réecrir les choses qu'il ne veut pas modifier,
 * il à aussi un visuel dès le départ sur les informations du contact actuel.
 *
 * L'utilisateur vas modifier dans le formulaire les informations du contact qu'il veut modifier.
 *
 *
 * Une fois celà fait lors de la validation modification une première étape de vérification est lancée.
 * L'étape va vérifier dans un premier temps si chaque entrée du formulaire n'est pas vide,
 * dans le cas ou une entrée est vide un message d'erreur s'affiche au dessus de l'entrée en question.
 * Dans un second temps à l'aide de regex on vas vérifier si le format entré par l'utilisateur est correct,
 * un regex va vérifier le text basique comme le nom, prénom , entreprise, le regex vérifie si l'entrée est composée seulement de lettres, espaces et tiret.
 * un regex va verifier le format de mail ,
 * si celui-ci possède des lettres et chiffres, un point avec lettres et chiffres (optionnel) avant l'arobase  , des lettres et chiffres après l'arobase suivit par un point et des lettres.
 * un regex vas vérifier le format de telephone , si celui-ci commence par +33 et contient 9 chiffres à sa suite
 * ou bien commence par un 0 et contient 9 chiffres à sa suite.
 *
 * Dans le cas ou un regex n'est pas respecté alors un message d'erreur s'affiche au dessus de l'entrée.
 * Si les deux vérifications sont respectée pour toute les entrées une troisième vérification est réalisée.
 * On emit un signal vers le Widget principale pour demander à l'aide d'un autre signal si l'adresse mail en entrée existe déjà dans la BDD étant donnée que celle-ci est l'id d'un contact.
 * la BDD renvoie un signal qui passe par le Widget principale de réponse avec un booleen pour affirmer ou non la présence du mail dans la BDD.
 * Dans le cas ou elle existe déjà , un message d'erreur s'affiche au dessus de l'entrée de mail.
 * Dans le cas ou celle-ci n'existe pas on envoie un signal pour valider le formulaire de modification de contact,
 *
 * on envoie un signal contenant le contact1 qui est le contact que l'on veut modifier
 * et on envoie le contact2 qui est le contact dans lequel on a chargé toute les informations en entrée,
 * tout ça vers le Widget principale qui renverra ce signal vers la BDD pour retrouver le contact1 dans une requête et remplacer chaque attributs par ceux du contact2.
 *
 * Un contact possède une photo.
 * L'utilisateur a la possibilité de supprimer la photo actuelle du contact pour laisser place à une photo destinée aux contact sans photo,
 * cette photo se trouve dans le répertoire ..\GestionContact\Assets du nom de ProfileIcon.jpg.
 * L'utilisateur à aussi la possibilité de changer la photo actuelle par une autre photo.
 *
 * Dans le cas ou l'utilisateur modifie la photo, lors de la validation du formulaire on vas récuperer cette image,
 * et on commence une vérification, si l'utilisateur a modifier la photo alors on supprime la photo du contact actuel dans le répertoire ou sont stoquées les photos
 * on récupère la nouvelle photo on va par la suite en modifier le nom avec un générateur de nom basique avec une suite de chiffres ex : Ppc043289473298.jpg
 * et on vas l'inserer dans un fichier contenant les photos de chaque contacts ..\GestionContact\Assets\PhotoContact
 * et on vas charger l'url dans celle du contact2.
 *
 * \class ModifContact
 */

/*!
 * \brief ModifContact::ModifContact
 * Constructeur de la classe ModifContact.
 * On initialise les connexions entre signaux et slots.
 * \param parent
 */

ModifContact::ModifContact(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModifContact)

{
    ui->setupUi(this);

        // signal emit par le boutton Supprimer Photo pour retirer la photo du contact à modifier.
        connect(this->ui->BsupprPhoto,SIGNAL(clicked()),this,SLOT(SupprimePhoto()));
        // signal emit par le boutton Telecharger Photo pour ajouter une nouvelle photo au contact.
        connect(this->ui->BdwnlPhoto,SIGNAL(clicked()),this,SLOT(TelechargePhoto()));
        // signal emit par le boutton Annuler Modification pour fermer le formulaire de modification et retourner à l'affiche du contact.
        connect(this->ui->BAnnuleModif,SIGNAL(clicked()),this,SLOT(AnnuleModification()));
        // signal emit par le boutton Valider Modification pour lancer la vérification de formulaire et par la suite valider si les entrées sont correctes.
        connect(this->ui->BValideModif,SIGNAL(clicked()),this,SLOT(VerificationContact()));
        // signal emit par la vérification des entrées pour lancer la modification.
        connect(this,SIGNAL(ValideContact()),this,SLOT(ValideModif()));


}

/*!
 * \brief ModifContact::~ModifContact
 * Destructeur de la classe ModifContact.
 */

ModifContact::~ModifContact()
{
    delete ui;
}

/*!
 * \brief ModifContact::initModifContact
 * Méthode ( slot ) qui permet de charger les informations du contact à modifier dans le formulaire.
 * Un signal est envoyé depuis le Widget principale pour lancer cette méthode avec comme paramètre le contact séléctionné à modifier.
 * On charge les informations du contact pour faciliter la prise en main de l'utilisateur, on ne vas donc pas vérifier si une entrée est différente du contact initial
 * on va directement réecrir les données dans la BDD même si elle restent les mêmes.
 *
 * On récupère donc toute les informations du contact puis on les charge dans les QLineEdit définis à chaque attributs
 * On charge aussi la photo et on l'affiche par la suite.
 * \param contact
 */

void ModifContact::initModifContact(Contact* contact){
    if (contact) {
        c1=contact;
        CheminPhoto=QString::fromStdString(contact->getPhoto());
        this->ui->LigneNom->setText(QString::fromStdString(contact->getNom()));
        this->ui->LignePrenom->setText(QString::fromStdString(contact->getPrenom()));
        this->ui->LigneEntreprise->setText(QString::fromStdString(contact->getEntreprise()));
        this->ui->LigneMail->setText(QString::fromStdString(contact->getMail()));
        this->ui->LigneTelephone->setText(QString::fromStdString(contact->getTelephone()));
        this->ui->LigneDate->setText(QString::fromStdString(contact->getDate().toString()));
        if(QString::compare(QString::fromStdString(contact->getPhoto()), QString()) != 0){

            bool valid = image.load(CheminPhoto);
            if(valid){
                image = image.scaledToWidth(ui->PhotoLabel->width(), Qt::SmoothTransformation);
                ui->PhotoLabel->setPixmap(QPixmap::fromImage(image));
                qDebug() << "repertoire : " << CheminPhoto;
            }
            else {
                qDebug() << "Erreur : Impossible de charger l'image.";
            }

        }
    }
}

/*!
 * \brief ModifContact::SupprimePhoto
 * Méthode ( slot ) qui permet de supprimer la photo déjà chargée dans le contact.
 * méthode utilisée dans le cas ou on souhaite retirer la photo pour laisser place à la photo de base d'un contact.
 */

void ModifContact::SupprimePhoto(){
    CheminPhoto.clear();
    this->ui->PhotoLabel->clear();
}

/*!
 * \brief ModifContact::TelechargePhoto
 * Méthode (slot) qui permet à l'utilisateur de télécharge une photo sur le formulaire,
 * L'url de la photo sera insérée dans une variable globale.
 * La photo vas directement être insérée dans un Label et sera affichée dans le formulaire.
 */

void ModifContact::TelechargePhoto()
{
    CheminPhoto = QFileDialog::getOpenFileName(this, "Sélectionner une photo", QDir::homePath(), "Images (*.png *.jpg *.jpeg *.bmp)");

    if(QString::compare(CheminPhoto, QString()) != 0){

        bool valid = image.load(CheminPhoto);
        if(valid){
                    image = image.scaledToWidth(ui->PhotoLabel->width(), Qt::SmoothTransformation);
                    ui->PhotoLabel->setPixmap(QPixmap::fromImage(image));
                    qDebug() << "repertoire : " << CheminPhoto;
        }
        else {
                    qDebug() << "Erreur : Impossible de charger l'image.";
        }

    }
    else {
       qDebug() << "Aucun fichier sélectionné.";
      }
}

/*!
 * \brief ModifContact::EnregistrePhotoContact
 * Méthode qui permet d'enregister la photo du contact dans un des répértoire de l'application.
 * Lorsque le contact est validé et que l'utilisateur à téléchargé une photo dans le formulaire,
 * la méthode ici est lancée pour récuperer cette photo en paramètre, créer un nouvel URL avec une génération aléatoire de nombre entre 10 million et 1 million
 * on copie la photo dans le répértoire en changant sont nom par la nouvelle url.
 *
 * La méthode à la fin renvoie la nouvelle Url pour l'inserer dans le contact envoyé par singal à la BDD.
 * Le contact a ainsi désormais sa photo dans le répertoire de l'application avec un nom unique pour eviter des erreurs d'affichages.
 * \param Url
 * \return cheminFichier
 */

std::string ModifContact::EnregistrePhotoContact(const std::string& Url) {
    std::string cheminAsset = "../GestionContact/Assets/PhotoContact/Ppc";
    std::string cheminFichier = "";


    std::string extension = Url.substr(Url.find_last_of('.') + 1);
    std::string NewUrl;
    bool stop = false;


    if (std::filesystem::exists(Url) && std::filesystem::is_regular_file(Url)) {
do {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dis(100000000, 999999999);
            NewUrl = std::to_string(dis(gen)) + "." + extension;
            cheminFichier = cheminAsset + NewUrl;

            if (!std::filesystem::exists(cheminFichier)) {
                std::filesystem::copy_file(Url, cheminFichier);
                qDebug()<<"Copie du fichier terminée !";
                    stop = true;

            } else {
                qDebug()<<"Erreur : Url déjà existant, recréation d'un Url..";
            }
} while (stop == false);
    } else {
qDebug()<<"Le fichier source n'existe pas ou n'est pas un fichier régulier.";
    }

    return cheminFichier;
}

/*!
 * \brief ModifContact::AnnuleModification
 * Méthode (slot) qui permet de fermer la fenêtre ce modification contact.
 *
 * On emet un signal au Widget principale pour fermer la fenêtre ModifContact et réouvrir la fenêtre AfficheContact.
 */

void ModifContact::AnnuleModification(){
    emit AnnuleModif();
}

/*!
 * \brief ModifContact::VerificationChamp
 * Méthode ( slot ) qui vérifie si les champs possèdent des erreurs.
 * en paramètre on à
 * \param champ : QLineEdit d'entré du formulaire.
 * \param label : associé au QLineEdit qui indique le type d'entrée et change de text en fonction des erreurs présentes.
 * \param reg : regex imposé à la vérification en fonction de l'entrée.
 * \param vide : message d'erreur indiquant que l'entrée est vide.
 * \param errRegex : message d'erreur inquant que le format est incorrect.
 * \param labelText : string initial du QLabel , permet de changer la valeur de celui ci sans perdre la valeur initiale.
 *
 * On vérifie donc le texte en entré qui il correspond au regex , si c'est le cas
 * on vérifie si le QLabel de l'entrée ne possède pas son texte initial , ex pour le mail : " Mail : "
 * si le QLabel n'a pas son texte initial c'est que l'entrée précédente avait un erreur, on change donc le texte pour retirer le text d'erreur.
 *
 * On vérifie donc que le texte en entré ne soit pas vide,
 * on vérifie si le QLabel de l'entrée possède pas déjà le message d'erreur vide , pour éviter d'ajouter une nouvelle fois le message d'erreur par dessus
 * si le QLabel n'a pas son texte d'erreur vide alors on lui change son text , ex pour le mail " Mail : Veuillez remplir cette case. "
 *
 * On vérifie donc le texte en entré qui il correspond au regex , si ce n'est pas le cas
 * on vérifie si le QLabel de l'entrée possède pas déjà le message d'erreur regex , pour éviter d'ajouter une nouvelle fois le message d'erreur par dessus
 * si le QLabel n'a pas son texte d'erreur de regex alors on lui change son texte , ex pour le mail " Mail : Le format est incorrect. "
 *
 *
 * \return false : dans le cas ou une vérification contient une erreur.
 * \return true : dans le cas ou une vérification contient aucune erreur.
 */

bool ModifContact::VerificationChamp(QLineEdit* champ, QLabel* label, const std::regex& reg, const QString& vide, const QString& errRegex, const QString& labelText) {
    if (std::regex_match(champ->text().toStdString(), reg)) {
if (label->text() != labelText) {
            label->setText(labelText);
}
return true;
    }
    else if (champ->text().isEmpty()) {
if (label->text() != labelText + vide) {
            label->setText(labelText + vide);
}
return false;
    }
    else {
if (label->text() != labelText + errRegex ) {
            label->setText(labelText + errRegex);
}
return false;
    }
}

/*!
 * \brief ModifContact::VerificationContact
 * Méthode (slot) qui commence la vérification des entrées du formulaire.
 * On utilise une seconde méthode ( VerificationChamp() ) qui return true dans le cas ou une entrée à aucune erreur.
 * dans le cas ou on a aucune erreur on emit un signal pour demander à la BDD si le mail entré existe déjà dans la BDD
 * dans le cas ou on a des erreur , la même méthode qui vérifie si return la valeur de vérification ( VerificationChamp() ) se charge d'afficher les erreurs.
 */

void ModifContact::VerificationContact() {


    std::regex reg("^[A-Za-z]+(?:[ -][A-Za-z]+)*$");
    std::regex regMail("^[[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}$");
    std::regex regTelephone("^(0|\\+33\\s?)[1-9](\\s?\\d{2}){4}$");

    QString vide = "<span style='color: red;'> Veuillez remplir cette case.</span>";
    QString errRegex = "<span style='color: red;'> Le format est incorrect.</span>";




    if (
        VerificationChamp(this->ui->LigneNom, this->ui->LabelNom, reg, vide, errRegex, "Nom :")
        &&
        VerificationChamp(this->ui->LignePrenom, this->ui->LabelPrenom, reg, vide, errRegex, "Prenom :")
        &&
        VerificationChamp(this->ui->LigneEntreprise, this->ui->LabelEntreprise, reg, vide, errRegex, "Entreprise :")
        &&
        VerificationChamp(this->ui->LigneMail, this->ui->LabelMail, regMail, vide, errRegex, "Mail :")
        &&
        VerificationChamp(this->ui->LigneTelephone, this->ui->LabelTelephone, regTelephone, vide, errRegex, "Telephone :")
        )
    {
    emit VerifMail(this->ui->LigneMail->text().toLower(),"modif");
    }
    else{
VerificationChamp(this->ui->LigneNom, this->ui->LabelNom, reg, vide, errRegex, "Nom :");

VerificationChamp(this->ui->LignePrenom, this->ui->LabelPrenom, reg, vide, errRegex, "Prenom :");

VerificationChamp(this->ui->LigneEntreprise, this->ui->LabelEntreprise, reg, vide, errRegex, "Entreprise :");


VerificationChamp(this->ui->LigneMail, this->ui->LabelMail, regMail, vide, errRegex, "Mail :");


VerificationChamp(this->ui->LigneTelephone, this->ui->LabelTelephone, regTelephone, vide, errRegex, "Telephone :");
    }
}

/*!
 * \brief ModifContact::ValideMail
 *Méthode (slot) qui s'execute lorsque la BDD renvoie la vérification de mail déjà existant.
 * Dans le cas ou le booleen du signal est false alors le mail est déjà existant et on met un message d'erreur.
 *
 * Dans le cas ou le booleen du signal est true c'est que l'utilisateur a modifié le mail et qu'il ne se trouve pas dans la BDD,
 * on remet le texte du QLabel à sa valeur initial et on emet un signal pour valider le contact au slot ValideModif().
 *
 * Dans le cas ou le booleen du signal est false MAIS que le mail en entrée est identique au mail du contact initial,
 * celà veut dire que l'utilisateur n'as pas touché au mail lors de sa modification donc on emet le signal pour valider le contact au slot  ValideModif().
 * \param val
 */

void ModifContact::ValideMail(bool val){
    if (val == false && this->ui->LigneMail->text().toLower().toStdString() == c1->getMail()) {
        this->ui->LabelMail->setText("Mail :");
        emit ValideContact();
    }   else if (val == false){
        this->ui->LabelMail->setText("Mail : <span style='color: red;'> Le Mail est déjà existant.</span>");
    } else {
        this->ui->LabelMail->setText("Mail :");
        emit ValideContact();
    }
}

/*!
 * \brief ModifContact::ValideModif
 * Méthode ( slot ) qui lance la validation du formulaire et envoie donc le contact1 ( initial ) et le contact2 (modifié) à la BDD.
 * On vérifie dans un premier temps l'url de la photo dans le formulaire, dans le cas ou celle ci est vide on assigne la photo de base d'utilisateur
 * qui est :  ../GestionContact/Assets/ProfileIcon.jpg
 *
 * Si la photo d'url n'est pas vide et est la même que celle du contact1, on garde alors le même Url et on la chargera dans le contact2.
 *
 * Si la photo d'url n'est pas vide et est différente que celle du contact
 * on appel une méthode qui vas permettre d'enregistrer la photo entrée dans un répertoire.
 * on va par la suite supprimer la photo du contact1 car elle ne sera plus utilisée.
 *
 * Une fois celà fait on crée un variable contact2 qu'on vas charger avec nos informations contenues dans le formulaire et on vas emit ce contact
 *
 * Une fenêtre de confirmation est créer afin d'éviter une suppréssion faite par inadvertance.
 * Si l'utilisateur confirme, on emet un signal au Widget principale pour communiquer avec la BDD.
 * On emit un second signal pour rafraichir la liste de contact dans le Widget principale pour ainsi afficher le contact modifié.
 */

void ModifContact::ValideModif(){

    if(c1){
        std::string Url="";

        if( CheminPhoto.toStdString() != c1->getPhoto() && !CheminPhoto.toStdString().empty()){
        Url = EnregistrePhotoContact(this->CheminPhoto.toStdString());
        }
        else if(this->CheminPhoto.toStdString().empty()){
        Url="../GestionContact/Assets/ProfileIcon.jpg";
        } else {
            Url = CheminPhoto.toStdString();
        }


        if (!c1->getPhoto().empty() && c1->getPhoto().find("../GestionContact/Assets/PhotoContact/") != std::string::npos && c1->getPhoto() != Url) {

            if (std::filesystem::exists(c1->getPhoto())) {
                std::filesystem::remove(c1->getPhoto());
                qDebug() << "Ancienne photo supprimée.";
            }
        }

    Contact * c2 = new Contact(
        this->ui->LigneNom->text().toStdString(),
        this->ui->LignePrenom->text().toStdString(),
        this->ui->LigneEntreprise->text().toStdString(),
        this->ui->LigneMail->text().toLower().toStdString(),
        this->ui->LigneTelephone->text().toStdString(),
        Url
        );


    c2->setDate(toDate(this->ui->LigneDate->text().toStdString()));

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation de modification", "Êtes-vous sûr de vouloir enregistrer ces modifications ?", QMessageBox::No | QMessageBox::Yes);
               if (reply == QMessageBox::Yes) {
            emit BDDModifContact(*c1,*c2);

            qDebug()<< "Modification contact.";

            emit UIListeContactRefresh();

                } else {

               qDebug() << "Modification annulée par l'utilisateur.";
                  return;
              }

    }
}

/*!
 * \brief ModifContact::toDate
 * Méthode qui permet de transformer une date sous forme de string entrée en paramètre en une date de type Date
 * et de la return.
 * ( ref Class Date )
 * \param date
 * \return d
 */

Date ModifContact::toDate(const std::string date){
    Date* d = new Date(01,01,2000);
    std::istringstream ss(date);
    char slash;
    int jour, mois, annee;

    ss >>  jour >> slash >> mois >> slash >> annee;
    d->setDate(jour,mois,annee);

    return *d;

}
