#include "Viewer/ViewOSG.h"

void jyViewOSG::creatGraphicsWinQt(int x, int y, int w, int h, const std::string & name, bool windowDecoration)
{
  osg::ref_ptr<osg::GraphicsContext::Traits> traits = new osg::GraphicsContext::Traits;
  traits->windowName = name;
  traits->windowDecoration = windowDecoration;
  traits->x = x;
  traits->y = y;
  traits->width = w;
  traits->height = h;
  traits->doubleBuffer = true;
  this->setGraphics(new osgQt::GraphicsWindowQt(traits.get()));
}

QWidget * jyViewOSG::addWidget()
{
  m_pNode = new osg::Node;
  m_pNode = m_pRoot;
  m_pRoot->addChild(m_pDelta->getRoot());
  m_pRoot->addChild(m_pRec->getRoot());
  //m_pNo1Viewer = new osgViewer::Viewer();
  const osgQt::GraphicsWindowQt::Traits *traits = this->getGraphics()->getTraits();
  osg::Camera *_temCamera = m_pViewer->getCamera();
  _temCamera->setGraphicsContext(this->getGraphics());
  _temCamera->setClearColor(osg::Vec4(0.2, 0.2, 0.6, 1.0));
  _temCamera->setViewport(0, 0, traits->width, traits->height);
  m_pViewer->setSceneData(m_pNode);
  //设置事件处理
  m_pViewer->addEventHandler(new osgViewer::StatsHandler);
  //设置漫游器
  m_pViewer->setCameraManipulator(new osgGA::TrackballManipulator);
  //设置线程模式
  m_pViewer->setThreadingModel(osgViewer::Viewer::SingleThreaded);

  //绑定成员变量就是这个格式
  return m_pGraphics->getGLWidget();
}

osgQt::GraphicsWindowQt * jyViewOSG::getGraphics()
{
  return m_pGraphics;
}

void jyViewOSG::setGraphics(osgQt::GraphicsWindowQt *mGraphics)
{
  m_pGraphics = mGraphics;
}
