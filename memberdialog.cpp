#include "memberdialog.h"
#include "ui_memberdialog.h"

MemberDialog::MemberDialog(QWidget *parent, AbstractStorageClass *storage) :
    QDialog(parent),
    ui(new Ui::MemberDialog)
{
    ui->setupUi(this);
    this->storage = storage;
}

MemberDialog::~MemberDialog()
{
    delete ui;
}

void MemberDialog::on_buttonBox_accepted()
{
    Person person(ui->name->text(), ui->address->toPlainText(), ui->phoneNo->text());
    this->storage->addPerson(&person);
}
