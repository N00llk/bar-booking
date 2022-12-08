#pragma once

#include <QMainWindow>
#include "ServerTransport.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class FormAuthorization;
class FormRegistration;
class FormBarView;
class FormCreateBar;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    ServerTransport& transport() { return m_transport; }

private:
    Ui::MainWindow *ui;
    FormAuthorization* m_authorizationForm;
    FormRegistration* m_registrationForm;
    FormBarView* m_barViewForm;
    FormCreateBar* m_createBarForm;
    ServerTransport m_transport;
    User m_activeUser;

private slots:
    void onAuthorizationSuccess(User::RoleEnum role, QString accessToken, QString refreshToken);
    void onAuthorizationFail(void);
    void onRegistrationSuccess(void);
    void onRegistrationFail(void);
    void onRegistrationRequested(void);
    void onAuthorizationRequested(void);
    void onBarCreationRequested(void);
    void onBarCreationCanceled(void);
    void onBarCreationSuccess(void);
};
