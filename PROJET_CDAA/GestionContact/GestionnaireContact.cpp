#include "GestionnaireContact.h"


/*!
 * \file GestionnaireContact.cpp
 * \brief Classe qui permet de gerer les Contacts
 * \class GestionnaireContact
 */


/*!
 * \brief GestionnaireContact::GestionnaireContact
 * Constructeur standard de la classe GestionnaireContact()
 */

GestionnaireContact::GestionnaireContact(){
  lstContacts =std::list<Contact *>();
}

/*!
 * \brief GestionnaireContact::~GestionnaireContact()
 * Destructeur de la classe GestionnaireContact
 */

GestionnaireContact::~GestionnaireContact(){}

//accesseurs

/*!
 * \brief GestionnaireContact::getLstContacts()
 * accesseur de la liste de contacts
 * \return this->lstContacts
 */

std::list<Contact *> GestionnaireContact::getLstContacts() const
{
  return this->lstContacts;
}

/*!
 * \brief GestionnaireContact::getContactAt(unsigned int i)
 * accesseur d'un contact à l'index i
 * on return it qui est le contact à l'index ajouté en paramètre.
 * \param i : index du contact dans la liste de contacts.
 * \return it;
 */

Contact* GestionnaireContact::getContactAt(unsigned int i){
  if (i < lstContacts.size()) {
      auto it = lstContacts.begin();
      std::advance(it, i);
      return *it;
  } else {
      return nullptr;
  }
}


/*!
 * \brief GestionnaireContact::addContact(Contact *c)
 * Méthode permettant d'ajouter un contact à la fin de la liste de contacts
 * \param c
 */

void GestionnaireContact::addContact(Contact *c)
{
  this->lstContacts.push_back(c);
}

/*!
 * \brief GestionnaireContact::deleteContact
 * permet de supprimer le contact de son choix de la liste de contacts
 * \param c
 */

void GestionnaireContact::deleteContact(Contact *c)
{
  lstContacts.remove(c);
}


/*!
 * \brief GestionnaireContact::deleteContact
 * permet de return la taille de la liste et de savoir combien de contacts s'y trouvent.
 * \return this->lstContacts.size();
 */
int GestionnaireContact::getNbContact() const{
  return this->lstContacts.size();
}

/*!
 * \brief GestionnaireContact::ContactsDisplay
 * permet d'afficher tout les contacts d'une liste de contact
 * sous forme de string à l'aide de la méthode toString() de la classe Contact
 * \return str
 */

std::string GestionnaireContact::ContactsDisplay() const{
  std::string str = "";
  if(lstContacts.size() != 0)
      for(auto &inter : lstContacts){
          str += inter->toString()+"\n";
      }

  return str;
}

/*!
 * \brief GestionnaireContact::clear
 * permet de nettoyer la liste du gestionnaire de contact
 */

void GestionnaireContact::clear()
{
   this->lstContacts.clear();
}


/*!
 * \brief GestionnaireContact::getSize()
 * Permet de return la taille de la liste de contact
 * \return str
 */

std::string GestionnaireContact::getSize()
{
   std::string str =  std::to_string(this->lstContacts.size());
   return str;
}


/*!
 * \brief GestionnaireContact::toString
 * Méthode qui permer de convertire une liste de contacts en string
 * et à l'afficher
 * \return str
 */

std::string GestionnaireContact::toString() const
{
   std::string str = "";
   str += "Liste de contacts : \n"+ContactsDisplay();
   return str;
}


//surcharge d'operateurs

/*!
 * \brief surcharge d'opérateur
 * Utilisation de la méthode toString pour afficher la liste de contact
 * \param os
 * \param gc
 * \return
 */

std::ostream& operator<<(std::ostream& os, const GestionnaireContact& gc)
{
os << gc.toString();
    return os;
}

