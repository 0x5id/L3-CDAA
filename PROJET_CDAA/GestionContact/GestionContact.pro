QT += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AfficheContact.cpp \
    AjoutContact.cpp \
    AjoutInteraction.cpp \
    BaseDeDonnee.cpp \
    Contact.cpp \
    Date.cpp \
    GestionnaireContact.cpp \
    GestionnaireInteraction.cpp \
    GestionnaireTodo.cpp \
    Interaction.cpp \
    ListeInteraction.cpp \
    ModifContact.cpp \
    PrincipaleWidget.cpp \
    Todo.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    AfficheContact.h \
    AjoutContact.h \
    AjoutInteraction.h \
    BaseDeDonnee.h \
    Contact.h \
    Date.h \
    GestionnaireContact.h \
    GestionnaireInteraction.h \
    GestionnaireTodo.h \
    Interaction.h \
    ListeInteraction.h \
    ModifContact.h \
    PrincipaleWidget.h \
    Todo.h \
    mainwindow.h

FORMS += \
    AfficheContact.ui \
    AjoutContact.ui \
    AjoutInteraction.ui \
    ListeInteraction.ui \
    ModifContact.ui \
    PrincipaleWidget.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
