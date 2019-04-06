#ifndef SORT_H
#define SORT_H

#include <QStandardItemModel>
#include <QWidget>

namespace Ui {
class sort;
}

class sort : public QWidget
{
    Q_OBJECT

signals:
    void secondWindow();

public:
    explicit sort(QWidget *parent = nullptr);
    ~sort();

private:
    Ui::sort *ui;
    QStandardItemModel *BDmodel;

};

#endif // SORT_H
