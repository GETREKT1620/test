#include "change.h"
#include "ui_change.h"
#include "mainwindow.h"
#include "form.h"
#include "QMessageBox"
#include "fstream"
#include "string"
#include "iostream"
#include "vector"
Change::Change(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Change)
{
    ui->setupUi(this);


    // фон картинкой
    QPixmap bkgnd("C:/Qt_labs/qt_labs-master/qt_labs-master/lab1/mac1.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

}

Change::~Change()
{
    delete ui;
}

void Change::on_pushButton_clicked()
{
    this->close();      // Закрываем окно
    emit secondWindow();
    ui->oldLog->setText("");
     ui->oldPass->setText("");
     ui->newLog->setText("");
      ui->newPass->setText("");

}

void Change::on_pushButton_3_clicked()
{
    QMessageBox note;

    DataBase obj;
    dataPass ob;
    dataPass ob1;

    QString ologin  = ui->oldLog->text();
    QString opass  = ui->oldPass->text();
    QString nlogin  = ui->newLog->text();
    QString npass  = ui->newPass->text();

     ob.login =  ologin.toStdString();
     ob.pass =  opass.toStdString();
     ob1.login = nlogin.toStdString();
     ob1.pass = npass.toStdString();
     obj.readPass();

    if ((obj.changePass(ob, ob1)) == 1)
    {
         obj.writePass();
         note.setText("Нou have successfully changed your password!");
         ui->oldLog->setText("");
          ui->oldPass->setText("");
          ui->newLog->setText("");
           ui->newPass->setText("");

           this->close();      // Закрываем окно
           emit secondWindow();
    }
    else
    {
        note.setText("Old login or password is incorrect");
        note.setInformativeText("Do you want to retry?");
        note.setStandardButtons(QMessageBox::Retry | QMessageBox::Close);
        note.setDefaultButton(QMessageBox::Retry);
    }

    int ret = note.exec();
    if(ret == QMessageBox::Close)
    {
        close();
    }

}
