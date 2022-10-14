#pragma once

#include <QWidget>

namespace Ui {
class FormOwner;
}

class FormOwner : public QWidget
{
    Q_OBJECT

public:
    explicit FormOwner(QWidget *parent = nullptr);
    ~FormOwner();

private:
    Ui::FormOwner *ui;
};

