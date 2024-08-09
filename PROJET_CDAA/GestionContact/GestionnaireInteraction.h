#ifndef GESTIONNAIREINTERACTION_H
#define GESTIONNAIREINTERACTION_H

#include <iostream>
#include <list>
#include <Date.h>
#include <Interaction.h>


/*!
 * @file GestionnaireInteraction.h
 * @brief Classe qui permet de générer un gestionnaire d'interactions
 * @class GestionnaireInteraction
 * @var list<Interaction *> lstInteractions
 */

class GestionnaireInteraction
{

private:

    std::list<Interaction *> lstInteractions;



public:
    //constructeurs et destructeurs
    GestionnaireInteraction();
    ~GestionnaireInteraction();

    //accesseur
    std::list<Interaction *> getLstInteractions() const;
    Interaction* getInteractionAt(unsigned int i);


    //méthodes
    std::string InteractionsDisplay() const;
    void modifInteraction(Interaction *c, unsigned int i);
    void addInteraction(Interaction *c);
    void deleteInteraction(Interaction *c);
    int getNbInteraction() const;
    void clear();
    std::string getSize();
    std::string toString() const;


    friend std::ostream& operator<<(std::ostream&, const GestionnaireInteraction&);
};

#endif // GESTIONNAIREINTERACTION_H
