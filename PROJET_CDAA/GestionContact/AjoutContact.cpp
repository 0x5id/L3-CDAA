#include "AjoutContact.h"
#include "ui_AjoutContact.h"
#include <QFileDialog>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QPixmap>
#include <regex>
#include <filesystem>
#include <random>

/*!
 * \file AjoutContact.cpp
 * \brief Classe qui permet l'affichage du formulaire d'ajout de contact.
 * L'utilisateur vas entrer dans le formulaire les informations du contact qu'il veut creer.
 * Une fois celà fait lors de la validation contact une première étape de vérification est lancée.
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
 * Dans le cas ou celle-ci n'existe pas on envoie un signal pour valider le formulaire d'ajout de contact,
 * on envoie un signal contenant le contact vers le Widget principale qui renverra ce signal vers la BDD pour l'ajouter.
 *
 * Un contact possède une photo.
 * Dans le cas ou l'utilisateur ne rentre pas de photo , le contact vas prendre comme valeur d'URL pour sa photo l'url de la photo de base,
 * cette photo de base se trouve dans le répertoire ..\GestionContact\Assets du nom de ProfileIcon.jpg
 *
 * Dans le cas ou l'utilisateur entre une image depuis son ordinateur, lors de la validation du formulaire on vas récuperer cette image,
 * on va par la suite en modifier le nom avec un générateur de nom basique avec une suite de chiffres ex : Ppc043289473298.jpg
 * et on vas l'inserer dans un fichier contenant les photos de chaque contacts ..\GestionContact\Assets\PhotoContact
 * et on vas changer l'url du contact avec la nouvelle URL.
 *
 * \class AjoutContact
 */


/*!
 * \brief AjoutContact::AjoutContact
 * Constructeur de la classe AjoutContact.
 * \param parent
 */
AjoutContact::AjoutContact(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AjoutContact)
{
    ui->setupUi(this);

    CheminPhoto="";

    connect(this->ui->BValideContact,SIGNAL(clicked()),this,SLOT(VerificationContact()));
    connect(this->ui->BdwnlPhoto,SIGNAL(clicked()),this,SLOT(TelechargePhoto()));
    connect(this->ui->BAnnuleFormulaire,SIGNAL(clicked()),this,SLOT(AnnuleFormulaire()));
    connect(this,SIGNAL(ValidContact()),this,SLOT(ValideContact()));

}

/*!
 * \brief AjoutContact::~AjoutContact
 * Destructeur de la classe AjoutContact.
 */
AjoutContact::~AjoutContact()
{
    delete ui;
}


/*!
 * \brief AjoutContact::VerificationContact
 * Méthode (slot) qui commence la vérification des entrées du formulaire.
 * On utilise une seconde méthode ( VerificationChamp() ) qui return true dans le cas ou une entrée à aucune erreur.
 * dans le cas ou on a aucune erreur on emit un signal pour demander à la BDD si le mail entré existe déjà dans la BDD
 * dans le cas ou on a des erreur , la même méthode qui vérifie si return la valeur de vérification ( VerificationChamp() ) se charge d'afficher les erreurs.
 */
