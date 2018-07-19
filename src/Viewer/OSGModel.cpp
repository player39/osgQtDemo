#include "Viewer/OSGModel.h"

jyOSGModel::jyOSGModel()
{
 
}

osg::ref_ptr<osg::MatrixTransform> jyOSGModel::returnRoot()
{
  return m_pRoot.get();
}

jyModelData * jyOSGModel::returnModelData()
{
  return m_pModelData;
}

void jyOSGModel::setModelData(jyModelData * _data)
{
  m_pModelData = _data;
}

jyModelData * jyOSGModel::getModelData()
{
  return m_pModelData;
}

void jyOSGModel::initModel()
{
  //m_pModelData = new jyModelData();
  geode = new osg::Geode;
  m_pLineGeode = new osg::Geode;
  m_pRoot = new osg::MatrixTransform();
  m_pRectangle = new osg::MatrixTransform();
  m_pLine = new osg::MatrixTransform();
  m_pRoot->addChild(m_pRectangle);
  m_pRoot->addChild(m_pLine);
  m_pRectangle->addChild(geode);
  m_pLine->addChild(m_pLineGeode);
  //��һ��
  osg::ref_ptr<osg::Geometry> _geom1 = new osg::Geometry();
  osg::ref_ptr<osg::Vec3Array> _surface1 = new osg::Vec3Array();
  for (int i = 0; i < 4; ++i)
  {
    _surface1->push_back(osg::Vec3(m_pModelData->m_pPoint[0][i]._x, m_pModelData->m_pPoint[0][i]._y, m_pModelData->m_pPoint[0][i]._z));
  }
  _geom1->setVertexArray(_surface1.get());

  osg::ref_ptr<osg::Vec3Array> _n1 = new osg::Vec3Array();//������һ�����߰󶨵����ķ�����

  _n1->push_back(osg::Vec3(1.0, 0.0, 0.0));//����Ϊָ��Y�Ḻ����
  _geom1->setNormalArray(_n1.get());//��ӷ��ߵ���������

  _geom1->setNormalBinding(osg::Geometry::BIND_OVERALL);//�����߽��а�

                                                        //���ö���Ĺ�����ʽ��QUADS���������4���������ɾ��Σ��ܹ�����ôЩ��ʽ��POINTS,LINES,LINE_STRIP,LINE_LOOP,TRIANGLES,TRIANGLE_STRIP,TRIANGLE_FAN,QUADS,QUAD_STRIP,POLYGON

  _geom1->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::QUADS, 0, 4));

  osg::ref_ptr<osg::Vec4Array> _c1 = new osg::Vec4Array();
  _c1->push_back(osg::Vec4(1.0, 0.0, 0.0, 1.0));
  _c1->push_back(osg::Vec4(0.0, 1.0, 0.0, 1.0));
  _c1->push_back(osg::Vec4(0.0, 0.0, 1.0, 1.0));
  _c1->push_back(osg::Vec4(1.0, 1.0, 1.0, 1.0));
  _geom1->setColorArray(_c1.get());
  _geom1->setColorBinding(osg::Geometry::BIND_PER_VERTEX);
  geode->addDrawable(_geom1.get());

  //�ڶ���
  osg::ref_ptr<osg::Geometry> _geom2 = new osg::Geometry();
  osg::ref_ptr<osg::Vec3Array> _surface2 = new osg::Vec3Array();

  for (int i = 0; i < 4; ++i)
  {
    _surface2->push_back(osg::Vec3(m_pModelData->m_pPoint[1][i]._x, m_pModelData->m_pPoint[1][i]._y, m_pModelData->m_pPoint[1][i]._z));
  }
  _geom2->setVertexArray(_surface2.get());

  osg::ref_ptr<osg::Vec3Array> _n2 = new osg::Vec3Array();//������һ�����߰󶨵����ķ�����

  _n2->push_back(osg::Vec3(0.0, -1.0, 0.0));//����Ϊָ��Y�Ḻ����
  _geom2->setNormalArray(_n2.get());//��ӷ��ߵ���������

  _geom2->setNormalBinding(osg::Geometry::BIND_OVERALL);//�����߽��а�
  _geom2->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::QUADS, 0, 4));
  osg::ref_ptr<osg::Vec4Array> _c2 = new osg::Vec4Array();
  _c2->push_back(osg::Vec4(1.0, 0.0, 0.0, 1.0));
  _c2->push_back(osg::Vec4(0.0, 1.0, 0.0, 1.0));
  _c2->push_back(osg::Vec4(0.0, 0.0, 1.0, 1.0));
  _c2->push_back(osg::Vec4(1.0, 1.0, 1.0, 1.0));
  _geom2->setColorArray(_c2.get());
  _geom2->setColorBinding(osg::Geometry::BIND_PER_VERTEX);
  geode->addDrawable(_geom2.get());
  //��������
  osg::ref_ptr<osg::Geometry> _geom3 = new osg::Geometry();
  osg::ref_ptr<osg::Vec3Array> _surface3 = new osg::Vec3Array();

  for (int i = 0; i < 4; ++i)
  {
    _surface3->push_back(osg::Vec3(m_pModelData->m_pPoint[2][i]._x, m_pModelData->m_pPoint[2][i]._y, m_pModelData->m_pPoint[2][i]._z));
  }
  _geom3->setVertexArray(_surface3.get());
  osg::ref_ptr<osg::Vec3Array> _n3 = new osg::Vec3Array();//������һ�����߰󶨵����ķ�����
  _n3->push_back(osg::Vec3(0.0, 0.0, -1.0));//����Ϊָ��Y�Ḻ����
  _geom3->setNormalArray(_n3.get());//��ӷ��ߵ���������
  _geom3->setNormalBinding(osg::Geometry::BIND_OVERALL);//�����߽��а�
  _geom3->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::QUADS, 0, 4));
  osg::ref_ptr<osg::Vec4Array> _c3 = new osg::Vec4Array();
  _c3->push_back(osg::Vec4(1.0, 0.0, 0.0, 1.0));
  _c3->push_back(osg::Vec4(0.0, 1.0, 0.0, 1.0));
  _c3->push_back(osg::Vec4(0.0, 0.0, 1.0, 1.0));
  _c3->push_back(osg::Vec4(1.0, 1.0, 1.0, 1.0));
  _geom3->setColorArray(_c3.get());
  _geom3->setColorBinding(osg::Geometry::BIND_PER_VERTEX);
  geode->addDrawable(_geom3.get());
  //������
  osg::ref_ptr<osg::Geometry> _geom4 = new osg::Geometry();
  osg::ref_ptr<osg::Vec3Array> _surface4 = new osg::Vec3Array();

  for (int i = 0; i < 4; ++i)
  {
    _surface4->push_back(osg::Vec3(m_pModelData->m_pPoint[0][i]._x * (-1), m_pModelData->m_pPoint[0][i]._y, m_pModelData->m_pPoint[0][i]._z));
  }
  _geom4->setVertexArray(_surface4.get());
  osg::ref_ptr<osg::Vec3Array> _n4 = new osg::Vec3Array();//������һ�����߰󶨵����ķ�����
  _n4->push_back(osg::Vec3(-1.0, 0.0, 0.0));//����Ϊָ��Y�Ḻ����
  _geom4->setNormalArray(_n4.get());//��ӷ��ߵ���������
  _geom4->setNormalBinding(osg::Geometry::BIND_OVERALL);//�����߽��а�
  _geom4->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::QUADS, 0, 4));
  osg::ref_ptr<osg::Vec4Array> _c4 = new osg::Vec4Array();
  _c4->push_back(osg::Vec4(1.0, 0.0, 0.0, 1.0));
  _c4->push_back(osg::Vec4(0.0, 1.0, 0.0, 1.0));
  _c4->push_back(osg::Vec4(0.0, 0.0, 1.0, 1.0));
  _c4->push_back(osg::Vec4(1.0, 1.0, 1.0, 1.0));
  _geom4->setColorArray(_c4.get());
  _geom4->setColorBinding(osg::Geometry::BIND_PER_VERTEX);
  geode->addDrawable(_geom4.get());
  //������
  osg::ref_ptr<osg::Geometry> _geom5 = new osg::Geometry();
  osg::ref_ptr<osg::Vec3Array> _surface5 = new osg::Vec3Array();

  for (int i = 0; i < 4; ++i)
  {
    _surface5->push_back(osg::Vec3(m_pModelData->m_pPoint[1][i]._x, m_pModelData->m_pPoint[1][i]._y * (-1), m_pModelData->m_pPoint[1][i]._z));
  }
  _geom5->setVertexArray(_surface5.get());
  osg::ref_ptr<osg::Vec3Array> _n5 = new osg::Vec3Array();//������һ�����߰󶨵����ķ�����
  _n5->push_back(osg::Vec3(0.0, 1.0, 0.0));//����Ϊָ��Y�Ḻ����
  _geom5->setNormalArray(_n5.get());//��ӷ��ߵ���������
  _geom5->setNormalBinding(osg::Geometry::BIND_OVERALL);//�����߽��а�
  _geom5->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::QUADS, 0, 4));
  osg::ref_ptr<osg::Vec4Array> _c5 = new osg::Vec4Array();
  _c5->push_back(osg::Vec4(1.0, 0.0, 0.0, 1.0));
  _c5->push_back(osg::Vec4(0.0, 1.0, 0.0, 1.0));
  _c5->push_back(osg::Vec4(0.0, 0.0, 1.0, 1.0));
  _c5->push_back(osg::Vec4(1.0, 1.0, 1.0, 1.0));
  _geom5->setColorArray(_c5.get());
  _geom5->setColorBinding(osg::Geometry::BIND_PER_VERTEX);
  geode->addDrawable(_geom5.get());
  //������
  osg::ref_ptr<osg::Geometry> _geom6 = new osg::Geometry();
  osg::ref_ptr<osg::Vec3Array> _surface6 = new osg::Vec3Array();

  for (int i = 0; i < 4; ++i)
  {
    _surface6->push_back(osg::Vec3(m_pModelData->m_pPoint[2][i]._x, m_pModelData->m_pPoint[2][i]._y, m_pModelData->m_pPoint[2][i]._z * (-1)));
  }
  _geom6->setVertexArray(_surface6.get());
  osg::ref_ptr<osg::Vec3Array> _n6 = new osg::Vec3Array();//������һ�����߰󶨵����ķ�����
  _n6->push_back(osg::Vec3(0.0, 0.0, 1.0));//����Ϊָ��Y�Ḻ����
  _geom6->setNormalArray(_n6.get());//��ӷ��ߵ���������
  _geom6->setNormalBinding(osg::Geometry::BIND_OVERALL);//�����߽��а�
  _geom6->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::QUADS, 0, 4));
  osg::ref_ptr<osg::Vec4Array> _c6 = new osg::Vec4Array();
  _c6->push_back(osg::Vec4(1.0, 0.0, 0.0, 1.0));
  _c6->push_back(osg::Vec4(0.0, 1.0, 0.0, 1.0));
  _c6->push_back(osg::Vec4(0.0, 0.0, 1.0, 1.0));
  _c6->push_back(osg::Vec4(1.0, 1.0, 1.0, 1.0));
  _geom6->setColorArray(_c6.get());
  _geom6->setColorBinding(osg::Geometry::BIND_PER_VERTEX);
  geode->addDrawable(_geom6.get());

  //-------�����
  osg::ref_ptr<osg::Geometry> _LineGeome = new osg::Geometry();
  osg::ref_ptr<osg::Vec3Array> _Line = new osg::Vec3Array();
  _Line->push_back(osg::Vec3(m_pModelData->m_pLine[0]._x, m_pModelData->m_pLine[0]._y, m_pModelData->m_pLine[0]._z));
  _Line->push_back(osg::Vec3(m_pModelData->m_pLine[1]._x, m_pModelData->m_pLine[1]._y, m_pModelData->m_pLine[1]._z));
  _LineGeome->setVertexArray(_Line.get());

  osg::ref_ptr<osg::Vec3Array> _LineN = new osg::Vec3Array();
  _LineN->push_back(osg::Vec3(0.0, -1.0, 0));
  _LineGeome->setNormalArray(_LineN.get());
  _LineGeome->setNormalBinding(osg::Geometry::BIND_OVERALL);
  _LineGeome->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::LINES, 0, 2));

  osg::ref_ptr<osg::Vec4Array> _color = new osg::Vec4Array();
  _color->push_back(osg::Vec4(1.0, 0.0, 0.0, 1.0));
  _LineGeome->setColorArray(_color.get());
  _LineGeome->setColorBinding(osg::Geometry::BIND_PER_VERTEX);
  m_pLineGeode->addDrawable(_LineGeome.get());
}

void jyOSGModel::setLineMatrixTransform()
{
}

void jyOSGModel::setRectangle()
{
}

osg::ref_ptr<osg::MatrixTransform> jyOSGModel::getLineMatrixGroup()
{
  return m_pLine;
}
