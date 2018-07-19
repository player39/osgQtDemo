#include "..\..\include\Viewer\ViewerGroup.h"

osgQt::GraphicsWindowQt * jyViewerGroup::creatGraphicsWinQt(int x, int y, int w, int h, const std::string & name, bool windowDecoration)
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
  return this->getGranphics();
}

QWidget * jyViewerGroup::addWidget()
{
 // m_pModel = new jyOSGModel();
  m_pNode = new osg::Node;
  m_pNode = this->getModel()->returnRoot();
  //m_pNo1Viewer = new osgViewer::Viewer();
  const osgQt::GraphicsWindowQt::Traits *traits = this->getGranphics()->getTraits();
  osg::Camera *_temCamera =this->getCamera();
  _temCamera->setGraphicsContext(this->getGranphics());
  _temCamera->setClearColor(osg::Vec4(0.2, 0.2, 0.6, 1.0));
  _temCamera->setViewport(0, 0, traits->width, traits->height);
  this->setSceneData(m_pNode);
  //设置事件处理
  this->addEventHandler(new osgViewer::StatsHandler);
  //设置漫游器
  this->setCameraManipulator(new osgGA::TrackballManipulator);
  //设置线程模式
  this->setThreadingModel(osgViewer::Viewer::SingleThreaded);

  //绑定成员变量就是这个格式
  return this->getGranphics()->getGLWidget();
}

void jyViewerGroup::bindDataChangeSig()
{
  getControl()->sigLineRotate.connect(boost::bind(&jyViewerGroup::changeLineRotate,this));
  getControl()->sigLineStretching.connect(boost::bind(&jyViewerGroup::changeLineStretching, this));
  getControl()->sigLineTranslate.connect(boost::bind(&jyViewerGroup::changeLineTranslate, this));
  getControl()->sigLineReset.connect(boost::bind(&jyViewerGroup::changLineReset, this));
}

void jyViewerGroup::changeLineRotate()
{
  osg::ref_ptr<osg::MatrixTransform> _temMatrix = getModel()->getLineMatrixGroup();
  _temMatrix->setMatrix(_temMatrix->getMatrix()*osg::Matrix::rotate(osg::DegreesToRadians(getControl()->getSourceData()->getLineRotate()._angle), getControl()->getSourceData()->getLineRotate()._x, getControl()->getSourceData()->getLineRotate()._y, getControl()->getSourceData()->getLineRotate()._z));
}

void jyViewerGroup::changeLineStretching()
{
}

void jyViewerGroup::changeLineTranslate()
{
}

void jyViewerGroup::changLineReset()
{
}
