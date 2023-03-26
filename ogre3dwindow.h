#ifndef OGRE3DWINDOW_H
#define OGRE3DWINDOW_H

#include <QWindow>

class Ogre3DApplication;

QT_BEGIN_NAMESPACE
namespace Ui { class Ogre3DWindow; }
QT_END_NAMESPACE

class Ogre3DWindow : public QWindow
{
    Q_OBJECT

public:
    Ogre3DWindow(QWindow *parent = nullptr);
    ~Ogre3DWindow();
    void startRendering();
    void init();
    void resizeEvent(QResizeEvent *event);

private:
    Ui::Ogre3DWindow *ui;
    Ogre3DApplication* m_ogre3DApplication;
};
#endif // OGRE3DWINDOW_H
