#include "ogre3dmainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Ogre3DMainWindow w;
    w.show();
    w.startRendering();
    return a.exec();
}
