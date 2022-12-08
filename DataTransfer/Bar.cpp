#include "Bar.h"

#include <QBitmap>
#include <QPainter>

Bar::Bar(QString name, QString address, QPixmap imagePreview):
    m_name(name),
    m_address(address),
    m_imagePreview(imagePreview)
{
}
