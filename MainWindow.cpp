#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include <QMessageBox>

#include <FormsAuthorization/FormAuthorization.h>
#include <FormsRegistration/FormRegistration.h>
#include <FormsBarView/FormBarView.h>
#include <FormsOwner/FormOwner.h>
#include <FormsBar/FormCreateBar.h>
#include <FormsBar/FormBarInspect.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_authorizationForm = new FormAuthorization(m_transport);
    m_registrationForm = new FormRegistration(m_transport);
    m_barViewForm = new FormBarView(m_transport, m_activeUser);
    m_createBarForm = new FormCreateBar();
    m_barInspectForm = new FormBarInspect();

    connect(m_authorizationForm, &FormAuthorization::authorizationSuccess, this, &MainWindow::onAuthorizationSuccess);
    connect(m_authorizationForm, &FormAuthorization::authorizationFail, this, &MainWindow::onAuthorizationFail);

    connect(m_registrationForm, &FormRegistration::registrationSuccess, this, &MainWindow::onRegistrationSuccess);
    connect(m_registrationForm, &FormRegistration::registrationFail, this, &MainWindow::onRegistrationFail);

    connect(m_authorizationForm, &FormAuthorization::registrationRequested, this, &MainWindow::onRegistrationRequested);
    connect(m_registrationForm, &FormRegistration::authorizationRequested, this, &MainWindow::onAuthorizationRequested);
    connect(m_barViewForm, &FormBarView::barCreationRequested, this, &MainWindow::onBarCreationRequested);
    connect(m_barViewForm, &FormBarView::barOpenRequested, this, &MainWindow::onBarOpeningRequested);
    connect(m_createBarForm, &FormCreateBar::barCreationSuccess, this, &MainWindow::onBarCreationSuccess);
    connect(m_createBarForm, &FormCreateBar::barCreationCanceled, this, &MainWindow::onBarCreationCanceled);

    ui->stackedWidget->addWidget(m_authorizationForm);
    ui->stackedWidget->addWidget(m_registrationForm);
    ui->stackedWidget->addWidget(m_barViewForm);
    ui->stackedWidget->addWidget(m_createBarForm);
    ui->stackedWidget->addWidget(m_barInspectForm);

    ui->stackedWidget->setCurrentWidget(m_authorizationForm);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onAuthorizationSuccess(User::RoleEnum role, QString accessToken, QString refreshToken)
{
    qDebug() << __FUNCTION__;
    m_activeUser.create(role, accessToken, refreshToken);
    ui->stackedWidget->setCurrentWidget(m_barViewForm);
}

void MainWindow::onAuthorizationFail()
{
    QMessageBox::critical(this, "Ошибка входа", "Неверные логин или пароль!");
}

void MainWindow::onRegistrationSuccess()
{
    QMessageBox::information(this, "Регистрация завершена", "Регистрация успешно завершена! Теперь вы можете войти в системую");
}

void MainWindow::onRegistrationFail()
{
    QMessageBox::critical(this, "Ошибка регистрации", "Такая учетная запись уже существует!");
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

void MainWindow::onBarCreationRequested()
{
    qDebug() << __FUNCTION__;
    ui->stackedWidget->setCurrentWidget(m_createBarForm);
}

void MainWindow::onBarOpeningRequested(const Bar &bar)
{
    qDebug() << __FUNCTION__;
    ui->stackedWidget->setCurrentWidget(m_barInspectForm);
}

void MainWindow::onBarCreationCanceled()
{
    ui->stackedWidget->setCurrentWidget(m_barViewForm);
}

void MainWindow::onBarCreationSuccess()
{
    ui->stackedWidget->setCurrentWidget(m_barViewForm);
}

