/****************************************************************************
** Meta object code from reading C++ file 'PrincipaleWidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../GestionContact/PrincipaleWidget.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PrincipaleWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSPrincipaleWidgetENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSPrincipaleWidgetENDCLASS = QtMocHelpers::stringData(
    "PrincipaleWidget",
    "RefreshContacts",
    "",
    "getLogs",
    "RefreshGC",
    "RefreshAffiche",
    "Contact*",
    "selectedContact",
    "RefreshListInter",
    "GestionnaireContact",
    "Gc",
    "refreshInteractionForm",
    "initModifContact",
    "BaseDDAjtContact",
    "Contact",
    "contact",
    "BaseDDMdfContact",
    "contact1",
    "contact2",
    "BaseDDAjtInteraction",
    "Interaction",
    "inter",
    "BaseDDSuppressionInteraction",
    "std::string",
    "mail",
    "BaseDDSuppressionContact",
    "setContacts",
    "GestC",
    "onAjoutContactClicked",
    "onAfficheIntersClicked",
    "ChoixDateA",
    "ChoixDateB",
    "ActuLigneDate",
    "RefreshListeContact",
    "onModificationContact",
    "onAjoutInteraction",
    "onAnnulationModif",
    "onAnnulationInteraction",
    "BDD_AjoutContact",
    "BDD_ModifContact",
    "BDD_SupprContact",
    "BDD_AjoutInteraction",
    "BDD_SupprInteraction",
    "onAfficheLogs",
    "RefreshLogs",
    "std::list<QString>",
    "logListe",
    "onContactClique",
    "row",
    "RefreshGestionnaireContact"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSPrincipaleWidgetENDCLASS_t {
    uint offsetsAndSizes[100];
    char stringdata0[17];
    char stringdata1[16];
    char stringdata2[1];
    char stringdata3[8];
    char stringdata4[10];
    char stringdata5[15];
    char stringdata6[9];
    char stringdata7[16];
    char stringdata8[17];
    char stringdata9[20];
    char stringdata10[3];
    char stringdata11[23];
    char stringdata12[17];
    char stringdata13[17];
    char stringdata14[8];
    char stringdata15[8];
    char stringdata16[17];
    char stringdata17[9];
    char stringdata18[9];
    char stringdata19[21];
    char stringdata20[12];
    char stringdata21[6];
    char stringdata22[29];
    char stringdata23[12];
    char stringdata24[5];
    char stringdata25[25];
    char stringdata26[12];
    char stringdata27[6];
    char stringdata28[22];
    char stringdata29[23];
    char stringdata30[11];
    char stringdata31[11];
    char stringdata32[14];
    char stringdata33[20];
    char stringdata34[22];
    char stringdata35[19];
    char stringdata36[18];
    char stringdata37[24];
    char stringdata38[17];
    char stringdata39[17];
    char stringdata40[17];
    char stringdata41[21];
    char stringdata42[21];
    char stringdata43[14];
    char stringdata44[12];
    char stringdata45[19];
    char stringdata46[9];
    char stringdata47[16];
    char stringdata48[4];
    char stringdata49[27];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSPrincipaleWidgetENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSPrincipaleWidgetENDCLASS_t qt_meta_stringdata_CLASSPrincipaleWidgetENDCLASS = {
    {
        QT_MOC_LITERAL(0, 16),  // "PrincipaleWidget"
        QT_MOC_LITERAL(17, 15),  // "RefreshContacts"
        QT_MOC_LITERAL(33, 0),  // ""
        QT_MOC_LITERAL(34, 7),  // "getLogs"
        QT_MOC_LITERAL(42, 9),  // "RefreshGC"
        QT_MOC_LITERAL(52, 14),  // "RefreshAffiche"
        QT_MOC_LITERAL(67, 8),  // "Contact*"
        QT_MOC_LITERAL(76, 15),  // "selectedContact"
        QT_MOC_LITERAL(92, 16),  // "RefreshListInter"
        QT_MOC_LITERAL(109, 19),  // "GestionnaireContact"
        QT_MOC_LITERAL(129, 2),  // "Gc"
        QT_MOC_LITERAL(132, 22),  // "refreshInteractionForm"
        QT_MOC_LITERAL(155, 16),  // "initModifContact"
        QT_MOC_LITERAL(172, 16),  // "BaseDDAjtContact"
        QT_MOC_LITERAL(189, 7),  // "Contact"
        QT_MOC_LITERAL(197, 7),  // "contact"
        QT_MOC_LITERAL(205, 16),  // "BaseDDMdfContact"
        QT_MOC_LITERAL(222, 8),  // "contact1"
        QT_MOC_LITERAL(231, 8),  // "contact2"
        QT_MOC_LITERAL(240, 20),  // "BaseDDAjtInteraction"
        QT_MOC_LITERAL(261, 11),  // "Interaction"
        QT_MOC_LITERAL(273, 5),  // "inter"
        QT_MOC_LITERAL(279, 28),  // "BaseDDSuppressionInteraction"
        QT_MOC_LITERAL(308, 11),  // "std::string"
        QT_MOC_LITERAL(320, 4),  // "mail"
        QT_MOC_LITERAL(325, 24),  // "BaseDDSuppressionContact"
        QT_MOC_LITERAL(350, 11),  // "setContacts"
        QT_MOC_LITERAL(362, 5),  // "GestC"
        QT_MOC_LITERAL(368, 21),  // "onAjoutContactClicked"
        QT_MOC_LITERAL(390, 22),  // "onAfficheIntersClicked"
        QT_MOC_LITERAL(413, 10),  // "ChoixDateA"
        QT_MOC_LITERAL(424, 10),  // "ChoixDateB"
        QT_MOC_LITERAL(435, 13),  // "ActuLigneDate"
        QT_MOC_LITERAL(449, 19),  // "RefreshListeContact"
        QT_MOC_LITERAL(469, 21),  // "onModificationContact"
        QT_MOC_LITERAL(491, 18),  // "onAjoutInteraction"
        QT_MOC_LITERAL(510, 17),  // "onAnnulationModif"
        QT_MOC_LITERAL(528, 23),  // "onAnnulationInteraction"
        QT_MOC_LITERAL(552, 16),  // "BDD_AjoutContact"
        QT_MOC_LITERAL(569, 16),  // "BDD_ModifContact"
        QT_MOC_LITERAL(586, 16),  // "BDD_SupprContact"
        QT_MOC_LITERAL(603, 20),  // "BDD_AjoutInteraction"
        QT_MOC_LITERAL(624, 20),  // "BDD_SupprInteraction"
        QT_MOC_LITERAL(645, 13),  // "onAfficheLogs"
        QT_MOC_LITERAL(659, 11),  // "RefreshLogs"
        QT_MOC_LITERAL(671, 18),  // "std::list<QString>"
        QT_MOC_LITERAL(690, 8),  // "logListe"
        QT_MOC_LITERAL(699, 15),  // "onContactClique"
        QT_MOC_LITERAL(715, 3),  // "row"
        QT_MOC_LITERAL(719, 26)   // "RefreshGestionnaireContact"
    },
    "PrincipaleWidget",
    "RefreshContacts",
    "",
    "getLogs",
    "RefreshGC",
    "RefreshAffiche",
    "Contact*",
    "selectedContact",
    "RefreshListInter",
    "GestionnaireContact",
    "Gc",
    "refreshInteractionForm",
    "initModifContact",
    "BaseDDAjtContact",
    "Contact",
    "contact",
    "BaseDDMdfContact",
    "contact1",
    "contact2",
    "BaseDDAjtInteraction",
    "Interaction",
    "inter",
    "BaseDDSuppressionInteraction",
    "std::string",
    "mail",
    "BaseDDSuppressionContact",
    "setContacts",
    "GestC",
    "onAjoutContactClicked",
    "onAfficheIntersClicked",
    "ChoixDateA",
    "ChoixDateB",
    "ActuLigneDate",
    "RefreshListeContact",
    "onModificationContact",
    "onAjoutInteraction",
    "onAnnulationModif",
    "onAnnulationInteraction",
    "BDD_AjoutContact",
    "BDD_ModifContact",
    "BDD_SupprContact",
    "BDD_AjoutInteraction",
    "BDD_SupprInteraction",
    "onAfficheLogs",
    "RefreshLogs",
    "std::list<QString>",
    "logListe",
    "onContactClique",
    "row",
    "RefreshGestionnaireContact"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSPrincipaleWidgetENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      32,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      13,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  206,    2, 0x06,    1 /* Public */,
       3,    0,  207,    2, 0x06,    2 /* Public */,
       4,    0,  208,    2, 0x06,    3 /* Public */,
       5,    1,  209,    2, 0x06,    4 /* Public */,
       8,    1,  212,    2, 0x06,    6 /* Public */,
      11,    1,  215,    2, 0x06,    8 /* Public */,
      12,    1,  218,    2, 0x06,   10 /* Public */,
      13,    1,  221,    2, 0x06,   12 /* Public */,
      16,    2,  224,    2, 0x06,   14 /* Public */,
      19,    2,  229,    2, 0x06,   17 /* Public */,
      22,    2,  234,    2, 0x06,   20 /* Public */,
      25,    1,  239,    2, 0x06,   23 /* Public */,
      26,    1,  242,    2, 0x06,   25 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      28,    0,  245,    2, 0x0a,   27 /* Public */,
      29,    0,  246,    2, 0x0a,   28 /* Public */,
      30,    0,  247,    2, 0x0a,   29 /* Public */,
      31,    0,  248,    2, 0x0a,   30 /* Public */,
      32,    0,  249,    2, 0x0a,   31 /* Public */,
      33,    0,  250,    2, 0x0a,   32 /* Public */,
      34,    0,  251,    2, 0x0a,   33 /* Public */,
      35,    0,  252,    2, 0x0a,   34 /* Public */,
      36,    0,  253,    2, 0x0a,   35 /* Public */,
      37,    0,  254,    2, 0x0a,   36 /* Public */,
      38,    1,  255,    2, 0x0a,   37 /* Public */,
      39,    2,  258,    2, 0x0a,   39 /* Public */,
      40,    0,  263,    2, 0x0a,   42 /* Public */,
      41,    1,  264,    2, 0x0a,   43 /* Public */,
      42,    2,  267,    2, 0x0a,   45 /* Public */,
      43,    0,  272,    2, 0x0a,   48 /* Public */,
      44,    1,  273,    2, 0x0a,   49 /* Public */,
      47,    2,  276,    2, 0x0a,   51 /* Public */,
      49,    1,  281,    2, 0x0a,   54 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, 0x80000000 | 14, 0x80000000 | 14,   17,   18,
    QMetaType::Void, 0x80000000 | 14, 0x80000000 | 20,    7,   21,
    QMetaType::Void, 0x80000000 | 20, 0x80000000 | 23,   21,   24,
    QMetaType::Void, 0x80000000 | 14,    7,
    QMetaType::Void, 0x80000000 | 9,   27,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, 0x80000000 | 14, 0x80000000 | 14,   17,   18,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 20,   21,
    QMetaType::Void, 0x80000000 | 20, 0x80000000 | 23,   21,   24,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 45,   46,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   48,    2,
    QMetaType::Void, 0x80000000 | 9,   27,

       0        // eod
};

