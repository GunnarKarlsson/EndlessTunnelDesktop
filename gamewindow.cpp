#include "gamewindow.h"
#include <QTimer>
#include "scenemanager.h"
#include "welcomescene.h"
#include "playscene.h"

GameWindow::GameWindow() : QOpenGLWindow(QOpenGLWindow::NoPartialUpdate)
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
    SceneManager *mgr = SceneManager::GetInstance();
    mgr->StartGraphics();

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
    //glClear(GL_COLOR_BUFFER_BIT);
    doFrame();
}

void GameWindow::teardownGL()
{
    // Currently we have no data to teardown
}

void GameWindow::doFrame() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0f, 5.0f, 7.0f, 1.0f);

    SceneManager *mgr = SceneManager::GetInstance();
    mgr->SetScreenSize(width(), height());
    glViewport(0, 0, width(), height());

    if (mIsFirstFrame) {
        mIsFirstFrame = false;
        mgr->RequestNewScene(new WelcomeScene());
    }

    // render!
    mgr->DoFrame();
}


