#include "wordcompare.h"

WordCompare::WordCompare(QObject *parent) : QObject(parent)
{

}

void WordCompare::randomMaker()
{
    QSqlQuery query;
    QString b;

    /*
    if(lang == "English")
        query.prepare("select id_sl, English from Slowa WHERE id_sl >= (abs(random()) % (SELECT max(id_sl + 1) FROM Slowa)) limit 1");
    if(lang == "Deutsch")
        query.prepare("select id_sl, Deutsch from Slowa WHERE id_sl >= (abs(random()) % (SELECT max(id_sl + 1) FROM Slowa)) limit 1");
    if(lang == "Japan")
        query.prepare("select id_sl, Japan from Slowa WHERE id_sl >= (abs(random()) % (SELECT max(id_sl + 1) FROM Slowa)) limit 1");
    */
    query.prepare("select id_sl, Polish from Slowa WHERE id_sl >= (abs(random()) % (SELECT max(id_sl + 1) FROM Slowa)) limit 1");
    query.exec();
     while (query.next()) {
         id = query.value(0).toInt();
         b = query.value(1).toString();
         qDebug() <<  b;
     }
     app = 1;
     emit changed(b);
}

void WordCompare::picRand()
{
    QSqlQuery query;
    QPixmap b;
    QByteArray z;

    query.prepare("select id_sl, image from Slowa WHERE id_sl >= (abs(random()) % (SELECT max(id_sl + 1) FROM Slowa)) limit 1");
    query.exec();
     while (query.next()) {
         id = query.value(0).toInt();
         z = query.value(1).toByteArray();
         b.loadFromData(z,"JPEG");
     }

    app = 2;
     emit picRanded(b);
}

void WordCompare::checkCorrect(QString val)
{
    QSqlQuery query;
    QString b;
    if(lang == "English")
        query.prepare("select English from Slowa WHERE id_sl = :id ");
    if(lang == "Deutsch")
        query.prepare("select Deutsch from Slowa WHERE id_sl = :id ");
    if(lang == "Japan")
        query.prepare("select Japan from Slowa WHERE id_sl = :id ");
    query.bindValue(":id", id);

    query.exec();
    while (query.next()) {
        b = query.value(0).toString();
        qDebug() <<  b;
    }
    qDebug()<<val;

    if(!QString::compare(b, val, Qt::CaseInsensitive))
    {
        if (app == 1)
            emit correctWord("Correct");
        if (app == 2)
            emit correctPic("Correct");
    }
    else
    {
        if (app == 1)
            emit incorrectWord("inCorrect");
        if (app == 2)
            emit incorrectPic("inCorrect");
    }
}

void WordCompare::assignValue(QString val)
{
    this->lang = val;
}
