#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "table.h"
#include <QMainWindow>
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Table TableCustomer;
    Table TableCategories;
    Table TableEmployees;
    Table TableOrderDetails;
    Table TableOrders;
    Table TableProducts;
    Table TableShippers;
    Table TableSuppliers;
private slots:
    void on_CreateOrder_clicked();

    void on_AddProduct_clicked();

    void on_DoneOrder_clicked();

    void on_Try_clicked();

    void on_Change_12_clicked();

    void on_Delete_clicked();

    void on_Delete_6_clicked();

    void on_Change_clicked();

    void on_Add_clicked();

    void on_ReportStoreWeek_clicked();

    void on_Store_clicked();

    void on_Change_4_clicked();

    void on_Store_2_clicked();

    void on_Store_3_clicked();

    void on_Change_9_clicked();

    void on_Add_4_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
