#include "Interaction.h"


// constructeurs et destructeurs

/*!
 * \file Interaction.cpp
 * \brief Classe qui permet de générer une interaction et d'integrer les Todo
 * \class Interaction
 */


/*!
 * \brief Interaction::Interaction()
 *constructeur standart de la classe Interaction
 *contenant les var
 *\var contenu : contenu de l'interaction initialement vide
 *\var date : date de la création de l'interaction
 *\var lstTodo : liste dans laquelle on ajoute les Todo
 */

Interaction::Interaction()
{
contenu = "";
date = Date();
lstTodo = std::list<Todo *>();
}

/*!
 * \brief Interaction::Interaction(const std::string & c , const Date & d, const std::list<Todo *> lst)
 *constructeur de la classe Interaction
 *contenant le paramètre et les variables
 *\param d : date générée par l'utilisateur que l'utilisateur ajoute à l'interaction
 *\param c : contenu que l'utilisateur ajoute à l'interaction
 *\param lst : liste de todo
 *\var contenu : contenu de l'interaction
 *\var date : date de la création de l'interaction
 *\var lstTodo : liste dans laquelle on ajoute les Todo
 */

Interaction::Interaction(const std::string & c,const Date & d,const std::list<Todo *> lst)
{
contenu =c;
date = d;
lstTodo = lst;
}




/*!
 * \brief Interaction::~Interaction()
 * destructeur de la classe interaction
 */

Interaction::~Interaction()
{

}


// accesseurs

/*!
 * \brief Interaction::getDate()
 * accesseur de la variable date
 * \return date
 */

Date Interaction::getDate() const
{
    return date;
}

/*!
 * \brief Interaction::getContenu()
 * accesseur de la variable contenu
 * \return contenu
 */

std::string Interaction::getContenu() const
{
    return contenu;
}

/*!
 * \brief Interaction::getLstTodo()
 * accesseur de la liste de Todo
 * \return this->lstTodo
 */

std::list<Todo *> Interaction::getLstTodo() const
{
    return this-> lstTodo;
}



// mutateurs

/*!
 * \brief Interaction::setDate()
 * mutateur de la variable date
 * \param d
 */

void Interaction::setDate(const Date & d)
{
    date = d;
}

/*!
 * \brief Interaction::setContenu()
 * mutateur de la variable contenu
 * \param c
 */

void Interaction::setContenu(const std::string & c)
{
    contenu = c;
}

/*!
 * \brief Interaction::setLstTodo()
 * mutateur de la liste de Todo
 * \param lst
 */

void Interaction::setLstTodo(std::list<Todo *> lst){
    this->lstTodo = lst;
}



//méthodes

/*!
 * \brief Interaction::addTodo()
 * Méthode permetant d'ajouter un Todo déjà généré à la liste de Todo d'une interaction
 * \param interTodo
 */

void Interaction::addTodo(Todo *interTodo){
    this->lstTodo.push_back(interTodo);
}

/*!
 * \brief Interaction::addTodo(std::string str, Date d)
 * Méthode permetant d'ajouter un Todo
 * avec le contenu et la date du todo en paramètres
 * à la liste de Todo d'une interaction
 * \param str
 * \param d
 */

void Interaction::addTodo(std::string str, Date d)
{
    Todo *interTodo= new Todo;
    interTodo->setContenu(str);
    interTodo->setDate(d);
    this->lstTodo.push_back(interTodo);
}

/*!
 * \brief Interaction::toString()
 * Méthode qui permet de convertir tout le contenu d'une interaction en String
 * on vérifie comme dans la classe date si la date est choisis par l'utilisateur
 * \return str
 */

std::string Interaction::toString() const{
    std::string str = "";

    str += getContenu()+" "+getDate().toString()+", ";
    if(lstTodo.size() != 0)
        for(auto &todo : lstTodo){
            str += todo->toString();
        }


    return str;
}


//surcharge d'operateurs

/*!
 * \brief Surcharge d'opérateur
 * on utilise la méthode toString pour convertir l'interaction en paramètre
 * \param os
 * \param i
 * \return
 */

std::ostream& operator<<(std::ostream & os, const Interaction & i)
{

    os << i.toString();
    return os;
}



