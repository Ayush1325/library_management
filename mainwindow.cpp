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
    titles << "Book Id" << "Title" << "Author" << "Publisher";

    this->model = new QStandardItemModel();
    this->model->setHorizontalHeaderLabels(titles);

    QList<Book> books = this->storage->getAllBooks();

    for (int i = 0; i < books.size(); ++i) {
        Book temp = books.at(i);
        QList<QStandardItem*> t = temp.returnItem();
        this->model->appendRow(t);
    }

    ui->bookList->setModel(this->model);
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
