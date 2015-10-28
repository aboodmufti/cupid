#include "databasemanager.h"

DatabaseManager::DatabaseManager()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/student/Desktop/project_files/cupid_DB.db");
    qDebug() << "/home/student/Desktop/project_files/cupid_DB.db";

    bool db_ok = db.open();

    if(db_ok == true){
        QSqlQuery *query = new QSqlQuery(db);
        //query->exec("drop table  STUDENT;");
        bool exec_ok = query->exec("create table if not exists STUDENT  (Sid INTEGER PRIMARY KEY AUTOINCREMENT , SName varchar(96),SUsername varchar(64), SOwnQualifications INT, SPartnerQualifications INT);");
        if(exec_ok == true){
            exec_ok = query->exec("INSERT INTO STUDENT (SName,SUsername,SOwnQualifications,SPartnerQualifications) VALUES ('Abood', 'aboodmufti', 1, 2 );");
            if(exec_ok == false){
                qDebug() << "Error: INSERT | " << query->lastError().text();
            }
            query->exec("select * from STUDENT;");

        }
        else{

            qDebug() << "Error: CREATE | " << query->lastError().text();
        }

        while (query->next()) {
            int id = query->value(0).toInt();
            QString name = query->value(1).toString();
            QString username = query->value(2).toString();
            int own = query->value(3).toInt();
            int partner = query->value(4).toInt();
            qDebug() << "id: " << id << "name: " << name << "own: " << own << "partner: " << partner;
        }
    }
    else{
        qDebug() << "Error: OPEN";
    }


}
