#include "mainwindow.h"
#include "ui_mainwindow.h"

//первый введеное число
double num_first;

//проверка на двойное нажатие мат операции......
//(например если ввели число, после нажали на знак мат операции, и еще раз нажали на знак мат операции до знака равно)
bool already_pressed_math_operations = false;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton__plus_minus,SIGNAL(clicked()),this,SLOT(opertions()));
    connect(ui->pushButton_percent,SIGNAL(clicked()),this,SLOT(opertions()));
    connect(ui->pushButton_division,SIGNAL(clicked()),this,SLOT(math_operations_division()));
    connect(ui->pushButton_multiply,SIGNAL(clicked()),this,SLOT(math_operations_multiply()));
    connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(math_operations_plus()));
    connect(ui->pushButton_minus,SIGNAL(clicked()),this,SLOT(math_operations_minus()));

    ui->pushButton_division->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_multiply->setCheckable(true);
    ui->pushButton_plus->setCheckable(true);
    ui->result_show->setText("0");
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::digits_numbers()
{
    QPushButton *button = static_cast<QPushButton*>(sender());
    double all_numbers;
    QString new_label;
    if(ui->result_show->text().contains(".")&&button->text()=="0")
    {
        new_label = ui->result_show->text() + button->text();
    }
    else
    {
        all_numbers = (ui->result_show->text() + button->text()).toDouble();
        new_label = QString::number(all_numbers, 'g',15);
    }

    ui->result_show->setText(new_label);
}

void MainWindow::on_pushButton_dot_clicked()
{
    if(!(ui->result_show->text().contains('.')))
    {
        ui->result_show->setText(ui->result_show->text()+".");

    }

}

void MainWindow::opertions()
{
    QPushButton *button = static_cast<QPushButton*>(sender());
    double all_numbers;
    QString new_label;

    if(button->text()=="+/-")
    {
        all_numbers = (ui->result_show->text()).toDouble();
        all_numbers = all_numbers*-1;
        new_label = QString::number(all_numbers, 'g',15);
        ui->result_show->setText(new_label);
    }
    else if(button->text()=="%")
    {
        all_numbers = (ui->result_show->text()).toDouble();
        all_numbers = all_numbers*0.01;
        new_label = QString::number(all_numbers, 'g',15);
        ui->result_show->setText(new_label);
    }
}

void MainWindow::math_operations_plus()
{
    ui->pushButton_division->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_multiply->setChecked(false);

    //QPushButton *button = static_cast<QPushButton*>(sender());
    if(!already_pressed_math_operations)
    {
        num_first = ui->result_show->text().toDouble();
    }

    ui->result_show->setText("");
    ui->pushButton_plus->setChecked(true);

    //история ввода
    QString labelHistory;

    labelHistory = QString::number(num_first, 'g',15);
    labelHistory += "+";
    ui->input_history->setText(labelHistory);
    already_pressed_math_operations = true;//мат операция нажата

}

void MainWindow::math_operations_minus()
{
    ui->pushButton_division->setChecked(false);
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_multiply->setChecked(false);

    //QPushButton *button = static_cast<QPushButton*>(sender());
    if(!already_pressed_math_operations)
    {
        num_first = ui->result_show->text().toDouble();
    }

    ui->result_show->setText("");
    ui->pushButton_minus->setChecked(true);

    //история ввода
    QString labelHistory;

    labelHistory = QString::number(num_first, 'g',15);
    labelHistory += "-";
    ui->input_history->setText(labelHistory);
    already_pressed_math_operations = true;//мат операция нажата

}

void MainWindow::math_operations_division()
{
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_multiply->setChecked(false);

    //QPushButton *button = static_cast<QPushButton*>(sender());
    if(!already_pressed_math_operations)
    {
        num_first = ui->result_show->text().toDouble();
    }

    ui->result_show->setText("");
    ui->pushButton_division->setChecked(true);

    //история ввода
    QString labelHistory;

    labelHistory = QString::number(num_first, 'g',15);
    labelHistory += "/";
    ui->input_history->setText(labelHistory);
    already_pressed_math_operations = true;//мат операция нажата

}

