#ifndef INTERACTION_H
#define INTERACTION_H
#include <string>
#include <ostream>
#include <iostream>
#include <list>
#include <Date.h>
#include <Todo.h>

/*!
 * \file Interaction.h
 * \brief Classe qui permet de creer les interactions et gerer les todo
 * \class Interaction
 * \var string contenu
 * \var Date date
 * \var list<Todo *> lstTodo
 */

class Interaction
{

    //attributs
private:
    Date date;
    std::string contenu;
    std::list<Todo *> lstTodo;

public:
    //constructeurs et destructeurs
    Interaction();
    Interaction(const std::string &);
    Interaction(const std::string & c,const Date & d,const std::list<Todo *> lst);
    ~Interaction();

//accesseurs
    Date getDate() const;
    std::string getContenu() const;
    std::list<Todo *> getLstTodo() const;

//mutateurs
    void setDate(const Date &);
    void setContenu(const std::string &);
    void setLstTodo(std::list<Todo *>);

//méthodes
    void addTodo(Todo *todo);
    void addTodo(std::string, Date);
    std::string toString() const;

//surcharge d'operateurs
    friend std::ostream& operator<<(std::ostream &,const Interaction &);
};

#endif // INTERACTION_H
