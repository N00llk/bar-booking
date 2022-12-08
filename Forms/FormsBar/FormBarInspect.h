#pragma once

#include <QWidget>

namespace Ui {
class FormBarInspect;
}

class FormBarInspect : public QWidget
{
    Q_OBJECT

public:
    explicit FormBarInspect(QWidget *parent = nullptr);
    ~FormBarInspect();

private:
    Ui::FormBarInspect *ui;
};

