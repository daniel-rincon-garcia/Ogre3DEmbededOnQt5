#ifndef OGRE3DAPPLICATION_H
#define OGRE3DAPPLICATION_H

#include <Ogre.h>
#include <OgreApplicationContextQt.h>

/**
 * @brief The Ogre3DApplication class. This class inherits from ApplicationContextQt to render a scene and from InputListener to detect key pressed or mouse events.
 */
class Ogre3DApplication: public OgreBites::ApplicationContextQt, public OgreBites::InputListener
{
public:
    /**
     * @brief Ogre3DApplication. Constructor.
     * @param windowToInject. This is the QWindow, it is used for create a RenderWindow object.
     */
    Ogre3DApplication(QWindow *windowToInject = nullptr);

    /**
     * @brief ~Ogre3DApplication. Destructor.
     */
    ~Ogre3DApplication();

    /**
     * @brief Overridden method used to detect pressing inputs from keyboard.
     * @param evt Press event given by keyboard.
     * @return true
     */
    bool keyPressed(const OgreBites::KeyboardEvent& evt);

    /**
     * @brief Overridden method used to detect moving inputs from keyboard.
     * @param evt Move event given by mouse.
     * @return
     */
    bool mouseMoved(const OgreBites::MouseMotionEvent& evt);

    /**
     * @brief Overridden method used to detect pressing inputs from mouse.
     * @param evt Press event given by mouse.
     * @return
     */
    bool mousePressed(const OgreBites::MouseButtonEvent& evt);

    /**
     * @brief Overridden method used to detect releasing inputs from mouse.
     * @param evt Release event given by mouse.
     * @return
     */
    bool mouseReleased(const OgreBites::MouseButtonEvent& evt);

    /**
     * @brief Overridden method that setups all the needed things to render a scene.
     */
    void setup();

    /**
     * @brief Renders one frame. Use to avoid flickering.
     */
    void renderOneFrame();

    /**
     * @brief Resizes the window to a certain size.
     * @param size The new size to apply.
     */
    void resize(QSize size);

private:
    /**
     * @brief The ogre root used to instantiate objects.
     */
    Ogre::Root* m_root;
    /**
     * @brief The QWindow to inject to create the render window.
     */
    QWindow* m_windowToInject;
    /**
     * @brief The render window where the scene is painted.
     */
    Ogre::RenderWindow* m_renderWindow;
};

#endif // OGRE3DAPPLICATION_H
