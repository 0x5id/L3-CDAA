#ifndef GESTIONNAIRETODO_H
#define GESTIONNAIRETODO_H
#include <Todo.h>
#include <list>


/*!
 * @file GestionnaireTodo.h
 * @brief Classe qui permet de générer un gestionnaire de todos
 * @class GestionnaireTodo
 * @var list<Todo *> lstTodos
 */

class GestionnaireTodo
{

private:

    std::list<Todo *> lstTodos;



public:
    //constructeurs et destructeurs
    GestionnaireTodo();
    ~GestionnaireTodo();

    //accesseur
    std::list<Todo *> getLstTodos() const;
    Todo* getTodoAt(unsigned int i);

    //méthodes

    void modifTodo(Todo *c, unsigned int i);
    void addTodo(Todo *c);
    void deleteTodo(Todo *c);

    void deleteLastTodo();
    int getNbTodo() const;
    void clear();
    std::string getSize();
    std::string toString() const;


    friend std::ostream& operator<<(std::ostream&, const GestionnaireTodo&);
};

#endif // GESTIONNAIRETODO_H
