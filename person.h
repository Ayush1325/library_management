#ifndef PERSON_H
#define PERSON_H
#include "QString"
#include "QDate"
#include "QUuid"

class Person
{
private:
    QUuid id;
    QString name;
    QString phone_no;
    QString address;

public:
    Person(QString, QString, QString);
};

#endif // PERSON_H
