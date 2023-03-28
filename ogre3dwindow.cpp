#include "ogre3dwindow.h"
#include "ogre3dapplication.h"
#include <QResizeEvent>

Ogre3DWindow::Ogre3DWindow(QWindow *parent)
    : QWindow(parent)
{
    m_ogre3DApplication = nullptr;
}

Ogre3DWindow::~Ogre3DWindow()
{
    delete m_ogre3DApplication;
}

void Ogre3DWindow::resizeEvent(QResizeEvent *event)
{
    if (m_ogre3DApplication)
    {
        m_ogre3DApplication->resize(event->size());
    }
}

void Ogre3DWindow::init()
{
    m_ogre3DApplication = new Ogre3DApplication(this);
    m_ogre3DApplication->initApp();
}

void Ogre3DWindow::startRendering()
{
    if (m_ogre3DApplication)
    {
        m_ogre3DApplication->getRoot()->startRendering();
        m_ogre3DApplication->closeApp();
    }
}

