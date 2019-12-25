#ifndef ABSTRACTSTORAGECLASS_H
#define ABSTRACTSTORAGECLASS_H
#include "book.h"
#include "person.h"


class AbstractStorageClass
{
public:
    AbstractStorageClass();

    virtual void addBook(Book);
    virtual void addPerson(Person);
    virtual void removeBook(Book);
    virtual void removePerson(Person);
};

#endif // ABSTRACTSTORAGECLASS_H
