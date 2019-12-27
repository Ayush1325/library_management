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

public:
    Book();
    Book(QString, QString , QString, QDate);
    Book(QUuid, QUuid, QString, QString, bool, QDate, QString, QDate);

    void Issue(QUuid);

    void Return();

    QList<QStandardItem*> returnItem();

    friend QDataStream &operator<<(QDataStream &out, const Book &book);
    friend QDataStream &operator>>(QDataStream &in, Book &book);
};

#endif // BOOK_H
