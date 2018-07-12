#include "QtWin/OSGQtWindow.h"

#include <QtCore/QtCore>
#include <QtGui/QtGui>
#include <osgDB/ReadFile>
#include <osgGA/TrackballManipulator>
#include <osgViewer/ViewerEventHandlers>
#include <osgViewer/Viewer>
#include <osgQt/GraphicsWindowQt>
#include <QVBoxLayout>
#include <QApplication>
#include <QtWidgets/QMainWindow>

/*
osgQt::GraphicsWindowQt* createGraphicsWindow(int x, int y, int w, int h)
{
  osg::ref_ptr<osg::GraphicsContext::Traits> traits = new osg::GraphicsContext::Traits;
  traits->windowDecoration = false;
  traits->x = x;
  traits->y = y;
  traits->width = w;
  traits->height = h;
  traits->doubleBuffer = true;

  return new osgQt::GraphicsWindowQt(traits.get());
}

class ViewerWidget : public QMainWindow
{
public:
  ViewerWidget(osgQt::GraphicsWindowQt* gw, osg::Node* scene)
    : QMainWindow()
  {
    //�����������Ĺ淶��traits�������xyָ�Ŀ�����GraphicsContext����viewer������
    const osg::GraphicsContext::Traits* traits = gw->getTraits();

    osg::Camera* camera = _viewer.getCamera();
    camera->setGraphicsContext(gw);
    //�����Ļ��ɫ��Ч����������
    camera->setClearColor(osg::Vec4(0.2, 0.2, 0.6, 1.0));
    camera->setViewport(new osg::Viewport(0, 0, traits->width, traits->height));
    //��͸��ͶӰ��������͸��ͶӰ����
    camera->setProjectionMatrixAsPerspective(
      30.0f, static_cast<double>(traits->width) / static_cast<double>(traits->height), 1.0f, 10000.0f);
    //����node�ڵ�
    _viewer.setSceneData(scene);
    //����¼�����
    _viewer.addEventHandler(new osgViewer::StatsHandler);
    //�����ת���Ź��� ���ӿڽ��в���
    _viewer.setCameraManipulator(new osgGA::TrackballManipulator);
    //�����߳�ģ��
    _viewer.setThreadingModel(osgViewer::Viewer::SingleThreaded);

    QVBoxLayout* layout = new QVBoxLayout;
    //gw�л�����һ��GLWidget
    QWidget *testw = new QWidget(this);
    
    
    this->setCentralWidget(gw->getGLWidget());
    layout->addWidget(gw->getGLWidget());
    testw->setLayout(layout);
    this->setCentralWidget(testw);
    //ˢ�»������ģ��
    connect(&_timer, SIGNAL(timeout()), this, SLOT(update()));
    _timer.start(40);
  }

protected:
  virtual void paintEvent(QPaintEvent* event)
  {
    //��Ⱦ�����
    _viewer.frame();
  }

  osgViewer::Viewer _viewer;
  QTimer _timer;
};
*/
int main(int argc, char** argv)
{
  QApplication app(argc, argv);
 /* osgQt::GraphicsWindowQt* gw = createGraphicsWindow(50, 50, 640, 480);
  osg::Node* scene = osgDB::readNodeFile("C://Users//Administrator//Downloads//OpenSceneGraph-Data-3.0.0//OpenSceneGraph-Data-3.0.0//cow.osg");

  ViewerWidget* widget = new ViewerWidget(gw, scene);
  widget->setGeometry(100, 100, 800, 600);
  widget->show();*/
  jyOSGQtWindow osgwin = new jyOSGQtWindow();
  osgwin.show();
 // jyOSGQtWindow *_pQtWin = new jyOSGQtWindow();
 // _pQtWin->show();
  return app.exec();
}