void AjoutContact::VerificationContact() {


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
        emit VerifMail(this->ui->LigneMail->text().toLower(),"ajout");

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
 * \brief AjoutContact::VerificationChamp
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
 * on vérifie si le QLabel de l'entrée ne possède pas son texte initial , ex pour le mail : " Mail : "
 * si le QLabel n'a pas son texte initial c'est que l'entrée précédente avait un erreur, on change donc le text pour retirer le text d'erreur.
 *
 * On vérifie donc que le texte en entré ne soit pas vide
 * on vérifie si le QLabel de l'entrée possède pas déjà le message d'erreur vide , pour éviter d'ajouter une nouvelle fois le message d'erreur par dessus
 * si le QLabel n'a pas son texte d'erreur vide alors on lui change son text , ex pour le mail " Mail : Veuillez remplir cette case. "
 *
 * On vérifie donc le texte en entré qui il correcpond au regex , si ce n'est pas le cas
 * on vérifie si le QLabel de l'entrée possède pas déjà le message d'erreur regex , pour éviter d'ajouter une nouvelle fois le message d'erreur par dessus
 * si le QLabel n'a pas son texte d'erreur de regex alors on lui change son text , ex pour le mail " Mail : Le format est incorrect. "
 *
 *
 * \return false : dans le cas ou une vérification contient une erreur.
 * \return true : dans le cas ou une vérification contient aucune erreur.
 */

bool AjoutContact::VerificationChamp(QLineEdit* champ, QLabel* label, const std::regex& reg, const QString& vide, const QString& errRegex, const QString& labelText) {
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
 * \brief AjoutContact::ValideMail
 * Méthode (slot) qui s'execute lorsque la BDD renvoie la vérification de mail déjà existant.
 * Dans le cas ou le booleen du signal est false alors le mail est déjà existant et on met un message d'erreur.
 * dans le cas ou le booleen du dignal est true , on remet le texte du QLabel à sa valeur initial et on emet un signal pour valider le contact au slot ValideContact().
 * \param val
 */

void AjoutContact::ValideMail(bool val){
    if (val == false){
        this->ui->LabelMail->setText("Mail : <span style='color: red;'> Le Mail est déjà existant.</span>");

    } else {
        this->ui->LabelMail->setText("Mail :");

    emit ValidContact();
    }
}

/*!
 * \brief AjoutContact::ValideContact
 * Méthode ( slot ) qui lance la validation du formulaire et envoie donc le contact à la BDD.
 * On vérifie dans un premier temps l'url de la photo du contact , dans le cas ou celle ci est vide on assigne la photo de base d'utilisateur
 * qui est :  ../GestionContact/Assets/ProfileIcon.jpg
 *
 * Si la photo d'url n'est pas vide on appel une méthode qui vas permettre d'enregistrer la photo entrée dans un répertoire.
 *
 * Une fois celà fait on créer un variable contact qu'on vas charger avec nos informations contenues dans le formulaire et on vas emit ce contact
 * Le signal ira vers la BDD en passant pas le Widget principale.
 *
 * On emit un second signal pour rafraichir la liste de contact dans le Widget principale pour ainsi afficher le nouveau contact.
 *
 * On appel pour finir une méthode qui néttoie le formulaire.
 */

void AjoutContact::ValideContact(){

    std::string Url="";

    if(!this->CheminPhoto.toStdString().empty()){
         Url= EnregistrePhotoContact(this->CheminPhoto.toStdString());
    qDebug() << Url;

    }
    else
    {
        Url="../GestionContact/Assets/ProfileIcon.jpg";
    }

        Contact c = Contact(
        this->ui->LigneNom->text().toStdString(),
        this->ui->LignePrenom->text().toStdString(),
        this->ui->LigneEntreprise->text().toStdString(),
        this->ui->LigneMail->text().toLower().toStdString(),
        this->ui->LigneTelephone->text().toStdString(),
        Url
        );

    emit BDDAjoutContact(c);

        qDebug()<< "Creation contact.";
    emit UIListeContactRefresh();

        AnnuleFormulaire();
}


/*!
 * \brief AjoutContact::EnregistrePhotoContact
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

std::string AjoutContact::EnregistrePhotoContact(const std::string& Url) {
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
 * \brief AjoutContact::TelechargePhoto
 * Méthode (slot) qui permet à l'utilisateur de télécharge une photo sur le formulaire,
 * L'url de la photo sera insérée dans une variable globale.
 * La photo vas directement être insérée dans un Label et sera affichée dans le formulaire.
 */

void AjoutContact::TelechargePhoto()
{
     CheminPhoto = QFileDialog::getOpenFileName(this, "Sélectionner une photo", QDir::homePath(), "Images (*.png *.jpg *.jpeg *.bmp)");

    if(QString::compare(CheminPhoto, QString()) != 0){

        bool valid = image.load(CheminPhoto);
        if(valid){
            image = image.scaledToWidth(ui->PhotoLabel->width(), Qt::SmoothTransformation);
            ui->PhotoLabel->setPixmap(QPixmap::fromImage(image));
            qDebug() << "repertoire : " << CheminPhoto;
        } else {
            qDebug() << "Erreur : Impossible de charger l'image.";
        }

    } else {
        qDebug() << "Aucun fichier sélectionné.";
    }
}

/*!
 * \brief AjoutContact::AnnuleFormulaire
 * Méthode qui néttoie toute les entrées du formulaire.
 */
void AjoutContact::AnnuleFormulaire(){
    this->ui->LigneNom->clear();
    this->ui->LignePrenom->clear();
    this->ui->LigneEntreprise->clear();
    this->ui->LigneMail->clear();
    this->ui->LigneTelephone->clear();
    this->CheminPhoto.clear();
    this->ui->PhotoLabel->clear();
}

