#ifndef _VIEWERGROUP_H 
#define _VIEWERGROUP_H

#include "Viewer/ViewerBase.h"
#include "Control/ControlGroup.h"

class jyViewerGroup :public jyViewerBase<jyControlGroup,jyOSGModel>
{

public:
  jyViewerGroup() :jyViewerBase<jyControlGroup, jyOSGModel>() {};
  //实现虚函数
  virtual osgQt::GraphicsWindowQt * creatGraphicsWinQt(int x, int y, int w, int h, const std::string& name = "", bool windowDecoration = false);
  virtual QWidget * addWidget();
  virtual void bindDataChangeSig();
  //实现一个对根节点的旋转操作
  virtual void changeRotate();
  //实现对线段的操作，仅实现了一个旋转
  void changeLineRotate();
  void changeLineStretching();
  void changeLineTranslate();
  void changLineReset();

private:
  osg::ref_ptr<osg::Node> m_pNode=NULL;
  boost::signals2::connection m_conStretching;
  boost::signals2::connection m_conRotate;
  boost::signals2::connection m_conTranslate;
  boost::signals2::connection m_conReset;

  boost::signals2::connection m_conDataRotate;
};
#endif //_VIEWERGROUP_H