#include "GestionnaireTodo.h"

/*!
 * \file GestionnaireTodo.cpp
 * \brief Classe qui permet de gerer les Todo
 * \class GestionnaireTodo
 */


/*!
 * \brief GestionnaireTodo::GestionnaireTodo
 * Constructeur standard de la classe GestionnaireTodo()
 */
GestionnaireTodo::GestionnaireTodo()
{
    lstTodos = std::list<Todo *>();
}

/*!
 * \brief GestionnaireTodo::~GestionnaireTodo
 * Destructeur de la classe GestionnaireTodo()
 */

GestionnaireTodo::~GestionnaireTodo(){}

/*!
 * \brief GestionnaireTodo::getLstTodos
 * Accesseur de la liste de Todos;
 * \return this->lstTodos;
 */

std::list<Todo *> GestionnaireTodo::getLstTodos() const
{
    return this->lstTodos;
}

/*!
 * \brief GestionnaireTodo::getTodoAt
 * Méthode qui permet de récuperer le Todo à l'index i dans la liste de todo
 * \param i
 * \return it;
 */

Todo* GestionnaireTodo::getTodoAt(unsigned int i){
    if (i < lstTodos.size()) {
        auto it = lstTodos.begin();
        std::advance(it, i);
        return *it;
    } else {
        return nullptr;
    }
}

/*!
 * \brief GestionnaireTodo::addTodo
 * Méthode qui permet d'ajouter le Todo i à la liste de Todos
 * \param i
 */

void GestionnaireTodo::addTodo(Todo *i)
{
    this->lstTodos.push_back(i);
}

/*!
 * \brief GestionnaireTodo::deleteTodo
 * Méthode qui permet de supprimer le Todo i dans la liste de Todos
 * \param i
 */

void GestionnaireTodo::deleteTodo(Todo *i)
{
    lstTodos.remove(i);
}

/*!
 * \brief GestionnaireTodo::deleteLastTodo
 * Méthode qui permet de retirer le dernier Todo de la liste
 *
 * la méthode est notament utilisée dans l'ajout d'interaction à un contact,
 * l'utilisateur vas ajouter un todo dans une liste de todo qui elle sera ajoutée au contact
 * une fois la validation de l'ajout de l'interaction.
 * Si l'utilisateur veut supprimer un todo il devra supprimer tout les todo en appelant cette méthode avec un boutton
 * jusque supprimer son todo.
 * La méthode n'est donc pas optimale.
 */

void GestionnaireTodo::deleteLastTodo()
{
    lstTodos.pop_back();
}

/*!
 * \brief GestionnaireTodo::getNbTodo
 * Méthode qui return le nombre de Todo dans la liste.
 * \return lstTodos.size();
 */
int GestionnaireTodo::getNbTodo() const{
    return this->lstTodos.size();
}

std::string GestionnaireTodo::toString() const{
    std::string str = "";
    if(lstTodos.size() != 0)
        for(auto &todo : lstTodos){
            str += todo->toString()+"\n";
        }

    return str;
}

/*!
 * \brief GestionnaireTodo::clear
 * permet de nettoyer la liste du gestionnaire de Todo
 */

void GestionnaireTodo::clear()
{
    this->lstTodos.clear();
}

/*!
 * \brief GestionnaireTodo::getSize
 * Méthode qui permet de récuperer dans un stering la taille de la liste de Todos
 * \return str;
 */

std::string GestionnaireTodo::getSize()
{
    std::string str =  std::to_string(this->lstTodos.size());



    return str;
}




//surcharge d'operateurs

/*!
 * \brief surcharge d'opérateur
 * Utilisation de la méthode toString pour afficher la liste de Todo
 * \param os
 * \param gc
 * \return
 */

std::ostream& operator<<(std::ostream& os, const GestionnaireTodo& gt)
{
    os << gt.toString();
    return os;
}
