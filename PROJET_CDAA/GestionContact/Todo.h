#ifndef TODO_H
#define TODO_H
#include <iostream>
#include <Date.h>

/*!
 * \file Todo.h
 * \brief Classe qui permet de creer les interactions avec le tag Todo
 * \class Todo
 * \var string contenu
 * \var Date date
 */

class Todo{
private:
    //attributs
    Date date;
    std::string contenu;

public:
    //constructeurs et destructeurs
     Todo();
    ~Todo();

    Todo(std::string);
    Todo(std::string, Date);


    //accesseurs
    std::string getContenu() const;
    Date getDate() const;

    //mutateurs
    void setContenu(const std::string);
    void setDate(const Date);

    //méthodes
    std::string toString() const;

    //surchages d'operateur
    friend std::ostream& operator<<(std::ostream&, const Todo &);


};

#endif // TODO_H
