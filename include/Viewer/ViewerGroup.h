#ifndef _VIEWERGROUP_H 
#define _VIEWERGROUP_H


#include "Viewer/ViewerBase.h"
#include "Control/ControlGroup.h"

class jyViewerGroup :public jyViewerBase<jyControlGroup,jyOSGModel>
{

public:
  jyViewerGroup() :jyViewerBase<jyControlGroup, jyOSGModel>() {};
  virtual osgQt::GraphicsWindowQt * creatGraphicsWinQt(int x, int y, int w, int h, const std::string& name = "", bool windowDecoration = false);
  virtual QWidget * addWidget();
  virtual void bindDataChangeSig();
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
};
#endif //