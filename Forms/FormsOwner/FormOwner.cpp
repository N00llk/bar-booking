#include "FormOwner.h"
#include "ui_FormOwner.h"

FormOwner::FormOwner(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormOwner)
{
    ui->setupUi(this);
}

FormOwner::~FormOwner()
{
    delete ui;
}
