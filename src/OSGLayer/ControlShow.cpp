#include "..\..\include\OSGLayer\ControlShow.h"



jyControlShow::jyControlShow(QObject *parent) {
 // connectFun(stretchingChange);
  
}

osgQt::GraphicsWindowQt * jyControlShow::CreatGraphicsWinQt(int x, int y, int w, int h, const std::string & name, bool windowDecoration)
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
 // return new osgQt::GraphicsWindowQt(traits.get());
  return m_pGraphics;
}
//������ʾ��һ�㣬����Ĳ��������ݲ��ȡӦ�û���group����translate
QWidget * jyControlShow::addViewWidget()
{
  //----test
  m_pModel = new jyOSGModel();
//  modelData = m_pModel->returnRoot();
  //-------------------
  m_pNode = new osg::Node;
  m_pNode = m_pModel->returnRoot();
  m_pNo1Viewer = new osgViewer::Viewer();
  const osgQt::GraphicsWindowQt::Traits *traits = m_pGraphics->getTraits();
  osg::Camera *_temCamera = m_pNo1Viewer->getCamera();
  _temCamera->setGraphicsContext(m_pGraphics);
  _temCamera->setClearColor(osg::Vec4(0.2,0.2,0.6,1.0));
  _temCamera->setViewport(0, 0, traits->width, traits->height);
  //--
  /*
  osg::Vec3d eye, center, up;
  _temCamera->getViewMatrixAsLookAt(eye, center, up);
  eye=osg::Vec3d(0.0,-20.0,0.0);
  center=osg::Vec3d(0.0,0.0,0.0);
  up=osg::Vec3d(0.0,0.0,1.0);
  _temCamera->setViewMatrixAsLookAt(eye, center, up);
  */
  m_pNo1Viewer->setSceneData(m_pNode);
  //�����¼�����
  m_pNo1Viewer->addEventHandler(new osgViewer::StatsHandler);
  //����������
  m_pNo1Viewer->setCameraManipulator(new osgGA::TrackballManipulator);
  //�����߳�ģʽ
  m_pNo1Viewer->setThreadingModel(osgViewer::Viewer::SingleThreaded);

  //�󶨳�Ա�������������ʽ
  m_conStretching = m_pModel->returnModelData()->m_sStrenchingSignal.connect(boost::bind(&jyControlShow::stretchingChange,this));
  m_conTranslate = m_pModel->returnModelData()->m_tTranslateSignal.connect(boost::bind(&jyControlShow::translateChange, this));
  m_conRotate = m_pModel->returnModelData()->m_rRotateSignal.connect(boost::bind(&jyControlShow::rotateChange,this));
  m_conreset = m_pModel->returnModelData()->m_Reset.connect(boost::bind(&jyControlShow::paramReset, this));
  return m_pGraphics->getGLWidget();
}
//��Viewer��ʾ����
void jyControlShow::flashWindow()
{
  m_pNo1Viewer->frame();
}
/*
void jyControlShow::changeGraphics()
{
 // osg::Node *test = new osg::Node;
  m_pNode = osgDB::readNodeFile("C://Users//Administrator//Downloads//OpenSceneGraph-Data-3.0.0//OpenSceneGraph-Data-3.0.0//cow.osg");
  m_pNo1Viewer->setSceneData(m_pNode);
}*/
jyOSGModel * jyControlShow::returnOSGModel()
{
  return m_pModel;
}
/*
boost::signals2::connection jyControlShow::connectFun(const slotType& slotfunction)
{
  mConnection = (m_pModel->returnModelData()->m_sStrenchingSignal).connect(slotfunction);
  return boost::signals2::connection();
}*/
//�����ź���ת��ƽ��
//����ģ�Ͷ���Ӧ����һ��MatrixTransform��Ϊ��


void jyControlShow::stretchingChange()
{
  //�õ����ڵ�ı任���󣬽�ԭ�ȵı任������µõ��ı任����ʵ��ͼ�α任
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


