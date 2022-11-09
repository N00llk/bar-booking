#include "FormAuthorization.h"
#include "ui_FormAuthorization.h"

#include <QGraphicsDropShadowEffect>

FormAuthorization::FormAuthorization(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormAuthorization)
{
    ui->setupUi(this);

    connect(ui->enterPushButton, &QPushButton::pressed, this, &FormAuthorization::onEnterPressed);

    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect();
    effect->setBlurRadius(1);
    effect->setOffset(3,3);

    ui->loginLineEdit->setGraphicsEffect(effect);
    ui->passwordLineEdit->setGraphicsEffect(effect);
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
