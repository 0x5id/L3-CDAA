#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <PrincipaleWidget.h>
#include <GestionnaireContact.h>

/*!
 * @file mainwindow.h
 * @brief Classe qui permet de générer le QMainWindow dans lequel se trouvera le Widget principale et tout ses enfants.
 * la classe vas aussi permettre de générer le fichier JSON qui contient l'entièreté des contacts
 * et elle permet aussi d'afficher les logs de l'application, tout ça grace au menu.
 * @class mainwindow
 * @var PrincipaleWidget* PrinWidget;
 * @var QString chemin;
 * @var GestionnaireContact Gc;
 */

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    PrincipaleWidget* PrinWidget;
    QString chemin;
    GestionnaireContact Gc;

    Ui::MainWindow *ui;

public slots:
    void ExporterJson();
    void getContacts(GestionnaireContact GestC);

signals:
    void RefreshContacts();
};
#endif // MAINWINDOW_H
