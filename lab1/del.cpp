#include "del.h"
#include "ui_del.h"
#include "mainwindow.h"
#include "form.h"
#include "QMessageBox"

del::del(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::del)
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

del::~del()
{
    delete ui;
}

void del::on_pushButtonBack_clicked()
{
    this->close();      // Закрываем окно
    emit secondWindow();
     ui->lid->setText("");
}

void del::on_pushButtonDel_clicked()
{

    QMessageBox note;



    DataBase obj;
    dataS ob;
    obj.read();



    QString id  = ui->lid->text();
    if (id == "")
    {
        note.setText("You must first enter the ID");
        note.setStandardButtons(QMessageBox::Ok);
        int ret = note.exec();
    }
    else{

    QMessageBox *msgBox = new QMessageBox(QMessageBox::Information,"warning","Are you sure you want to delete the selected data?",
    QMessageBox::Ok| QMessageBox::Cancel);

    if(msgBox->exec() == QMessageBox::Ok)
    {
    int id1 = id.toInt() - 1;

   if ((obj.del(id1)) == 1)
   {
       obj.write();
       note.setText("You have successfully deleted data!");
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
           note.setStandardButtons(QMessageBox::Retry | QMessageBox::Cancel);
           note.setDefaultButton(QMessageBox::Retry);
   }
   int ret = note.exec();
}
    else
    {
        ui->lid->setText("");

    }


   delete msgBox;
}



}


void del::on_pushButtonRef_clicked()
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
