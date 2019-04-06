#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "fstream"
#include "string"
#include "iostream"
#include "vector"
using namespace std;
#include <QMainWindow>
#include <form.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonConf_clicked();





signals:
    void sendText(QString str); //сигнал отправляет текст из autorize


private:
    Ui::MainWindow *ui;
    Form *sndwindow;
    check *checkW;
};


struct dataPass
{
    string login;
    string pass;
    string st;
};

struct dataS
{
    string fio;
    string tel;
    string date;
};


class DataBase
{
public:


    DataBase()
    {}
    ~DataBase()
    {}

    bool openFilePass() //открывает файл БД паролей
    {

        flP.open ("C:Qt_labs\\qt_labs-master\\qt_labs-masterv\\lab1\\file1.json",ios::binary | ios::in | ios::out);

        if (!flP)
            {
                return 0;
            }
           return 1;

    }

    bool openFile() //открывает файл БД
    {

        fl.open ("C:Qt_labs\\qt_labs-master\\qt_labs-masterv\\lab1\\DataBase.json",ios::binary | ios::in | ios::out);

        if (!fl)
            {
                return 0;
            }
           return 1;

    }

    int bdPassSize() // возвращает количество записей в векторе паролей
    {

       return bd_pass.size();

    }

    int bdSize() // возвращает количество записей в векторе
    {

       return bd.size();

    }

    int sortBdSize() // возвращает количество записей в векторе
    {

       return sort_bd.size();

    }


    bool newOpenFilePass() // открывает файл с паролями для перезаписи
        {
            flP.open("C:Qt_labs\\qt_labs-master\\qt_labs-masterv\\lab1\\file1.json", ios::binary | ios::trunc | ios::out | ios::in);

            if (!flP)
            {
                return 0;
            }
            return 1;

        }

    bool newOpenFile() // открывает файл БД для перезаписи
        {
            fl.open("C:Qt_labs\\qt_labs-master\\qt_labs-masterv\\lab1\\DataBase.json", ios::binary | ios::trunc | ios::out | ios::in);

            if (!fl)
            {
                return 0;
            }
            return 1;

        }


    bool closeFilePass() //закрывает файл с паролями
    {
        flP.close();

        if (!flP)
            {
                return 0;
            }
           return 1;
    }

    bool closeFile() //закрывает файл с БД
    {
        fl.close();

        if (!fl)
            {
                return 0;
            }
           return 1;
    }

    int sizeFilePass() //возвращает количество записей в файле БД с паролями
    {

        int k = 0;
        string sk;

        while (!(flP.eof()))
        {
            getline(flP, sk, '}');
            k++;
        }
        k--;

        closeFilePass();
        openFilePass();
        return k;
    }

    int sizeFile() //возвращает количество записей в файле БД
    {

        int k = 0;
        string sk;

        while (!(fl.eof()))
        {
            getline(fl, sk, '}');
            k++;
        }
        k--;

        closeFile();
        openFile();
        return k;
    }


    dataS zapis(int id)
    {
        return bd[id];



    }

    dataS zapis_sort(int id)
    {
        return sort_bd[id];



    }


    string checkFio(string fio)
    {


            int l = fio.length();
            int i = 0;
            int k = 0;


            for (; i < l; i++)
                if (fio[i]<'a' || fio[i]>'z')
                {
                    k++;
                }

            if ((fio[0] > 64) && (fio[0] < 91 ) && ( k==1 ))
            {
                return fio;
            }
            else if (k == 0)
            {
                fio[0] += 'A' - 'a';
                return fio;
            }
            else
            {
                return "no!";
            }
        }

    bool checkTel(string tel)
    {
        int l = tel.length();
        if (l != 10)
        {
            return  0;
        }
        else
        {
            int i=0;
            for(; i<l; i++)
              if(tel[i]<'0' || tel[i]>'9')
                  break;
            if(i<l)
              return 0;
            else
              return 1;

        }
    }



    bool sort(dataS obg, bool ck1,bool ck2, bool ck3)
    {
        int answ = 0;
        if ((ck1 == 0) && (ck2 == 0) && (ck3 == 0))
        {
            return 0;
        }
        else
        {
            int k = bd.size();
            dataS obl;

            for  (int i = 0; i < k; i++)
            {
               int stat1 = 0;
            if (ck1 == 1)
            {
                stat1++;

                if (obg.fio == bd[i].fio)
                {
                     cout << "ck1--" << endl;
                     stat1 --;
                }



             }

                 if (ck2 == 1)
                {
                    stat1++;
                    if (obg.tel == bd[i].tel)
                    {
                         obl.tel = bd[i].tel;
                         cout << "ck2--" << endl;
                        stat1 --;
                    }


                 }

                 if (ck3 == 1)
                    {
                        stat1++;
                        if (obg.date == bd[i].date)
                        {
                            obl.date = bd[i].date;
                             cout << "ck3--" << endl;
                            stat1 --;
                        }


                    }

                 if (stat1 == 0)
                 {
                     answ++;
                     obl.fio = bd[i].fio;
                     obl.date = bd[i].date;
                     obl.tel = bd[i].tel;
                    sort_bd.push_back(obl);

                 }


            }

        }


    if (answ == 0)
    {
    return 0;
    }
    else{
        return 1;

    }

  }




