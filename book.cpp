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

Book::Book(QUuid book_id, QUuid issuer_id, QString title, QString author, bool is_issued, QDate issue_date, QString publisher, QDate return_date, QDate publish_date) {
    this->book_id = book_id;
    this->issuer_id = issuer_id;
    this->title = title;
    this->author = author;
    this->is_issued = is_issued;
    this->issue_date = issue_date;
    this->publisher = publisher;
    this->return_date = return_date;
    this->publish_date = publish_date;
}

void Book::Issue(QUuid id) {
    this->issue_date = QDate::currentDate();
    this->is_issued = true;
    this->issuer_id = id;
}

void Book::Return() {
    this->return_date = QDate::currentDate();
    this->is_issued = false;
}

QList<QStandardItem*> Book::returnItem() {
    QStandardItem* title = new QStandardItem(this->title);
    QStandardItem* publisher = new QStandardItem(this->publisher);
    QStandardItem* book_id = new QStandardItem(this->book_id.toString());
    QStandardItem* author = new QStandardItem(this->author);

    QList<QStandardItem*> temp;
    temp << book_id << title << author << publisher;
    return temp;
}

QDataStream &operator<<(QDataStream &out, const Book &book)
{
    out << book.book_id.toString() << book.issuer_id.toString()
        << book.title << book.author
        << book.is_issued << book.issue_date
        << book.publisher << book.return_date
        << book.publish_date;
    return out;
}

QDataStream &operator>>(QDataStream &in, Book &book)
{
    QString title, author, publisher, b, i;
    QUuid book_id, issuer_id;
    QDate issue_date, return_date, publish_date;
    bool is_issued;
    in >> b >> i
            >> title >> author
            >> is_issued >> issue_date
            >> publisher >> return_date
            >> publish_date;
    book_id = QUuid::fromString(b);
    issuer_id = QUuid::fromString(i);
    book = Book(book_id, issuer_id, title, author, is_issued, issue_date, publisher, return_date, publish_date);
    return in;
}
