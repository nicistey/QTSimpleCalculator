#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
private slots:
    void digits_numbers();

    void on_pushButton_dot_clicked();
    void opertions();
    void on_pushButton_AC_clicked();
    void on_pushButton_equally_clicked();
    //void math_operations();
    void math_operations_plus();
    void math_operations_minus();
    void math_operations_division();
    void math_operations_multiply();
};
#endif // MAINWINDOW_H
