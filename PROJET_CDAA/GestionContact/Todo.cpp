#include "Todo.h"

/*!
 * \file Todo.cpp
 * \brief Classe qui permet de générer une interaction Todo
 * \class Todo
 */


/*!
 * \brief Todo::Todo()
 *constructeur standart de la classe Todo
 */


Todo::Todo(){
    setContenu("");
    date = Date();
}

/*!
 * \brief Todo::Todo(std::string)
 * constructeur qui permet de creer un Todo avec le contenu de notre choix
 * avec la date de création du Todo
 * \param str : contenu du Todo
 */

Todo::Todo(std::string contenu){
    setContenu(contenu);
    date = Date();
}

/*!
 * \brief Todo::Todo(std::string , Date )
 * constructeur qui permet de creer un Todo avec le contenu et la date de notre choix
 * \param str : contenu du Todo
 * \param d : date associée au Todo
 */

Todo::Todo(std::string contenu, Date d){
    setContenu(contenu);
    setDate(d);
}
Todo::~Todo(){}

/*!
 * \brief Todo::getContenu
 * \return this->contenu
 */

//accesseurs
std::string Todo::getContenu() const{
    return this->contenu;
}

/*!
 * \brief Todo::getDate
 * \return date
 */

Date Todo::getDate() const{
    return date;
}

//mutateurs

/*!
 * \brief Todo::setContenu
 * \param str : contenu que l'utilisateur rentre
 */


void Todo::setContenu(const std::string str){
    this->contenu = str;
}

/*!
 * \brief Todo::setDate
 * \param d : date que l'utilisateur rentre
 */

void Todo::setDate(const Date d){
    date = d;
}
//méthodes

/*!
 * \brief Todo::toString
 * Méthode qui va permettre de convertir un Todo en string
 * on vérifie le booleen Modif dans l'accesseur getDate() pour savoir
 * si c'est un Todo avec une date ajoutée ou non.
 * \return str : string dans lequel est stocké le Todo sous forme de string
 */

std::string Todo::toString() const{
    std::string str = "";
    if(this->getDate().Modification())
        str += "@Todo "+this->getContenu()+" @Date "+this->getDate().toString()+"\n";
    else
        str += "@Todo "+this->getContenu();
    return str;
}

/*!
 * \brief surcharge d'opérateur
 * on utilise la méthode toString pour renvoyer le Todo
 * \param lt : Todo
 * \return os
 */

//surchage d'opérateurs
std::ostream& operator<<(std::ostream& os, const Todo &lt){
    os << lt.toString();
    return os;
}
