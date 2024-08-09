#include "Contact.h"


/*!
 * \file Contact.cpp
 * \brief Classe qui permet de générer un contact
 * \class Contact
 */


//constructeurs et destructeurs

/*!
 * \brief Contact::Contact()
 *constructeur standart de la classe Contact
 */


Contact::Contact(){
    setNom("");
    setPrenom("");
    setEntreprise("");
    setMail("");
    setPhoto("");
    setTelephone("");
    lstInteractions = std::list<Interaction *>();
}


/*!
 * \brief Contact::Contact()
 *constructeur de la classe Contact
 *\param n : nom du contact
 *\param prenom : prenom du contact
 *\param e : entreprise du contact
 *\param m : mail du contact
 *\param t : telephone du contact
 *\param photo : chemin de la photo du contact
 */

Contact::Contact(const std::string & n, const std::string & prenom, const std::string & e,
                 const std::string & m, const std::string & t, const std::string & photo)
{
    this->setNom(n);
    this->setPrenom(prenom);
    this->setEntreprise(e);
    this->setMail(m);
    this->setTelephone(t);
    this->setPhoto(photo);
    Date date;
    this->lstInteractions = std::list<Interaction *>();
}


/*!
 * \brief Contact::~Contact()
 *destructeur de la classe Contact
 */

Contact::~Contact(){}


//accesseurs

/*!
 * \brief Contact::getNom()
 *accesseur du nom du contact
 *\return this->nom
 */

std::string Contact::getNom() const
{
    return this->nom;
}

/*!
 * \brief Contact::getPrenom()
 *accesseur du prenom du contact
 *\return this->prenom
 */

std::string Contact::getPrenom() const
{
    return this->prenom;
}

/*!
 * \brief Contact::getEntreprise()
 *accesseur de l'entreprise du contact
 *\return this->entreprise
 */

std::string Contact::getEntreprise() const
{
    return this->entreprise;
}

/*!
 * \brief Contact::getMail()
 *accesseur du mail du contact
 *\return this->mail
 */

std::string Contact::getMail() const
{
    return this->mail;
}

/*!
 * \brief Contact::getTelephone()
 *accesseur du numero de Telephone du contact
 *\return this->telephone
 */

std::string Contact::getTelephone() const
{
    return this->telephone;
}

/*!
 * \brief Contact::getPhoto()
 *accesseur de l'url de la photo du contact
 *\return this->photo
 */

std::string Contact::getPhoto() const
{
    return this->photo;
}

/*!
 * \brief Contact::getDateCreation()
 *accesseur de la date de creation du contact
 *\return this->date
 */

Date Contact::getDate() const
{
 return this->date;
}

/*!
 * \brief Contact::getLstInteractions()
 *accesseur de la liste d'interactions du contact
 *\return this->nom
 */

std::list<Interaction *> Contact::getLstInteractions() const
{
    return this-> lstInteractions;
}



//mutateurs

/*!
 * \brief Contact::setNom()
 *mutateur du nom du contact
 *\var str
 */

void Contact::setNom (const std::string & str)
{
    nom = formatString(str);
}

/*!
 * \brief Contact::setPrenom()
 *mutateur du prenom du contact
 *\var str
 */

void Contact::setPrenom (const std::string & str)
{
    prenom = formatString(str);
}

/*!
 * \brief Contact::setEntreprise()
 *mutateur de l'entreprise du contact
 *\var str
 */

void Contact::setEntreprise (const std::string & str)
{
    entreprise = formatString(str);
}

/*!
 * \brief Contact::setMail()
 *mutateur du mail du contact
 *\var str
 */

void Contact::setMail (const std::string & str)
{
    mail= str;
}

/*!
 * \brief Contact::setTelephone()
 *mutateur du telephone du contact
 *\var str
 */

void Contact::setTelephone (const std::string & str)
{
    telephone = str;
}

/*!
 * \brief Contact::setPhoto()
 *mutateur de l'url de la photo du contact
 *\var str
 */

void Contact::setPhoto (const std::string & str)
{
    photo = str;
}

/*!
 * \brief Contact::setDateCreation()
 *mutateur de la date du contact
 *\var date
 */

void Contact::setDate(const Date &date){
    this->date = date;
}


/*!
 * \brief Contact::setLstInteraction()
 *mutateur de la liste d'interactions du contact
 *\var lst
 */

void Contact::setLstInteraction(std::list<Interaction *> lst){
this->lstInteractions = lst;
}


//méthodes

/*!
 * \brief Contact::AddInteraction()
 * méthode qui permet de rajouter une interaction
 * à la fin de la liste d'interaction d'un contact
 *\var interaction
 */

void Contact::AddInteraction(Interaction *interaction)
{
this->lstInteractions.push_back(interaction);
}


/*!
 * \brief Contact::InteractionsDisplay()
 * méthode permettant d'afficher une liste d'interaction d'un contact
 * à l'aide de la méthode toString()
 *\return str : return sous forme de string la liste des interactions
 */

  std::string Contact::InteractionsDisplay() const{
    std::string str = "";
    if(lstInteractions.size() != 0)
        for(auto &inter : lstInteractions){
            str += inter->toString()+"\n";
            for(auto &todo : inter->getLstTodo())
                str += todo->toString()+"\n";

        }

    return str;
}

  /*!
   * \brief Contact::ToString()
   * méthode permettant de convertir l'ensemble d'un contact en une seule variable string
   * retourné
   *\return str : return sous forme de string toutes les informations d'un contact
   */


  std::string Contact::toString() const{
      std::string str = "";
      str += "Nom : "+this->getNom();
      str += "\nPrenom : "+this->getPrenom();
      str +="\nEntreprise : "+this->getEntreprise();
      str += "\nMail : "+this->getMail();
      str += "\nTelephone : "+this->getTelephone();
      str += "\nChemin Photo : "+this->getPhoto();
      str += "\nDate : "+this->getDate().toString();
      str += "\nInteraction(s) : \n"+InteractionsDisplay();
      return str;
  }



  std::string Contact::formatString(const std::string & input) {
      std::string fString = input;

      if (!fString.empty()) {
        fString[0] = std::toupper(fString[0]);
        for (size_t i = 1; i < fString.length(); ++i) {
            fString[i] = std::tolower(fString[i]);
        }
      }

      return fString;
  }


 //surcharge d'operateurs



  /*!
 * \brief Surcharche d'opérateurs
 * on utilise la méthode toString sur un contact et on le return
 * \param os
 * \param c
 *\return str : return sous forme de string la liste des interactions
 */

std::ostream& operator<<(std::ostream& os, const Contact& c)
{
os << c.toString();
    return os;
}
