/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[19];
    char stringdata0[390];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 18), // "on_valider_clicked"
QT_MOC_LITERAL(4, 53, 24), // "on_tab_produit_activated"
QT_MOC_LITERAL(5, 78, 5), // "index"
QT_MOC_LITERAL(6, 84, 15), // "on_read_clicked"
QT_MOC_LITERAL(7, 100, 20), // "on_supprimer_clicked"
QT_MOC_LITERAL(8, 121, 35), // "on_lineEdit_3_cursorPositionC..."
QT_MOC_LITERAL(9, 157, 4), // "arg1"
QT_MOC_LITERAL(10, 162, 4), // "arg2"
QT_MOC_LITERAL(11, 167, 28), // "on_pushButton_delete_clicked"
QT_MOC_LITERAL(12, 196, 26), // "on_pushButton_show_clicked"
QT_MOC_LITERAL(13, 223, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(14, 247, 24), // "on_inserer_photo_clicked"
QT_MOC_LITERAL(15, 272, 31), // "on_comboBox_currentIndexChanged"
QT_MOC_LITERAL(16, 304, 33), // "on_comboBox_2_currentIndexCha..."
QT_MOC_LITERAL(17, 338, 21), // "on_comboBox_activated"
QT_MOC_LITERAL(18, 360, 29) // "on_comboBox_2_textHighlighted"

    },
    "MainWindow\0on_pushButton_clicked\0\0"
    "on_valider_clicked\0on_tab_produit_activated\0"
    "index\0on_read_clicked\0on_supprimer_clicked\0"
    "on_lineEdit_3_cursorPositionChanged\0"
    "arg1\0arg2\0on_pushButton_delete_clicked\0"
    "on_pushButton_show_clicked\0"
    "on_pushButton_2_clicked\0"
    "on_inserer_photo_clicked\0"
    "on_comboBox_currentIndexChanged\0"
    "on_comboBox_2_currentIndexChanged\0"
    "on_comboBox_activated\0"
    "on_comboBox_2_textHighlighted"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    1,   86,    2, 0x08 /* Private */,
       6,    0,   89,    2, 0x08 /* Private */,
       7,    0,   90,    2, 0x08 /* Private */,
       8,    2,   91,    2, 0x08 /* Private */,
      11,    0,   96,    2, 0x08 /* Private */,
      12,    0,   97,    2, 0x08 /* Private */,
      13,    0,   98,    2, 0x08 /* Private */,
      14,    0,   99,    2, 0x08 /* Private */,
      15,    1,  100,    2, 0x08 /* Private */,
      16,    1,  103,    2, 0x08 /* Private */,
      17,    1,  106,    2, 0x08 /* Private */,
      18,    1,  109,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,    9,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        //case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->on_valider_clicked(); break;
        case 2: _t->on_tab_produit_activated((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 3: _t->on_read_clicked(); break;
        //case 4: _t->on_supprimer_clicked(); break;
       // case 5: _t->on_lineEdit_3_cursorPositionChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->on_pushButton_delete_clicked(); break;
       // case 7: _t->on_pushButton_show_clicked(); break;
        case 8: _t->on_pushButton_2_clicked(); break;
        //case 9: _t->on_inserer_photo_clicked(); break;
        case 10: _t->on_comboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
       // case 11: _t->on_comboBox_2_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        //case 12: _t->on_comboBox_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
       // case 13: _t->on_comboBox_2_textHighlighted((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
