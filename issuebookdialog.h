#ifndef ISSUEBOOKDIALOG_H
#define ISSUEBOOKDIALOG_H

#include <QDialog>
#include "abstractstorageclass.h"
#include "QCompleter"
#include "QMessageBox"

namespace Ui {
class IssueBookDialog;
}

class IssueBookDialog : public QDialog
{
    Q_OBJECT

public:
    explicit IssueBookDialog(QWidget *parent, QStandardItemModel *model, AbstractStorageClass *storage, int pos);
    ~IssueBookDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::IssueBookDialog *ui;
    QStandardItemModel *model;
    AbstractStorageClass *storage;
    int pos;
    QStringList members;
};

#endif // ISSUEBOOKDIALOG_H
