#include <QApplication>
#include "gamewindow.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSurfaceFormat format;
    format.setDepthBufferSize(24);
    format.setStencilBufferSize(8);
    format.setVersion(2,1);
    GameWindow window;
    window.resize(800, 600);
    window.setFormat(format);
    window.show();
    return a.exec();
}
