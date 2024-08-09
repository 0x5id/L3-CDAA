#ifndef AFFICHECONTACT_H
#define AFFICHECONTACT_H

#include <QWidget>
#include <QTableWidget>
#include <Contact.h>
#include <fstream>
#include <string>
#include <regex>

/*!
 * @file AfficheContact.h
 * @brief Classe qui permet de générer une interface pour afficher le contact et permet d'interagir avec celui-ci.
 * @class AfficheContact
 * @var QImage image
 * @var Interaction * selectedInteraction;
 * @var QTableWidget * TableInteractionSeule;
 * @var Contact * c;
 */


namespace Ui {
class AfficheContact;
}

class AfficheContact : public QWidget
{
    Q_OBJECT

public:
    explicit AfficheContact(QWidget *parent = nullptr);
    ~AfficheContact();


    QImage image;
    Interaction * selectedInteraction;
    QTableWidget * TableInteractionSeule;
    Contact * c;

    //Méthode
    Date toDate(std::string);

private:
    Ui::AfficheContact *ui;

public slots:
    void RefreshAffiche(Contact* contact);
    void SupprimeContact();
    void ModifContact();
    void AjtInteraction();
    void AfficheInteraction();
    void SupprInteraction();
    void onInteractionClique(int row,int);

signals:
    void SuppressionContact();
    void ModificationContact();
    void AjoutInteraction();
    void ModificationInteraction(Interaction inter);
    void SuppressionInteraction(Interaction inter,std::string mail);



};

#endif // AFFICHECONTACT_H
