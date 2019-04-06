#include "check.h"
#include "ui_check.h"
#include "mainwindow.h"
#include "QMessageBox"

check::check(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::check)
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

    changeWD = new changeD();
    connect(changeWD, &changeD::secondWindow, this, &Form::show);

    addW = new add();
    connect(addW, &add::secondWindow, this, &Form::show);

    delW = new del();
    connect(delW, &del::secondWindow, this, &Form::show);

}

check::~check()
{
    delete ui;
}

void check::resirvedTextCheck(QString str)
{
    ui->label->setText(str);

}


void check::on_pushButton_clicked()
{
    this->close();      // Закрываем окно
    emit secondWindow();
}

void check::on_pushButton_2_clicked()
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

void check::on_pushButtonCD_clicked()
{
    QMessageBox note;
   QString qstatus  = ui->label->text();


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

void check::on_pushButtonAdd_clicked()
{

    QMessageBox note;
   QString qstatus  = ui->label->text();


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

void check::on_pushButtonDel_clicked()
{

    QMessageBox note;
   QString qstatus  = ui->label->text();


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
