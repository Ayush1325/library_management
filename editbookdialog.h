#ifndef EDITBOOKDIALOG_H
#define EDITBOOKDIALOG_H

#include <QDialog>
#include "abstractstorageclass.h"

namespace Ui {
class EditBookDialog;
}

class EditBookDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditBookDialog(QWidget *parent, AbstractStorageClass *storage, QStandardItemModel *model, int pos);
    ~EditBookDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::EditBookDialog *ui;
    AbstractStorageClass *storage;
    QStandardItemModel *model;
    int pos;
    QUuid id;
};

#endif // EDITBOOKDIALOG_H
