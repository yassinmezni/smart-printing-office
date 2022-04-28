QT       += core gui
QT       += sql
QT       += serialport
QT       += core gui multimedia multimediawidgets
QT       += core gui sql printsupport network
QT       += core gui sql
QT       += core gui sql multimedia printsupport charts network serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    client.cpp \
    commande.cpp \
    connection.cpp \
    employee.cpp \
    excel.cpp \
    fournisseur.cpp \
    livraison.cpp \
    main.cpp \
    mainClient.cpp \
    mainCommande.cpp \
    mainEmploye.cpp \
    mainLivraison.cpp \
    mainLogin.cpp \
    mainProduit.cpp \
    mainwindow.cpp \
    produit.cpp \
    qcustomplot.cpp \
    qrcode.cpp \
    smtp.cpp \
    statistic.cpp

HEADERS += \
    arduino.h \
    client.h \
    commande.h \
    connection.h \
    employee.h \
    excel.h \
    fournisseur.h \
    livraison.h \
    mainwindow.h \
    produit.h \
    qcustomplot.h \
    qrcode.h \
    smtp.h \
    statistic.h

FORMS += \
    mainwindow.ui \
    statistic.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc \
    resources.qrc \
    resources.qrc