Q_CONSTINIT const QMetaObject PrincipaleWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSPrincipaleWidgetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSPrincipaleWidgetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSPrincipaleWidgetENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<PrincipaleWidget, std::true_type>,
        // method 'RefreshContacts'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'getLogs'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'RefreshGC'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'RefreshAffiche'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Contact *, std::false_type>,
        // method 'RefreshListInter'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<GestionnaireContact, std::false_type>,
        // method 'refreshInteractionForm'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Contact *, std::false_type>,
        // method 'initModifContact'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Contact *, std::false_type>,
        // method 'BaseDDAjtContact'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Contact, std::false_type>,
        // method 'BaseDDMdfContact'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Contact, std::false_type>,
        QtPrivate::TypeAndForceComplete<Contact, std::false_type>,
        // method 'BaseDDAjtInteraction'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Contact, std::false_type>,
        QtPrivate::TypeAndForceComplete<Interaction, std::false_type>,
        // method 'BaseDDSuppressionInteraction'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Interaction, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'BaseDDSuppressionContact'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Contact, std::false_type>,
        // method 'setContacts'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<GestionnaireContact, std::false_type>,
        // method 'onAjoutContactClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onAfficheIntersClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ChoixDateA'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ChoixDateB'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ActuLigneDate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'RefreshListeContact'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onModificationContact'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onAjoutInteraction'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onAnnulationModif'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onAnnulationInteraction'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'BDD_AjoutContact'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Contact, std::false_type>,
        // method 'BDD_ModifContact'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Contact, std::false_type>,
        QtPrivate::TypeAndForceComplete<Contact, std::false_type>,
        // method 'BDD_SupprContact'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'BDD_AjoutInteraction'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Interaction, std::false_type>,
        // method 'BDD_SupprInteraction'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Interaction, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'onAfficheLogs'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'RefreshLogs'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::list<QString>, std::false_type>,
        // method 'onContactClique'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'RefreshGestionnaireContact'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<GestionnaireContact, std::false_type>
    >,
    nullptr
} };

void PrincipaleWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PrincipaleWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->RefreshContacts(); break;
        case 1: _t->getLogs(); break;
        case 2: _t->RefreshGC(); break;
        case 3: _t->RefreshAffiche((*reinterpret_cast< std::add_pointer_t<Contact*>>(_a[1]))); break;
        case 4: _t->RefreshListInter((*reinterpret_cast< std::add_pointer_t<GestionnaireContact>>(_a[1]))); break;
        case 5: _t->refreshInteractionForm((*reinterpret_cast< std::add_pointer_t<Contact*>>(_a[1]))); break;
        case 6: _t->initModifContact((*reinterpret_cast< std::add_pointer_t<Contact*>>(_a[1]))); break;
        case 7: _t->BaseDDAjtContact((*reinterpret_cast< std::add_pointer_t<Contact>>(_a[1]))); break;
        case 8: _t->BaseDDMdfContact((*reinterpret_cast< std::add_pointer_t<Contact>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Contact>>(_a[2]))); break;
        case 9: _t->BaseDDAjtInteraction((*reinterpret_cast< std::add_pointer_t<Contact>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Interaction>>(_a[2]))); break;
        case 10: _t->BaseDDSuppressionInteraction((*reinterpret_cast< std::add_pointer_t<Interaction>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<std::string>>(_a[2]))); break;
        case 11: _t->BaseDDSuppressionContact((*reinterpret_cast< std::add_pointer_t<Contact>>(_a[1]))); break;
        case 12: _t->setContacts((*reinterpret_cast< std::add_pointer_t<GestionnaireContact>>(_a[1]))); break;
        case 13: _t->onAjoutContactClicked(); break;
        case 14: _t->onAfficheIntersClicked(); break;
        case 15: _t->ChoixDateA(); break;
        case 16: _t->ChoixDateB(); break;
        case 17: _t->ActuLigneDate(); break;
        case 18: _t->RefreshListeContact(); break;
        case 19: _t->onModificationContact(); break;
        case 20: _t->onAjoutInteraction(); break;
        case 21: _t->onAnnulationModif(); break;
        case 22: _t->onAnnulationInteraction(); break;
        case 23: _t->BDD_AjoutContact((*reinterpret_cast< std::add_pointer_t<Contact>>(_a[1]))); break;
        case 24: _t->BDD_ModifContact((*reinterpret_cast< std::add_pointer_t<Contact>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Contact>>(_a[2]))); break;
        case 25: _t->BDD_SupprContact(); break;
        case 26: _t->BDD_AjoutInteraction((*reinterpret_cast< std::add_pointer_t<Interaction>>(_a[1]))); break;
        case 27: _t->BDD_SupprInteraction((*reinterpret_cast< std::add_pointer_t<Interaction>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<std::string>>(_a[2]))); break;
        case 28: _t->onAfficheLogs(); break;
        case 29: _t->RefreshLogs((*reinterpret_cast< std::add_pointer_t<std::list<QString>>>(_a[1]))); break;
        case 30: _t->onContactClique((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 31: _t->RefreshGestionnaireContact((*reinterpret_cast< std::add_pointer_t<GestionnaireContact>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PrincipaleWidget::*)();
            if (_t _q_method = &PrincipaleWidget::RefreshContacts; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PrincipaleWidget::*)();
            if (_t _q_method = &PrincipaleWidget::getLogs; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PrincipaleWidget::*)();
            if (_t _q_method = &PrincipaleWidget::RefreshGC; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (PrincipaleWidget::*)(Contact * );
            if (_t _q_method = &PrincipaleWidget::RefreshAffiche; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (PrincipaleWidget::*)(GestionnaireContact );
            if (_t _q_method = &PrincipaleWidget::RefreshListInter; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (PrincipaleWidget::*)(Contact * );
            if (_t _q_method = &PrincipaleWidget::refreshInteractionForm; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (PrincipaleWidget::*)(Contact * );
            if (_t _q_method = &PrincipaleWidget::initModifContact; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (PrincipaleWidget::*)(Contact );
            if (_t _q_method = &PrincipaleWidget::BaseDDAjtContact; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (PrincipaleWidget::*)(Contact , Contact );
            if (_t _q_method = &PrincipaleWidget::BaseDDMdfContact; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (PrincipaleWidget::*)(Contact , Interaction );
            if (_t _q_method = &PrincipaleWidget::BaseDDAjtInteraction; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (PrincipaleWidget::*)(Interaction , std::string );
            if (_t _q_method = &PrincipaleWidget::BaseDDSuppressionInteraction; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (PrincipaleWidget::*)(Contact );
            if (_t _q_method = &PrincipaleWidget::BaseDDSuppressionContact; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (PrincipaleWidget::*)(GestionnaireContact );
            if (_t _q_method = &PrincipaleWidget::setContacts; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 12;
                return;
            }
        }
    }
}

const QMetaObject *PrincipaleWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PrincipaleWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSPrincipaleWidgetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int PrincipaleWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 32)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 32;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 32)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 32;
    }
    return _id;
}

// SIGNAL 0
void PrincipaleWidget::RefreshContacts()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void PrincipaleWidget::getLogs()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void PrincipaleWidget::RefreshGC()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void PrincipaleWidget::RefreshAffiche(Contact * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void PrincipaleWidget::RefreshListInter(GestionnaireContact _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void PrincipaleWidget::refreshInteractionForm(Contact * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void PrincipaleWidget::initModifContact(Contact * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void PrincipaleWidget::BaseDDAjtContact(Contact _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void PrincipaleWidget::BaseDDMdfContact(Contact _t1, Contact _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void PrincipaleWidget::BaseDDAjtInteraction(Contact _t1, Interaction _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void PrincipaleWidget::BaseDDSuppressionInteraction(Interaction _t1, std::string _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void PrincipaleWidget::BaseDDSuppressionContact(Contact _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void PrincipaleWidget::setContacts(GestionnaireContact _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}
QT_WARNING_POP
