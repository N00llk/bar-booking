#include "ServerTransport.h"

#include <QUrlQuery>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QByteArray>

ServerTransport::ServerTransport():
    m_url(QUrl(m_stringUrl)),
    m_netManager(new QNetworkAccessManager(this))
{

}

void ServerTransport::requestLoginUser(const QObject *sender, const char *senderSlot, const LoginStruct &data)
{
    QNetworkRequest request(m_loginUrl);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject obj;
    obj["email"] = data.email;
    obj["password"] = data.password;

    QJsonDocument doc(obj);
    QByteArray requestBody = doc.toJson(QJsonDocument::Compact);

    connect(m_netManager, SIGNAL(finished(QNetworkReply*)), sender, senderSlot, Qt::ConnectionType::SingleShotConnection);

    m_netManager->post(request, requestBody);
}

void ServerTransport::requestRegisterUser(const QObject *sender, const char *senderSlot, const RegistrationStruct &data)
{
    const QString m_registrationUrlWithRole = m_registrationUrl + (data.role == User::RoleEnum::Owner ? "owner" : "admin");
    QNetworkRequest request(m_registrationUrlWithRole);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject obj;

    obj["name"] = data.name;
    obj["surname"] = data.surname;
    obj["patronymic"] = data.patronymic;
    obj["email"] = data.email;
    obj["phone"] = data.phone;
    obj["password"] = data.password;

    QJsonDocument doc(obj);
    QByteArray requestBody = doc.toJson(QJsonDocument::Compact);

    connect(m_netManager, SIGNAL(finished(QNetworkReply*)), sender, senderSlot, Qt::ConnectionType::SingleShotConnection);

    m_netManager->post(request, requestBody);
}
