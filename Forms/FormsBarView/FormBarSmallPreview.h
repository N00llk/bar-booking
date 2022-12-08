#pragma once

#include <QWidget>
#include <Bar.h>

namespace Ui {
class FormBarSmallPreview;
}

class FormBarSmallPreview : public QWidget
{
    Q_OBJECT

public:
    explicit FormBarSmallPreview(const Bar& bar, QWidget *parent = nullptr);
    ~FormBarSmallPreview();

signals:
    void barOpeningRequest(const Bar& bar);

private slots:
    void onBarOpenPushButtonPressed();

private:
    Ui::FormBarSmallPreview *ui;
    const Bar& m_bar;
};

