#include "GestionnaireInteraction.h"


/*!
 * \file GestionnaireInteraction.cpp
 * \brief Classe qui permet de gerer les Interactions
 * \class GestionnaireInteraction
 */

/*!
 * \brief GestionnaireInteraction::GestionnaireInteraction
 * Constructeur standard de la classe GestionnaireInteraction()
 */

GestionnaireInteraction::GestionnaireInteraction()
{
    lstInteractions =std::list<Interaction *>();
}

/*!
 * \brief GestionnaireInteraction::~GestionnaireInteraction
 * Destructeur de la classe GestionnaireInteraction()
 */

GestionnaireInteraction::~GestionnaireInteraction(){}


/*!
 * \brief GestionnaireInteraction::getLstInteractions()
 * accesseur de la liste d'interactions
 * \return this->lstInteractions;
 */

std::list<Interaction *> GestionnaireInteraction::getLstInteractions() const
{
    return this->lstInteractions;
}

/*!
 * \brief GestionnaireInteraction::getInteractionAt(unsigned int i)
 * accesseur d'une interaction à l'index i
 * on return it qui est l'interaction à l'index ajouté en paramètre.
 * \param i : index de l'interaction dans la liste d'interactions.
 * \return it;
 */

Interaction* GestionnaireInteraction::getInteractionAt(unsigned int i){
    if (i < lstInteractions.size()) {
        auto it = lstInteractions.begin();
        std::advance(it, i);
        return *it;
    } else {
        return nullptr;
    }
}

/*!
 * \brief GestionnaireInteraction::addInteraction
 * Méthode qui permet d'ajouter une interaction i dans la liste d'interaction.
 * \param i
 */

void GestionnaireInteraction::addInteraction(Interaction *i)
{
    this->lstInteractions.push_back(i);
}

/*!
 * \brief GestionnaireInteraction::deleteInteraction
 * Méthode qui permet de retrier l'interaction i de la liste d'interactions.
 * \param i
 */

void GestionnaireInteraction::deleteInteraction(Interaction *i)
{
    lstInteractions.remove(i);
}

/*!
 * \brief GestionnaireInteraction::getNbInteraction
 * Méthode qui permet de récuperer le nombre d'interactions dans la liste.
 * \return this->lstInteractions.size();
 */

int GestionnaireInteraction::getNbInteraction() const{
    return this->lstInteractions.size();
}

/*!
 * \brief GestionnaireInteraction::InteractionsDisplay
 * Méthode qui permet d'afficher l'interaction dans la console.
 * \return str;
 */

std::string GestionnaireInteraction::InteractionsDisplay() const{
    std::string str = "";
    if(lstInteractions.size() != 0)
        for(auto &inter : lstInteractions){
            str += inter->toString()+"\n";
        }

    return str;
}

/*!
 * \brief GestionnaireInteraction::clear
 * permet de nettoyer la liste du gestionnaire de Interaction
 */

void GestionnaireInteraction::clear()
{
    this->lstInteractions.clear();
}


/*!
 * \brief GestionnaireInteraction::getSize
 * Méthode qui permet de renvoyer dans un string la taille de la liste d'intéractions
 * \return str;
 */

std::string GestionnaireInteraction::getSize()
{
    std::string str =  std::to_string(this->lstInteractions.size());
    return str;
}

/*!
 * \brief GestionnaireInteraction::toString
 * Méthode qui permet d'inserer toute les intéractions dans un string et de le renvoyer.
 * \return str;
 */

std::string GestionnaireInteraction::toString() const
{
    std::string str = "";
    str += "Liste des Interactions : \n"+InteractionsDisplay();
    return str;
}


//surcharge d'operateurs

/*!
 * \brief surcharge d'opérateur
 * Utilisation de la méthode toString pour afficher la liste de Interaction
 * \param os
 * \param gc
 * \return
 */

std::ostream& operator<<(std::ostream& os, const GestionnaireInteraction& gi)
{
    os << gi.toString();
    return os;
}
