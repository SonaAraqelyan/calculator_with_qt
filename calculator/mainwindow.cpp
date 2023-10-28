#include "mainwindow.h"
#include "ui_mainwindow.h"

double first;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->zero,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->one,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->two,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->three,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->four,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->five,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->six,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->seven,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->eight,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->nine,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->plus_minus,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->persent,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->persent,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->plus,SIGNAL(clicked()),this,SLOT(main_operations()));
    connect(ui->minus,SIGNAL(clicked()),this,SLOT(main_operations()));
    connect(ui->division,SIGNAL(clicked()),this,SLOT(main_operations()));
    connect(ui->multiplication,SIGNAL(clicked()),this,SLOT(main_operations()));

    ui->multiplication->setCheckable(true);
    ui->division->setCheckable(true);
    ui->plus->setCheckable(true);
    ui->minus->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers(){
    QPushButton *button = (QPushButton *)sender();
    double all_numbers;
    QString new_label;

    if(ui->label->text().contains('.') && button->text()=="0"){
        //ui->label->setText("");
        new_label = ui->label->text() + button->text();
    }else{
        //ui->label->setText("");
        all_numbers = (ui->label->text() + button->text()).toDouble();
        new_label=QString::number(all_numbers,'g',7);
        ui->label->setText(new_label);
    }

}

void MainWindow::operations(){
    QPushButton *button = (QPushButton *)sender();
    double all_numbers;
    QString new_label;
    if(button->text()=="+/-"){
        all_numbers = (ui->label->text()).toDouble();
        all_numbers=all_numbers*(-1);
        new_label=QString::number(all_numbers,'g',7);
        ui->label->setText(new_label);
    }else if(button->text()=="%"){
        all_numbers = (ui->label->text()).toDouble();
        all_numbers=all_numbers/10;
        new_label=QString::number(all_numbers,'g',7);
        ui->label->setText(new_label);
    }
}

void MainWindow::main_operations(){
    QPushButton *button = (QPushButton *)sender();
    first = ui->label->text().toDouble();
    ui->label->setText("");
    button->setChecked(true);
}

void MainWindow::on_point_clicked()
{
    if(!ui->label->text().contains('.')){
       ui->label->setText(ui->label->text() + '.');
    }

}


void MainWindow::on_clear_clicked()
{
    ui->minus->setChecked(false);
    ui->plus->setChecked(false);
    ui->division->setChecked(false);
    ui->multiplication->setChecked(false);

    ui->label->setText("0");
}


void MainWindow::on_equal_clicked()
{
    double label_num;
    double second;
    QString new_label;

    second = ui->label->text().toDouble();

    if(ui->plus->isChecked()){
       label_num = first + second;
       new_label=QString::number(label_num,'g',7);
       ui->label->setText(new_label);
       ui->plus->setChecked(false);
    }else if(ui->minus->isChecked()){
       label_num = first - second;
       new_label=QString::number(label_num,'g',7);
       ui->label->setText(new_label);
       ui->minus->setChecked(false);
    }else if(ui->division->isChecked()){
       if(second==0){
           ui->label->setText("0");
       }else{
        label_num = first / second;
        new_label=QString::number(label_num,'g',7);
        ui->label->setText(new_label);
       }
       ui->division->setChecked(false);
    }else if(ui->multiplication->isChecked()){
       label_num = first * second;
       new_label=QString::number(label_num,'g',7);
       ui->label->setText(new_label);
       ui->multiplication->setChecked(false);
    }
}

