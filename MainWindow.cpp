#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include <QMessageBox>

#include <FormsAuthorization/FormAuthorization.h>
#include <FormsOwner/FormOwner.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_authorizationForm = new FormAuthorization(this);

    connect(m_authorizationForm, &FormAuthorization::authorizationSuccess, this, &MainWindow::onAuthorizationSuccess);
    connect(m_authorizationForm, &FormAuthorization::authorizationFail, this, &MainWindow::onAuthorizationFail);
    ui->centralwidget->layout()->addWidget(m_authorizationForm);
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
        ui->centralwidget->layout()->removeWidget(m_authorizationForm);
        ui->centralwidget->layout()->addWidget(new FormOwner(this));
        break;
    case UserType::Manager:
        break;
    }
}

void MainWindow::onAuthorizationFail()
{
    QMessageBox::critical(this, "Ошибка входа", "Неверные логин или пароль!");
}

