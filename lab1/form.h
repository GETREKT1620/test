#ifndef FORM_H
#define FORM_H
#include "change.h"
#include "changed.h"
#include "add.h"
#include "del.h"
#include <QWidget>
#include "check.h"
#include "sor1t.h"


namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

signals:
    void firstWindow();

    void sendTextToCheck(QString str);

private slots:
    void on_pushButtonBack_clicked();

    void on_pushButton_clicked();

    void on_pushButtonCD_clicked();

    void on_pushButtonAdd_clicked();

    void on_pushButtonDel_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

public slots:
    void resirvedText(QString str);//слот принимающий текст из LineEdit

private:
    Ui::Form *ui;
    Change *changeW;
    changeD *changeWD;
    add *addW;
    del *delW;
    check *checkW;
    sor1t *sor1tW;

};

#endif // FORM_H
