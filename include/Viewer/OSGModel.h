#ifndef _OSGMODEL_H
#define _OSGMODEL_H

#include <osg/Node>
#include <osg/Geode>
#include <osg/Geometry>
#include <osg/MatrixTransform>
#include "Model/ModelData.h"
#include <boost/signals2.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>

class jyOSGModel
{

public:
  jyOSGModel();
  osg::ref_ptr<osg::MatrixTransform> returnRoot();
  //提供QT层访问底层数据的接口
  jyModelData *returnModelData();
  void setModelData(jyModelData *_data);
  jyModelData * getModelData();
  void initModel();
  //get/set访问器
  void setLineMatrixTransform();
  void setRectangle();

  osg::ref_ptr<osg::MatrixTransform> getLineMatrixGroup();

private:
  osg::ref_ptr<osg::Geode> geode=NULL;
  osg::ref_ptr<osg::Geode> m_pLineGeode = NULL;
  //纯C++和boost实现的底层数据，修改底层数据时通过boost signals2发送一个信号在这个类中接收 实习伸缩，平移，旋转的效果
  jyModelData *m_pModelData=NULL;
  osg::ref_ptr<osg::MatrixTransform> m_pRoot = NULL;
  osg::ref_ptr<osg::MatrixTransform> m_pLine = NULL;
  osg::ref_ptr<osg::MatrixTransform> m_pRectangle = NULL;

};

#endif // !_OSGMODEL_H
