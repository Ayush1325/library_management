#include "abstractstorageclass.h"

AbstractStorageClass::AbstractStorageClass(QMainWindow *m)
{
    this->main_window = m;
}

void AbstractStorageClass::addBook(Book*) {}

void AbstractStorageClass::addPerson(Person*) {}

void AbstractStorageClass::removeBook(Book*) {}

void AbstractStorageClass::removePerson(Person*) {}

QList<Book> AbstractStorageClass::getAllBooks() {}

void AbstractStorageClass::checkStorage() {}
