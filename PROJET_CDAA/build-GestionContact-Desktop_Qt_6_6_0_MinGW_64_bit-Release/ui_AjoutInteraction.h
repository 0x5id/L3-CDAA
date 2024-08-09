/********************************************************************************
** Form generated from reading UI file 'AjoutInteraction.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTINTERACTION_H
#define UI_AJOUTINTERACTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AjoutInteraction
{
public:
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout;
    QLabel *LabelContact;
    QPushButton *BRetour;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *LayoutEntreprise;
    QLabel *LabelInteraction;
    QLineEdit *LigneDateInteraction;
    QTextEdit *LigneContenuInteraction;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *LabelTodo;
    QLineEdit *LigneDateTodo;
    QTextEdit *LigneContenuTodo;
    QPushButton *BAjoutTodo;
    QVBoxLayout *LayoutTelephone;
    QLabel *LabelTelephone;
    QTextEdit *LigneEnsembleTodo;
    QPushButton *BSupprTodo;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *BAnnuleInteraction;
    QPushButton *BValideInteraction;

    void setupUi(QWidget *AjoutInteraction)
    {
        if (AjoutInteraction->objectName().isEmpty())
            AjoutInteraction->setObjectName("AjoutInteraction");
        AjoutInteraction->resize(783, 647);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AjoutInteraction->sizePolicy().hasHeightForWidth());
        AjoutInteraction->setSizePolicy(sizePolicy);
        AjoutInteraction->setMinimumSize(QSize(0, 0));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(255, 170, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        AjoutInteraction->setPalette(palette);
        AjoutInteraction->setAutoFillBackground(true);
        verticalLayout_8 = new QVBoxLayout(AjoutInteraction);
        verticalLayout_8->setObjectName("verticalLayout_8");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        horizontalLayout->setContentsMargins(-1, -1, -1, 0);
        LabelContact = new QLabel(AjoutInteraction);
        LabelContact->setObjectName("LabelContact");
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(100);
        sizePolicy1.setVerticalStretch(100);
        sizePolicy1.setHeightForWidth(LabelContact->sizePolicy().hasHeightForWidth());
        LabelContact->setSizePolicy(sizePolicy1);
        LabelContact->setMinimumSize(QSize(100, 50));
        LabelContact->setMaximumSize(QSize(10000, 50));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(26);
        font.setBold(true);
        font.setItalic(false);
        LabelContact->setFont(font);
        LabelContact->setAcceptDrops(false);

        horizontalLayout->addWidget(LabelContact);

        BRetour = new QPushButton(AjoutInteraction);
        BRetour->setObjectName("BRetour");

        horizontalLayout->addWidget(BRetour);


        verticalLayout_8->addLayout(horizontalLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        LayoutEntreprise = new QVBoxLayout();
        LayoutEntreprise->setObjectName("LayoutEntreprise");
        LabelInteraction = new QLabel(AjoutInteraction);
        LabelInteraction->setObjectName("LabelInteraction");

        LayoutEntreprise->addWidget(LabelInteraction);

        LigneDateInteraction = new QLineEdit(AjoutInteraction);
        LigneDateInteraction->setObjectName("LigneDateInteraction");
        LigneDateInteraction->setMaximumSize(QSize(10000, 16777215));
        LigneDateInteraction->setMouseTracking(true);
        LigneDateInteraction->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        LigneDateInteraction->setClearButtonEnabled(true);

        LayoutEntreprise->addWidget(LigneDateInteraction);

        LigneContenuInteraction = new QTextEdit(AjoutInteraction);
        LigneContenuInteraction->setObjectName("LigneContenuInteraction");
        sizePolicy.setHeightForWidth(LigneContenuInteraction->sizePolicy().hasHeightForWidth());
        LigneContenuInteraction->setSizePolicy(sizePolicy);
        LigneContenuInteraction->setMinimumSize(QSize(0, 130));
        LigneContenuInteraction->setMaximumSize(QSize(16777215, 100000));

        LayoutEntreprise->addWidget(LigneContenuInteraction);


        verticalLayout_5->addLayout(LayoutEntreprise);


        verticalLayout->addLayout(verticalLayout_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        LabelTodo = new QLabel(AjoutInteraction);
        LabelTodo->setObjectName("LabelTodo");

        verticalLayout_3->addWidget(LabelTodo);

        LigneDateTodo = new QLineEdit(AjoutInteraction);
        LigneDateTodo->setObjectName("LigneDateTodo");
        LigneDateTodo->setMinimumSize(QSize(0, 0));
        LigneDateTodo->setMaximumSize(QSize(500, 16777215));
        LigneDateTodo->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout_3->addWidget(LigneDateTodo);

        LigneContenuTodo = new QTextEdit(AjoutInteraction);
        LigneContenuTodo->setObjectName("LigneContenuTodo");
        LigneContenuTodo->setMinimumSize(QSize(0, 150));
        LigneContenuTodo->setMaximumSize(QSize(16777215, 150));

        verticalLayout_3->addWidget(LigneContenuTodo);

        BAjoutTodo = new QPushButton(AjoutInteraction);
        BAjoutTodo->setObjectName("BAjoutTodo");
        BAjoutTodo->setMinimumSize(QSize(150, 0));
        BAjoutTodo->setMaximumSize(QSize(100000, 22));

        verticalLayout_3->addWidget(BAjoutTodo);


        horizontalLayout_3->addLayout(verticalLayout_3);

        LayoutTelephone = new QVBoxLayout();
        LayoutTelephone->setObjectName("LayoutTelephone");
        LabelTelephone = new QLabel(AjoutInteraction);
        LabelTelephone->setObjectName("LabelTelephone");

        LayoutTelephone->addWidget(LabelTelephone);

        LigneEnsembleTodo = new QTextEdit(AjoutInteraction);
        LigneEnsembleTodo->setObjectName("LigneEnsembleTodo");
        LigneEnsembleTodo->setMinimumSize(QSize(0, 180));
        LigneEnsembleTodo->setMaximumSize(QSize(16777215, 180));
        LigneEnsembleTodo->setReadOnly(true);

        LayoutTelephone->addWidget(LigneEnsembleTodo);

        BSupprTodo = new QPushButton(AjoutInteraction);
        BSupprTodo->setObjectName("BSupprTodo");
        BSupprTodo->setMinimumSize(QSize(150, 0));
        BSupprTodo->setMaximumSize(QSize(10000, 22));

        LayoutTelephone->addWidget(BSupprTodo);


        horizontalLayout_3->addLayout(LayoutTelephone);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_8->addLayout(verticalLayout);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        BAnnuleInteraction = new QPushButton(AjoutInteraction);
        BAnnuleInteraction->setObjectName("BAnnuleInteraction");

        horizontalLayout_4->addWidget(BAnnuleInteraction);

        BValideInteraction = new QPushButton(AjoutInteraction);
        BValideInteraction->setObjectName("BValideInteraction");

        horizontalLayout_4->addWidget(BValideInteraction);


        verticalLayout_8->addLayout(horizontalLayout_4);


        retranslateUi(AjoutInteraction);

        QMetaObject::connectSlotsByName(AjoutInteraction);
    } // setupUi

    void retranslateUi(QWidget *AjoutInteraction)
    {
        AjoutInteraction->setWindowTitle(QCoreApplication::translate("AjoutInteraction", "Form", nullptr));
        LabelContact->setText(QCoreApplication::translate("AjoutInteraction", "Ajout Interaction : ", nullptr));
        BRetour->setText(QCoreApplication::translate("AjoutInteraction", "Retour", nullptr));
        LabelInteraction->setText(QCoreApplication::translate("AjoutInteraction", "Contenu Interaction :", nullptr));
#if QT_CONFIG(tooltip)
        LigneDateInteraction->setToolTip(QCoreApplication::translate("AjoutInteraction", "<html><head/><body><p>Date Interaction au format jj/mm/aaaa</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        LigneDateInteraction->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
        LigneDateInteraction->setInputMask(QString());
        LigneDateInteraction->setText(QString());
        LigneDateInteraction->setPlaceholderText(QCoreApplication::translate("AjoutInteraction", "Date Interaction", nullptr));
#if QT_CONFIG(tooltip)
        LigneContenuInteraction->setToolTip(QCoreApplication::translate("AjoutInteraction", "Contenu Interaction", nullptr));
#endif // QT_CONFIG(tooltip)
        LigneContenuInteraction->setPlaceholderText(QCoreApplication::translate("AjoutInteraction", "Contenu Interaction", nullptr));
        LabelTodo->setText(QCoreApplication::translate("AjoutInteraction", "Contenu Todo :", nullptr));
#if QT_CONFIG(tooltip)
        LigneDateTodo->setToolTip(QCoreApplication::translate("AjoutInteraction", "Date Todo au format jj/mm/aaaa", nullptr));
#endif // QT_CONFIG(tooltip)
        LigneDateTodo->setPlaceholderText(QCoreApplication::translate("AjoutInteraction", "Date Todo", nullptr));
#if QT_CONFIG(tooltip)
        LigneContenuTodo->setToolTip(QCoreApplication::translate("AjoutInteraction", "Contenu du Todo", nullptr));
#endif // QT_CONFIG(tooltip)
        LigneContenuTodo->setPlaceholderText(QCoreApplication::translate("AjoutInteraction", "Contenu Todo", nullptr));
        BAjoutTodo->setText(QCoreApplication::translate("AjoutInteraction", "Ajouter Todo", nullptr));
        LabelTelephone->setText(QCoreApplication::translate("AjoutInteraction", "Ensemble des Todo :", nullptr));
        LigneEnsembleTodo->setPlaceholderText(QCoreApplication::translate("AjoutInteraction", "Liste des Todo \303\240 ajouter \303\240 l'interaction", nullptr));
        BSupprTodo->setText(QCoreApplication::translate("AjoutInteraction", "Supprimer le dernier Todo", nullptr));
        BAnnuleInteraction->setText(QCoreApplication::translate("AjoutInteraction", "Annuler", nullptr));
        BValideInteraction->setText(QCoreApplication::translate("AjoutInteraction", "Valider", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AjoutInteraction: public Ui_AjoutInteraction {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTINTERACTION_H
