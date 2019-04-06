#include "sor1t.h"
#include "ui_sor1t.h"
#include "form.h"
#include "QMessageBox"
#include "fstream"
#include "string"
#include "iostream"
#include "vector"
#include "mainwindow.h"

sor1t::sor1t(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sor1t)
{
    ui->setupUi(this);
    // фон картинкой
    QPixmap bkgnd("C:/Qt_labs/qt_labs-master/qt_labs-master/lab1/mac1.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

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




}

sor1t::~sor1t()
{
    delete ui;
}

void sor1t::on_pushButton_clicked()
{
    this->close();      // Закрываем окно
    emit secondWindow();
}

void sor1t::on_bok_clicked()
{

    QMessageBox note;
    DataBase obj;
    dataS ob;
    obj.read();

    QString fio  = ui->lfio->text();
    QString tel  = ui->ltel->text();
    QString id  = ui->lid->text();
    QString date = ui->dateEdit->text();

    string rightDate = date.toStdString();
    string rightFio = fio.toStdString();
    string rightTel = tel.toStdString();

    ob.fio = rightFio;
      ob.date = rightDate;
        ob.tel = rightTel;

    bool chk1 = ui->checkBox_2->isChecked();
     bool chk2 = ui->checkBox_3->isChecked();
      bool chk3 = ui->checkBox_4->isChecked();

     if (obj.sort(ob, chk1, chk2, chk3) == 1)

{
      int k = obj.sortBdSize();
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
               dataS base = obj.zapis_sort(n);
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
     else{

         note.setText("Nothing was found by the given parameters!");
         note.setStandardButtons(QMessageBox::Ok);
        int ret = note.exec();
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





     }




}
