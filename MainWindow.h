#pragma once

#include <QMainWindow>
#include "ServerTransport.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

enum class UserType;
class FormAuthorization;
class FormRegistration;

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
    ServerTransport m_transport;

private slots:
    void onAuthorizationSuccess(UserType userType);
    void onAuthorizationFail(void);
    void onRegistrationRequested(void);
    void onAuthorizationRequested(void);
};
