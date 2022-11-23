#include "User.h"

User::User()
{

}

void User::create(RoleEnum role, QString accessToken, QString refreshToken)
{
    m_userRole = role;
    m_accessToken = accessToken;
    m_refreshToken = refreshToken;
}

void User::cleanup()
{
    m_userRole = RoleEnum::Invalide;
    m_accessToken = "";
    m_refreshToken = "";
}
