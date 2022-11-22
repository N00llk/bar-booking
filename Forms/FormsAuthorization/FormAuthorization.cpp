#include "FormAuthorization.h"
#include "ui_FormAuthorization.h"

#include <QGraphicsDropShadowEffect>
#include <QNetworkReply>

FormAuthorization::FormAuthorization(ITransport &transport, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormAuthorization),
    m_transport(transport)
{
    ui->setupUi(this);

    connect(ui->enterPushButton, &QPushButton::pressed, this, &FormAuthorization::onEnterPressed);
    connect(ui->registrationLabel, &QLabel::linkActivated, this, &FormAuthorization::registrationRequested);

    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect();
    effect->setBlurRadius(1);
    effect->setOffset(3,3);

    QGraphicsDropShadowEffect* effect1 = new QGraphicsDropShadowEffect();
    effect1->setBlurRadius(1);
    effect1->setOffset(3,3);

    ui->loginLineEdit->setGraphicsEffect(effect);
    ui->passwordLineEdit->setGraphicsEffect(effect1);
    ui->loginLineEdit->setPlaceholderText("Почта");
    ui->passwordLineEdit->setPlaceholderText("Пароль");

}

FormAuthorization::~FormAuthorization()
{
    delete ui;
}

void FormAuthorization::onEnterPressed()
{
    ITransport::LoginStruct loginData;

    loginData.email = ui->loginLineEdit->text();
    loginData.password = ui->passwordLineEdit->text();

    m_transport.requestLoginUser(this, SLOT(onLoginReply(QNetworkReply*)), loginData);
}

void FormAuthorization::onLoginReply(QNetworkReply *reply)
{
    qDebug() << reply->error() << static_cast<int>(reply->error());

//    switch(reply->error())
//    if (loginStr.length() > 4)
//    {
//        emit authorizationSuccess(UserType::Owner);
//    }
//    else if (loginStr.length() > 3)
//    {
//        emit authorizationSuccess(UserType::Manager);
//    }
//    else
//    {
//        emit authorizationFail();
//    }
}
