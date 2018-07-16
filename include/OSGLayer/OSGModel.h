#ifndef _OSGMODEL_H
#define _OSGMODEL_H
#include <osg/Node>
#include <osg/Geode>
#include <osg/Geometry>
#include <osg/MatrixTransform>
#include "SourceData/ModelData.h"
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
private:
  osg::ref_ptr<osg::Geode> geode=NULL;
  //��C++��boostʵ�ֵĵײ����ݣ��޸ĵײ�����ʱͨ��boost signals2����һ���ź���������н��� ʵϰ������ƽ�ƣ���ת��Ч��
  jyModelData *m_pModelData=NULL;
  osg::ref_ptr<osg::MatrixTransform> m_pRoot = NULL;
};

#endif // !_OSGMODEL_H
