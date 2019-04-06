#ifndef SOR1T_H
#define SOR1T_H
#include <QStandardItemModel>
#include <QWidget>

namespace Ui {
class sor1t;
}

class sor1t : public QWidget
{
    Q_OBJECT

public:
    explicit sor1t(QWidget *parent = nullptr);
    ~sor1t();

signals:
    void secondWindow();

private slots:
    void on_pushButton_clicked();

    void on_bok_clicked();

private:
    Ui::sor1t *ui;
    QStandardItemModel *BDmodel;
};

#endif // SOR1T_H
