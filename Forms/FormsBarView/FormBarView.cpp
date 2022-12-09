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

    m_barList.append(Bar("АРКА", "Большая Конюшенная ул, 27", QPixmap(":/images/bar-arka.jpeg")));
    m_barList.append(Bar("History club", "Конюшенная пл, 2в", QPixmap(":/images/bar-history.jpg")));
    m_barList.append(Bar("Gitano", "Садовая ул, 12", QPixmap(":/images/bar-gitano.jpg")));

    QIcon userProfileIcon(QPixmap(":/images/user-profile.png"));

    ui->userProfileToolButton->setIcon(userProfileIcon);
    ui->userProfileToolButton->setIconSize(QSize(40, 40));

    connect(m_addNewBarForm, &FormAddNewBar::barCreationRequested, this, &FormBarView::barCreationRequested);

    for (const Bar& bar: m_barList)
    {
        FormBarSmallPreview* smallViewForm = new FormBarSmallPreview(bar, this);
        connect(smallViewForm, &FormBarSmallPreview::barOpeningRequest, this, &FormBarView::barOpenRequested);
        ui->scrollAreaWidgetContents->layout()->addWidget(smallViewForm);
    }

    ui->scrollAreaWidgetContents->layout()->addWidget(m_addNewBarForm);
}

FormBarView::~FormBarView()
{
    delete ui;
}
