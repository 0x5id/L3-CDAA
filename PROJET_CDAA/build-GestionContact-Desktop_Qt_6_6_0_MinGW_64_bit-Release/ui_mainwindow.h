/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *AExporterJSON;
    QAction *AAfficheLogs;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *MainLayout;
    QMenuBar *menubar;
    QMenu *menuFichier;
    QMenu *menuContact;
    QMenu *menuLogs;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(1300, 730);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1300, 730));
        MainWindow->setLayoutDirection(Qt::LeftToRight);
        MainWindow->setAutoFillBackground(false);
        AExporterJSON = new QAction(MainWindow);
        AExporterJSON->setObjectName("AExporterJSON");
        AAfficheLogs = new QAction(MainWindow);
        AAfficheLogs->setObjectName("AAfficheLogs");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        centralwidget->setMinimumSize(QSize(930, 705));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        MainLayout = new QVBoxLayout();
        MainLayout->setObjectName("MainLayout");

        horizontalLayout->addLayout(MainLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1300, 21));
        menuFichier = new QMenu(menubar);
        menuFichier->setObjectName("menuFichier");
        menuContact = new QMenu(menuFichier);
        menuContact->setObjectName("menuContact");
        menuLogs = new QMenu(menuFichier);
        menuLogs->setObjectName("menuLogs");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFichier->menuAction());
        menuFichier->addAction(menuContact->menuAction());
        menuFichier->addAction(menuLogs->menuAction());
        menuContact->addAction(AExporterJSON);
        menuLogs->addAction(AAfficheLogs);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        AExporterJSON->setText(QCoreApplication::translate("MainWindow", "Exporter JSON", nullptr));
        AAfficheLogs->setText(QCoreApplication::translate("MainWindow", "Afficher les logs", nullptr));
        menuFichier->setTitle(QCoreApplication::translate("MainWindow", "Fichier", nullptr));
        menuContact->setTitle(QCoreApplication::translate("MainWindow", "Contact", nullptr));
        menuLogs->setTitle(QCoreApplication::translate("MainWindow", "Logs", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
