#ifndef CHANGE_H
#define CHANGE_H

#include <QWidget>

namespace Ui {
class Change;
}

class Change : public QWidget
{
    Q_OBJECT

public:
    explicit Change(QWidget *parent = nullptr);
    ~Change();

signals:
    void secondWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Change *ui;
};

#endif // CHANGE_H
