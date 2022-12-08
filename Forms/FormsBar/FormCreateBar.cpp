#include "FormCreateBar.h"
#include "ui_FormCreateBar.h"

FormCreateBar::FormCreateBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormCreateBar)
{
    ui->setupUi(this);

    ui->barNameLineEdit->setPlaceholderText("@New_bar");
    ui->addressLineEdit->setPlaceholderText("@Санкт-Петербург");
    ui->phoneNumberLineEdit->setPlaceholderText("0000000000");
    ui->barNetLineEdit->setPlaceholderText("@сеть_баров");
    ui->emailLineEdit->setPlaceholderText("-");

    connect(ui->cancelBarAddpushButton, &QPushButton::clicked, this, &FormCreateBar::barCreationCanceled);
}

FormCreateBar::~FormCreateBar()
{
    delete ui;
}
