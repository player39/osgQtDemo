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
  //�ṩQT����ʵײ����ݵĽӿ�
  jyModelData *returnModelData();
  void setModelData(jyModelData *_data);
  jyModelData * getModelData();
  void initModel();
  //get/set������
  void setLineMatrixTransform();
  void setRectangle();

  osg::ref_ptr<osg::MatrixTransform> getLineMatrixGroup();

private:
  osg::ref_ptr<osg::Geode> geode=NULL;
  osg::ref_ptr<osg::Geode> m_pLineGeode = NULL;
  //��C++��boostʵ�ֵĵײ����ݣ��޸ĵײ�����ʱͨ��boost signals2����һ���ź���������н��� ʵϰ������ƽ�ƣ���ת��Ч��
  jyModelData *m_pModelData=NULL;
  osg::ref_ptr<osg::MatrixTransform> m_pRoot = NULL;
  osg::ref_ptr<osg::MatrixTransform> m_pLine = NULL;
  osg::ref_ptr<osg::MatrixTransform> m_pRectangle = NULL;

};

#endif // !_OSGMODEL_H
