#ifndef LISTEINTERACTION_H
#define LISTEINTERACTION_H

#include "GestionnaireContact.h"
#include <QWidget>
#include <QDate>
#include <QCalendarWidget>

/*!
 * @file ListeInteraction.h
 * @brief Classe qui permet de générer une interface pour afficher la liste de toute les interactions de chaque contact dans le Widget principal.
 * @class ListeInteraction
 * @var bool DateAB;
 * @var GestionnaireContact GestC;
 * @var QCalendarWidget* Cal;
 */

namespace Ui {
class ListeInteraction;
}

class ListeInteraction : public QWidget
{
    Q_OBJECT

public:
    explicit ListeInteraction(QWidget *parent = nullptr);
    ~ListeInteraction();

    bool DateAB;
    GestionnaireContact GestC;
    QCalendarWidget* Cal;

private:
    Ui::ListeInteraction *ui;


public slots:
    void ChoixDateA();
    void ChoixDateB();
    void ActuLigneDate();
    void RefreshList();
    void RefreshListInter(GestionnaireContact Gc);

signals :
    void refreshList();

};

#endif // LISTEINTERACTION_H
