#include "Util.h"
#include <CommonDef.h>
ColType checkType(QString typeStr){
    if(typeStr == "INTERGER") return INT;
    if(typeStr == "REAL") return REAL;
    if(typeStr == "TEXT") return TEXT;
    return UNKNOWN;
}

QString quoteSql(QString const& orgStr) {
    return QString("'%1'").arg(orgStr);
};


// Backup file locate in orgFPath in path with name is filename
// This is the same as save Data
void SaveData(QString orgFPath, QString path, QString filename){
    QFile::copy(orgFPath, QString("%1/%2").arg(path, filename));
};


void BackupData(QString orgFPath, QString path, QString filename){
    filename.append(".backup");
    QFile::copy(orgFPath, QString("%1/%2").arg(path, filename));
};

int OpenData(bool useTemp){
    QDir dir;
    QString dataName = "data.db";
    QString dbPath; // the database path is store in dbPath
    QString curPath = dir.currentPath();
    dbPath = curPath + "/" + dataName;

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    if(useTemp) {
        QString temp = "temp.db";
        QString tempPath =   curPath + "/" + temp;
        SaveData(dbPath, curPath,temp);
        db.setDatabaseName(tempPath);
    }else{
        db.setDatabaseName(dbPath);
    }

    if(!db.open()){
          qDebug() << "Error, no database";
          return 1;
    }
    return 0;
}

int closeDataBase(bool useTemp, QString path){
    if(useTemp){
        QFile::copy(QString("%1/%2").arg(path, "temp.db"),
                    QString("%1/%2").arg(path, "data.db"));
    }
    return 0;
}
