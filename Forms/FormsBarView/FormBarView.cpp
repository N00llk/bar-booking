#include "FormBarView.h"
#include "ui_FormBarView.h"

FormBarView::FormBarView(ITransport &transport, User& activeUser, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormBarView),
    m_transport(transport),
    m_activeUser(activeUser)
{
    ui->setupUi(this);
}

FormBarView::~FormBarView()
{
    delete ui;
}
