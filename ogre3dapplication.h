#ifndef OGRE3DAPPLICATION_H
#define OGRE3DAPPLICATION_H


#include <Ogre.h>
#include <OgreApplicationContextQt.h>

class Ogre3DApplication: public OgreBites::ApplicationContextQt, public OgreBites::InputListener
{
public:
    Ogre3DApplication(QWindow *windowToInject = nullptr);
    ~Ogre3DApplication();

    bool keyPressed(const OgreBites::KeyboardEvent& evt);
    bool mouseMoved(const OgreBites::MouseMotionEvent& evt);
    bool mousePressed(const OgreBites::MouseButtonEvent& evt);
    bool mouseReleased(const OgreBites::MouseButtonEvent& evt);

    void setup();

    void resize(QSize size);

private:
    Ogre::Root* m_root;
    QWindow* m_windowToInject;
    Ogre::RenderWindow* m_renderWindow;
};

#endif // OGRE3DAPPLICATION_H
