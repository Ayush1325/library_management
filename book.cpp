#include "book.h"

Book::Book(){}

Book::Book(QString title, QString author, QString publisher, QDate publish_date)
{
    this->title = title;
    this->author = author;
    this->publisher = publisher;
    this->publish_date = publish_date;
    this->book_id = QUuid::createUuid();
    this->is_issued = false;
}

Book::Book(QUuid book_id, QUuid issuer_id, QString title, QString author, bool is_issued, QDate issue_date, QString publisher, QDate publish_date) {
    this->book_id = book_id;
    this->issuer_id = issuer_id;
    this->title = title;
    this->author = author;
    this->is_issued = is_issued;
    this->issue_date = issue_date;
    this->publisher = publisher;
    this->publish_date = publish_date;
}

void Book::Issue(QUuid id) {
    this->issue_date = QDate::currentDate();
    this->is_issued = true;
    this->issuer_id = id;
}

void Book::Return() {
    this->is_issued = false;
}

QList<QStandardItem*> Book::returnItem() {
    QStandardItem* title = new QStandardItem(this->title);
    QStandardItem* publisher = new QStandardItem(this->publisher);
    QStandardItem* book_id = new QStandardItem(this->book_id.toString());
    QStandardItem* author = new QStandardItem(this->author);
    QString stat = status();
    QStandardItem* status = new QStandardItem(stat);
    QStandardItem* publish_date = new QStandardItem(this->publish_date.toString());

    QList<QStandardItem*> temp;
    temp << book_id << title << author << publisher << publish_date << status;
    return temp;
}

QDataStream &operator<<(QDataStream &out, const Book &book)
{
    out << book.book_id << book.issuer_id
        << book.title << book.author
        << book.is_issued << book.issue_date
        << book.publisher << book.publish_date;
    return out;
}

QDataStream &operator>>(QDataStream &in, Book &book)
{
    QString title, author, publisher;
    QUuid book_id, issuer_id;
    QDate issue_date, publish_date;
    bool is_issued;
    in >> book_id >> issuer_id
            >> title >> author
            >> is_issued >> issue_date
            >> publisher >> publish_date;
    book = Book(book_id, issuer_id, title, author, is_issued, issue_date, publisher, publish_date);
    return in;
}

QString Book::status() {
    return is_issued? "Yes" : "No";
}

void Book::Update(QString title, QString author, QString publisher, QDate publish_date) {
    this->title = title;
    this->author = author;
    this->publish_date = publish_date;
    this->publisher = publisher;
}
