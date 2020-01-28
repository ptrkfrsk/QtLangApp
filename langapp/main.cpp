#include <QApplication>
#include <QDebug>
#include "mainwindow.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QSqlTableModel>
#include <QTableView>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    // init Database
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("localhost");
    db.setDatabaseName("test");
    db.setUserName("test");
    db.setPassword("test123");
    bool ok = db.open();
    qDebug() << ok;


    QSqlTableModel test;
    test.setTable("Jezyki");
    test.select();
    QTableView* testView = new QTableView;
    testView->setModel(&test);
    testView->show();


    return a.exec();
}
