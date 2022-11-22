#include "ServerTransport.h"

#include <QUrlQuery>

ServerTransport::ServerTransport():
    m_url(QUrl(m_stringUrl)),
    m_netManager(new QNetworkAccessManager(this))
{

}

void ServerTransport::requestLoginUser(const QObject *sender, const char *senderSlot, const LoginStruct &data)
{
    QNetworkRequest request(m_url);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "bar-booking-desktop/" + sender->objectName());

    QUrlQuery params;
    params.addQueryItem("email", data.email);
    params.addQueryItem("password", data.password);

    connect(m_netManager, SIGNAL(finished(QNetworkReply*)), sender, senderSlot, Qt::ConnectionType::SingleShotConnection);

    m_netManager->post(request, params.query().toUtf8());
}
