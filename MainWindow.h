#pragma once

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

enum class UserType;
class FormAuthorization;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    FormAuthorization* m_authorizationForm;

private slots:
    void onAuthorizationSuccess(UserType userType);
    void onAuthorizationFail(void);
};