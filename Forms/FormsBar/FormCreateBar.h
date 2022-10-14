#pragma once

#include <QWidget>

namespace Ui {
class FormCreateBar;
}

class FormCreateBar : public QWidget
{
    Q_OBJECT

public:
    explicit FormCreateBar(QWidget *parent = nullptr);
    ~FormCreateBar();

private:
    Ui::FormCreateBar *ui;
};

