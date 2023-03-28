#include "ogre3dwindow.h"
#include "ogre3dapplication.h"
#include <QResizeEvent>
#include <iostream>
Ogre3DWindow::Ogre3DWindow(QWindow *parent)
    : QWindow(parent), m_backingStore(new QBackingStore(this))
{
    m_ogre3DApplication = nullptr;
}

Ogre3DWindow::~Ogre3DWindow()
{
    delete m_ogre3DApplication;
}

void Ogre3DWindow::exposeEvent(QExposeEvent *)
{
    if (isExposed())
    {
        renderNow();
    }
}

void Ogre3DWindow::resizeEvent(QResizeEvent *resizeEvent)
{
    m_backingStore->resize(resizeEvent->size());
    if (m_ogre3DApplication)
    {
        m_ogre3DApplication->resize(resizeEvent->size());
    }
}

void Ogre3DWindow::renderNow()
{
    if (!isExposed())
    {
        return;
    }

    if (m_ogre3DApplication)
    {
        m_ogre3DApplication->renderOneFrame();
    }

    QRect rect(0, 0, width(), height());
    m_backingStore->beginPaint(rect);

    QPaintDevice *device = m_backingStore->paintDevice();
    QPainter painter(device);

    painter.drawImage(0, 0, QImage(m_backingStore->size(), QImage::Format_ARGB32));
    painter.end();

    m_backingStore->endPaint();
    m_backingStore->flush(rect);
}

bool Ogre3DWindow::event(QEvent *event)
{
    if (event->type() == QEvent::UpdateRequest)
    {
        renderNow();
        return true;
    }
    return QWindow::event(event);
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

