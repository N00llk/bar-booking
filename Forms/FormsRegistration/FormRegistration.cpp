#include "FormRegistration.h"
#include "ui_FormRegistration.h"

FormRegistration::FormRegistration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FormRegistration)
{
    ui->setupUi(this);
}

FormRegistration::~FormRegistration()
{
    delete ui;
}
