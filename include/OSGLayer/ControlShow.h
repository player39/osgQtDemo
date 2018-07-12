#ifndef _CONTROLSHOW_H
#define _CONTROLSHOW_H

#include <osgViewer/Viewer>
#include <osgViewer/ViewerEventHandlers>
#include <osgQt/GraphicsWindowQt>
#include <osgDB/ReadFile>
#include <osgGA/TrackballManipulator>
#include <QtWidgets/QWidget>
#include <QtCore/QObject>
#include <QtCore/QString>
#include <osg/MatrixTransform>

class jyControlShow :public QObject
{
  Q_OBJECT

public:
  jyControlShow(QObject *parent = Q_NULLPTR);
  osgQt::GraphicsWindowQt* CreatGraphicsWinQt(int x, int y, int w, int h,const std::string& name="",bool windowDecoration=false);
  QWidget *addViewWidget(osg::Node *modelData);
  void flashWindow();
  void changeGraphics();
//  osgQt::GLWidget * returnGLWidget();
private:
  osgViewer::Viewer *m_pNo1Viewer=NULL;
  osg::ref_ptr<osgQt::GraphicsWindowQt> m_pGraphics=NULL;
  osg::ref_ptr<osg::Node> m_pNode = NULL;
 // osg::ref_ptr<osg::MatrixTransform> m_pRoot = NULL;
//  osgQt::GLWidget *m_pNo1GLWidget;
public slots:
  void stretchingChange();
  void RotateChange();
  void TranslatipnChange();
};

#endif // !_CONTROLSHOW_H
