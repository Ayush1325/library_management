#include "bookdialog.h"
#include "ui_bookdialog.h"

BookDialog::BookDialog(QWidget *parent, AbstractStorageClass *storage, QStandardItemModel *model) :
    QDialog(parent),
    ui(new Ui::BookDialog)
{
    ui->setupUi(this);
    this->storage = storage;
    this->model = model;
}

BookDialog::~BookDialog()
{
    delete ui;
}

void BookDialog::on_basicActions_accepted()
{
    Book book(ui->title->text(), ui->author->text(), ui->pulisher->text(), ui->publishDate->date());
    this->storage->addBook(&book);
    this->model->appendRow(book.returnItem());
}
