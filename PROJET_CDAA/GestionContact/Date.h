#ifndef DATE_H
#define DATE_H

#include <time.h>
#include <string>
#include <iostream>
#include <stdexcept>

/*!
 * \file Date.h
 * \brief Classe qui sert à générer les dates
 * \class Date
 * \var unsigned int jour
 * \var unsigned int mois
 * \var unsigned int annee
 */

class Date
{

private:
    //attributs
    tm *date;
    unsigned int jour;
    unsigned int mois;
    unsigned int annee;
    bool modif;


public:
    //constructeurs et destructeurs
    Date();
    ~Date();

    Date(const unsigned int, const unsigned int , const unsigned int);


    //mutateurs
    void setJour(const unsigned int j);
    void setMois(const unsigned int m);
    void setAnnee(const unsigned int a);

    //accesseurs
    unsigned int getJour() const;
    unsigned int getMois() const;
    unsigned int getAnnee() const;

    //méthodes
    void setDate(const unsigned int, const unsigned int, const unsigned int);
    bool Modification() const;
    std::string toString();

    //surcharge d'operateurs
    friend std::ostream& operator<<(std::ostream& os, const Date& d);
};

#endif // DATE_H
