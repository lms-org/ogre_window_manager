#ifndef SHARED_VISUAL_WINDOW_H
#define SHARED_VISUAL_WINDOW_H

#include <OGRE/OgreSceneManager.h>
#include <OGRE/OgreCamera.h>
#include <OGRE/OgreViewport.h>
#include <OGRE/OgreSceneNode.h>

#include <lms/logger.h>

class VisualManager;

namespace visual{

class Window{
public:

    Window();
    /**
     * @brief Window::init only call this method if you know what you are doing :)
     * @param rootLogger logger from the VisualManager used to create a childlogger
     * @param vm VisualManager that created the frame
     * @param width width of the frame
     * @param height hight of the frame
     * @param title title of the frame
     * @param movement_enabbled //TODO doesn't seem to work!
     * @param fullscreen //TODO doesn't work yet
     */
    void init(lms::logging::Logger& rootLogger, VisualManager* vm,int width,int height, const std::string &title,bool movement_enabled = true,bool fullscreen = false);
    ~Window();

    Ogre::SceneManager *getSceneManager() {
        return manager;
    }

    Ogre::Camera *getCamera() {
        return camera;
    }

    Ogre::RenderWindow *getGfxWindow() {
        return ogreWindow;
    }

    void update();

    void enableMovement(bool enabled) {
        movement_enabled = enabled;
    }
    
private:
    Ogre::SceneManager *manager;
    Ogre::Camera *camera;
    Ogre::Viewport *viewport;
    Ogre::RenderWindow *ogreWindow;

    VisualManager *creator;

    bool movement_enabled;
    lms::logging::Logger* logger;
};

}

#endif
