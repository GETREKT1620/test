#ifndef CHECK_H
#define CHECK_H
#include <QStandardItemModel>
#include <QWidget>
#include "changed.h"
#include "add.h"
#include "del.h"

namespace Ui {
class check;
}

class check : public QWidget
{
    Q_OBJECT

signals:

    void firstWindow();
    void secondWindow();


public:
    explicit check(QWidget *parent = nullptr);
    ~check();


public slots:
    void resirvedTextCheck(QString str);//слот принимающий текст из LineEdit


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButtonCD_clicked();

    void on_pushButtonAdd_clicked();

    void on_pushButtonDel_clicked();

private:
    Ui::check *ui;
    QStandardItemModel *BDmodel;
    changeD *changeWD;
    add *addW;
    del *delW;
};

#endif // CHECK_H



