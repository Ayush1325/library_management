#ifndef FILESTORAGE_H
#define FILESTORAGE_H
#include "abstractstorageclass.h"
#include "QFile"
#include "QMessageBox"


class FileStorage : public AbstractStorageClass
{
private:
    QString member_file_name = "member.dat";
    QString book_file_name = "books.dat";
public:
    FileStorage(QMainWindow *m);
    ~FileStorage();

    void addBook(Book*) override;
    void addPerson(Person*) override;
    void removeBook(QUuid) override;
    void removePerson(QUuid) override;

    QList<Book> getAllBooks() override;

    void checkStorage() override;
};

#endif // FILESTORAGE_H
