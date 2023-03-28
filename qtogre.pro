QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets opengl

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    ogre3dmainwindow.cpp \
    ogre3dapplication.cpp \
    ogre3dwindow.cpp

HEADERS += \
    ogre3dmainwindow.h \
    ogre3dapplication.h \
    ogre3dwindow.h

FORMS += \
    ogre3dmainwindow.ui

#DEFINES += OGRE_BUILD_DLL OGRE_UNICODE_SUPPORT OGRE_DEBUG_MODE

OgreFolder  = "C:\ogre-13.6.3\build\sdk"

INCLUDEPATH += "$$OgreFolder\include\OGRE" "$$OgreFolder\include\OGRE\Bites" "$$OgreFolder\include\OGRE\RTShaderSystem"

#LIBS     += -L$$OgreFolder\bin -lOgreMain -lOgreBites -lOgreBitesQt -lOgreRTShaderSystem
LIBS     += -L$$OgreFolder\lib -lOgreMain -lOgreBitesQt -lOgreBites -lOgreRTShaderSystem

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
