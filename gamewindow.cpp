#include "gamewindow.h"
#include <QTimer>
#include <QKeyEvent>
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

    installEventFilter(this);

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
    //Do nothing
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
    update();
}

bool GameWindow::eventFilter(QObject *obj, QEvent *event) {
    if (event->type() == QEvent::MouseButtonPress) {
        qDebug() << "eventFilter called" << endl;
        SceneManager *mgr = SceneManager::GetInstance();
        mgr->GetScene()->OnMouseDown();
    } else if (event->type() == QEvent::KeyPress) {
        QKeyEvent* key = static_cast<QKeyEvent*>(event);
        SceneManager *mgr = SceneManager::GetInstance();
        switch (key->key()) {
        case Qt::Key_A:
            mgr->GetScene()->OnJoy(-0.3, 0.0);
            break;
        case Qt::Key_D:
            mgr->GetScene()->OnJoy(0.3, 0.0);
            break;
        case Qt::Key_W:
            mgr->GetScene()->OnJoy(0.0, -0.3);
            break;
        case Qt::Key_S:
            mgr->GetScene()->OnJoy(0.0, 0.3);
            break;
        default:
            break;
        }
    }
    return QObject::eventFilter(obj, event);
}


