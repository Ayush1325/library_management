#include "person.h"

Person::Person() {}

Person::Person(QString name, QString phone_no, QString address)
{
    this->name = name;
    this->phone_no = phone_no;
    this->address = address;
    this->id = QUuid::createUuid();
}

Person::Person(QUuid id, QString name, QString phone_no, QString address) {
    this->id = id;
    this->name = name;
    this->phone_no = phone_no;
    this->address = address;
}

QDataStream &operator<<(QDataStream &out, const Person &member)
{
    out << member.id << member.name
        << member.address << member.phone_no;
    return out;
}

QDataStream &operator>>(QDataStream &in, Person &member)
{
    QString name, address, phone_no;
    QUuid id;
    in >> id >> name >> address >> phone_no;
    member = Person(id, name, address, phone_no);
    return in;
}

QList<QStandardItem*> Person::returnItem() {
    QStandardItem* name = new QStandardItem(this->name);
    QStandardItem* address = new QStandardItem(this->address);
    QStandardItem* id = new QStandardItem(this->id.toString());
    QStandardItem* phone_no = new QStandardItem(this->phone_no);

    QList<QStandardItem*> temp;
    temp << id << name << phone_no << address;
    return temp;
}
