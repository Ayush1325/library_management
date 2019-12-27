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

private:
    Ui::MainWindow *ui;
    AbstractStorageClass *storage;
    QStandardItemModel *model;
};
#endif // MAINWINDOW_H
