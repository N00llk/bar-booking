#pragma once

#include <QObject>
#include <QNetworkAccessManager>

class ITransport
{
public:
    struct LoginStruct
    {
        QString email;
        QString password;
    };

    virtual void requestLoginUser(const QObject* sender, const char* senderSlot, const LoginStruct& data) = 0;
};

