#ifndef WELCOMESCENE_H
#define WELCOMESCENE_H

#include "engine.h"
#include "ourshader.h"
#include "texquad.h"
#include "uiscene.h"
#include "util.h"

/* The "welcome scene" (main menu) */
class WelcomeScene : public UiScene {
    protected:
        // IDs for our buttons:
        int mPlayButtonId;
        int mStoryButtonId;
        int mAboutButtonId;

        virtual void RenderBackground();
        virtual void OnButtonClicked(int id);

        void UpdateWidgetStates();

    public:
        WelcomeScene();
        ~WelcomeScene();

        virtual void OnCreateWidgets();
        virtual void OnStartGraphics();
        virtual void OnKillGraphics();

        virtual void DoFrame();

        virtual void OnMouseDown();
};

#endif // WELCOMESCENE_H
