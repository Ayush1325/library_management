#include "filestorage.h"

FileStorage::FileStorage(QMainWindow *m) : AbstractStorageClass(m)
{

}

void FileStorage::addBook(Book* book) {
    QFile file(book_file_name);
    if(!file.open(QIODevice::WriteOnly)) {
        QMessageBox::warning(this->main_window, "Warning", "Cannot open file : " + file.errorString());
    }
    QDataStream out(&file);
    out << book;
    file.close();
}

void FileStorage::addPerson(Person*) {}

void FileStorage::removeBook(Book*) {}

void FileStorage::removePerson(Person*) {}

QList<Book> FileStorage::getAllBooks() {
    QFile file(book_file_name);
    QList<Book> tempList;
    Book obj;
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this->main_window, "Warning", "Cannot open file : " + file.errorString());
    }
    QDataStream in(&file);
    while(!file.atEnd()) {
        in >> obj;
        tempList.append(obj);
    }
    return tempList;
}

void FileStorage::checkStorage() {
    QFile file(book_file_name);

    if(!file.exists()) {
        file.open(QIODevice::WriteOnly);
    }
    file.close();
}
