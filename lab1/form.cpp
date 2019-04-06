#include "form.h"
#include "ui_form.h"
#include "mainwindow.h"
#include "QMessageBox"
#include "fstream"
#include "string"
#include "iostream"
#include "vector"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);


    changeW = new Change();
    connect(changeW, &Change::secondWindow, this, &Form::show);

    changeWD = new changeD();
    connect(changeWD, &changeD::secondWindow, this, &Form::show);

    addW = new add();
    connect(addW, &add::secondWindow, this, &Form::show);

    delW = new del();
    connect(delW, &del::secondWindow, this, &Form::show);

    checkW = new check();
    connect(checkW, &check::secondWindow, this, &Form::show);

    sor1tW = new sor1t();
    connect(sor1tW, &sor1t::secondWindow, this, &Form::show);



    // фон картинкой
    QPixmap bkgnd("C:/Qt_labs/qt_labs-master/qt_labs-master/lab1/mac1.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    checkW = new check();
    connect(checkW, &check::secondWindow, this, &Form::show);

    connect(this, SIGNAL(sendTextToCheck(QString)),checkW,SLOT(resirvedTextCheck(QString)));


}

Form::~Form()
{
    delete ui;
}

void Form::resirvedText(QString str)
{
    ui->labelSt->setText(str);

}



void Form::on_pushButtonBack_clicked()
{

    this->close();      // Закрываем окно
    emit firstWindow();

}

void Form::on_pushButton_clicked()
{
    changeW->show(); // Показываем 3e окно
        this->close();
}


void Form::on_pushButtonCD_clicked()
{
     QMessageBox note;
    QString qstatus  = ui->labelSt->text();


    if (qstatus != "admin")
    {
        note.setText("You do not have access to this function!");
        note.setStandardButtons(QMessageBox::Ok);
         int ret = note.exec();

    }
    else{
    changeWD->show(); // Показываем 4e окно
        this->close();
    }


}

void Form::on_pushButtonAdd_clicked()
{
    QMessageBox note;
   QString qstatus  = ui->labelSt->text();


   if (qstatus != "admin")
   {
       note.setText("You do not have access to this function!");
       note.setStandardButtons(QMessageBox::Ok);
        int ret = note.exec();

   }
   else{
    addW->show();
    this->close();
   }
}

void Form::on_pushButtonDel_clicked()
{
    QMessageBox note;
   QString qstatus  = ui->labelSt->text();


   if (qstatus != "admin")
   {
       note.setText("You do not have access to this function!");
       note.setStandardButtons(QMessageBox::Ok);
        int ret = note.exec();

   }
   else{
    delW->show();
    this->close();
   }
}


void Form::on_pushButton_4_clicked()
{
    QMessageBox note;
    QString qstatus  = ui->labelSt->text();
    if (qstatus == "user")
    {
        note.setText("You do not have access to this function!");
        note.setStandardButtons(QMessageBox::Ok);
         int ret = note.exec();

    }
    else{


        emit sendTextToCheck(qstatus);

        checkW->show(); // Показываем 5e окно
            this->close();

    }






 }

void Form::on_pushButton_5_clicked()
{
    sor1tW->show(); // Показываем 5e окно
        this->close();
}
