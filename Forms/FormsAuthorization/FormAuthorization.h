#pragma once

#include <QWidget>

enum class UserType
{
    Owner,
    Manager
};

namespace Ui {
class FormAuthorization;
}

class FormAuthorization : public QWidget
{
    Q_OBJECT

public:
    explicit FormAuthorization(QWidget *parent = nullptr);
    ~FormAuthorization();

private:
    Ui::FormAuthorization *ui;

signals:
    void authorizationSuccess(UserType userType);
    void authorizationFail(void);

private slots:
    void onEnterPressed(void);
};

