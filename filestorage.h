#ifndef FILESTORAGE_H
#define FILESTORAGE_H
#include "abstractstorageclass.h"
#include "QFile"
#include "QMessageBox"


class FileStorage : public AbstractStorageClass
{
private:
    QString people_file_name = "people.dat";
    QString book_file_name = "books.dat";
public:
    FileStorage(QMainWindow *m);

    void addBook(Book*) override;
    void addPerson(Person*) override;
    void removeBook(Book*) override;
    void removePerson(Person*) override;

    QList<Book> getAllBooks() override;

    void checkStorage() override;
};

#endif // FILESTORAGE_H
