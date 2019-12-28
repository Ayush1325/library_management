#include "abstractstorageclass.h"

AbstractStorageClass::AbstractStorageClass(QMainWindow *m)
{
    this->main_window = m;
}

void AbstractStorageClass::addBook(Book*) {}

void AbstractStorageClass::addPerson(Person*) {}

void AbstractStorageClass::removeBook(QUuid) {}

void AbstractStorageClass::removePerson(QUuid) {}

QList<Book> AbstractStorageClass::getAllBooks() {return QList<Book>();}

void AbstractStorageClass::checkStorage() {}

Book AbstractStorageClass::editBook(QUuid, std::function<void(Book &)>) {}

AbstractStorageClass::~AbstractStorageClass() {
    delete main_window;
}
