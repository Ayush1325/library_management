#ifndef MEMBERDIALOG_H
#define MEMBERDIALOG_H

#include <QDialog>
#include "abstractstorageclass.h"

namespace Ui {
class MemberDialog;
}

class MemberDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MemberDialog(QWidget *parent, AbstractStorageClass *storage);
    ~MemberDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::MemberDialog *ui;
    AbstractStorageClass *storage;
};

#endif // MEMBERDIALOG_H