    bool dateCheck(string date)
    {
        if (date == "")
        {
            return 0;
        }

        int l = date.length();
        int p1 = 0;
        int p2 = 0;
        int check = 0;

        for (int i = 0; i < l; i++)
        {
            if (date[i] == '.')
            {
                check++;
                if (p1 == 0)
                {
                    p1 = i;
                }
                else
                {
                    p2 = i;
                }

            }
        }
        if (check == 0)
            return 0;

            cout << p1 << " " << p2 << endl;

        string day = date.substr(0, p1);
        cout << day << endl;

        int monL = p2 - p1 - 1;
        int monP = p1 + 1;

        string month = date.substr(monP, monL);
        cout << month << endl;

        int yearP = l - 4;
        string year = date.substr(yearP, 4);
        cout << year << endl;
        int year1 = stoi(year);

        ///////////////// check ////////////////////

        if ((year1 > 2019) || (year1 < 1960))
        {
            return 0;
        }


        return 1;
    }


    bool addPass(dataPass temp_data) //добавляет 1 запись в БД с паролями
    {
        bd_pass.push_back(temp_data);
        return 1;
    }

    bool add(dataS temp_data) //добавляет 1 запись в БД
    {
        bd.push_back(temp_data);
        return 1;
    }

    bool delPass(int id) //удаляет данные с заданным id из БД с паролями
        {
            if (bd_pass.size() <= id)
            {

                return 0;

            }
            else
            {
                bd_pass.erase(bd_pass.begin() + id);
                return 1;

            }
        }

    bool del(int id) //удаляет данные с заданным id из БД
        {
            if (bd.size() <= id)
            {

                return 0;

            }
            else
            {
                bd.erase(bd.begin() + id);
                return 1;

            }
        }

        dataS spisok(int num)
        {


            return bd[num];

        }

     bool changePass(dataPass oldtemp, dataPass newtemp) // смена пароля
     {

         int s = bd_pass.size();
         for (int i = 0; i < s; i++)
         {
             if ((bd_pass[i].login == oldtemp.login) && (bd_pass[i].pass == oldtemp.pass ))
             {
                 if (newtemp.login != "")
                 {
                     bd_pass[i].login = newtemp.login;
                 }

                 bd_pass[i].pass = newtemp.pass;
                 return 1;
             }


         }

             return 0;
     }




    bool change(int id, dataS temp_data) // меняет данные в БД с заданным id, на заданные данные temp_data
        {
            if (bd.size() <= id)
            {
                return 0;
            }
            else
            {
                string mfio = bd[id].fio;
                string mtel = bd[id].tel;
                string mdate = bd[id].date;

                if (temp_data.fio != "")
                {
                    bd[id].fio = temp_data.fio;
                }
                else
                {
                    bd[id].fio = mfio;
                }

                if (temp_data.tel != "")
                {
                    bd[id].tel = temp_data.tel;
                }
                else
                {
                    bd[id].tel = mtel;
                }

                if (temp_data.date != "")
                {
                    bd[id].date = temp_data.date;
                }
                else
                {
                    bd[id].date = mdate;

                }

                return 1;

            }

        }


    bool readPass() //считывает всю БД из файла паролей
    {
        openFilePass();
        downloadPass();
        closeFilePass();
        return 1;
    }

    bool read() //считывает всю БД из файла
    {
        openFile();
        download();
        closeFile();
        return 1;
    }



    bool downloadPass() //построчно считывает БД из файла паролей
    {
        string line;

        int s = sizeFilePass();
        cout << "size = " << s << endl;

            for(int i = 0; i < s; i++)
        {
            getline(flP, line, '}');
            dataPass data2add = parsingPass(line);
            addPass(data2add);

        }
        return 1;
    }

    bool download() //построчно считывает БД из файла
    {
        string line;

        int s = sizeFile();
        cout << "size = " << s << endl;

            for(int i = 0; i < s; i++)
        {
            getline(fl, line, '}');
            dataS data2add = parsing(line);
            add(data2add);

        }
        return 1;
    }

    void getV()
    {
        bd.clear();

    }


    string data2stringPass(dataPass temp) // обратный парсинг паролей
        {
            string res;
            string nlog = temp.login;
            string npass = temp.pass;;
            string nst = temp.st;;
            string smb1 = "\n";
            string smb2 = "\t";
            string smb3 = "\r";
            string s1 = "{";
            string s2 = "\"login\": \"";
            string s3 = "\",";
            string s4 = "\"password\": \"";
            string s5 = "\"status\": \"";
            string s6 = "\";";
            string s7 = "}";


            res = s1 + smb3 + smb1 + smb2 + s2 + nlog + s3 + smb3 + smb1 + smb2 + s4 + npass + s3 + smb3 + smb1 + smb2 + s5 + nst + s6 + smb3 + smb1 + s7 + smb1;
            cout << res << endl;


            return res;
        }

