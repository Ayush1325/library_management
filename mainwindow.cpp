#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->storage = new FileStorage(this);
    this->storage->checkStorage();

    QStringList titles;
    titles << "Book Id" << "Title" << "Author" << "Publisher" << "Publish Date" << "Available";

    this->model = new QStandardItemModel();
    this->model->setHorizontalHeaderLabels(titles);

    QList<Book> books = this->storage->getAllBooks();

    for (int i = 0; i < books.size(); ++i) {
        Book temp = books.at(i);
        QList<QStandardItem*> t = temp.returnItem();
        this->model->appendRow(t);
    }
    ui->bookList->setModel(this->model);
    ui->issueBtn->setEnabled(false);
    ui->returnBtn->setEnabled(false);
    ui->editBtn->setEnabled(false);
    ui->removeBtn->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete storage;
    delete model;
}


void MainWindow::on_addBookBtn_clicked()
{
    BookDialog book_dialog(this, this->storage, this->model);
    book_dialog.setModal(true);
    book_dialog.exec();
}

void MainWindow::on_addMember_clicked()
{
    MemberDialog dialog(this, this->storage);
    dialog.setModal(true);
    dialog.exec();
}


void MainWindow::on_bookList_clicked(const QModelIndex &index)
{
    QStandardItem* temp = this->model->item(index.row(), 4);
    if(temp->text() == "Yes") {
        ui->issueBtn->setEnabled(true);
        ui->returnBtn->setEnabled(false);
    }
    else {
        ui->returnBtn->setEnabled(true);
        ui->issueBtn->setEnabled(false);
    }
    ui->removeBtn->setEnabled(true);
    ui->editBtn->setEnabled(true);
    this->activated_row = index.row();
}

void MainWindow::on_issueBtn_clicked()
{
    QUuid id = QUuid::fromString(this->model->item(this->activated_row)->text());
//    this->storage->editBook(id, [](Book &obj) {obj.Issue(QUuid::fromString('123'));});
}

void MainWindow::on_returnBtn_clicked()
{

}

void MainWindow::on_removeBtn_clicked()
{
    QUuid id = QUuid::fromString(this->model->item(this->activated_row)->text());
    this->storage->removeBook(id);
    this->model->removeRow(this->activated_row);
}

void MainWindow::on_editBtn_clicked()
{
    EditBookDialog dialog(this, this->storage, this->model, this->activated_row);
    dialog.setModal(true);
    dialog.exec();
}

void MainWindow::on_searchBox_textChanged(const QString &arg1)
{
    QList<QStandardItem*> temp = this->model->findItems(arg1, Qt::MatchFlag::MatchContains, this->searchOptions);
    for(int i = 0; i < temp.size(); ++i) {
        QStandardItem* t = temp.at(i);
        QList<QStandardItem*> l = this->model->takeRow(t->row());
        this->model->insertRow(0, l);
    }
}

void MainWindow::on_searchOption_currentIndexChanged(int index)
{
    this->searchOptions = index;
}
