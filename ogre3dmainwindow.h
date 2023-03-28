#ifndef OGRE3DMAINWINDOW_H
#define OGRE3DMAINWINDOW_H

#include <QMainWindow>

class Ogre3DWindow;

QT_BEGIN_NAMESPACE
namespace Ui { class Ogre3DMainWindow; }
QT_END_NAMESPACE

/**
 * @brief The Ogre3DMainWindow class. This class inherits from QMainWindow and is used as entry point to drop Qt controls and Ogre 3D render in a Window.
 */
class Ogre3DMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    /**
     * @brief Ogre3DMainWindow. Constructor.
     * @param parent. This is the parent widget, it is used for Qt purposes.
     */
    Ogre3DMainWindow(QWidget *parent = nullptr);

    /**
     * @brief ~Ogre3DMainWindow. Destructor.
     */
    ~Ogre3DMainWindow();

    /**
     * @brief Starts the rendering by calling to the QWindow used for Ogre 3D.
     */
    void startRendering();

private slots:
    /**
     * @brief onAttachToLayoutPushButtonClicked. Slot used to attach the QWindow used for Ogre 3D to the layout.
     */
    void onAttachToLayoutPushButtonClicked();

private:
    /**
     * @brief ui. User interface object that contains all the visual components of the main window.
     */
    Ui::Ogre3DMainWindow *ui;
    /**
     * @brief m_ogre3DWindow. The QWindows used for Ogre 3D to render a scene.
     */
    Ogre3DWindow* m_ogre3DWindow;
    /**
     * @brief m_containerWidget. The QWidget used to wrap the QMainWindow and attach to layout.
     */
    QWidget* m_containerWidget;
};

#endif // OGRE3DMAINWINDOW_H
