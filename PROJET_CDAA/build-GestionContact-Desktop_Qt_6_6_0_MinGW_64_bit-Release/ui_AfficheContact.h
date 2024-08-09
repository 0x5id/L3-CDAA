/********************************************************************************
** Form generated from reading UI file 'AfficheContact.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AFFICHECONTACT_H
#define UI_AFFICHECONTACT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AfficheContact
{
public:
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *LabelPhotoAff;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_5;
    QLabel *LabelNom;
    QLabel *LabelPrenom;
    QLabel *LabelMail;
    QLabel *LabelEntreprise;
    QLabel *LabelTelephone;
    QLabel *LabelDate;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *BSupprInteraction;
    QPushButton *BAfficheInteraction;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *LayoutTable;
    QTableWidget *TableInteractionContact;
    QHBoxLayout *horizontalLayout;
    QPushButton *BModifierContact;
    QPushButton *BAjoutInteraction;
    QPushButton *BSupprContact;

    void setupUi(QWidget *AfficheContact)
    {
        if (AfficheContact->objectName().isEmpty())
            AfficheContact->setObjectName("AfficheContact");
        AfficheContact->resize(938, 612);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(153, 193, 241, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        AfficheContact->setPalette(palette);
        AfficheContact->setAutoFillBackground(true);
        horizontalLayout_7 = new QHBoxLayout(AfficheContact);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        LabelPhotoAff = new QLabel(AfficheContact);
        LabelPhotoAff->setObjectName("LabelPhotoAff");
        LabelPhotoAff->setMinimumSize(QSize(200, 200));
        LabelPhotoAff->setMaximumSize(QSize(200, 200));

        horizontalLayout_4->addWidget(LabelPhotoAff);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_7->setContentsMargins(30, -1, -1, -1);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        LabelNom = new QLabel(AfficheContact);
        LabelNom->setObjectName("LabelNom");

        horizontalLayout_5->addWidget(LabelNom);

        LabelPrenom = new QLabel(AfficheContact);
        LabelPrenom->setObjectName("LabelPrenom");

        horizontalLayout_5->addWidget(LabelPrenom);


        verticalLayout_7->addLayout(horizontalLayout_5);

        LabelMail = new QLabel(AfficheContact);
        LabelMail->setObjectName("LabelMail");

        verticalLayout_7->addWidget(LabelMail);

        LabelEntreprise = new QLabel(AfficheContact);
        LabelEntreprise->setObjectName("LabelEntreprise");

        verticalLayout_7->addWidget(LabelEntreprise);

        LabelTelephone = new QLabel(AfficheContact);
        LabelTelephone->setObjectName("LabelTelephone");

        verticalLayout_7->addWidget(LabelTelephone);

        LabelDate = new QLabel(AfficheContact);
        LabelDate->setObjectName("LabelDate");

        verticalLayout_7->addWidget(LabelDate);


        horizontalLayout_4->addLayout(verticalLayout_7);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer = new QSpacerItem(20, 120, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        BSupprInteraction = new QPushButton(AfficheContact);
        BSupprInteraction->setObjectName("BSupprInteraction");
        BSupprInteraction->setEnabled(false);

        horizontalLayout_3->addWidget(BSupprInteraction);


        verticalLayout->addLayout(horizontalLayout_3);

        BAfficheInteraction = new QPushButton(AfficheContact);
        BAfficheInteraction->setObjectName("BAfficheInteraction");
        BAfficheInteraction->setEnabled(false);

        verticalLayout->addWidget(BAfficheInteraction);


        horizontalLayout_4->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);


        verticalLayout_5->addLayout(horizontalLayout_4);

        LayoutTable = new QHBoxLayout();
        LayoutTable->setSpacing(10);
        LayoutTable->setObjectName("LayoutTable");
        LayoutTable->setContentsMargins(5, -1, 6, -1);
        TableInteractionContact = new QTableWidget(AfficheContact);
        TableInteractionContact->setObjectName("TableInteractionContact");
        TableInteractionContact->setMinimumSize(QSize(0, 0));

        LayoutTable->addWidget(TableInteractionContact);


        verticalLayout_5->addLayout(LayoutTable);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        BModifierContact = new QPushButton(AfficheContact);
        BModifierContact->setObjectName("BModifierContact");

        horizontalLayout->addWidget(BModifierContact);

        BAjoutInteraction = new QPushButton(AfficheContact);
        BAjoutInteraction->setObjectName("BAjoutInteraction");

        horizontalLayout->addWidget(BAjoutInteraction);

        BSupprContact = new QPushButton(AfficheContact);
        BSupprContact->setObjectName("BSupprContact");

        horizontalLayout->addWidget(BSupprContact);


        verticalLayout_5->addLayout(horizontalLayout);


        horizontalLayout_7->addLayout(verticalLayout_5);


        retranslateUi(AfficheContact);

        QMetaObject::connectSlotsByName(AfficheContact);
    } // setupUi

    void retranslateUi(QWidget *AfficheContact)
    {
        AfficheContact->setWindowTitle(QCoreApplication::translate("AfficheContact", "Form", nullptr));
        LabelPhotoAff->setText(QString());
        LabelNom->setText(QCoreApplication::translate("AfficheContact", "Nom", nullptr));
        LabelPrenom->setText(QCoreApplication::translate("AfficheContact", "Prenom", nullptr));
        LabelMail->setText(QCoreApplication::translate("AfficheContact", "Mail", nullptr));
        LabelEntreprise->setText(QCoreApplication::translate("AfficheContact", "Entreprise", nullptr));
        LabelTelephone->setText(QCoreApplication::translate("AfficheContact", "Telephone", nullptr));
        LabelDate->setText(QCoreApplication::translate("AfficheContact", "Date", nullptr));
        BSupprInteraction->setText(QCoreApplication::translate("AfficheContact", "Supprimer Interaction", nullptr));
        BAfficheInteraction->setText(QCoreApplication::translate("AfficheContact", "Afficher Interaction", nullptr));
        BModifierContact->setText(QCoreApplication::translate("AfficheContact", "Modifier", nullptr));
        BAjoutInteraction->setText(QCoreApplication::translate("AfficheContact", "Ajout Interaction", nullptr));
        BSupprContact->setText(QCoreApplication::translate("AfficheContact", "Supprimer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AfficheContact: public Ui_AfficheContact {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AFFICHECONTACT_H
