#ifndef ABSTRACTSTORAGECLASS_H
#define ABSTRACTSTORAGECLASS_H
#include "book.h"
#include "person.h"
#include "QMainWindow"


class AbstractStorageClass
{
protected:
    QMainWindow *main_window;
public:
    AbstractStorageClass(QMainWindow *);
    ~AbstractStorageClass();

    virtual void addBook(Book*);
    virtual void addPerson(Person*);
    virtual void removeBook(QUuid);
    virtual void removePerson(QUuid);
    virtual QList<Book> getAllBooks();
    virtual void checkStorage();
};

#endif // ABSTRACTSTORAGECLASS_H