    string data2string(dataS temp) // обратный парсинг
        {
            string res;
            string nlog = temp.fio;
            string npass = temp.tel;;
            string nst = temp.date;;
            string smb1 = "\n";
            string smb2 = "\t";
            string smb3 = "\r";
            string s1 = "{";
            string s2 = "\"fio\": \"";
            string s3 = "\",";
            string s4 = "\"tel\": \"";
            string s5 = "\"date\": \"";
            string s6 = "\";";
            string s7 = "}";


            res = s1 + smb3 + smb1 + smb2 + s2 + nlog + s3 + smb3 + smb1 + smb2 + s4 + npass + s3 + smb3 + smb1 + smb2 + s5 + nst + s6 + smb3 + smb1 + s7 + smb1;
            cout << res << endl;


            return res;
        }

    bool uploadPass()// записывает всю БД в файл паролей
        {
            dataPass temp_data;
            string temp_str;

            int s = bd_pass.size();

            for (int i = 0; i < s; i++)
            {
                temp_data = bd_pass[i];
                temp_str = data2stringPass(temp_data);
                flP << temp_str << endl;


            }

            return 1;

        }

    bool upload()// записывает всю БД в файл
        {
            dataS temp_data;
            string temp_str;

            int s = bd.size();

            for (int i = 0; i < s; i++)
            {
                temp_data = bd[i];
                temp_str = data2string(temp_data);
                fl << temp_str << endl;


            }

            return 1;

        }

    bool writePass() //запись всей БД в файл паролей (save button)
        {
            newOpenFilePass();
            uploadPass();
            flP.close();
            return 1;

        }

    bool write() //запись всей БД в файл (save button)
        {
            newOpenFile();
            upload();
            fl.close();
            bd.clear();
            return 1;

        }


    dataPass parsingPass(string tline) //парсинг строки паролей
    {
        dataPass temp;

        unsigned long long pos1 = 0;
        unsigned long long pos2 = 0;
        unsigned long long leng = 0;

        string pass1;
        string login1;
        string st1;

        pos1 = tline.find("\"login\"") + 10;
        pos2 = tline.find("\"password\"") - 5;
        leng = pos2 - pos1;
        login1 = tline.substr(pos1, leng);
        cout << "login is: " << login1 << endl;

        pos1 = tline.find("\"password\"") + 13;
        pos2 = tline.find("\"status\"") - 5;
        leng = pos2 - pos1;
        pass1 = tline.substr(pos1, leng);
        cout << "password is: " << pass1 << endl;

        pos1 = tline.find("\"status\"") + 11;
        pos2 = tline.find(";") - 1;
        leng = pos2 - pos1;
        st1 = tline.substr(pos1, leng);
        cout << "status is: " << st1 << endl;

        temp.login = login1;
        temp.pass = pass1;
        temp.st = st1;
        return temp;

    }

    dataS parsing(string tline) //парсинг строки
    {
        dataS temp;

        unsigned long long pos1 = 0;
        unsigned long long pos2 = 0;
        unsigned long long leng = 0;

        string fio1;
        string tel1;
        string date1;

        pos1 = tline.find("\"fio\"") + 8;
        pos2 = tline.find("\"tel\"") - 5;
        leng = pos2 - pos1;
        fio1 = tline.substr(pos1, leng);
        cout << "fio is: " << fio1 << endl;

        pos1 = tline.find("\"tel\"") + 8;
        pos2 = tline.find("\"date\"") - 5;
        leng = pos2 - pos1;
        tel1 = tline.substr(pos1, leng);
        cout << "tel is: " << tel1 << endl;

        pos1 = tline.find("\"date\"") + 9;
        pos2 = tline.find(";") - 1;
        leng = pos2 - pos1;
        date1 = tline.substr(pos1, leng);
        cout << "date is: " << date1 << endl;

        temp.fio = fio1;
        temp.tel = tel1;
        temp.date = date1;
        return temp;

    }

    QString autorize(QString log, QString pass) //функция авторизации
    {
        QString qlogin;
        QString qpass;
        QString qst;

        string login2;
        string pass2;
        string st2;
        int size = bd_pass.size();

       for (int i = 0; i < size; i++)
        {
            login2 = bd_pass[i].login;
            pass2 = bd_pass[i].pass;
            st2 = bd_pass[i].st;

           qpass = QString::fromStdString(pass2);
           qlogin = QString::fromStdString(login2);
           qst = QString::fromStdString(st2);

           if ((qpass == pass) && (qlogin == log))
           {
               return qst;
           }


       }

       closeFilePass();
       return "no";

    }




private:
vector<dataPass> bd_pass;
vector<dataS> bd;
fstream flP;
fstream fl;
vector<dataS> sort_bd;
};



#endif // MAINWINDOW_H
