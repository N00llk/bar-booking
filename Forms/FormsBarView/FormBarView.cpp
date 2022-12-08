#include "FormBarView.h"
#include "ui_FormBarView.h"

#include "FormBarSmallPreview.h"
#include "FormAddNewBar.h"

FormBarView::FormBarView(ITransport &transport, User& activeUser, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormBarView),
    m_transport(transport),
    m_activeUser(activeUser),
    m_addNewBarForm(new FormAddNewBar(this))
{
    ui->setupUi(this);

    connect(m_addNewBarForm, &FormAddNewBar::barCreationRequested, this, &FormBarView::barCreationRequested);
    ui->scrollAreaWidgetContents->layout()->addWidget(new FormBarSmallPreview(this));
    ui->scrollAreaWidgetContents->layout()->addWidget(m_addNewBarForm);
}

FormBarView::~FormBarView()
{
    delete ui;
}
