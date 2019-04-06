#include "changed.h"
#include "ui_changed.h"
#include "mainwindow.h"
#include "form.h"
#include "QMessageBox"
#include "fstream"
#include "string"
#include "iostream"
#include "vector"
changeD::changeD(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::changeD)
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

changeD::~changeD()
{
    delete ui;
}

void changeD::on_pushButton_clicked()
{
    this->close();      // Закрываем окно
    emit secondWindow();
    ui->lfio->setText("");
     ui->ltel->setText("");

      ui->lid->setText("");
}

void changeD::on_bok_clicked()
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

    if (id  == "")
        {
            note.setText("You must first enter the ID");
            note.setStandardButtons(QMessageBox::Ok);
        }
        else{
        if ((rightFio == "") && (rightTel == "") && (( ui->radioButton->isChecked()) == 0))
        {
            note.setText("There is no data to add!");
            note.setStandardButtons(QMessageBox::Ok);
        }
        else
        {

        if((obj.checkFio(rightFio) == "no!") && (rightFio != ""))
        {
           note.setText("your name must be all letters.");
           note.setStandardButtons(QMessageBox::Ok);
        }
        else{

        if ((obj.checkTel(rightTel) == 0) && (rightTel != ""))
        {
            note.setText("Your number should consist of only 10 digits.");
            note.setStandardButtons(QMessageBox::Ok);
        }
        else{

         if ((obj.dateCheck(rightDate) == 0) && (( ui->radioButton->isChecked()) != 0))
                {
                    note.setText("Invalid date parameter.");
                    note.setStandardButtons(QMessageBox::Ok);
                }
                else if ((obj.dateCheck(rightDate) == 1) && ( ui->radioButton->isChecked() == 1))
                {
                     ob.date = rightDate;
                }


        ob.fio =  obj.checkFio(rightFio);
            ob.tel =  tel.toStdString();

        int id1 = id.toInt() - 1;

        if ((obj.change(id1, ob)) == 1)
        {
            obj.write();
            note.setText("You have successfully changed data!");
            ui->lfio->setText("");
             ui->ltel->setText("");
              ui->lid->setText("");

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
    else
    {
        note.setText("ID is incorrect");
        note.setInformativeText("Do you want to retry?");
        note.setStandardButtons(QMessageBox::Retry | QMessageBox::Close);
        note.setDefaultButton(QMessageBox::Retry);
    }

}

}

}


}
    int ret = note.exec();

}
void changeD::on_radioButton_clicked(bool checked)
{   /*
    if (( ui->radioButton->isChecked()) == 0)
    {

     }
     */
}

void changeD::on_pushButtonR_clicked()
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
