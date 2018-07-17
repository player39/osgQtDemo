#include "..\..\include\OSGLayer\ControlBase.h"

jyControlBase::jyControlBase()
{
}

osgQt::GraphicsWindowQt * jyControlBase::CreatGraphicsWinQt(int x, int y, int w, int h, const std::string & name, bool windowDecoration)
{
  //�Ϳ�����й�
  // osg::DisplaySettings *ds = osg::DisplaySettings::instance().get();
  osg::ref_ptr<osg::GraphicsContext::Traits> traits = new osg::GraphicsContext::Traits;
  traits->windowName = name;
  //����װ�����ԣ��������С��
  traits->windowDecoration = windowDecoration;
  traits->x = x;
  traits->y = y;
  traits->width = w;
  traits->height = h;
  traits->doubleBuffer = true;
  //alphaͨ������ʾ�Ҷȼ���
  /*
  traits->alpha = ds->getMinimumNumAlphaBits();
  //ģ�建�壿����������Ⱦ���򣬶�Ӧosg�еļ�ѡ������
  traits->stencil = ds->getMinimumNumStencilBits();
  //������
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
  //�����¼�����
  m_pNo1Viewer->addEventHandler(new osgViewer::StatsHandler);
  //����������
  m_pNo1Viewer->setCameraManipulator(new osgGA::TrackballManipulator);
  //�����߳�ģʽ
  m_pNo1Viewer->setThreadingModel(osgViewer::Viewer::SingleThreaded);

  //�󶨳�Ա�������������ʽ
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
