#include "filestorage.h"
#include "QDebug"

FileStorage::FileStorage(QMainWindow *m) : AbstractStorageClass(m) {}

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

void FileStorage::removeBook(QUuid id) {
    QFile rfile(book_file_name), wfile("temp.dat");
    Book obj;
    if(!rfile.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this->main_window, "Warning", "Cannot open file : " + rfile.errorString());
    }
    if(!wfile.open(QIODevice::WriteOnly)) {
        QMessageBox::warning(this->main_window, "Warning", "Cannot open file : " + wfile.errorString());
    }
    QDataStream in(&rfile), out(&wfile);
    while(!rfile.atEnd()) {
        in >> obj;
        if (obj.getBookId() != id) {
            out << obj;
        }
    }
    rfile.remove();
    rfile.close();
    bool t = wfile.rename(book_file_name);
    qDebug() << t;
    wfile.close();
}

void FileStorage::removePerson(QUuid id) {
    QFile rfile(member_file_name), wfile("temp.dat");
    Person obj;
    if(!rfile.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this->main_window, "Warning", "Cannot open file : " + rfile.errorString());
    }
    if(!wfile.open(QIODevice::WriteOnly)) {
        QMessageBox::warning(this->main_window, "Warning", "Cannot open file : " + wfile.errorString());
    }
    QDataStream in(&rfile), out(&wfile);
    while(!rfile.atEnd()) {
        in >> obj;
        if (obj.getId() != id) {
            out << obj;
        }
    }
    rfile.remove();
    rfile.close();
    bool t = wfile.rename(book_file_name);
    qDebug() << t;
    wfile.close();
}

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

Book FileStorage::editBook(QUuid id, std::function<void(Book &)> func) {
    QFile rfile(book_file_name), wfile("temp.dat");
    Book obj;
    Book robj;
    if(!rfile.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this->main_window, "Warning", "Cannot open file : " + rfile.errorString());
    }
    if(!wfile.open(QIODevice::WriteOnly)) {
        QMessageBox::warning(this->main_window, "Warning", "Cannot open file : " + wfile.errorString());
    }
    QDataStream in(&rfile), out(&wfile);
    while(!rfile.atEnd()) {
        in >> obj;
        if (obj.getBookId() == id) {
            func(obj);
            robj = obj;
        }
        out << obj;
    }
    rfile.remove();
    rfile.close();
    wfile.rename(book_file_name);
    wfile.close();
    return robj;
}

QStringList FileStorage::getAllMemberIds() {
    QFile file(member_file_name);
    QStringList ids;
    Person obj;
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this->main_window, "Warning", "Cannot open file : " + file.errorString());
    }
    QDataStream in(&file);
    while(!file.atEnd()) {
        in >> obj;
        ids.append(obj.getId().toString());
    }
    file.close();
    return ids;
}


FileStorage::~FileStorage() {

}
