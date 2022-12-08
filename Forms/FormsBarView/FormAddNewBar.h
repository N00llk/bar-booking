#pragma once

#include <QWidget>

namespace Ui {
class FormAddNewBar;
}

class FormAddNewBar : public QWidget
{
    Q_OBJECT

public:
    explicit FormAddNewBar(QWidget *parent = nullptr);
    ~FormAddNewBar();

signals:
    void barCreationRequested(void);

private:
    Ui::FormAddNewBar *ui;
};

