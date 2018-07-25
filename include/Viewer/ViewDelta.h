#ifndef _VIEWERRECTANGLEGROUP_H
#define _VIEWERRECTANGLEGROUP_H

#include <osg/Node>
#include <osg/Geode>
#include <osg/Geometry>
#include <osg/MatrixTransform>
#include "Control/ControlDelta.h"
#include "Viewer/ViewBase.h"

class jyViewDelta :public jyViewBase<jyControlDelta>
{
public:
  jyViewDelta(jyControlDelta *mControl) :jyViewBase<jyControlDelta>(mControl) { initView(); };
  //��ʼ���麯��ʵ��
  virtual void initView();
  //ʵ��һ����ת����
  virtual void updataViewRotate();
  virtual void updataViewStretching();
  virtual void updataViewTranslate();
  virtual void updataViewReset();
  osg::ref_ptr<osg::MatrixTransform> getRoot();

private:
  osg::ref_ptr<osg::Node> m_pDeltaNode = NULL;
  osg::ref_ptr<osg::MatrixTransform> m_pDeltaRoot = NULL;
  osg::ref_ptr<osg::Geode> m_pGeode = NULL;
  osg::ref_ptr<osg::Geometry> m_pGeometry = NULL;
};

#endif //_VIEWERRECTANGLEGROUP_H
