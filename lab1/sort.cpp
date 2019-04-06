#include "sort.h"
#include "ui_sort.h"

sort::sort(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sort)
{
    ui->setupUi(this);
}

sort::~sort()
{
    delete ui;
}
