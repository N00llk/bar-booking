#include "MainWindow.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile styleFile(":/styles/bar-booking.qss");

    if (styleFile.open(QFile::ReadOnly))
    {
        a.setStyleSheet(QLatin1String(styleFile.readAll()));
        styleFile.close();
    }

    MainWindow w;
    w.show();
    return a.exec();
}
