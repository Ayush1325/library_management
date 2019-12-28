#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "book.h"
#include "QDate"
#include "abstractstorageclass.h"
#include "filestorage.h"
#include "QStringListModel"
#include "QStandardItemModel"
#include "bookdialog.h"
#include "memberdialog.h"
#include "QDebug"
#include "editbookdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addBookBtn_clicked();

    void on_addMember_clicked();
    void on_bookList_clicked(const QModelIndex &index);

    void on_issueBtn_clicked();

    void on_returnBtn_clicked();

    void on_removeBtn_clicked();

    void on_editBtn_clicked();

    void on_searchBox_textChanged(const QString &arg1);

    void on_searchOption_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    AbstractStorageClass *storage;
    QStandardItemModel *model;
    uint activated_row = 0;
    int searchOptions = 0;
};
#endif // MAINWINDOW_H
