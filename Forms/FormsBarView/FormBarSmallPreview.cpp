#include "FormBarSmallPreview.h"
#include "ui_FormBarSmallPreview.h"

FormBarSmallPreview::FormBarSmallPreview(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormBarSmallPreview)
{
    ui->setupUi(this);
}

FormBarSmallPreview::~FormBarSmallPreview()
{
    delete ui;
}
