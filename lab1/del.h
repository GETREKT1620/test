#ifndef DEL_H
#define DEL_H
#include <QStandardItemModel>
#include <QWidget>

namespace Ui {
class del;
}

class del : public QWidget
{
    Q_OBJECT

public:
    explicit del(QWidget *parent = nullptr);
    ~del();

signals:
    void secondWindow();

private slots:
    void on_pushButtonBack_clicked();

    void on_pushButtonDel_clicked();


    void on_pushButtonRef_clicked();

private:
    Ui::del *ui;
     QStandardItemModel *BDmodel;
};

#endif // DEL_H
