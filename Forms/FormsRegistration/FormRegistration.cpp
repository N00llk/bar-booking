#include "FormRegistration.h"
#include "ui_FormRegistration.h"

#include <QGraphicsDropShadowEffect>
#include <QNetworkReply>
#include <QJsonDocument>

FormRegistration::FormRegistration(ITransport& transport, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormRegistration),
    m_transport(transport)
{
    ui->setupUi(this);

    connect(ui->authorizationLabel, &QLabel::linkActivated, this, &FormRegistration::authorizationRequested);
    connect(ui->registrationPushButton, &QPushButton::clicked, this, &FormRegistration::onRegistrationPressed);

    ui->nameLineEdit->setPlaceholderText("Имя");
    ui->surnameLineEdit->setPlaceholderText("Фамилия");
    ui->emailLineEdit->setPlaceholderText("Почта");
    ui->passwordLineEdit->setPlaceholderText("Пароль");
    ui->passwordRepeatLineEdit->setPlaceholderText("Повторите пароль");
    ui->userRoleComboBox->setPlaceholderText("Ваша роль");
}

FormRegistration::~FormRegistration()
{
    delete ui;
}

void FormRegistration::onRegistrationPressed()
{
    ITransport::RegistrationStruct regData;

    regData.name = ui->nameLineEdit->text();
    regData.surname = ui->surnameLineEdit->text();
    regData.patronymic = "";
    regData.email = ui->emailLineEdit->text();
    regData.password = ui->passwordLineEdit->text();
    regData.role = static_cast<User::RoleEnum>(ui->userRoleComboBox->currentIndex() + 1);

    m_transport.requestRegisterUser(this, SLOT(onRegistrationReply(QNetworkReply*)), regData);
}

void FormRegistration::onRegistrationReply(QNetworkReply *reply)
{
    qDebug() << reply->error() << static_cast<int>(reply->error());

    switch(reply->error())
    {
    case QNetworkReply::NetworkError::NoError:
    {
        emit registrationSuccess();
        break;
    }
    default:
    {
        emit registrationFail();
        break;
    }
    }
}
