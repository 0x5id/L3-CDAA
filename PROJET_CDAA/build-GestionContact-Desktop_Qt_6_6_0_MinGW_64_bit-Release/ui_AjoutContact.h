/********************************************************************************
** Form generated from reading UI file 'AjoutContact.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTCONTACT_H
#define UI_AJOUTCONTACT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AjoutContact
{
public:
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout;
    QLabel *PhotoLabel;
    QPushButton *BdwnlPhoto;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *LayoutNom;
    QLabel *LabelNom;
    QLineEdit *LigneNom;
    QVBoxLayout *LayoutPrenom;
    QLabel *LabelPrenom;
    QLineEdit *LignePrenom;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *LayoutEntreprise;
    QLabel *LabelEntreprise;
    QLineEdit *LigneEntreprise;
    QVBoxLayout *LayoutMail;
    QLabel *LabelMail;
    QLineEdit *LigneMail;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *LayoutTelephone;
    QLabel *LabelTelephone;
    QLineEdit *LigneTelephone;
    QVBoxLayout *LayoutDate;
    QLabel *LabelDate;
    QLineEdit *lineEdit_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *BAnnuleFormulaire;
    QPushButton *BValideContact;

    void setupUi(QWidget *AjoutContact)
    {
        if (AjoutContact->objectName().isEmpty())
            AjoutContact->setObjectName("AjoutContact");
        AjoutContact->resize(783, 647);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AjoutContact->sizePolicy().hasHeightForWidth());
        AjoutContact->setSizePolicy(sizePolicy);
        AjoutContact->setMinimumSize(QSize(0, 0));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(0, 255, 127, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        AjoutContact->setPalette(palette);
        AjoutContact->setAutoFillBackground(true);
        verticalLayout_8 = new QVBoxLayout(AjoutContact);
        verticalLayout_8->setObjectName("verticalLayout_8");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        PhotoLabel = new QLabel(AjoutContact);
        PhotoLabel->setObjectName("PhotoLabel");
        PhotoLabel->setMinimumSize(QSize(200, 200));
        PhotoLabel->setMaximumSize(QSize(200, 200));
        PhotoLabel->setAutoFillBackground(true);

        horizontalLayout->addWidget(PhotoLabel);

        BdwnlPhoto = new QPushButton(AjoutContact);
        BdwnlPhoto->setObjectName("BdwnlPhoto");
        BdwnlPhoto->setMinimumSize(QSize(200, 50));
        BdwnlPhoto->setMaximumSize(QSize(200, 50));

        horizontalLayout->addWidget(BdwnlPhoto);


        verticalLayout_8->addLayout(horizontalLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        LayoutNom = new QVBoxLayout();
        LayoutNom->setObjectName("LayoutNom");
        LabelNom = new QLabel(AjoutContact);
        LabelNom->setObjectName("LabelNom");

        LayoutNom->addWidget(LabelNom);

        LigneNom = new QLineEdit(AjoutContact);
        LigneNom->setObjectName("LigneNom");

        LayoutNom->addWidget(LigneNom);


        horizontalLayout_5->addLayout(LayoutNom);

        LayoutPrenom = new QVBoxLayout();
        LayoutPrenom->setObjectName("LayoutPrenom");
        LabelPrenom = new QLabel(AjoutContact);
        LabelPrenom->setObjectName("LabelPrenom");

        LayoutPrenom->addWidget(LabelPrenom);

        LignePrenom = new QLineEdit(AjoutContact);
        LignePrenom->setObjectName("LignePrenom");

        LayoutPrenom->addWidget(LignePrenom);


        horizontalLayout_5->addLayout(LayoutPrenom);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        LayoutEntreprise = new QVBoxLayout();
        LayoutEntreprise->setObjectName("LayoutEntreprise");
        LabelEntreprise = new QLabel(AjoutContact);
        LabelEntreprise->setObjectName("LabelEntreprise");

        LayoutEntreprise->addWidget(LabelEntreprise);

        LigneEntreprise = new QLineEdit(AjoutContact);
        LigneEntreprise->setObjectName("LigneEntreprise");

        LayoutEntreprise->addWidget(LigneEntreprise);


        horizontalLayout_2->addLayout(LayoutEntreprise);

        LayoutMail = new QVBoxLayout();
        LayoutMail->setObjectName("LayoutMail");
        LabelMail = new QLabel(AjoutContact);
        LabelMail->setObjectName("LabelMail");

        LayoutMail->addWidget(LabelMail);

        LigneMail = new QLineEdit(AjoutContact);
        LigneMail->setObjectName("LigneMail");

        LayoutMail->addWidget(LigneMail);


        horizontalLayout_2->addLayout(LayoutMail);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        LayoutTelephone = new QVBoxLayout();
        LayoutTelephone->setObjectName("LayoutTelephone");
        LabelTelephone = new QLabel(AjoutContact);
        LabelTelephone->setObjectName("LabelTelephone");

        LayoutTelephone->addWidget(LabelTelephone);

        LigneTelephone = new QLineEdit(AjoutContact);
        LigneTelephone->setObjectName("LigneTelephone");

        LayoutTelephone->addWidget(LigneTelephone);


        horizontalLayout_3->addLayout(LayoutTelephone);

        LayoutDate = new QVBoxLayout();
        LayoutDate->setObjectName("LayoutDate");
        LabelDate = new QLabel(AjoutContact);
        LabelDate->setObjectName("LabelDate");

        LayoutDate->addWidget(LabelDate);

        lineEdit_2 = new QLineEdit(AjoutContact);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setEnabled(false);

        LayoutDate->addWidget(lineEdit_2);


        horizontalLayout_3->addLayout(LayoutDate);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(50, 140, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer);


        verticalLayout_8->addLayout(verticalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        BAnnuleFormulaire = new QPushButton(AjoutContact);
        BAnnuleFormulaire->setObjectName("BAnnuleFormulaire");

        horizontalLayout_4->addWidget(BAnnuleFormulaire);

        BValideContact = new QPushButton(AjoutContact);
        BValideContact->setObjectName("BValideContact");

        horizontalLayout_4->addWidget(BValideContact);


        verticalLayout_8->addLayout(horizontalLayout_4);


        retranslateUi(AjoutContact);

        QMetaObject::connectSlotsByName(AjoutContact);
    } // setupUi

    void retranslateUi(QWidget *AjoutContact)
    {
        AjoutContact->setWindowTitle(QCoreApplication::translate("AjoutContact", "Form", nullptr));
        PhotoLabel->setText(QString());
        BdwnlPhoto->setText(QCoreApplication::translate("AjoutContact", "T\303\251l\303\251charger une photo", nullptr));
        LabelNom->setText(QCoreApplication::translate("AjoutContact", "Nom :", nullptr));
        LabelPrenom->setText(QCoreApplication::translate("AjoutContact", "Prenom :", nullptr));
        LabelEntreprise->setText(QCoreApplication::translate("AjoutContact", "Entreprise :", nullptr));
        LabelMail->setText(QCoreApplication::translate("AjoutContact", "Mail :", nullptr));
        LabelTelephone->setText(QCoreApplication::translate("AjoutContact", "Telephone :", nullptr));
        LabelDate->setText(QCoreApplication::translate("AjoutContact", "Date :", nullptr));
        lineEdit_2->setText(QString());
        BAnnuleFormulaire->setText(QCoreApplication::translate("AjoutContact", "Annuler", nullptr));
        BValideContact->setText(QCoreApplication::translate("AjoutContact", "Valider", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AjoutContact: public Ui_AjoutContact {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTCONTACT_H
