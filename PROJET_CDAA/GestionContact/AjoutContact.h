#ifndef AJOUTCONTACT_H
#define AJOUTCONTACT_H

#include <QWidget>
#include <Contact.h>
#include <QString>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QPixmap>
#include <QLineEdit>
#include <QLabel>
#include <regex>

/*!
 * @file AjoutContact.h
 * @brief Classe qui permet de générer une interface pour ajouter un contact.
 * @class AjoutContact
 * @var QString CheminPhoto;
 * @var QImage image;
 */


namespace Ui {
class AjoutContact;
}

class AjoutContact : public QWidget
{
    Q_OBJECT

public:
    explicit AjoutContact(QWidget *parent = nullptr);
    ~AjoutContact();

    QString CheminPhoto;
    QImage image;

private:
    Ui::AjoutContact *ui;
    //méthodes
    bool VerificationChamp(QLineEdit* champ, QLabel* label, const std::regex& reg, const QString& vide, const QString& errRegex, const QString& labelText);
    std::string EnregistrePhotoContact(const std::string& Url);


public slots:
    void ValideContact();
    void VerificationContact();
    void TelechargePhoto();
    void AnnuleFormulaire();
    void ValideMail(bool val);

signals:
   void ValidContact();
   void UIListeContactRefresh();
   void BDDAjoutContact(Contact c);
   void VerifMail(QString mail, std::string type);



};

#endif // AJOUTCONTACT_H
