#include "FormCreateBar.h"
#include "ui_FormCreateBar.h"

FormCreateBar::FormCreateBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormCreateBar)
{
    ui->setupUi(this);
}

FormCreateBar::~FormCreateBar()
{
    delete ui;
}
