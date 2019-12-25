#ifndef BOOK_H
#define BOOK_H
#include "QString"
#include "QUuid"
#include "QDate"

class Book
{
private:
    QUuid book_id;
    QUuid issuer_id;
    QString title;
    QString author;
    QString publisher;
    QDate publish_date;
    QDate issue_date;
    QDate return_date;
    bool is_issued;

public:
    Book(QString, QString , QString, QDate);

    void Issue(QUuid);

    void Return();
};

#endif // BOOK_H
