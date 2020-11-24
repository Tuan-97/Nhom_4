#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

    int convertdate(std::string);

private slots:
    void on_CreateOrder_clicked();

    void on_AddProduct_clicked();

    void on_DoneOrder_clicked();

    void on_Try_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
