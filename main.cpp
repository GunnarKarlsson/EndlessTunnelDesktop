#include <QApplication>
#include "gamewindow.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSurfaceFormat format;
    format.setDepthBufferSize(24);
    format.setVersion(2,1);
    //format.setProfile(QSurfaceFormat::defaultFormat());
    QSurfaceFormat::setDefaultFormat(format);

    GameWindow window;
    window.resize(800, 600);
    window.show();

    int major = 0;
    int minor = 0;
    glGetIntegerv(GL_MAJOR_VERSION, &major);
    glGetIntegerv(GL_MINOR_VERSION, &minor);
    qDebug() << "major: " << major << endl;
    qDebug() << "minor:" << minor << endl;
    QString versionString(QLatin1String(reinterpret_cast<const char*>(glGetString(GL_VERSION))));
        qDebug() << "Driver Version String:" << versionString;
        qDebug() << "Current Context:" << window.format();
    return a.exec();
}
