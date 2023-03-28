#ifndef OGRE3DWINDOW_H
#define OGRE3DWINDOW_H

#include <QtGui>
#include <QScopedPointer>

class Ogre3DApplication;

/**
 * @brief The Ogre3DWindow class. This class inherits from QWindow and is used as base to use the Ogre 3D objects.
 * Further explanation: Reasons for using QWindow over QWidget
 *
 * Smaller memory and processing footprint. Simply put, QWidgets use a lot of resources in comparison to QWindows and thus
 * adds a lot of unnecessary overhead. Ogre3D doesn't require much from Qt besides a surface to draw upon and the input/window
 * events from the underlying OS and windowing system that a QWindow provides. As a related sidenote, QWidget actually inherits
 * from QWindow as shown in the below inheritance chain.
 * Easier integration. Because of the simplicity of QWindow it is actually much easier to integrate Ogre3D into Qt using a QWindow
 * versus using a QWidget. QWidget by default creates a surface to draw on which Ogre3D doesn't need to draw upon. Thus, as shown
 * in earlier Qt-Ogre3D implementation documents you need to override Qt methods to prevent the default QWidget methods from
 * "drawing over" Ogre3D. Using a QWindow this is unnecessary as with a QWindow no "surface" is automatically created; you can simply
 * supply QWindow's native "Window ID" (whether it is a HWND on Windows or the equivalent representations on Linux/Mac OS) and Ogre3D
 * takes care of the rest.
 * All standard Qt functionality can still be implemented. If you still need to have a QWidget (for integration into a
 * QMainWindow/QTabWidget/etc.) this can still be achieved. You can easily create a QWidget "container" for your QWindow and get all
 * of the standard benefits of a QWidget. A standard use case for this would be needing to place an Ogre3D-integrated QWindow inside
 * of a standard QMainWindow as a "central widget".
 *
 * See https://doc.qt.io/qt-6/qtgui-rasterwindow-example.html.
 * See https://wiki.ogre3d.org/Qt. https://wiki.ogre3d.org/QtOgre. https://wiki.ogre3d.org/Ogre+overlays+using+Qt.
 * See https://wiki.ogre3d.org/Integrating+Ogre+into+QT5.
 */
class Ogre3DWindow : public QWindow
{
    Q_OBJECT

public:
    /**
     * @brief Ogre3DWindow. Constructor.
     * @param parent. This is the parent widget, it is used for Qt purposes.
     */
    Ogre3DWindow(QWindow *parent = nullptr);

    /**
     * @brief ~Ogre3DMainWindow. Destructor.
     */
    ~Ogre3DWindow();

public slots:
    /**
     * @brief renderNow. Slot used to render the Ogre 3D content in the QWindow avoiding flickering.
     */
    void renderNow();

protected:
    /**
     * @brief event. Overridden method used to handle the update event. When the event comes in we call renderNow() to render the window right away.
     * @param event. The new event that comes.
     * @return The QWindow event.
     */
    bool event(QEvent *event) override;

    /**
     * @brief resizeEvent. Overridden method used to detect changes in the window geometry and act accordingly.
     * @param event. The new size event to be applied to the new window geoemtry.
     */
    void resizeEvent(QResizeEvent *event) override;

    /**
     * @brief exposeEvent. Overridden method used to notify us that the window's exposure in the windowing system has changed.
     * @param event. The event that contains the exposed sub-region, but since we will anyway draw the entire window every time, we do not make use of that.
     */
    void exposeEvent(QExposeEvent *event) override;

public:
    /**
     * @brief init. Inits the ApplicationContextQt and the scene objects by creating the needed Ogre 3D objects.
     */
    void init();
    /**
     * @brief startRendering. Starts the rendering by calling to the Ogre 3D startRendering primitive.
     */
    void startRendering();

private:
    /**
     * @brief m_ogre3DApplication. The Ogre 3D core application in charge of rendering.
     */
    Ogre3DApplication* m_ogre3DApplication;
    /**
     * @brief m_backingStore. Is what we use to manage the window's back buffer for QPainter based graphics.
     */
    QScopedPointer<QBackingStore> m_backingStore;
};
#endif // OGRE3DWINDOW_H
