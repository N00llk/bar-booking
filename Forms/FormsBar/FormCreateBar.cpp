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
    ui->kitchenLineEdit->setPlaceholderText("@Кухня");
    ui->categoryLineEdit->setPlaceholderText("@Категория");
    ui->descriptionPlainTextEdit->setPlaceholderText("@Описание");
    ui->emailLineEdit->setPlaceholderText("@email");

    connect(ui->cancelBarAddpushButton, &QPushButton::clicked, this, &FormCreateBar::barCreationCanceled);
}

FormCreateBar::~FormCreateBar()
{
    delete ui;
}
