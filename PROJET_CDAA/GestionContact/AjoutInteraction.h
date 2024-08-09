#ifndef AJOUTINTERACTION_H
#define AJOUTINTERACTION_H

#include <QWidget>
#include <Contact.h>
#include <GestionnaireInteraction.h>
#include <GestionnaireTodo.h>
#include <Todo.h>
#include <string>
#include <regex>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>


/*!
 * @file AjoutInteraction.h
 * @brief Classe qui permet de générer une interface pour ajouter une interaction a un contact.
 * @class AjoutInteraction
 * @var Interaction* interaction;
 * @var GestionnaireTodo gt;
 * @var Contact * contact;
 */


namespace Ui {
class AjoutInteraction;
}

class AjoutInteraction : public QWidget
{
    Q_OBJECT

public:
    explicit AjoutInteraction(QWidget *parent = nullptr);
    ~AjoutInteraction();

    Interaction* interaction;
    GestionnaireTodo gt;
    Contact * contact;

    //méthode
    Date toDate(std::string);

private:
    Ui::AjoutInteraction *ui;
    //méthode
    bool VerificationChamp(QLineEdit* champ,QTextEdit* champ2, QLabel* label, const std::regex& reg,const std::regex& regDate, const QString& vide, const QString& errRegex, const QString& labelText);

public slots:
    void FermeFormulaire();
    void AnnuleFormInteraction();
    void VerificationInteraction();
    void SupprimeTodoList();
    void AjoutTodoList();
    void ValideInteraction();
    void refreshInteractionForm(Contact * contact);

signals:
    void AnnuleAjoutInteraction();
    void BDDAjoutInteraction(Interaction inter);
    void ValidInteraction();
    void clearForm();


};

#endif // AJOUTINTERACTION_H
