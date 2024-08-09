#ifndef MODIFCONTACT_H
#define MODIFCONTACT_H

#include <QWidget>
#include <Contact.h>
#include <BaseDeDonnee.h>
#include <QString>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QPixmap>
#include <QLineEdit>
#include <QLabel>
#include <string>
#include <regex>
#include <QFileDialog>


/*!
 * @file ModifContact.h
 * @brief Classe qui permet de générer l'interface pour modifier un contact.
 * @class ModifContact
 * @var QImage image;
 * @var QString CheminPhoto;
 * @var BaseDeDonnee BaseDD;
 * @var Contact* c1;
 */

namespace Ui {
class ModifContact;
}

class ModifContact : public QWidget
{
    Q_OBJECT

public:
    explicit ModifContact(QWidget *parent = nullptr);
    ~ModifContact();

    QImage image;
    QString CheminPhoto;
    BaseDeDonnee BaseDD;
    Contact* c1;

    //Méthode
    Date toDate(std::string);

private:
    Ui::ModifContact *ui;
    //Méthodes
    bool VerificationChamp(QLineEdit* champ, QLabel* label, const std::regex& reg, const QString& vide, const QString& errRegex, const QString& labelText);
    std::string EnregistrePhotoContact(const std::string& Url);

public slots:
    void initModifContact(Contact* contact);
    void SupprimePhoto();
    void TelechargePhoto();
    void ValideModif();
    void AnnuleModification();
    void VerificationContact();
    void ValideMail(bool val);

signals:
    void AnnuleModif();
    void UIListeContactRefresh();
    void BDDModifContact(Contact c1,Contact c2);
    void ValideContact();
    void VerifMail(QString,std::string);


};

#endif // MODIFCONTACT_H
