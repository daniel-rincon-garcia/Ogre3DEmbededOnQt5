#include "ogre3dapplication.h"
#include <OgreRTShaderSystem.h>

Ogre3DApplication::Ogre3DApplication(QWindow *windowToInject): ApplicationContextQt("Tutorial App"), m_windowToInject(windowToInject), m_root(nullptr), m_renderWindow(nullptr)
{
    injectMainWindow(windowToInject);
}

Ogre3DApplication::~Ogre3DApplication()
{
    delete m_renderWindow;
    delete m_windowToInject;
    delete m_root;
}

bool Ogre3DApplication::keyPressed(const OgreBites::KeyboardEvent& evt)
{
    if (evt.keysym.sym == OgreBites::SDLK_ESCAPE)
    {
        m_root->queueEndRendering();
    }
    return true;
}
bool Ogre3DApplication::mouseMoved(const OgreBites::MouseMotionEvent& evt)
{

}
bool Ogre3DApplication::mousePressed(const OgreBites::MouseButtonEvent& evt)
{

}
bool Ogre3DApplication::mouseReleased(const OgreBites::MouseButtonEvent& evt)
{

}

void Ogre3DApplication::resize(QSize size)
{
    if (m_renderWindow)
    {
        m_renderWindow->resize(size.width(), size.height());
    }
}

void Ogre3DApplication::setup()
{
    // do not forget to call the base first
    ApplicationContextQt::setup();
    addInputListener(this);
    m_root = getRoot();
    //m_root->loadPlugin("RenderSystem_GLES2");//RenderSystem_GL
    Ogre::RenderSystem* rs = m_root->getRenderSystemByName("OpenGL Rendering Subsystem");//OpenGL ES 2.x Rendering Subsystem
    m_root->setRenderSystem(rs);
    //rs->setConfigOption("Full Screen", "No");
    //rs->setConfigOption("Video Mode", "800 x 600 @ 32-bit colour");
    Ogre::NameValuePairList params;
    params["externalWindowHandle"] = Ogre::StringConverter::toString(reinterpret_cast<size_t>(m_windowToInject->winId()));
    //params["sRGB"] = "true";
    //params["currentGLContext"] = "true";
    //params["glEsVersion"] = "2";
    m_renderWindow = m_root->createRenderWindow("QT Window", m_windowToInject->width(), m_windowToInject->height(), false, &params);
    m_renderWindow->setVisible(true);
    //m_renderWindow->setVSyncEnabled(true);
    //m_renderWindow->setVSyncInterval(0);
    Ogre::SceneManager* scnMgr = m_root->createSceneManager();
    m_renderWindow->setActive(true);
    // register our scene with the RTSS
    /*Ogre::RTShader::ShaderGenerator* shadergen = Ogre::RTShader::ShaderGenerator::getSingletonPtr();
    shadergen->addSceneManager(scnMgr);
    shadergen->setTargetLanguage("glsles"); // Selecciona el lenguaje para el que se generarán los shaders.
    mShaderGenerator->setShaderCachePath("./shader_cache/"); // Especifica la ruta donde se guardará la caché de shaders generados.*/
    // -- tutorial section start --
    //! [turnlights]
    scnMgr->setAmbientLight(Ogre::ColourValue(0.5, 0.5, 0.5));
    //! [turnlights]

    //! [newlight]
    Ogre::Light* light = scnMgr->createLight("MainLight");
    Ogre::SceneNode* lightNode = scnMgr->getRootSceneNode()->createChildSceneNode();
    lightNode->attachObject(light);
    //! [newlight]

    //! [lightpos]
    lightNode->setPosition(20, 80, 50);
    //! [lightpos]

    //! [camera]
    Ogre::SceneNode* camNode = scnMgr->getRootSceneNode()->createChildSceneNode();

    // create the camera
    Ogre::Camera* cam = scnMgr->createCamera("myCam");
    cam->setNearClipDistance(5); // specific to this sample
    cam->setAutoAspectRatio(true);
    camNode->attachObject(cam);
    camNode->setPosition(0, 0, 140);
    m_renderWindow->addViewport(cam);
    //! [camera]

    Ogre::Entity* ogreEntity = scnMgr->createEntity("Barrel.mesh");
    Ogre::Entity* sphereEntity = scnMgr->createEntity("sphere", Ogre::SceneManager::PT_SPHERE);
    //! [entity1]

    //! [entity1node]
    Ogre::SceneNode* ogreNode = scnMgr->getRootSceneNode()->createChildSceneNode();
    //! [entity1node]

    //! [entity1nodeattach]
    ogreNode->attachObject(sphereEntity);
    //! [entity1nodeattach]

    //! [cameramove]
    camNode->setPosition(0, 47, 222);
    //! [cameramove]

    //! [entity2]
    Ogre::Entity* ogreEntity2 = scnMgr->createEntity("Barrel.mesh");
    Ogre::SceneNode* ogreNode2 = scnMgr->getRootSceneNode()->createChildSceneNode(Ogre::Vector3(84, 48, 0));
    ogreNode2->attachObject(ogreEntity2);
    //! [entity2]

    //! [entity3]
    Ogre::Entity* ogreEntity3 = scnMgr->createEntity("Barrel.mesh");
    Ogre::SceneNode* ogreNode3 = scnMgr->getRootSceneNode()->createChildSceneNode();
    ogreNode3->setPosition(0, 104, 0);
    ogreNode3->setScale(2, 1.2, 1);
    ogreNode3->attachObject(ogreEntity3);
    //! [entity3]

    //! [entity4]
    Ogre::Entity* ogreEntity4 = scnMgr->createEntity("ogrehead.mesh");
    Ogre::SceneNode* ogreNode4 = scnMgr->getRootSceneNode()->createChildSceneNode();
    ogreNode4->setPosition(-84, 48, 0);
    ogreNode4->roll(Ogre::Degree(-90));
    ogreNode4->attachObject(ogreEntity4);
}
