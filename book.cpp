#include "book.h"

Book::Book(QString title, QString author, QString publisher, QDate publish_date)
{
    this->title = title;
    this->author = author;
    this->publisher = publisher;
    this->publish_date = publish_date;
    this->book_id = QUuid::createUuid();
    this->is_issued = false;
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
