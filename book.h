#ifndef BOOK_H
#define BOOK_H
#include "QString"
#include "QUuid"
#include "QDate"
#include "QStandardItem"

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
    bool is_issued;

    QString status();

public:
    Book();
    Book(QString, QString , QString, QDate);
    Book(QUuid, QUuid, QString, QString, bool, QDate, QString, QDate);

    void Issue(QUuid);

    void Return();

    QList<QStandardItem*> returnItem();

    QUuid getBookId() {return book_id;}

    void Update(QString, QString, QString, QDate);

    friend QDataStream &operator<<(QDataStream &out, const Book &book);
    friend QDataStream &operator>>(QDataStream &in, Book &book);
};

#endif // BOOK_H
