#ifndef SEEDER_H
#define SEEDER_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QSqlTableModel>
#include <QTableView>
#include <QDebug>
#include <vector>


class Seeder
{
public:
    Seeder();
    int MakeTables();
    int DeleteTables();
    int FillTables();
private:
    std::vector<QString> langs;
    std::vector<QString> plWords;
    std::vector<QString> engWords;
    std::vector<QString> deWords;

};

#endif // SEEDER_H
