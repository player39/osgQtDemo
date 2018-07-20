#ifndef _VIEWERRECTANGLEGROUP_H
#define _VIEWERRECTANGLEGROUP_H

#include "Control/ControlRecGroup.h"
#include "Viewer/OSGModel.h"
#include "Viewer/ViewerBase.h"

class jyViewerRectangleGroup :public jyViewerBase<jyControlRecGroup, jyOSGModel>
{

public:
  jyViewerRectangleGroup() :jyViewerBase<jyControlRecGroup, jyOSGModel>() {};
  //�麯��ʵ��
  virtual QWidget *addWidget();
  virtual osgQt::GraphicsWindowQt *creatGraphicsWinQt(int x, int y, int w, int h, const std::string& name = "", bool windowDecoration = false);
  virtual void bindDataChangeSig();
  //ʵ��һ����ת����
  void changeRecRotate();

private:
  osg::ref_ptr<osg::Node> m_pNode = NULL;
  boost::signals2::connection m_conRotate;
};

#endif
