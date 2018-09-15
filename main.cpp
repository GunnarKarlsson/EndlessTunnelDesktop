#include <QApplication>
#include "gamewindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameWindow window;
    window.resize(800, 600);
    window.show();

    return a.exec();
}
