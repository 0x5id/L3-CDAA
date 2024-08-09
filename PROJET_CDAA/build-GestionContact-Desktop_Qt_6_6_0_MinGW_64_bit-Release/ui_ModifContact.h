/********************************************************************************
** Form generated from reading UI file 'ModifContact.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFCONTACT_H
#define UI_MODIFCONTACT_H

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

class Ui_ModifContact
{
public:
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout;
    QLabel *PhotoLabel;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer;
    QPushButton *BdwnlPhoto;
    QPushButton *BsupprPhoto;
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
    QLineEdit *LigneDate;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *BAnnuleModif;
    QPushButton *BValideModif;

    void setupUi(QWidget *ModifContact)
    {
        if (ModifContact->objectName().isEmpty())
            ModifContact->setObjectName("ModifContact");
        ModifContact->resize(783, 647);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ModifContact->sizePolicy().hasHeightForWidth());
        ModifContact->setSizePolicy(sizePolicy);
        ModifContact->setMinimumSize(QSize(0, 0));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(255, 162, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        ModifContact->setPalette(palette);
        ModifContact->setAutoFillBackground(true);
        verticalLayout_8 = new QVBoxLayout(ModifContact);
        verticalLayout_8->setObjectName("verticalLayout_8");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        PhotoLabel = new QLabel(ModifContact);
        PhotoLabel->setObjectName("PhotoLabel");
        PhotoLabel->setMinimumSize(QSize(200, 200));
        PhotoLabel->setMaximumSize(QSize(200, 200));
        PhotoLabel->setAutoFillBackground(true);

        horizontalLayout->addWidget(PhotoLabel);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        BdwnlPhoto = new QPushButton(ModifContact);
        BdwnlPhoto->setObjectName("BdwnlPhoto");
        BdwnlPhoto->setMinimumSize(QSize(140, 35));
        BdwnlPhoto->setMaximumSize(QSize(140, 35));

        horizontalLayout_6->addWidget(BdwnlPhoto);

        BsupprPhoto = new QPushButton(ModifContact);
        BsupprPhoto->setObjectName("BsupprPhoto");
        BsupprPhoto->setMinimumSize(QSize(140, 35));
        BsupprPhoto->setMaximumSize(QSize(140, 35));

        horizontalLayout_6->addWidget(BsupprPhoto);


        horizontalLayout->addLayout(horizontalLayout_6);


        verticalLayout_8->addLayout(horizontalLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        LayoutNom = new QVBoxLayout();
        LayoutNom->setObjectName("LayoutNom");
        LabelNom = new QLabel(ModifContact);
        LabelNom->setObjectName("LabelNom");

        LayoutNom->addWidget(LabelNom);

        LigneNom = new QLineEdit(ModifContact);
        LigneNom->setObjectName("LigneNom");

        LayoutNom->addWidget(LigneNom);


        horizontalLayout_5->addLayout(LayoutNom);

        LayoutPrenom = new QVBoxLayout();
        LayoutPrenom->setObjectName("LayoutPrenom");
        LabelPrenom = new QLabel(ModifContact);
        LabelPrenom->setObjectName("LabelPrenom");

        LayoutPrenom->addWidget(LabelPrenom);

        LignePrenom = new QLineEdit(ModifContact);
        LignePrenom->setObjectName("LignePrenom");

        LayoutPrenom->addWidget(LignePrenom);


        horizontalLayout_5->addLayout(LayoutPrenom);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        LayoutEntreprise = new QVBoxLayout();
        LayoutEntreprise->setObjectName("LayoutEntreprise");
        LabelEntreprise = new QLabel(ModifContact);
        LabelEntreprise->setObjectName("LabelEntreprise");

        LayoutEntreprise->addWidget(LabelEntreprise);

        LigneEntreprise = new QLineEdit(ModifContact);
        LigneEntreprise->setObjectName("LigneEntreprise");

        LayoutEntreprise->addWidget(LigneEntreprise);


        horizontalLayout_2->addLayout(LayoutEntreprise);

        LayoutMail = new QVBoxLayout();
        LayoutMail->setObjectName("LayoutMail");
        LabelMail = new QLabel(ModifContact);
        LabelMail->setObjectName("LabelMail");

        LayoutMail->addWidget(LabelMail);

        LigneMail = new QLineEdit(ModifContact);
        LigneMail->setObjectName("LigneMail");

        LayoutMail->addWidget(LigneMail);


        horizontalLayout_2->addLayout(LayoutMail);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        LayoutTelephone = new QVBoxLayout();
        LayoutTelephone->setObjectName("LayoutTelephone");
        LabelTelephone = new QLabel(ModifContact);
        LabelTelephone->setObjectName("LabelTelephone");

        LayoutTelephone->addWidget(LabelTelephone);

        LigneTelephone = new QLineEdit(ModifContact);
        LigneTelephone->setObjectName("LigneTelephone");

        LayoutTelephone->addWidget(LigneTelephone);


        horizontalLayout_3->addLayout(LayoutTelephone);

        LayoutDate = new QVBoxLayout();
        LayoutDate->setObjectName("LayoutDate");
        LabelDate = new QLabel(ModifContact);
        LabelDate->setObjectName("LabelDate");

        LayoutDate->addWidget(LabelDate);

        LigneDate = new QLineEdit(ModifContact);
        LigneDate->setObjectName("LigneDate");
        LigneDate->setEnabled(true);

        LayoutDate->addWidget(LigneDate);


        horizontalLayout_3->addLayout(LayoutDate);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(50, 140, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer);


        verticalLayout_8->addLayout(verticalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        BAnnuleModif = new QPushButton(ModifContact);
        BAnnuleModif->setObjectName("BAnnuleModif");

        horizontalLayout_4->addWidget(BAnnuleModif);

        BValideModif = new QPushButton(ModifContact);
        BValideModif->setObjectName("BValideModif");

        horizontalLayout_4->addWidget(BValideModif);


        verticalLayout_8->addLayout(horizontalLayout_4);


        retranslateUi(ModifContact);

        QMetaObject::connectSlotsByName(ModifContact);
    } // setupUi

    void retranslateUi(QWidget *ModifContact)
    {
        ModifContact->setWindowTitle(QCoreApplication::translate("ModifContact", "Form", nullptr));
        PhotoLabel->setText(QString());
        BdwnlPhoto->setText(QCoreApplication::translate("ModifContact", "T\303\251l\303\251charger une photo", nullptr));
        BsupprPhoto->setText(QCoreApplication::translate("ModifContact", "Supprimer la photo", nullptr));
        LabelNom->setText(QCoreApplication::translate("ModifContact", "Nom :", nullptr));
        LabelPrenom->setText(QCoreApplication::translate("ModifContact", "Prenom :", nullptr));
        LabelEntreprise->setText(QCoreApplication::translate("ModifContact", "Entreprise :", nullptr));
        LabelMail->setText(QCoreApplication::translate("ModifContact", "Mail :", nullptr));
        LabelTelephone->setText(QCoreApplication::translate("ModifContact", "Telephone :", nullptr));
        LabelDate->setText(QCoreApplication::translate("ModifContact", "Date :", nullptr));
        LigneDate->setText(QString());
        BAnnuleModif->setText(QCoreApplication::translate("ModifContact", "Annuler", nullptr));
        BValideModif->setText(QCoreApplication::translate("ModifContact", "Modifier", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModifContact: public Ui_ModifContact {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFCONTACT_H
