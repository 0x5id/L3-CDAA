#ifndef CONTACT_H
#define CONTACT_H

#include <Date.h>
#include <Interaction.h>
#include <stdexcept>
#include <string>
#include <iostream>
#include <list>


/*!
 * @file Contact.h
 * @brief Classe qui permet de générer un contact
 * @class Contact
 * @var string nom
 * @var string prenom
 * @var string entreprise
 * @var string mail
 * @var string telephone
 * @var string photo
 * @var Date date
 * @var list<Interaction *> lstInteractions
 */

class Contact
{
private:
    //attributs
    std::string nom;
    std::string prenom;
    std::string entreprise;
    std::string mail;
    std::string telephone;
    std::string photo;
    Date date;
    std::list<Interaction *> lstInteractions;




public:
    //constructeurs et destructeurs
    Contact();
    ~Contact();
    Contact(const std::string &, const std::string &, const std::string &,
            const std::string &,const std::string &,const std::string &);

    //accesseurs
    std::string getNom() const;
    std::string getPrenom() const;
    std::string getEntreprise() const;
    std::string getMail() const;
    std::string getTelephone() const;
    std::string getPhoto() const;
    Date getDate() const;
    std::list<Interaction *> getLstInteractions() const;


    //mutateurs
        void setNom(const std::string &);
        void setPrenom(const std::string &);
        void setEntreprise(const std::string &);
        void setMail(const std::string &);
        void setTelephone(const std::string &);
        void setPhoto(const std::string &);
        void setDate(const Date& = Date());
        void setLstInteraction(std::list<Interaction *>);

        //Methodes
        void AddInteraction(Interaction *interaction);

        std::string InteractionsDisplay() const;
        std::string toString() const;
        std::string formatString(const std::string &);

        //surcharge d'operateurs
        friend std::ostream& operator<<(std::ostream&, const Contact&);
};

#endif // CONTACT_H
