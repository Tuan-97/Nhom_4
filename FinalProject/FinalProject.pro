QT       += core gui sql

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
    Class/categories.cpp \
    Class/customer.cpp \
    Class/employees.cpp \
    Class/order.cpp \
    Class/orderdetails.cpp \
    Class/products.cpp \
    Class/shipper.cpp \
    Class/soldproduct.cpp \
    Class/supplier.cpp \
<<<<<<< HEAD
    TableManagement.cpp \
    main.cpp \
    mainwindow.cpp \
    table.cpp
=======
    date.cpp \
    main.cpp \
    mainwindow.cpp \
    update_database.cpp
>>>>>>> 5af8377f30fd3d27315d9902109d8ab8ae646be1

HEADERS += \
    Class/categories.h \
    Class/customer.h \
    Class/employees.h \
    Class/order.h \
    Class/orderdetails.h \
    Class/products.h \
    Class/shipper.h \
    Class/soldproduct.h \
    Class/supplier.h \
    Extern_Variables.h \
<<<<<<< HEAD
    TableManagement.h \
    mainwindow.h \
    table.h
=======
    date.h \
    mainwindow.h \
    update_database.h
>>>>>>> 5af8377f30fd3d27315d9902109d8ab8ae646be1

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target