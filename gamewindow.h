#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QOpenGLWindow>
#include <QOpenGLFunctions>

class GameWindow : public QOpenGLWindow, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    GameWindow();
    ~GameWindow();
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
    void teardownGL();

public slots:
    void doFrame();
private:
    bool mIsFirstFrame = true;

private:

};

#endif // GAMEWINDOW_H
