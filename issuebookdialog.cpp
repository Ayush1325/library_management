#include "issuebookdialog.h"
#include "ui_issuebookdialog.h"

IssueBookDialog::IssueBookDialog(QWidget *parent, QStandardItemModel *model, AbstractStorageClass *storage, int pos) :
    QDialog(parent),
    ui(new Ui::IssueBookDialog)
{
    ui->setupUi(this);
    this->model = model;
    this->storage = storage;
    this->pos = pos;
    QStringList suggestions = this->storage->getAllMemberIds();
    this->members = suggestions;
    QCompleter *completer = new QCompleter(suggestions, this);
    completer->setCaseSensitivity(Qt::CaseSensitive);
    ui->id->setCompleter(completer);
}

IssueBookDialog::~IssueBookDialog()
{
    delete ui;
}

void IssueBookDialog::on_buttonBox_accepted()
{
    if(this->members.contains(ui->id->text())) {
        QUuid issuer_id = QUuid::fromString(ui->id->text());
        QUuid book_id = QUuid::fromString(this->model->item(pos)->text());
        auto func = [=](Book &b){b.Issue(issuer_id);};
        Book b = this->storage->editBook(book_id, func);
        this->model->removeRow(this->pos);
        this->model->insertRow(this->pos, b.returnItem());
    }
    else {
        QMessageBox::warning(this, "Error", "Invalid Member");
    }
}
