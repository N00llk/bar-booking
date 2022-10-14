#include "FormAuthorization.h"
#include "ui_FormAuthorization.h"

FormAuthorization::FormAuthorization(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormAuthorization)
{
    ui->setupUi(this);

    connect(ui->enterPushButton, &QPushButton::pressed, this, &FormAuthorization::onEnterPressed);
}

FormAuthorization::~FormAuthorization()
{
    delete ui;
}

void FormAuthorization::onEnterPressed()
{
    QString loginStr = ui->loginLineEdit->text();

    if (loginStr.length() > 4)
    {
        emit authorizationSuccess(UserType::Owner);
    }
    else if (loginStr.length() > 3)
    {
        emit authorizationSuccess(UserType::Manager);
    }
    else
    {
        emit authorizationFail();
    }
}