void MainWindow::math_operations_multiply()
{
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_division->setChecked(false);

    //QPushButton *button = static_cast<QPushButton*>(sender());
    if(!already_pressed_math_operations)
    {
        num_first = ui->result_show->text().toDouble();
    }

    ui->result_show->setText("");
    ui->pushButton_multiply->setChecked(true);

    //история ввода
    QString labelHistory;

    labelHistory = QString::number(num_first, 'g',15);
    labelHistory += "*";
    ui->input_history->setText(labelHistory);
    already_pressed_math_operations = true;//мат операция нажата

}

/*
void MainWindow::math_operations()
{
    if (!already_pressed_math_operations)
    {
        QPushButton *button = static_cast<QPushButton*>(sender());
        num_first = ui->result_show->text().toDouble();
        ui->result_show->setText("");


        button->setChecked(true);

        //история ввода
        QString labelHistory;
        if(ui->pushButton_plus->isChecked())
        {
            labelHistory = QString::number(num_first, 'g',15);
            labelHistory += "+";
            ui->input_history->setText(labelHistory);
            already_pressed_math_operations = true;//мат операция нажата
        }
        else if(ui->pushButton_multiply->isChecked())
        {
            labelHistory = QString::number(num_first, 'g',15);
            labelHistory += "*";
            ui->input_history->setText(labelHistory);
            already_pressed_math_operations = true;//мат операция нажата
        }
        else if(ui->pushButton_minus->isChecked())
        {
            labelHistory = QString::number(num_first, 'g',15);
            labelHistory += "-";
            ui->input_history->setText(labelHistory);
            already_pressed_math_operations = true;//мат операция нажата
        }
        else if(ui->pushButton_division->isChecked())
        {
            labelHistory = QString::number(num_first, 'g',15);
            labelHistory += "/";
            ui->input_history->setText(labelHistory);
            already_pressed_math_operations = true;//мат операция нажата
        }
    }



}
*/

void MainWindow::on_pushButton_AC_clicked()
{
    ui->pushButton_division->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_multiply->setChecked(false);
    ui->pushButton_plus->setChecked(false);
    already_pressed_math_operations = false;

    ui->result_show->setText("0");
    ui->input_history->setText("");
}


void MainWindow::on_pushButton_equally_clicked()
{
    already_pressed_math_operations = false;
    double labelNumber, num_second;
    QString new_label;
    num_second = ui->result_show->text().toDouble();
    if(ui->pushButton_plus->isChecked())
    {
        ui->input_history->setText("");
        labelNumber = num_first+num_second;
        new_label = QString::number(labelNumber, 'g',15);
        ui->result_show->setText(new_label);
        ui->pushButton_plus->setChecked(false);
    }
    else if(ui->pushButton_multiply->isChecked())
    {
        ui->input_history->setText("");
        labelNumber = num_first*num_second;
        new_label = QString::number(labelNumber, 'g',15);
        ui->result_show->setText(new_label);
        ui->pushButton_multiply->setChecked(false);
    }
    else if(ui->pushButton_minus->isChecked())
    {
        ui->input_history->setText("");
        labelNumber = num_first-num_second;
        new_label = QString::number(labelNumber, 'g',15);
        ui->result_show->setText(new_label);
        ui->pushButton_minus->setChecked(false);
    }
    else if(ui->pushButton_division->isChecked())
    {
        if(num_second == 0)
        {
            ui->input_history->setText("");
            ui->result_show->setText("невозможно");
        }
        else
        {
            ui->input_history->setText("");
            labelNumber = num_first/num_second;
            new_label = QString::number(labelNumber, 'g',15);
            ui->result_show->setText(new_label);
            ui->pushButton_division->setChecked(false);
        }

    }
}

