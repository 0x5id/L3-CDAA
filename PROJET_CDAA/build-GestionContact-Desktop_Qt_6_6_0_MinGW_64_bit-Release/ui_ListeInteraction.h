/********************************************************************************
** Form generated from reading UI file 'ListeInteraction.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTEINTERACTION_H
#define UI_LISTEINTERACTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ListeInteraction
{
public:
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *LayoutTable;
    QTableWidget *TableInteraction;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *BouttonDateA;
    QLineEdit *LigneDateA;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *BouttonDateB;
    QLineEdit *LigneDateB;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QLineEdit *RechercheLine;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QComboBox *CritereCB;
    QHBoxLayout *horizontalLayout_5;
    QLabel *NbInteractionLabel;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *ListeInteraction)
    {
        if (ListeInteraction->objectName().isEmpty())
            ListeInteraction->setObjectName("ListeInteraction");
        ListeInteraction->resize(938, 612);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(119, 8, 127, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        ListeInteraction->setPalette(palette);
        ListeInteraction->setAutoFillBackground(true);
        horizontalLayout_7 = new QHBoxLayout(ListeInteraction);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        LayoutTable = new QHBoxLayout();
        LayoutTable->setSpacing(10);
        LayoutTable->setObjectName("LayoutTable");
        LayoutTable->setContentsMargins(5, -1, 6, -1);
        TableInteraction = new QTableWidget(ListeInteraction);
        TableInteraction->setObjectName("TableInteraction");
        TableInteraction->setMinimumSize(QSize(0, 0));

        LayoutTable->addWidget(TableInteraction);


        verticalLayout_5->addLayout(LayoutTable);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        BouttonDateA = new QPushButton(ListeInteraction);
        BouttonDateA->setObjectName("BouttonDateA");
        BouttonDateA->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_3->addWidget(BouttonDateA);

        LigneDateA = new QLineEdit(ListeInteraction);
        LigneDateA->setObjectName("LigneDateA");
        LigneDateA->setEnabled(false);
        LigneDateA->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_3->addWidget(LigneDateA);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        BouttonDateB = new QPushButton(ListeInteraction);
        BouttonDateB->setObjectName("BouttonDateB");
        BouttonDateB->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_2->addWidget(BouttonDateB);

        LigneDateB = new QLineEdit(ListeInteraction);
        LigneDateB->setObjectName("LigneDateB");
        LigneDateB->setEnabled(false);
        LigneDateB->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_2->addWidget(LigneDateB);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_4 = new QLabel(ListeInteraction);
        label_4->setObjectName("label_4");

        horizontalLayout_6->addWidget(label_4);

        RechercheLine = new QLineEdit(ListeInteraction);
        RechercheLine->setObjectName("RechercheLine");
        RechercheLine->setMinimumSize(QSize(300, 0));
        RechercheLine->setMaximumSize(QSize(400, 16777215));

        horizontalLayout_6->addWidget(RechercheLine);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label = new QLabel(ListeInteraction);
        label->setObjectName("label");

        horizontalLayout_4->addWidget(label);

        CritereCB = new QComboBox(ListeInteraction);
        CritereCB->setObjectName("CritereCB");
        CritereCB->setMinimumSize(QSize(300, 0));

        horizontalLayout_4->addWidget(CritereCB);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        NbInteractionLabel = new QLabel(ListeInteraction);
        NbInteractionLabel->setObjectName("NbInteractionLabel");

        horizontalLayout_5->addWidget(NbInteractionLabel);


        verticalLayout_2->addLayout(horizontalLayout_5);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_5->addLayout(horizontalLayout);


        horizontalLayout_7->addLayout(verticalLayout_5);


        retranslateUi(ListeInteraction);

        QMetaObject::connectSlotsByName(ListeInteraction);
    } // setupUi

    void retranslateUi(QWidget *ListeInteraction)
    {
        ListeInteraction->setWindowTitle(QCoreApplication::translate("ListeInteraction", "Form", nullptr));
        BouttonDateA->setText(QCoreApplication::translate("ListeInteraction", "De :", nullptr));
        BouttonDateB->setText(QCoreApplication::translate("ListeInteraction", "\303\200 :", nullptr));
        label_4->setText(QCoreApplication::translate("ListeInteraction", "Mot Cl\303\251 :", nullptr));
        label->setText(QCoreApplication::translate("ListeInteraction", "Crit\303\250res :", nullptr));
        NbInteractionLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ListeInteraction: public Ui_ListeInteraction {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTEINTERACTION_H
