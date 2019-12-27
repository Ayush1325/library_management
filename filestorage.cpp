#include "filestorage.h"

FileStorage::FileStorage(QMainWindow *m) : AbstractStorageClass(m)
{

}

void FileStorage::addBook(Book* book) {
    QFile file(book_file_name);
    if(!file.open(QIODevice::Append)) {
        QMessageBox::warning(this->main_window, "Warning", "Cannot open file : " + file.errorString());
    }
    QDataStream out(&file);
    out << (*book);
    file.close();
}

void FileStorage::addPerson(Person* member) {
    QFile file(member_file_name);
    if(!file.open(QIODevice::Append)) {
        QMessageBox::warning(this->main_window, "Warning", "Cannot open file : " + file.errorString());
    }
    QDataStream out(&file);
    out << (*member);
    file.close();
}

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
    QFile book_file(book_file_name);
    QFile member_file(member_file_name);
    if(!book_file.exists()) {
        book_file.open(QIODevice::WriteOnly);
    }
    if(!member_file.exists()) {
        member_file.open(QIODevice::WriteOnly);
    }
    book_file.close();
    member_file.close();
}

FileStorage::~FileStorage() {

}
