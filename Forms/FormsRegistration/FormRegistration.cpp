#include "FormRegistration.h"
#include "ui_FormRegistration.h"

FormRegistration::FormRegistration(ITransport& transport, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormRegistration)
{
    ui->setupUi(this);

    connect(ui->authorizationLabel, &QLabel::linkActivated, this, &FormRegistration::authorizationRequested);

    ui->nameLineEdit->setPlaceholderText("Имя");
    ui->surnameLineEdit->setPlaceholderText("Фамилия");
    ui->loginLineEdit->setPlaceholderText("Почта");
    ui->passwordLineEdit->setPlaceholderText("Пароль");
    ui->passwordRepeatLineEdit->setPlaceholderText("Повторите пароль");
    ui->userRoleComboBox->setPlaceholderText("Ваша роль");
}

FormRegistration::~FormRegistration()
{
    delete ui;
}
