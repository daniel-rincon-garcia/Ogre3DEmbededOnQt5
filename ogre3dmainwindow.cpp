#include "ogre3dmainwindow.h"
#include "ui_ogre3dmainwindow.h"
#include "ogre3dwindow.h"

Ogre3DMainWindow::Ogre3DMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Ogre3DMainWindow)
{
    ui->setupUi(this);
    connect(ui->attachToLayoutPushButton, &QPushButton::clicked, this, &Ogre3DMainWindow::onAttachToLayoutPushButtonClicked);
    m_ogre3DWindow = new Ogre3DWindow();
    m_ogre3DWindow->init();
    m_ogre3DWindow->show();
    m_containerWidget = nullptr;
}

Ogre3DMainWindow::~Ogre3DMainWindow()
{
    delete ui;
    delete m_ogre3DWindow;
}

void Ogre3DMainWindow::startRendering()
{
    m_ogre3DWindow->startRendering();
}

void Ogre3DMainWindow::onAttachToLayoutPushButtonClicked()
{
    if (!m_containerWidget)
    {
        m_containerWidget = QWidget::createWindowContainer(m_ogre3DWindow, this);
        ui->horizontalLayout->addWidget(m_containerWidget);
    }
}
