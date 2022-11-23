#pragma once

#include <QWidget>

#include <ITransport.h>

namespace Ui {
class FormRegistration;
}

class FormRegistration : public QWidget
{
    Q_OBJECT

public:
    explicit FormRegistration(ITransport& transport, QWidget *parent = nullptr);
    ~FormRegistration();

private:
    Ui::FormRegistration *ui;
    ITransport& m_transport;

signals:
    void registrationSuccess(void);
    void registrationFail(void);
    void authorizationRequested(void);

private slots:
    void onRegistrationPressed(void);
    void onRegistrationReply(QNetworkReply* reply);
};

