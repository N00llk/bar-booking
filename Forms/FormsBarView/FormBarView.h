#pragma once

#include <QWidget>

#include "ITransport.h"

namespace Ui {
class FormBarView;
}

class FormAddNewBar;

class FormBarView : public QWidget
{
    Q_OBJECT

public:
    explicit FormBarView(ITransport& transport, User& activeUser, QWidget *parent = nullptr);
    ~FormBarView();

signals:
    void barCreationRequested(void);
    void barOpenRequested(const Bar& bar);

private:
    FormAddNewBar*      m_addNewBarForm;
    Ui::FormBarView*    ui;
    ITransport&         m_transport;
    const User&         m_activeUser;
    QVector<Bar>        m_barList;
};

