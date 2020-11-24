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
    TableManagement.cpp \
    main.cpp \
    mainwindow.cpp \
    table.cpp

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
    TableManagement.h \
    mainwindow.h \
    table.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
