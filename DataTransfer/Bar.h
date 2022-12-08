#pragma once

#include <QString>
#include <QTime>
#include <QPixmap>


class Bar
{
public:
    Bar(QString name, QString address, QPixmap imagePreview);
public:
    QString m_name;
    QString m_address;
    QTime   m_openTime;
    QTime   m_closeTime;
    QPixmap m_imagePreview;
};

