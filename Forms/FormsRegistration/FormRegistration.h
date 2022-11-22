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

signals:
    void authorizationRequested(void);

private:
    Ui::FormRegistration *ui;
};

