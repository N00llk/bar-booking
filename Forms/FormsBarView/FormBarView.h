#pragma once

#include <QWidget>

#include "ITransport.h"

namespace Ui {
class FormBarView;
}

class FormBarView : public QWidget
{
    Q_OBJECT

public:
    explicit FormBarView(ITransport& transport, User& activeUser, QWidget *parent = nullptr);
    ~FormBarView();

private:
    Ui::FormBarView *ui;
    ITransport& m_transport;
    const User& m_activeUser;
};

