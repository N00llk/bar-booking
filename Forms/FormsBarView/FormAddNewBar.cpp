#include "FormAddNewBar.h"
#include "ui_FormAddNewBar.h"

FormAddNewBar::FormAddNewBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormAddNewBar)
{
    ui->setupUi(this);

    connect(ui->addNewBarLabel, &QLabel::linkActivated, this, &FormAddNewBar::barCreationRequested);
}

FormAddNewBar::~FormAddNewBar()
{
    delete ui;
}
