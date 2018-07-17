#ifndef _CONTROLSHOW_H
#define _CONTROLSHOW_H
#define _SCL_SECURE_NO_WARNINGS

#include <osgViewer/Viewer>
#include <osgViewer/ViewerEventHandlers>
#include <osgQt/GraphicsWindowQt>
#include <osgDB/ReadFile>
#include <osgGA/TrackballManipulator>
#include <QtWidgets/QWidget>
#include <QtCore/QObject>
#include <QtCore/QString>
#include <osg/MatrixTransform>
#include <boost/signals2.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include "OSGLayer/OSGModel.h"

typedef boost::signals2::signal<void()>::slot_type slotType;

class jyControlShow :public QObject
{

  Q_OBJECT

public:
  jyControlShow(QObject *parent = Q_NULLPTR);
  osgQt::GraphicsWindowQt* CreatGraphicsWinQt(int x, int y, int w, int h,const std::string& name="",bool windowDecoration=false);
  QWidget *addViewWidget();
  void flashWindow();
  //提供qt层访问底层的接口
  jyOSGModel *returnOSGModel();
  //通过osg提供的变换矩阵 实现平移旋转拉伸 复位通过设置单位矩阵实现
  void stretchingChange();
  void rotateChange();
  void translateChange();
  void paramReset();

private:
  osgViewer::Viewer *m_pNo1Viewer=NULL;
  osg::ref_ptr<osgQt::GraphicsWindowQt> m_pGraphics=NULL;
  osg::ref_ptr<osg::Node> m_pNode = NULL;
  //四个连接
  boost::signals2::connection m_cConStretching;
  boost::signals2::connection m_cConTranslate;
  boost::signals2::connection m_cConRotate;
  boost::signals2::connection m_cConreset;
  //存放用于显示的osg模型
  jyOSGModel *m_pModel;

};

#endif // !_CONTROLSHOW_H
