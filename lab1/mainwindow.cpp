#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "fstream"
#include "string"
#include "iostream"
#include "vector"
#include "form.h"
#include "ui_form.h"
using namespace std;



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);




       sndwindow = new Form();
       connect(sndwindow, &Form::firstWindow, this, &MainWindow::show);

       connect(this, SIGNAL(sendText(QString)),sndwindow,SLOT(resirvedText(QString)));




        //фон картинкой
        QPixmap bkgnd("C:/Qt_labs/qt_labs-master/qt_labs-master/lab1/mac1.jpg");
        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonConf_clicked()
{
    DataBase obj;
    QString login  = ui->lineEditLogin->text();
    QString pass  = ui->lineEditPassword->text();

    obj.readPass();

emit sendText(obj.autorize(login, pass));

    QMessageBox note;
   if (obj.autorize(login, pass) == "admin")
   {
        note.setText("You logged as an Admin");
        sndwindow->show(); // Показываем второе окно
        this->close();



   }
   else if(obj.autorize(login, pass) == "user")
   {
       note.setText("You logged as an User");
       sndwindow->show(); // Показываем второе окно
           this->close();

   }

   else if(obj.autorize(login, pass) == "manager")
   {
       note.setText("You logged as a Manager");
       sndwindow->show(); // Показываем второе окно
           this->close();


   }
   else if (obj.autorize(login, pass) == "no")
   {
       note.setText("Login or password is incorrect");
       note.setInformativeText("Do you want to retry?");
       note.setStandardButtons(QMessageBox::Retry | QMessageBox::Close);
       note.setDefaultButton(QMessageBox::Retry);
        ui->lineEditLogin->setText("");
         ui->lineEditPassword->setText("");
   }

   else {

       note.setText("Login or password is incorrect");
       note.setInformativeText("Do you want to retry?");
       note.setStandardButtons(QMessageBox::Retry | QMessageBox::Close);
       note.setDefaultButton(QMessageBox::Retry);
        ui->lineEditLogin->setText("");
         ui->lineEditPassword->setText("");
   }

   int ret = note.exec();
   if(ret == QMessageBox::Close)
   {
       close();
   }


}



