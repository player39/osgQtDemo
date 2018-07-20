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
  //拿到根节点，osg有内置的遍历器 节点多的时候应该使用遍历器
  osg::ref_ptr<osg::MatrixTransform> getRoot();
  osg::ref_ptr<osg::MatrixTransform> getRecRoot();
  osg::ref_ptr<osg::MatrixTransform> getLineMatrixGroup();
  osg::ref_ptr<osg::MatrixTransform> getRecMatrixGroup();
  //绑定数据源
  void setModelData(jyModelData *_data);
  jyModelData * getModelData();
  //初始化Model
  void initModel();
  //初始化另一视图的模型
  void setRecModel();

private:
  //正六面体
  osg::ref_ptr<osg::Geode> geode=NULL;
  //线段
  osg::ref_ptr<osg::Geode> m_pLineGeode = NULL;
  osg::ref_ptr<osg::MatrixTransform> m_pRoot = NULL;
  osg::ref_ptr<osg::MatrixTransform> m_pLine = NULL;
  osg::ref_ptr<osg::MatrixTransform> m_pRectangle = NULL;
  //属于另一视图三角形的节点
  osg::ref_ptr<osg::Geode> m_pRecGeode = NULL;
  osg::ref_ptr<osg::MatrixTransform> m_pRecMatrix = NULL;
  //底层数据
  jyModelData *m_pModelData = NULL;
};

#endif // !_OSGMODEL_H
