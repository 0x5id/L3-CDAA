#include "Date.h"
#include <sstream>

/*!
 * \file Date.cpp
 * \brief Classe qui permet de générer une Date
 * \class Date
 */

// constructeurs et destructeurs

/*!
 * \brief Date::Date()
 *constructeur standart de la classe Date
 *permet de générer la date du jour de cette dite génération.
 * \var modif : modif est un booleen initialisé à false dans ce constructeur
 *  ce qui permettra de savoir si la date à été choisie ou non
 */

Date::Date()
{
    time_t tn = time(0);
    this->date = localtime(&tn);

    unsigned int JourMtn = date->tm_mday;
    this->setJour(JourMtn);
    unsigned int MoisMtn = date->tm_mon +1;
    this->setMois(MoisMtn);
    unsigned int AnneeMtn = date->tm_year+1900;
    this->setAnnee(AnneeMtn);

    modif = false ;

}

/*!
 * \brief Date::~Date()
 *destructeur standart de la classe Date
 */

Date::~Date(){}


/*!
 * \brief Date::Date(const unsigned int , const unsigned int , const unsigned int)
 *constructeur de la classe Date
 *permet de générer la date de son choi.
 *\param jour : valeur du jour choisis
 *\param mois : valeur du mois choisis
 *\param annee : valeur de l'annee choisie
 * \var modif : modif est un booleen initialisé à true dans ce constructeur
 *  ce qui veut dire que la date à bien été choisis ici
 */

Date::Date(const unsigned int jour, const unsigned int mois, const unsigned int annee){
    setDate(jour, mois, annee);
    modif = true;
}



// accesseurs

/*!
 * \brief Date::getJour()
 * accesseur permetant d'acceder à la variable jour
 * si la variable modif est true , cela signifie que l'utilisateur à rentré sa propre date
 * donc on return la variable jour
 *\return this->jour
 *si la variable modif est à false alors l'utilisateur génère la date du jour de cette même génération
 *\return date->tm_mday
 */

unsigned int Date::getJour() const{
    if(Modification())
        return this->jour;
    else
        return date->tm_mday;
}

/*!
 * \brief Date::getMois()
 * accesseur permetant d'acceder à la variable mois
 * si la variable modif est true , cela signifie que l'utilisateur à rentré sa propre date
 * donc on return la variable mois
 *\return this->mois
 *si la variable modif est à false alors l'utilisateur génère la date du jour de cette même génération
 *\return date->tm_mon+1
 *on ajoute +1 car la méthode considère les mois d'allant de O à 11
 */

unsigned int Date::getMois() const{
    if(Modification())
        return this->mois;
    else
        return date->tm_mon+1;
}

/*!
 * \brief Date::getAnnee()
 * accesseur permetant d'acceder à la variable annee
 * si la variable modif est true , cela signifie que l'utilisateur à rentré sa propre date
 * donc on return la variable annee
 *\return this->annee
 *si la variable modif est à false alors l'utilisateur génère la date du jour de cette même génération
 *\return date->tm_year+1900
 *on ajoute +1900 pour avoir l'année correcte
 */

unsigned int Date::getAnnee() const{
    if(Modification())
        return this->annee;
    else
        return date->tm_year+1900;
}



//mutateurs

/*!
 * \brief Date::setJour()
 * mutateur permetant de selection le jour de son choix
 * \param j
 */

void Date::setJour(const unsigned int j){
    this->jour=j;
}

/*!
 * \brief Date::setMois()
 * mutateur permetant de selection le mois de son choix
 * \param m
 */

void Date::setMois(const unsigned int m){
    this->mois=m;
}

/*!
 * \brief Date::setAnnee()
 * mutateur permetant de selection l'annee de son choix
 * \param a
 */

void Date::setAnnee(const unsigned int a){
    this->annee=a;
}

/*!
 * \brief Date::setJour()
 * mutateur de créer la date de son choix
 * avec comme condition un jour allant de 1 à 31
 * un mois de 1 à 12
 * une année supérieure à 1950
 * \param jour : entrée du jour
 * \param mois : entrée du mois
 * \param annnee : entrée du annnee
 *
 * si les conditions ne sont pas respectés la console affiche une erreur.
 */

void Date::setDate(const unsigned int jour, const unsigned int mois, const unsigned int annee){
    if(jour >= 1 && jour <= 31)
        setJour(jour);
    else
        throw std::invalid_argument("L'entrée du Jour n'est pas valide ");

    if(mois >= 1 && mois <= 12)
        setMois(mois);
    else
        throw std::invalid_argument("L'entrée du Mois n'est pas valide");

    if(annee >= 1950)
        setAnnee(annee);
    else
        throw std::invalid_argument("L'entrée de l'Annee n'est pas valide");
}


//méthodes


/*!
 * \brief Date::Modification()
 * Méthode permmetant de return le bool modif afin de savoir si la date est généré par choix
 * ou bien à ce jour
 * si true alors l'utilisateur à choisis
 * si false alors la date est à ce jour.
 * \return modif
 */

bool Date::Modification() const{
    return modif;
}

/*!
 * \brief Date::ToString()
 * méthode qui permet de convertir tout les variable d'une date en une seule date sous forme de string
 * ce qui donne JJ/MM/AAAA
 */


std::string Date::toString(){
    std::string varJour="";
    std::string varMois="";

    if(this->getJour() <10)
        varJour += "0";
    varJour += std::to_string(this->getJour());

    if(this->getMois() <10)
        varMois += "0";
    varMois += std::to_string(this->getMois());

    return varJour+"/"+varMois+"/"+std::to_string(this->getAnnee());
}



//surcharge d'operateurs

/*!
 * \brief Surchage d'opérateur
 * on return dans l'os la variable jour, mois et annee séparés par des " / " d'une date
 * \return os
 */

std::ostream& operator<<(std::ostream& os, const Date& date){
    os << date.jour << '/' << date.mois << '/' << date.annee;
    return os;
}
