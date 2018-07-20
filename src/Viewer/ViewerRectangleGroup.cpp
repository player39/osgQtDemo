#include "..\..\include\Viewer\ViewerRectangleGroup.h"

QWidget * jyViewerRectangleGroup::addWidget()
{
  m_pNode = new osg::Node;
  m_pNode = this->getModel()->getRecRoot();
  //m_pNo1Viewer = new osgViewer::Viewer();
  const osgQt::GraphicsWindowQt::Traits *traits = this->getGranphics()->getTraits();
  osg::Camera *_temCamera = this->getCamera();
  _temCamera->setGraphicsContext(this->getGranphics());
  _temCamera->setClearColor(osg::Vec4(0.2, 0.2, 0.6, 1.0));
  _temCamera->setViewport(0, 0, traits->width, traits->height);
  this->setSceneData(m_pNode);
  //�����¼�����
  this->addEventHandler(new osgViewer::StatsHandler);
  //����������
  this->setCameraManipulator(new osgGA::TrackballManipulator);
  //�����߳�ģʽ
  this->setThreadingModel(osgViewer::Viewer::SingleThreaded);

  //�󶨳�Ա�������������ʽ
  return this->getGranphics()->getGLWidget();
}

osgQt::GraphicsWindowQt * jyViewerRectangleGroup::creatGraphicsWinQt(int x, int y, int w, int h, const std::string & name, bool windowDecoration)
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

void jyViewerRectangleGroup::bindDataChangeSig()
{
  m_conRotate=getControl()->sigRootRotate.connect(boost::bind(&jyViewerRectangleGroup::changeRecRotate,this));
}

void jyViewerRectangleGroup::changeRecRotate()
{
  osg::ref_ptr<osg::MatrixTransform> _temMatrix = new osg::MatrixTransform();
  _temMatrix = getModel()->getRecMatrixGroup();
  _temMatrix->setMatrix(_temMatrix->getMatrix()*osg::Matrix::rotate(osg::DegreesToRadians(getControl()->getSourceData()->getRecRotate()._angle), getControl()->getSourceData()->getRecRotate()._x, getControl()->getSourceData()->getRecRotate()._y, getControl()->getSourceData()->getRecRotate()._z));
}
