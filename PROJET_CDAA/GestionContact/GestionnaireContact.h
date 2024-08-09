#ifndef GESTIONNAIRECONTACT_H
#define GESTIONNAIRECONTACT_H

#include <iostream>
#include <list>
#include <Date.h>
#include <Contact.h>


/*!
 * @file GestionnaireContact.h
 * @brief Classe qui permet de générer un gestionnaire de contact
 * @class GestionnaireContact
 * @var list<Contact *> lstContacts
 */

class GestionnaireContact
{

    private:

      std::list<Contact *> lstContacts;



    public:
      //constructeurs et destructeurs
      GestionnaireContact();
      ~GestionnaireContact();

      //accesseur
      std::list<Contact *> getLstContacts() const;
      Contact* getContactAt(unsigned int i);

      //méthodes
      std::string ContactsDisplay() const;
      void modifContact(Contact *c, unsigned int i);
      void addContact(Contact *c);
      void deleteContact(Contact *c);
      int getNbContact() const;
      void clear();
      std::string getSize();
      std::string toString() const;


    friend std::ostream& operator<<(std::ostream&, const GestionnaireContact&);
};

#endif // GESTIONNAIRECONTACT_H
