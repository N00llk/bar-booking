#pragma once

#include <QWidget>

#include "ITransport.h"

namespace Ui {
class FormAuthorization;
}

class FormAuthorization : public QWidget
{
    Q_OBJECT

public:
    explicit FormAuthorization(ITransport& transport, QWidget *parent = nullptr);
    ~FormAuthorization();

private:
    Ui::FormAuthorization *ui;
    ITransport& m_transport;

signals:
    void authorizationSuccess(User::RoleEnum userType, QString accessToken, QString refreshToken);
    void authorizationFail(void);
    void registrationRequested(void);

private slots:
    void onEnterPressed(void);
    void onLoginReply(QNetworkReply* reply);
};

