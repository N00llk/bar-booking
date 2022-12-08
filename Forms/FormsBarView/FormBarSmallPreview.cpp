#include "FormBarSmallPreview.h"
#include "ui_FormBarSmallPreview.h"

#include <QPainter>
#include <QBitmap>

FormBarSmallPreview::FormBarSmallPreview(const Bar& bar, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormBarSmallPreview),
    m_bar(bar)
{
    ui->setupUi(this);

    ui->barNameLabel->setText(m_bar.m_name);
    ui->barAddressLabel->setText(m_bar.m_address);
    ui->barImageLabel->setPixmap(m_bar.m_imagePreview);
    ui->barImageLabel->setScaledContents(true);
    ui->barImageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    connect(ui->barOpenPushButton, &QPushButton::pressed, this, &FormBarSmallPreview::onBarOpenPushButtonPressed);
}

FormBarSmallPreview::~FormBarSmallPreview()
{
    delete ui;
}

void FormBarSmallPreview::onBarOpenPushButtonPressed()
{
    emit barOpeningRequest(m_bar);
}
