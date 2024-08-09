/********************************************************************************
** Form generated from reading UI file 'PrincipaleWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRINCIPALEWIDGET_H
#define UI_PRINCIPALEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PrincipaleWidget
{
public:
    QFormLayout *formLayout;
    QGridLayout *gridLayout;
    QPushButton *BouttonDateA;
    QLineEdit *LigneDateA;
    QPushButton *BouttonDateB;
    QLineEdit *LigneDateB;
    QFormLayout *formLayout_2;
    QLabel *label;
    QLineEdit *RechercheLine;
    QLabel *label_2;
    QComboBox *CritereCB;
    QLabel *label_3;
    QLabel *NbContactLabel;
    QFormLayout *formLayout_5;
    QTableWidget *CtctListe;
    QFormLayout *Main_tableLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *AjoutContact;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *AfficheInters;

    void setupUi(QWidget *PrincipaleWidget)
    {
        if (PrincipaleWidget->objectName().isEmpty())
            PrincipaleWidget->setObjectName("PrincipaleWidget");
        PrincipaleWidget->setWindowModality(Qt::WindowModal);
        PrincipaleWidget->resize(900, 675);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PrincipaleWidget->sizePolicy().hasHeightForWidth());
        PrincipaleWidget->setSizePolicy(sizePolicy);
        PrincipaleWidget->setMinimumSize(QSize(900, 675));
        PrincipaleWidget->setLayoutDirection(Qt::LeftToRight);
        formLayout = new QFormLayout(PrincipaleWidget);
        formLayout->setObjectName("formLayout");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        gridLayout->setSizeConstraint(QLayout::SetNoConstraint);
        BouttonDateA = new QPushButton(PrincipaleWidget);
        BouttonDateA->setObjectName("BouttonDateA");
        BouttonDateA->setMinimumSize(QSize(100, 0));

        gridLayout->addWidget(BouttonDateA, 0, 0, 1, 1);

        LigneDateA = new QLineEdit(PrincipaleWidget);
        LigneDateA->setObjectName("LigneDateA");
        LigneDateA->setEnabled(false);
        LigneDateA->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(LigneDateA, 0, 1, 1, 1);

        BouttonDateB = new QPushButton(PrincipaleWidget);
        BouttonDateB->setObjectName("BouttonDateB");
        BouttonDateB->setMinimumSize(QSize(100, 0));

        gridLayout->addWidget(BouttonDateB, 1, 0, 1, 1);

        LigneDateB = new QLineEdit(PrincipaleWidget);
        LigneDateB->setObjectName("LigneDateB");
        LigneDateB->setEnabled(false);
        sizePolicy.setHeightForWidth(LigneDateB->sizePolicy().hasHeightForWidth());
        LigneDateB->setSizePolicy(sizePolicy);
        LigneDateB->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(LigneDateB, 1, 1, 1, 1);


        formLayout->setLayout(0, QFormLayout::LabelRole, gridLayout);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName("formLayout_2");
        label = new QLabel(PrincipaleWidget);
        label->setObjectName("label");

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label);

        RechercheLine = new QLineEdit(PrincipaleWidget);
        RechercheLine->setObjectName("RechercheLine");
        sizePolicy.setHeightForWidth(RechercheLine->sizePolicy().hasHeightForWidth());
        RechercheLine->setSizePolicy(sizePolicy);
        RechercheLine->setMaximumSize(QSize(300, 300));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, RechercheLine);

        label_2 = new QLabel(PrincipaleWidget);
        label_2->setObjectName("label_2");

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_2);

        CritereCB = new QComboBox(PrincipaleWidget);
        CritereCB->setObjectName("CritereCB");
        sizePolicy.setHeightForWidth(CritereCB->sizePolicy().hasHeightForWidth());
        CritereCB->setSizePolicy(sizePolicy);
        CritereCB->setMaximumSize(QSize(300, 300));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, CritereCB);

        label_3 = new QLabel(PrincipaleWidget);
        label_3->setObjectName("label_3");

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_3);

        NbContactLabel = new QLabel(PrincipaleWidget);
        NbContactLabel->setObjectName("NbContactLabel");

        formLayout_2->setWidget(2, QFormLayout::FieldRole, NbContactLabel);


        formLayout->setLayout(0, QFormLayout::FieldRole, formLayout_2);

        formLayout_5 = new QFormLayout();
        formLayout_5->setObjectName("formLayout_5");
        formLayout_5->setRowWrapPolicy(QFormLayout::DontWrapRows);
        CtctListe = new QTableWidget(PrincipaleWidget);
        CtctListe->setObjectName("CtctListe");
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(CtctListe->sizePolicy().hasHeightForWidth());
        CtctListe->setSizePolicy(sizePolicy1);
        CtctListe->setMinimumSize(QSize(305, 0));

        formLayout_5->setWidget(0, QFormLayout::SpanningRole, CtctListe);


        formLayout->setLayout(1, QFormLayout::LabelRole, formLayout_5);

        Main_tableLayout = new QFormLayout();
        Main_tableLayout->setObjectName("Main_tableLayout");

        formLayout->setLayout(1, QFormLayout::FieldRole, Main_tableLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        AjoutContact = new QPushButton(PrincipaleWidget);
        AjoutContact->setObjectName("AjoutContact");
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(AjoutContact->sizePolicy().hasHeightForWidth());
        AjoutContact->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(AjoutContact);


        formLayout->setLayout(2, QFormLayout::LabelRole, horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_2->setContentsMargins(7, -1, -1, -1);
        AfficheInters = new QPushButton(PrincipaleWidget);
        AfficheInters->setObjectName("AfficheInters");
        sizePolicy.setHeightForWidth(AfficheInters->sizePolicy().hasHeightForWidth());
        AfficheInters->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(AfficheInters);


        formLayout->setLayout(2, QFormLayout::FieldRole, horizontalLayout_2);


        retranslateUi(PrincipaleWidget);

        QMetaObject::connectSlotsByName(PrincipaleWidget);
    } // setupUi

    void retranslateUi(QWidget *PrincipaleWidget)
    {
        PrincipaleWidget->setWindowTitle(QCoreApplication::translate("PrincipaleWidget", "Form", nullptr));
        BouttonDateA->setText(QCoreApplication::translate("PrincipaleWidget", "De :", nullptr));
        BouttonDateB->setText(QCoreApplication::translate("PrincipaleWidget", "\303\200 :", nullptr));
        label->setText(QCoreApplication::translate("PrincipaleWidget", " Mot Cl\303\251 :", nullptr));
        label_2->setText(QCoreApplication::translate("PrincipaleWidget", " Crit\303\250res :", nullptr));
        label_3->setText(QCoreApplication::translate("PrincipaleWidget", " Nombre de contacts :", nullptr));
        NbContactLabel->setText(QCoreApplication::translate("PrincipaleWidget", "TextLabel", nullptr));
        AjoutContact->setText(QCoreApplication::translate("PrincipaleWidget", "Ajouter", nullptr));
        AfficheInters->setText(QCoreApplication::translate("PrincipaleWidget", "Afficher les interractions ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PrincipaleWidget: public Ui_PrincipaleWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRINCIPALEWIDGET_H
