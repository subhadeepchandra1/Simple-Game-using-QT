#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
#include<QMessageBox>
#include<stdlib.h>
#include<time.h>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    srand(time(NULL));

    ui->messageLabel->setText("");
    secretNumber=rand()%10+1;
    qDebug()<<"Secret number generated: "<<QString::number(secretNumber);
    ui->startOverButton->setDisabled(true);
}

Widget::~Widget()
{
    delete ui;
}

/*void Widget::on_pushButton_clicked()
{
    qDebug()<<"User clicked on a button";
    QMessageBox::information(this,"Message","You have clicked",QMessageBox::Ok);
}*/

void Widget::on_guessButton_clicked()
{
    guessNumber=ui->spinBox->value();
    qDebug()<<"Guess number generated: "<<QString::number(guessNumber);

    if(guessNumber==secretNumber)
    {
        ui->messageLabel->setText("Congratulations number is "+QString::number(secretNumber));

        ui->guessButton->setDisabled(true);
        ui->startOverButton->setDisabled(false);
    }
    else
    {
        if(secretNumber<guessNumber)
        {
            ui->messageLabel->setText("Number is lower than that.");
        }
        else
        {
            ui->messageLabel->setText("Number is greater than that.");
        }
    }
}

void Widget::on_startOverButton_clicked()
{
    ui->messageLabel->setText("");
    secretNumber=rand()%10+1;
    qDebug()<<"Secret number generated: "<<QString::number(secretNumber);
    ui->startOverButton->setDisabled(true);
    ui->guessButton->setDisabled(false);
    ui->spinBox->setValue(1);
}
