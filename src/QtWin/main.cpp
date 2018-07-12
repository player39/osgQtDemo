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
    //设置了上下文规范，traits这个参数xy指的可能是GraphicsContext对于viewer的坐标
    const osg::GraphicsContext::Traits* traits = gw->getTraits();

    osg::Camera* camera = _viewer.getCamera();
    camera->setGraphicsContext(gw);
    //清空屏幕颜色，效果上是设置
    camera->setClearColor(osg::Vec4(0.2, 0.2, 0.6, 1.0));
    camera->setViewport(new osg::Viewport(0, 0, traits->width, traits->height));
    //以透视投影参数设置透视投影矩阵
    camera->setProjectionMatrixAsPerspective(
      30.0f, static_cast<double>(traits->width) / static_cast<double>(traits->height), 1.0f, 10000.0f);
    //设置node节点
    _viewer.setSceneData(scene);
    //添加事件处理
    _viewer.addEventHandler(new osgViewer::StatsHandler);
    //添加旋转缩放功能 对视口进行操作
    _viewer.setCameraManipulator(new osgGA::TrackballManipulator);
    //设置线程模型
    _viewer.setThreadingModel(osgViewer::Viewer::SingleThreaded);

    QVBoxLayout* layout = new QVBoxLayout;
    //gw中会生成一个GLWidget
    QWidget *testw = new QWidget(this);
    
    
    this->setCentralWidget(gw->getGLWidget());
    layout->addWidget(gw->getGLWidget());
    testw->setLayout(layout);
    this->setCentralWidget(testw);
    //刷新画面控制模型
    connect(&_timer, SIGNAL(timeout()), this, SLOT(update()));
    _timer.start(40);
  }

protected:
  virtual void paintEvent(QPaintEvent* event)
  {
    //渲染出框架
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

