#pragma once

#include <QObject>
#include <QUrl>

#include "ITransport.h"

class ServerTransport: public QObject, public ITransport
{
    Q_OBJECT
public:
    ServerTransport();

    void requestLoginUser(const QObject* sender, const char* senderSlot, const LoginStruct& data) override;
    void requestRegisterUser(const QObject* sender, const char* senderSlot, const RegistrationStruct& data) override;

private:
    const QString m_stringUrl = "http://77.234.215.138:60866/bar/api/v1";
    const QString m_loginUrl = m_stringUrl + "/login";
    const QString m_registrationUrl = m_stringUrl + "/register/";
    const QUrl m_url;
    QNetworkAccessManager* m_netManager;
};

