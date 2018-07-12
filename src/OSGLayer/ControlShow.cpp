#include "..\..\include\OSGLayer\ControlShow.h"

jyControlShow::jyControlShow(QObject *parent) {
  
}

osgQt::GraphicsWindowQt * jyControlShow::CreatGraphicsWinQt(int x, int y, int w, int h, const std::string & name, bool windowDecoration)
{
  //和抗锯齿有关
 // osg::DisplaySettings *ds = osg::DisplaySettings::instance().get();
  osg::ref_ptr<osg::GraphicsContext::Traits> traits = new osg::GraphicsContext::Traits;
  traits->windowName = name;
  //窗口装饰属性，如最大化最小化
  traits->windowDecoration = windowDecoration;
  traits->x = x;
  traits->y = y;
  traits->width = w;
  traits->height = h;
  traits->doubleBuffer = true;
 
  //alpha通道？表示灰度级？
  /*
  traits->alpha = ds->getMinimumNumAlphaBits();
  //模板缓冲？用于限制渲染区域，对应osg中的拣选工作？
  traits->stencil = ds->getMinimumNumStencilBits();
  //采样？
  traits->samples = ds->getMultiSamples();
  traits->sampleBuffers = ds->getNumMultiSamples();
  */
  m_pGraphics = new osgQt::GraphicsWindowQt(traits.get());
 // return new osgQt::GraphicsWindowQt(traits.get());
  return m_pGraphics;
}

QWidget * jyControlShow::addViewWidget(osg::Node * modelData)
{
  m_pNode = new osg::Node;
  m_pNode = modelData;
  m_pNo1Viewer = new osgViewer::Viewer();
  const osgQt::GraphicsWindowQt::Traits *traits = m_pGraphics->getTraits();
  osg::Camera *_temCamera = m_pNo1Viewer->getCamera();
  _temCamera->setGraphicsContext(m_pGraphics);
  _temCamera->setClearColor(osg::Vec4(0.2,0.2,0.6,1.0));
  _temCamera->setViewport(0, 0, traits->width, traits->height);
  //--
  osg::Vec3d eye, center, up;
  _temCamera->getViewMatrixAsLookAt(eye, center, up);
  eye=osg::Vec3d(0.0,-20.0,0.0);
  center=osg::Vec3d(0.0,0.0,0.0);
  up=osg::Vec3d(0.0,0.0,1.0);
  _temCamera->setViewMatrixAsLookAt(eye, center, up);
  
  m_pNo1Viewer->setSceneData(m_pNode);
  m_pNo1Viewer->addEventHandler(new osgViewer::StatsHandler);
  //m_pNo1Viewer->setCameraManipulator(new osgGA::TrackballManipulator);
  m_pNo1Viewer->setThreadingModel(osgViewer::Viewer::SingleThreaded);
  return m_pGraphics->getGLWidget();
}

void jyControlShow::flashWindow()
{
  m_pNo1Viewer->frame();
}

void jyControlShow::changeGraphics()
{
 // osg::Node *test = new osg::Node;
  m_pNode = osgDB::readNodeFile("C://Users//Administrator//Downloads//OpenSceneGraph-Data-3.0.0//OpenSceneGraph-Data-3.0.0//cow.osg");
  m_pNo1Viewer->setSceneData(m_pNode);
}
//先缩放后旋转再平移
void jyControlShow::stretchingChange()
{
  osg::ref_ptr<osg::MatrixTransform> _pTrans = new osg::MatrixTransform();
  _pTrans->setMatrix(osg::Matrix::scale(1, 1, 0.5));
  _pTrans->addChild(m_pNode.get());
  m_pNo1Viewer->setSceneData(_pTrans.get());

}

void jyControlShow::RotateChange()
{
}

void jyControlShow::TranslatipnChange()
{
}

