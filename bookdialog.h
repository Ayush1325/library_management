#ifndef BOOKDIALOG_H
#define BOOKDIALOG_H

#include <QDialog>
#include "abstractstorageclass.h"

namespace Ui {
class BookDialog;
}

class BookDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BookDialog(QWidget *parent, AbstractStorageClass *storage, QStandardItemModel *model);
    ~BookDialog();

private slots:
    void on_basicActions_accepted();

private:
    Ui::BookDialog *ui;
    AbstractStorageClass *storage;
    QStandardItemModel *model;
};

#endif // BOOKDIALOG_H
