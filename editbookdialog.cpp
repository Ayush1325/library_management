#include "editbookdialog.h"
#include "ui_editbookdialog.h"

EditBookDialog::EditBookDialog(QWidget *parent, AbstractStorageClass *storage, QStandardItemModel *model, int pos) :
    QDialog(parent),
    ui(new Ui::EditBookDialog)
{
    ui->setupUi(this);
    this->model = model;
    this->pos = pos;
    this->storage = storage;
    QList<QStandardItem*> temp;
    for (int i = 0; i < 5; ++i) {
        temp.append(this->model->item(pos, i));
    }
    this->id = QUuid::fromString(temp.at(0)->text());
    ui->title->setText(temp.at(1)->text());
    ui->author->setText(temp.at(2)->text());
    ui->publisher->setText(temp.at(3)->text());
    ui->publlishDate->setDate(QDate::fromString(temp.at(4)->text()));
}

EditBookDialog::~EditBookDialog()
{
    delete ui;
}

void EditBookDialog::on_buttonBox_accepted()
{
    auto temp = [=](Book &b) {b.Update(ui->title->text(), ui->author->text(), ui->publisher->text(), ui->publlishDate->date());};
    Book b = this->storage->editBook(this->id, temp);
    this->model->takeRow(this->pos);
    this->model->insertRow(this->pos, b.returnItem());
}
