#include "FormAddNewBar.h"
#include "ui_FormAddNewBar.h"

FormAddNewBar::FormAddNewBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormAddNewBar)
{
    ui->setupUi(this);
}

FormAddNewBar::~FormAddNewBar()
{
    delete ui;
}
