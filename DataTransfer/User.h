#pragma once

#include <QString>


class User
{
public:
    enum class RoleEnum
    {
        Invalide = 0,
        Owner = 1,
        Admin = 2
    };

    User();

    void create(RoleEnum role, QString accessToken, QString refreshToken);
    void cleanup();

    QString accessToken() { return m_accessToken; }
    QString refreshToken() { return m_refreshToken; }
    RoleEnum userRole() { return m_userRole; }

private:
    RoleEnum m_userRole;
    QString m_accessToken;
    QString m_refreshToken;
};

