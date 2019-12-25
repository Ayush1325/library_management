#include "person.h"

Person::Person(QString name, QString phone_no, QString address)
{
    this->name = name;
    this->phone_no = phone_no;
    this->address = address;
    this->id = QUuid::createUuid();
}
