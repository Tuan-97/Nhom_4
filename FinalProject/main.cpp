#include "mainwindow.h"
#include <QCoreApplication>
#include <QtSql>
#include <QSqlDatabase>
#include <QSql>
#include <QSqlError>
#include <QDir>
#include <QFile>
#include <QDebug>
#include <QSqlQuery>
#include <QString>
#include <iostream>
#include <fstream>

#include <QApplication>

int main(int argc, char *argv[])
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QDir dir;
    QString dbPath;
    QFileInfo checkCurrent(dir.currentPath() +"/data.db");
    QFileInfo checkHome(dir.homePath() +"/data.db");
    QFileInfo checkTemp(dir.tempPath() +"/data.db");
    if(checkCurrent.exists() && checkCurrent.isFile()){
        dbPath = dir.currentPath() +"/data.db";
    }else if(checkHome.exists() && checkHome.isFile()){
        dbPath = dir.homePath() +"/data.db";
    }else if(checkTemp.exists() && checkTemp.isFile()){
        dir.tempPath() +"/data.db";
    }else{
        dbPath = "F:/LG_Training/Exercise/Nhom_4/FinalProject/data.db";
    }
    qDebug() << dbPath;
    db.setDatabaseName(dbPath);

    if(!db.open()){
          qDebug() << "Error, no database";
          return 1;
    }
    QSqlQuery qry;


    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
