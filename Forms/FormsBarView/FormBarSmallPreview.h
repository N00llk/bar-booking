#pragma once

#include <QWidget>

namespace Ui {
class FormBarSmallPreview;
}

class FormBarSmallPreview : public QWidget
{
    Q_OBJECT

public:
    explicit FormBarSmallPreview(QWidget *parent = nullptr);
    ~FormBarSmallPreview();

private:
    Ui::FormBarSmallPreview *ui;
};

