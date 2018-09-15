#ifndef SCENE_H
#define SCENE_H

struct PointerCoords;

/* Represents a scene. A scene is an object that knows how to render itself to the
 * screen and knows how to react to input. At any moment in the game, exactly one
 * scene is active, and that scene is the one who decides what gets drawn to the
 * screen and how input is handled. See also: SceneManager */
class Scene {
    public:
        // Called when graphics context is initialized. This is when textures,
        // geometry, etc should be initialized.
        virtual void OnStartGraphics();

        // Called when the graphics context is about to be shut down. Tear down
        // all geometry, textures, etc.
        virtual void OnKillGraphics();

        // Called when this scene has just been installed as the active scene.
        virtual void OnInstall();

        // Called when it's time to draw a frame to the screen.
        virtual void DoFrame();

        // Called when this scene is about to be uninstalled as the active scene.
        virtual void OnUninstall();

        // Called when a pointer goes down (e.g. touch, touchpad, etc)
        virtual void OnPointerDown(int pointerId, const struct PointerCoords *coords);

        // Called when a pointer goes up (e.g. touch, touchpad, etc)
        virtual void OnPointerUp(int pointerId, const struct PointerCoords *coords);

        // Called when a pointer moves (e.g. touch, touchpad, etc)
        virtual void OnPointerMove(int pointerId, const struct PointerCoords *coords);

        // Called when the device's back key is pressed
        virtual bool OnBackKeyPressed();

        // Called when a key goes down
        virtual void OnKeyDown(int ourKeyCode);

        // Called when a key goes up
        virtual void OnKeyUp(int ourKeyCode);

        // Called when there is joystick input. joyX and joyY are in the range [-1.0,1.0].
        virtual void OnJoy(float joyX, float joyY);

        // Called when screen gets resized
        virtual void OnScreenResized(int width, int height);

        // Called when game is paused (e.g. onPause())
        virtual void OnPause();

        // Called when game is resumed (e.g. onResumed())
        virtual void OnResume();

        // Destructor
        virtual ~Scene();
};

#endif // SCENE_H
