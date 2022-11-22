#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include <QMessageBox>

#include <FormsAuthorization/FormAuthorization.h>
#include <FormsRegistration/FormRegistration.h>
#include <FormsOwner/FormOwner.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_authorizationForm = new FormAuthorization(m_transport);
    m_registrationForm = new FormRegistration(m_transport);

    connect(m_authorizationForm, &FormAuthorization::authorizationSuccess, this, &MainWindow::onAuthorizationSuccess);
    connect(m_authorizationForm, &FormAuthorization::authorizationFail, this, &MainWindow::onAuthorizationFail);

    connect(m_authorizationForm, &FormAuthorization::registrationRequested, this, &MainWindow::onRegistrationRequested);
    connect(m_registrationForm, &FormRegistration::authorizationRequested, this, &MainWindow::onAuthorizationRequested);

    ui->stackedWidget->addWidget(m_authorizationForm);
    ui->stackedWidget->addWidget(m_registrationForm);

    ui->stackedWidget->setCurrentWidget(m_authorizationForm);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onAuthorizationSuccess(UserType userType)
{
    qDebug() << __FUNCTION__ << (int)userType;

    switch(userType)
    {
    case UserType::Owner:
//        ui->centralwidget->layout()->removeWidget(m_authorizationForm);
//        ui->centralwidget->layout()->addWidget(new FormOwner(this));
        break;
    case UserType::Manager:
        break;
    }
}

void MainWindow::onAuthorizationFail()
{
    QMessageBox::critical(this, "Ошибка входа", "Неверные логин или пароль!");
}

void MainWindow::onRegistrationRequested()
{
    qDebug() << __FUNCTION__;
    ui->stackedWidget->setCurrentWidget(m_registrationForm);
}

void MainWindow::onAuthorizationRequested()
{
    qDebug() << __FUNCTION__;
    ui->stackedWidget->setCurrentWidget(m_authorizationForm);
}

