#ifndef CONNECTION_H
#define CONNECTION_H

#include <QtSql>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QFile>
#include <QIODevice>
#include <QDomElement>
#include <QTextStream>
#include <QDomDocument>
#include <QDomProcessingInstruction>

static bool createConnection(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("manager_data");
    db.setUserName("root");
    db.setPassword("123");
    if (!db.open()){
//        qDebug() << "Failed to connect to root mysql admin";
    } else {
//        qDebug() << "open";
    }

    QSqlQuery query(db);

    // 创建分类表   //注意这里varchar一定要指定长度，不然会出错
    query.exec("create table type(id int primary key,name varchar(20)) "
               "ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8"); //建表时指定编码方式为utf8
    query.exec(QString("insert into type values(0, '请选择类型')"));
    query.exec(QString("insert into type values(01, '电视')"));
    query.exec(QString("insert into type values(02, '空调')"));

    //创建品牌表
    query.exec("create table brand(id int primary key, name varchar(20), "
               "type varchar(20), price int, sum int, sell int, last int) "
               "ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8");
    //query.exec(QString("insert into brand values(0, '请选择品牌', '电视', null, null, null, null)"));
    query.exec(QString("insert into brand values(01, '海信', '电视', 3699, 50, 10, 40)"));
    query.exec(QString("insert into brand values(02, '创维', '电视', 3499, 20, 5 ,15)"));
    query.exec(QString("insert into brand values(03, '海尔', '电视', 4199, 80, 40, 40)"));
    query.exec(QString("insert into brand values(04, '王牌', '电视', 3999, 40, 10 ,30)"));
    query.exec(QString("insert into brand values(05, '海尔', '空调', 2899, 60, 10, 50)"));
    query.exec(QString("insert into brand values(06, '格力', '空调', 2799, 70, 20 ,50)"));

    // 创建密码表
    query.exec("create table password(pwd varchar(20) primary key)"
               "ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8");
    query.exec(QString("insert into password values('123')"));

    return true;
}

static bool createXml(){
    QFile file("data2.xml");
    if (file.exists()){
        return true;
    }
    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate)){
        return false;
    }
    QDomDocument doc;
    QDomProcessingInstruction instruction;
    instruction = doc.createProcessingInstruction(
                "xml", "version=\"2.0\" encoding=\"UTF-8\"");
    doc.appendChild(instruction);
    QDomElement root = doc.createElement(QString("日销售清单"));
    doc.appendChild(root);
    QTextStream out(&file);
    doc.save(out, 4);
    file.close();
    return true;
}
#endif // CONNECTION_H
