#include "..\..\include\OSGLayer\OSGModel.h"

jyOSGModel::jyOSGModel()
{
  m_pModelData = new jyModelData();
  geode = new osg::Geode;
//  geode->addDrawable(_geom.get());
  m_pRoot = new osg::MatrixTransform();
  m_pRoot->addChild(geode);
  //第一面
  osg::ref_ptr<osg::Geometry> _geom1 = new osg::Geometry();
  osg::ref_ptr<osg::Vec3Array> _surface1 = new osg::Vec3Array();
  for (int i = 0; i < 4; ++i)
  {
    _surface1->push_back(osg::Vec3(m_pModelData->m_pPoint[0][i]._x, m_pModelData->m_pPoint[0][i]._y, m_pModelData->m_pPoint[0][i]._z));
  }
  _geom1->setVertexArray(_surface1.get());

  osg::ref_ptr<osg::Vec3Array> _n1 = new osg::Vec3Array();//定义了一个法线绑定到该四方体中

  _n1->push_back(osg::Vec3(1.0, 0.0, 0.0));//法线为指向Y轴负半轴
  _geom1->setNormalArray(_n1.get());//添加法线到几何体中

  _geom1->setNormalBinding(osg::Geometry::BIND_OVERALL);//将法线进行绑定

  //设置顶点的关联方式，这里是Quad方式，总共有这么些方式：POINTS,LINES,LINE_STRIP,LINE_LOOP,TRIANGLES,TRIANGLE_STRIP,TRIANGLE_FAN,QUADS,QUAD_STRIP,POLYGON

  _geom1->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::QUADS, 0, 4));

  osg::ref_ptr<osg::Vec4Array> _c1 = new osg::Vec4Array();
  _c1->push_back(osg::Vec4(1.0, 0.0, 0.0, 1.0));
  _c1->push_back(osg::Vec4(0.0, 1.0, 0.0, 1.0));
  _c1->push_back(osg::Vec4(0.0, 0.0, 1.0, 1.0));
  _c1->push_back(osg::Vec4(1.0, 1.0, 1.0, 1.0));
  _geom1->setColorArray(_c1.get());
  _geom1->setColorBinding(osg::Geometry::BIND_PER_VERTEX);
  geode->addDrawable(_geom1.get());

  //第二面
  osg::ref_ptr<osg::Geometry> _geom2 = new osg::Geometry();
  osg::ref_ptr<osg::Vec3Array> _surface2 = new osg::Vec3Array();

  for (int i = 0; i < 4; ++i)
  {
    _surface2->push_back(osg::Vec3(m_pModelData->m_pPoint[1][i]._x, m_pModelData->m_pPoint[1][i]._y, m_pModelData->m_pPoint[1][i]._z));
  }
  _geom2->setVertexArray(_surface2.get());

  osg::ref_ptr<osg::Vec3Array> _n2 = new osg::Vec3Array();//定义了一个法线绑定到该四方体中

  _n2->push_back(osg::Vec3(0.0, -1.0, 0.0));//法线为指向Y轴负半轴
  _geom2->setNormalArray(_n2.get());//添加法线到几何体中

  _geom2->setNormalBinding(osg::Geometry::BIND_OVERALL);//将法线进行绑定
  _geom2->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::QUADS, 0, 4));
  osg::ref_ptr<osg::Vec4Array> _c2 = new osg::Vec4Array();
  _c2->push_back(osg::Vec4(1.0, 0.0, 0.0, 1.0));
  _c2->push_back(osg::Vec4(0.0, 1.0, 0.0, 1.0));
  _c2->push_back(osg::Vec4(0.0, 0.0, 1.0, 1.0));
  _c2->push_back(osg::Vec4(1.0, 1.0, 1.0, 1.0));
  _geom2->setColorArray(_c2.get());
  _geom2->setColorBinding(osg::Geometry::BIND_PER_VERTEX);
  geode->addDrawable(_geom2.get());
  //第三个面
  osg::ref_ptr<osg::Geometry> _geom3 = new osg::Geometry();
  osg::ref_ptr<osg::Vec3Array> _surface3 = new osg::Vec3Array();

  for (int i = 0; i < 4; ++i)
  {
    _surface3->push_back(osg::Vec3(m_pModelData->m_pPoint[2][i]._x, m_pModelData->m_pPoint[2][i]._y, m_pModelData->m_pPoint[2][i]._z));
  }
  _geom3->setVertexArray(_surface3.get());
  osg::ref_ptr<osg::Vec3Array> _n3 = new osg::Vec3Array();//定义了一个法线绑定到该四方体中
  _n3->push_back(osg::Vec3(0.0, 0.0, -1.0));//法线为指向Y轴负半轴
  _geom3->setNormalArray(_n3.get());//添加法线到几何体中
  _geom3->setNormalBinding(osg::Geometry::BIND_OVERALL);//将法线进行绑定
  _geom3->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::QUADS, 0, 4));
  osg::ref_ptr<osg::Vec4Array> _c3 = new osg::Vec4Array();
  _c3->push_back(osg::Vec4(1.0, 0.0, 0.0, 1.0));
  _c3->push_back(osg::Vec4(0.0, 1.0, 0.0, 1.0));
  _c3->push_back(osg::Vec4(0.0, 0.0, 1.0, 1.0));
  _c3->push_back(osg::Vec4(1.0, 1.0, 1.0, 1.0));
  _geom3->setColorArray(_c3.get());
  _geom3->setColorBinding(osg::Geometry::BIND_PER_VERTEX);
  geode->addDrawable(_geom3.get());
  //第四面
  osg::ref_ptr<osg::Geometry> _geom4 = new osg::Geometry();
  osg::ref_ptr<osg::Vec3Array> _surface4 = new osg::Vec3Array();

  for (int i = 0; i < 4; ++i)
  {
    _surface4->push_back(osg::Vec3(m_pModelData->m_pPoint[0][i]._x * (-1), m_pModelData->m_pPoint[0][i]._y, m_pModelData->m_pPoint[0][i]._z));
  }
  _geom4->setVertexArray(_surface4.get());
  osg::ref_ptr<osg::Vec3Array> _n4 = new osg::Vec3Array();//定义了一个法线绑定到该四方体中
  _n4->push_back(osg::Vec3(-1.0, 0.0, 0.0));//法线为指向Y轴负半轴
  _geom4->setNormalArray(_n4.get());//添加法线到几何体中
  _geom4->setNormalBinding(osg::Geometry::BIND_OVERALL);//将法线进行绑定
  _geom4->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::QUADS, 0, 4));
  osg::ref_ptr<osg::Vec4Array> _c4 = new osg::Vec4Array();
  _c4->push_back(osg::Vec4(1.0, 0.0, 0.0, 1.0));
  _c4->push_back(osg::Vec4(0.0, 1.0, 0.0, 1.0));
  _c4->push_back(osg::Vec4(0.0, 0.0, 1.0, 1.0));
  _c4->push_back(osg::Vec4(1.0, 1.0, 1.0, 1.0));
  _geom4->setColorArray(_c4.get());
  _geom4->setColorBinding(osg::Geometry::BIND_PER_VERTEX);
  geode->addDrawable(_geom4.get());
  //第五面
  osg::ref_ptr<osg::Geometry> _geom5 = new osg::Geometry();
  osg::ref_ptr<osg::Vec3Array> _surface5 = new osg::Vec3Array();

  for (int i = 0; i < 4; ++i)
  {
    _surface5->push_back(osg::Vec3(m_pModelData->m_pPoint[1][i]._x, m_pModelData->m_pPoint[1][i]._y * (-1), m_pModelData->m_pPoint[1][i]._z));
  }
  _geom5->setVertexArray(_surface5.get());
  osg::ref_ptr<osg::Vec3Array> _n5 = new osg::Vec3Array();//定义了一个法线绑定到该四方体中
  _n5->push_back(osg::Vec3(0.0, 1.0, 0.0));//法线为指向Y轴负半轴
  _geom5->setNormalArray(_n5.get());//添加法线到几何体中
  _geom5->setNormalBinding(osg::Geometry::BIND_OVERALL);//将法线进行绑定
  _geom5->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::QUADS, 0, 4));
  osg::ref_ptr<osg::Vec4Array> _c5 = new osg::Vec4Array();
  _c5->push_back(osg::Vec4(1.0, 0.0, 0.0, 1.0));
  _c5->push_back(osg::Vec4(0.0, 1.0, 0.0, 1.0));
  _c5->push_back(osg::Vec4(0.0, 0.0, 1.0, 1.0));
  _c5->push_back(osg::Vec4(1.0, 1.0, 1.0, 1.0));
  _geom5->setColorArray(_c5.get());
  _geom5->setColorBinding(osg::Geometry::BIND_PER_VERTEX);
  geode->addDrawable(_geom5.get());
  //第六面
  osg::ref_ptr<osg::Geometry> _geom6 = new osg::Geometry();
  osg::ref_ptr<osg::Vec3Array> _surface6 = new osg::Vec3Array();

  for (int i = 0; i < 4; ++i)
  {
    _surface6->push_back(osg::Vec3(m_pModelData->m_pPoint[2][i]._x, m_pModelData->m_pPoint[2][i]._y, m_pModelData->m_pPoint[2][i]._z * (-1)));
  }
  _geom6->setVertexArray(_surface6.get());
  osg::ref_ptr<osg::Vec3Array> _n6 = new osg::Vec3Array();//定义了一个法线绑定到该四方体中
  _n6->push_back(osg::Vec3(0.0, 0.0, 1.0));//法线为指向Y轴负半轴
  _geom6->setNormalArray(_n6.get());//添加法线到几何体中
  _geom6->setNormalBinding(osg::Geometry::BIND_OVERALL);//将法线进行绑定
  _geom6->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::QUADS, 0, 4));
  osg::ref_ptr<osg::Vec4Array> _c6 = new osg::Vec4Array();
  _c6->push_back(osg::Vec4(1.0, 0.0, 0.0, 1.0));
  _c6->push_back(osg::Vec4(0.0, 1.0, 0.0, 1.0));
  _c6->push_back(osg::Vec4(0.0, 0.0, 1.0, 1.0));
  _c6->push_back(osg::Vec4(1.0, 1.0, 1.0, 1.0));
  _geom6->setColorArray(_c6.get());
  _geom6->setColorBinding(osg::Geometry::BIND_PER_VERTEX);
  geode->addDrawable(_geom6.get());
  /*
  
  for (int j=0;j<3;++j)
  {
    float flag[3] = { 1.0,1.0,1.0 };
    flag[j] = -1.0;
    for (int i=0;i<4;++i)
    {
     _surface->push_back(osg::Vec3(m_pModelData->m_pPoint[j][i]._x, m_pModelData->m_pPoint[j][i]._y, m_pModelData->m_pPoint[j][i]._z));
    }
    for (int i = 0; i < 4; ++i)
    {
      _surface->push_back(osg::Vec3(m_pModelData->m_pPoint[j][i]._x * flag[0], m_pModelData->m_pPoint[j][i]._y * flag[1], m_pModelData->m_pPoint[j][i]._z * flag[2]));
    }
  }
  _geom->setVertexArray(_surface.get());
  
  /*
  v->push_back(osg::Vec3(-1.0, -1.0, -1.0));
  v->push_back(osg::Vec3( 1.0, -1.0, -1.0));
  v->push_back(osg::Vec3( 1.0, -1.0,  1.0));
  v->push_back(osg::Vec3(-1.0, -1.0, 1.0));

  v->push_back(osg::Vec3(-1.0,  1.0, -1.0));
  v->push_back(osg::Vec3( 1.0,  1.0, -1.0));
  v->push_back(osg::Vec3( 1.0,  1.0,  1.0));
  v->push_back(osg::Vec3(-1.0, 1.0, 1.0));

  v->push_back(osg::Vec3(1.0, -1.0, -1.0));
  v->push_back(osg::Vec3(1.0, 1.0, -1.0));
  v->push_back(osg::Vec3(1.0, 1.0, 1.0));
  v->push_back(osg::Vec3(1.0, -1.0, 1.0));

  v->push_back(osg::Vec3(-1.0, -1.0, -1.0));
  v->push_back(osg::Vec3(1.0, -1.0, -1.0));
  v->push_back(osg::Vec3(1.0, 1.0, -1.0));
  v->push_back(osg::Vec3(1.0, -1.0, 1.0));

  _geom->setVertexArray(v.get());
  
  osg::ref_ptr<osg::Vec4Array> c = new osg::Vec4Array();
  for (int i = 0; i < 6; i++)
  {
    c->push_back(osg::Vec4(1.0, 0.0, 0.0, 1.0));
    c->push_back(osg::Vec4(0.0, 1.0, 0.0, 1.0));
    c->push_back(osg::Vec4(0.0, 0.0, 1.0, 1.0));
    c->push_back(osg::Vec4(1.0, 1.0, 1.0, 1.0));
  }
  
  _geom->setColorArray(c.get());
  _geom->setColorBinding(osg::Geometry::BIND_PER_VERTEX);

  osg::ref_ptr<osg::Vec3Array> n = new osg::Vec3Array();//定义了一个法线绑定到该四方体中

  n->push_back(osg::Vec3(0.0, -1.0, 0.0));//法线为指向Y轴负半轴
  n->push_back(osg::Vec3(0.0,  1.0, 0.0));
  n->push_back(osg::Vec3(1.0, 0.0, 0.0));
  n->push_back(osg::Vec3(-1.0, 0.0, 0.0));
  n->push_back(osg::Vec3(0.0, 0.0, -1.0));
  n->push_back(osg::Vec3(0.0, 0.0, 1.0));
 // n->push_back(osg::Vec3(1.0, 0.0, 0.0));
//  n->push_back(osg::Vec3(0.0, 0.0, 1.0));
  _geom->setNormalArray(n.get());//添加法线到几何体中

  _geom->setNormalBinding(osg::Geometry::BIND);//将法线进行绑定

                                                      //设置顶点的关联方式，这里是Quad方式，总共有这么些方式：POINTS,LINES,LINE_STRIP,LINE_LOOP,TRIANGLES,TRIANGLE_STRIP,TRIANGLE_FAN,QUADS,QUAD_STRIP,POLYGON

  _geom->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::QUADS, 0, 24));

  geode = new osg::Geode;
  geode->addDrawable(_geom.get());*/


}

osg::ref_ptr<osg::MatrixTransform> jyOSGModel::returnRoot()
{
  return m_pRoot.get();
}

jyModelData * jyOSGModel::returnModelData()
{
  return m_pModelData;
}
