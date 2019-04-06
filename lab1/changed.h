#ifndef CHANGED_H
#define CHANGED_H

#include <QWidget>
#include "QStandardItemModel"

namespace Ui {
class changeD;
}

class changeD : public QWidget
{
    Q_OBJECT

public:
    explicit changeD(QWidget *parent = nullptr);
    ~changeD();

signals:
    void secondWindow();

private slots:
    void on_pushButton_clicked();

    void on_bok_clicked();

    void on_radioButton_clicked(bool checked);

    void on_pushButtonR_clicked();

private:
    Ui::changeD *ui;
    QStandardItemModel *BDmodel;
};

#endif // CHANGED_H
