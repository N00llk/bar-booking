#include "FormBarInspect.h"
#include "ui_FormBarInspect.h"

FormBarInspect::FormBarInspect(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormBarInspect)
{
    ui->setupUi(this);
}

FormBarInspect::~FormBarInspect()
{
    delete ui;
}
