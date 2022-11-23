#pragma once

#include <QObject>
#include <QNetworkAccessManager>
#include <User.h>

class ITransport
{
public:
    struct LoginStruct
    {
        QString email;
        QString password;
    };

    struct RegistrationStruct
    {
        QString name;
        QString surname;
        QString patronymic;
        QString email;
        QString phone;
        QString password;
        User::RoleEnum role;
    };

    virtual void requestLoginUser(const QObject* sender, const char* senderSlot, const LoginStruct& data) = 0;
    virtual void requestRegisterUser(const QObject* sender, const char* senderSlot, const RegistrationStruct& data) = 0;
};

