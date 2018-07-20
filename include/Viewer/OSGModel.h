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
  //�õ����ڵ㣬osg�����õı����� �ڵ���ʱ��Ӧ��ʹ�ñ�����
  osg::ref_ptr<osg::MatrixTransform> getRoot();
  osg::ref_ptr<osg::MatrixTransform> getRecRoot();
  osg::ref_ptr<osg::MatrixTransform> getLineMatrixGroup();
  osg::ref_ptr<osg::MatrixTransform> getRecMatrixGroup();
  //������Դ
  void setModelData(jyModelData *_data);
  jyModelData * getModelData();
  //��ʼ��Model
  void initModel();
  //��ʼ����һ��ͼ��ģ��
  void setRecModel();

private:
  //��������
  osg::ref_ptr<osg::Geode> geode=NULL;
  //�߶�
  osg::ref_ptr<osg::Geode> m_pLineGeode = NULL;
  osg::ref_ptr<osg::MatrixTransform> m_pRoot = NULL;
  osg::ref_ptr<osg::MatrixTransform> m_pLine = NULL;
  osg::ref_ptr<osg::MatrixTransform> m_pRectangle = NULL;
  //������һ��ͼ�����εĽڵ�
  osg::ref_ptr<osg::Geode> m_pRecGeode = NULL;
  osg::ref_ptr<osg::MatrixTransform> m_pRecMatrix = NULL;
  //�ײ�����
  jyModelData *m_pModelData = NULL;
};

#endif // !_OSGMODEL_H
