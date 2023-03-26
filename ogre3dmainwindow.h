#ifndef OGRE3DMAINWINDOW_H
#define OGRE3DMAINWINDOW_H

#include <QMainWindow>

class Ogre3DWindow;

QT_BEGIN_NAMESPACE
namespace Ui { class Ogre3DMainWindow; }
QT_END_NAMESPACE

class Ogre3DMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    Ogre3DMainWindow(QWidget *parent = nullptr);
    ~Ogre3DMainWindow();
    void startRendering();
private slots:
    void onAttachToLayoutPushButtonClicked();

private:
    Ui::Ogre3DMainWindow *ui;
    Ogre3DWindow* m_ogre3DWindow;
    QWidget* m_containerWidget;
};

#endif // OGRE3DMAINWINDOW_H
