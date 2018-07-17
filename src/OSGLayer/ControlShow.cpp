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
  return m_pGraphics;
}
//负责显示这一层，传入的参数从数据层获取应该会变成group或者translate
QWidget * jyControlShow::addViewWidget()
{
  m_pModel = new jyOSGModel();
  m_pNode = new osg::Node;
  m_pNode = m_pModel->returnRoot();
  m_pNo1Viewer = new osgViewer::Viewer();
  const osgQt::GraphicsWindowQt::Traits *traits = m_pGraphics->getTraits();
  osg::Camera *_temCamera = m_pNo1Viewer->getCamera();
  _temCamera->setGraphicsContext(m_pGraphics);
  _temCamera->setClearColor(osg::Vec4(0.2,0.2,0.6,1.0));
  _temCamera->setViewport(0, 0, traits->width, traits->height);
  m_pNo1Viewer->setSceneData(m_pNode);
  //设置事件处理
  m_pNo1Viewer->addEventHandler(new osgViewer::StatsHandler);
  //设置漫游器
  m_pNo1Viewer->setCameraManipulator(new osgGA::TrackballManipulator);
  //设置线程模式
  m_pNo1Viewer->setThreadingModel(osgViewer::Viewer::SingleThreaded);

  //绑定成员变量就是这个格式
  m_cConStretching = m_pModel->returnModelData()->m_sStrenchingSignal.connect(boost::bind(&jyControlShow::stretchingChange,this));
  m_cConTranslate = m_pModel->returnModelData()->m_tTranslateSignal.connect(boost::bind(&jyControlShow::translateChange, this));
  m_cConRotate = m_pModel->returnModelData()->m_rRotateSignal.connect(boost::bind(&jyControlShow::rotateChange,this));
  m_cConreset = m_pModel->returnModelData()->m_Reset.connect(boost::bind(&jyControlShow::paramReset, this));
  return m_pGraphics->getGLWidget();
}
//将Viewer显示出来
void jyControlShow::flashWindow()
{
  m_pNo1Viewer->frame();
}

jyOSGModel * jyControlShow::returnOSGModel()
{
  return m_pModel;
}
//先缩放后旋转再平移
//数据模型顶层应该是一个MatrixTransform作为根

void jyControlShow::stretchingChange()
{
  //得到根节点的变换矩阵，将原先的变换矩阵乘新得到的变换矩阵实现图形变换
  osg::ref_ptr<osg::MatrixTransform> _pTrans = m_pModel->returnRoot();
  _pTrans->setMatrix(_pTrans->getMatrix()*osg::Matrix::scale(m_pModel->returnModelData()->returnStrenching()._x, m_pModel->returnModelData()->returnStrenching()._y, m_pModel->returnModelData()->returnStrenching()._z));
}

void jyControlShow::rotateChange()
{
  osg::ref_ptr<osg::MatrixTransform> _pTrans = m_pModel->returnRoot();
  _pTrans->setMatrix(_pTrans->getMatrix()*osg::Matrix::rotate(osg::DegreesToRadians(m_pModel->returnModelData()->returnRotate()._angle), m_pModel->returnModelData()->returnRotate()._x, m_pModel->returnModelData()->returnRotate()._y, m_pModel->returnModelData()->returnRotate()._z));
}

void jyControlShow::translateChange()
{
  osg::ref_ptr<osg::MatrixTransform> _pTrans = m_pModel->returnRoot();
  _pTrans->setMatrix(_pTrans->getMatrix()*osg::Matrix::translate(m_pModel->returnModelData()->returntranslate()._x, m_pModel->returnModelData()->returntranslate()._y, m_pModel->returnModelData()->returntranslate()._z));
}

void jyControlShow::paramReset()
{
  osg::ref_ptr<osg::MatrixTransform> _pTrans = m_pModel->returnRoot();
  osg::Matrix _reset = osg::Matrix();
  _pTrans->setMatrix(_reset);
}


