1.- Ogre 13.6.3 was used. Download soure code from https://www.ogre3d.org/download/sdk/sdk-ogre.
2.- Uncompress ogre-13.6.3.zip in C:\ogre-13.6.3
3.- Create a folder named build in C:\ogre-13.6.3
2.- Instructions to build Ogre (use CMake (cmake-gui) to build, see https://ogrecave.github.io/ogre/api/latest/building-ogre.html):
2.1.- Put "C:/ogre-13.6.3" in the "Where is the source code" text line edit.
2.2.- Put "C:/ogre-13.6.3/build" in the "Where to build the binaries" text line edit. This step is not mandatory but is very important to get OgreBitesQt library.
2.3.- Put "C:/Qt/5.15.2/mingw81_64/lib/cmake/Qt5" in the QT_DIR line edit. This step is not mandatory but is very important to get OgreBitesQt library.
2.4.- Put "C:/Qt/5.15.2/mingw81_64/lib/cmake/Qt5Core" in the Qt5Core_DIR line edit. This step is not mandatory but is very important to get OgreBitesQt library.
2.5.- Put "C:/Qt/5.15.2/mingw81_64/lib/cmake/Qt5Gui" in the Qt5Gui_DIR line edit. This step is not mandatory but is very important to get OgreBitesQt library.
2.6.- Put "C:/Qt/5.15.2/mingw81_64/lib/cmake/Qt5" in the Qt5_DIR line edit. This step is not mandatory but is very important to get OgreBitesQt library.
2.7.- Put "C:/Qt/5.15.2/mingw81_64/lib/cmake/Qt5" in the Qt_DIR line edit. This step is not mandatory but is very important to get OgreBitesQt library.
2.8.- Click on Configure.A dialogue will appear asking you to select a generator. Click Finish.
2.9.- Select the desired settings and click on Configure again and then click on Generate.
3.- Open cmd.exe and execute the next from build directory: cmake --build . --config Release
4.- Open cmd.exe and execute the next from build directory: cmake --build . --config Release --target install

Use Ogre 3D in a Qt application:
1.- Add C:\ogre-13.6.3\build\sdk\bin to the Path environment variable.
2.- Add the include paths and link with the next static or dynamic libraries in the .pro file:
OgreFolder  = "C:\ogre-13.6.3\build\sdk"

INCLUDEPATH += "$$OgreFolder\include\OGRE" "$$OgreFolder\include\OGRE\Bites" "$$OgreFolder\include\OGRE\RTShaderSystem"

#LIBS     += -L$$OgreFolder\bin -lOgreMain -lOgreBites -lOgreBitesQt -lOgreRTShaderSystem
LIBS     += -L$$OgreFolder\lib -lOgreMain -lOgreBitesQt -lOgreBites -lOgreRTShaderSystem
3.- Put plugins.cfg, resources.cfg and samples.cfg in the executable application.