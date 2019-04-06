#ifndef ADD_H
#define ADD_H

#include <QWidget>
#include "QStandardItemModel"

namespace Ui {
class add;
}

class add : public QWidget
{
    Q_OBJECT

public:
    explicit add(QWidget *parent = nullptr);
    ~add();

signals:
    void secondWindow();

private slots:
    void on_pushButtonBack_clicked();

    void on_pushButtonAdd_clicked();

    void on_pushButtonR_clicked();

private:
    Ui::add *ui;
    QStandardItemModel *BDmodel;

};

#endif // ADD_H
