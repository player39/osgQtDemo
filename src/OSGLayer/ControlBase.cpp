#include "..\..\include\OSGLayer\ControlBase.h"

jyControlBase::jyControlBase()
{
}

osgQt::GraphicsWindowQt * jyControlBase::CreatGraphicsWinQt(int x, int y, int w, int h, const std::string & name, bool windowDecoration)
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
  return m_pGraphics;
}

QWidget * jyControlBase::addViewWidget()
{
  m_pModel = new jyOSGModel();
  m_pNode = new osg::Node;
  m_pNode = m_pModel->returnRoot();
  m_pNo1Viewer = new osgViewer::Viewer();
  const osgQt::GraphicsWindowQt::Traits *traits = m_pGraphics->getTraits();
  osg::Camera *_temCamera = m_pNo1Viewer->getCamera();
  _temCamera->setGraphicsContext(m_pGraphics);
  _temCamera->setClearColor(osg::Vec4(0.2, 0.2, 0.6, 1.0));
  _temCamera->setViewport(0, 0, traits->width, traits->height);
  m_pNo1Viewer->setSceneData(m_pNode);
  //设置事件处理
  m_pNo1Viewer->addEventHandler(new osgViewer::StatsHandler);
  //设置漫游器
  m_pNo1Viewer->setCameraManipulator(new osgGA::TrackballManipulator);
  //设置线程模式
  m_pNo1Viewer->setThreadingModel(osgViewer::Viewer::SingleThreaded);

  //绑定成员变量就是这个格式
  /*m_cConStretching = m_pModel->returnModelData()->m_sStrenchingSignal.connect(boost::bind(&jyControlShow::stretchingChange, this));
  m_cConTranslate = m_pModel->returnModelData()->m_tTranslateSignal.connect(boost::bind(&jyControlShow::translateChange, this));
  m_cConRotate = m_pModel->returnModelData()->m_rRotateSignal.connect(boost::bind(&jyControlShow::rotateChange, this));
  m_cConreset = m_pModel->returnModelData()->m_Reset.connect(boost::bind(&jyControlShow::paramReset, this));*/
  return m_pGraphics->getGLWidget();
}

void jyControlBase::flashWindow()
{
  m_pNo1Viewer->frame();
}

jyOSGModel * jyControlBase::returnOSGModel()
{
  return m_pModel;
}

void jyControlBase::stretchingChange()
{
  osg::ref_ptr<osg::MatrixTransform> _pTrans = m_pModel->returnRoot();
  _pTrans->setMatrix(_pTrans->getMatrix()*osg::Matrix::scale(m_pModel->returnModelData()->returnStrenching()._x, m_pModel->returnModelData()->returnStrenching()._y, m_pModel->returnModelData()->returnStrenching()._z));
}

void jyControlBase::rotateChange()
{
  osg::ref_ptr<osg::MatrixTransform> _pTrans = m_pModel->returnRoot();
  _pTrans->setMatrix(_pTrans->getMatrix()*osg::Matrix::rotate(osg::DegreesToRadians(m_pModel->returnModelData()->returnRotate()._angle), m_pModel->returnModelData()->returnRotate()._x, m_pModel->returnModelData()->returnRotate()._y, m_pModel->returnModelData()->returnRotate()._z));
}

void jyControlBase::translateChange()
{
  osg::ref_ptr<osg::MatrixTransform> _pTrans = m_pModel->returnRoot();
  _pTrans->setMatrix(_pTrans->getMatrix()*osg::Matrix::translate(m_pModel->returnModelData()->returntranslate()._x, m_pModel->returnModelData()->returntranslate()._y, m_pModel->returnModelData()->returntranslate()._z));
}

void jyControlBase::paramReset()
{
  osg::ref_ptr<osg::MatrixTransform> _pTrans = m_pModel->returnRoot();
  osg::Matrix _reset = osg::Matrix();
  _pTrans->setMatrix(_reset);
}
