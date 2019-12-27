#ifndef PERSON_H
#define PERSON_H
#include "QString"
#include "QDate"
#include "QUuid"
#include "QStandardItem"

class Person
{
private:
    QUuid id;
    QString name;
    QString phone_no;
    QString address;

public:
    Person();
    Person(QString, QString, QString);
    Person(QUuid, QString, QString, QString);

    QList<QStandardItem*> returnItem();
    QUuid getId() {return id;}

    friend QDataStream &operator<<(QDataStream &out, const Person &member);
    friend QDataStream &operator>>(QDataStream &in, Person &member);
};

#endif // PERSON_H
