#include "add.h"
#include "ui_add.h"
#include "mainwindow.h"
#include "form.h"
#include "QMessageBox"

add::add(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add)
{
    ui->setupUi(this);

    DataBase obj;
        dataS ob;
        obj.read();
        int k = obj.bdSize();


    BDmodel = new QStandardItemModel(k,3,this);
        ui->tableView->setModel(BDmodel);
        QModelIndex index;
        QStringList list = {"SURNAME", "TELEPHONE", "DATE"};
        BDmodel->QStandardItemModel::setHorizontalHeaderLabels(list);


        for (int col = 0; col < BDmodel->columnCount(); col++)
        {
            int n = 0;
            for (int row = 0; row < BDmodel->rowCount(); row++)
            {
                index = BDmodel->index(row, col);
                 dataS base = obj.zapis(n);
                if (col == 0)
                {

                      string value = base.fio;
                      QString qvalue = QString::fromStdString(value);
                      BDmodel->setData(index, qvalue);
                }
                else if (col == 1)
                {

                    string value = base.tel;
                    QString qvalue = QString::fromStdString(value);
                    BDmodel->setData(index, qvalue);

                }
                else
                {
                    string value = base.date;
                    QString qvalue = QString::fromStdString(value);
                    BDmodel->setData(index, qvalue);

                }

                n++;
            }

        }



    // фон картинкой
    QPixmap bkgnd("C:/Qt_labs/qt_labs-master/qt_labs-master/lab1/mac1.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

add::~add()
{
    delete ui;
}

void add::on_pushButtonBack_clicked()
{
    this->close();      // Закрываем окно
    emit secondWindow();
    ui->lfio->setText("");
    ui->ltel->setText("");
}

void add::on_pushButtonAdd_clicked()
{
    dataS ob1;
    DataBase obj1;

    obj1.read();

    QMessageBox note;
    QString fio  = ui->lfio->text();
    QString tel  = ui->ltel->text();
    QString date = ui->dateEdit->text();

    string rightFio = fio.toStdString();
    string rightTel = tel.toStdString();
     string rightDate = date.toStdString();

    if(obj1.checkFio(rightFio) == "no!")
    {
       note.setText("your name must be all letters.");
       note.setStandardButtons(QMessageBox::Ok);
    }
    else{

        if (obj1.checkTel(rightTel) == 0)
        {
            note.setText("Your number should consist of only 10 digits.");
            note.setStandardButtons(QMessageBox::Ok);
        }
        else{

            if (obj1.dateCheck(rightDate) == 0)
            {
                note.setText("Invalid date parameter.");
                note.setStandardButtons(QMessageBox::Ok);
            }
            else {

    ob1.fio =  obj1.checkFio(rightFio);
    ob1.tel =  tel.toStdString();
    ob1.date = rightDate;

    if ((obj1.add(ob1)) == 1)
    {

        obj1.write();
        note.setText("You have successfully added data!");
       ui->lfio->setText("");
       ui->ltel->setText("");

      // obj1.getV();
       obj1.read();
       int k = obj1.bdSize();
       BDmodel = new QStandardItemModel(k,3,this);
       ui->tableView->setModel(BDmodel);

       QModelIndex index;
       QStringList list = {"SURNAME", "TELEPHONE", "DATE"};
       BDmodel->QStandardItemModel::setHorizontalHeaderLabels(list);



       for (int col = 0; col < BDmodel->columnCount(); col++)
       {
           int n = 0;
           for (int row = 0; row < BDmodel->rowCount(); row++)
           {
               index = BDmodel->index(row, col);
                dataS base = obj1.zapis(n);
               if (col == 0)
               {

                     string value = base.fio;
                     QString qvalue = QString::fromStdString(value);
                     BDmodel->setData(index, qvalue);
               }
               else if (col == 1)
               {

                   string value = base.tel;
                   QString qvalue = QString::fromStdString(value);
                   BDmodel->setData(index, qvalue);

               }
               else
               {
                   string value = base.date;
                   QString qvalue = QString::fromStdString(value);
                   BDmodel->setData(index, qvalue);

               }

               n++;
           }

        }
    }
    else
    {
        note.setText("Data is incorrect");
            note.setInformativeText("Do you want to retry?");
            note.setStandardButtons(QMessageBox::Retry | QMessageBox::Close);
            note.setDefaultButton(QMessageBox::Retry);

    }


}

}

}


     int ret = note.exec();
}




void add::on_pushButtonR_clicked()
{
    dataS ob1;
    DataBase obj1;
    obj1.read();
    int k = obj1.bdSize();
    BDmodel = new QStandardItemModel(k,3,this);
    ui->tableView->setModel(BDmodel);
    QStringList list = {"SURNAME", "TELEPHONE", "DATE"};
    BDmodel->QStandardItemModel::setHorizontalHeaderLabels(list);

    QModelIndex index;



    for (int col = 0; col < BDmodel->columnCount(); col++)
    {
        int n = 0;
        for (int row = 0; row < BDmodel->rowCount(); row++)
        {
            index = BDmodel->index(row, col);
             dataS base = obj1.zapis(n);
            if (col == 0)
            {

                  string value = base.fio;
                  QString qvalue = QString::fromStdString(value);
                  BDmodel->setData(index, qvalue);
            }
            else if (col == 1)
            {

                string value = base.tel;
                QString qvalue = QString::fromStdString(value);
                BDmodel->setData(index, qvalue);

            }
            else
            {
                string value = base.date;
                QString qvalue = QString::fromStdString(value);
                BDmodel->setData(index, qvalue);

            }

            n++;
        }

     }


}
