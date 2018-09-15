#include "gamewindow.h"
#include <QTimer>

GameWindow::GameWindow()
{

}

GameWindow::~GameWindow()
{
    makeCurrent();
    teardownGL();
}

void GameWindow::initializeGL()
{
    // Initialize OpenGL Backend
    initializeOpenGLFunctions();
    //TODO: add OpenGL version log

    // Set global information
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(doFrame()));
    timer->start(20);
}

void GameWindow::resizeGL(int width, int height)
{
    // Currently we are not handling width/height changes
    (void)width;
    (void)height;
}

void GameWindow::paintGL()
{
    // Clear
    glClear(GL_COLOR_BUFFER_BIT);
}

void GameWindow::teardownGL()
{
    // Currently we have no data to teardown
}

void GameWindow::doFrame() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0f, 5.0f, 7.0f, 1.0f);
}


