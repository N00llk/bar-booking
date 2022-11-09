#pragma once

#include <QDialog>

namespace Ui {
class FormRegistration;
}

class FormRegistration : public QDialog
{
    Q_OBJECT

public:
    explicit FormRegistration(QWidget *parent = nullptr);
    ~FormRegistration();

private:
    Ui::FormRegistration *ui;
};

