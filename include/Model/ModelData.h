#ifndef _MODELDATA_H
#define _MODELDATA_H

#include <iostream>
#include <boost/signals2.hpp>
#include <boost/bind.hpp>
//存顶点
struct point
{
  float _x;
  float _y;
  float _z;
};
//存旋转角和旋转轴
struct rotateAngle
{
  float _angle;
  float _x;
  float _y;
  float _z;
  rotateAngle() :_angle(0.0), _x(0.0), _y(0.0), _z(0.0) {};
};
//存缩放比例
struct stretching
{
  float _x;
  float _y;
  float _z;
  stretching(): _x(0.0), _y(0.0), _z(0.0) {};
};
//存平移坐标
struct translate
{
  float _x;
  float _y;
  float _z;
  translate() : _x(0.0), _y(0.0), _z(0.0) {};
};

typedef boost::signals2::signal<void ()> boostSig;
//这个数据源中有两个图形 一根线段一个矩形通过一个继承下来的控制器，分别控制两个图形的变换
class jyModelData
{

public:
  jyModelData();
  //改变数据后对应发送4个信号
  boostSig m_sStrenchingSignal;
  boostSig m_rRotateSignal;
  boostSig m_tTranslateSignal;
  boostSig m_Reset;
  //改为一个信号
 // boostSig m_sigChangeData;
  //顶点数据，矩形
  point m_pPoint[3][4];
  point m_pLine[2];
  point m_pRec[3];
  //改变3个数据
  void ChangeStretching(float _X, float _Y, float _Z);
  void ChangeRotate(float _Angle, float _X, float _Y, float _Z);
  void ChangeTranslate(float _X, float _Y, float _Z);
  void ResetParam();
  //改变线段的接口
  void ChangeLineStretching(float _X, float _Y, float _Z);
  void ChangeLineRotate(float _Angle, float _X, float _Y, float _Z);
  void ChangeLineTranslate(float _X, float _Y, float _Z);
  void ResetLineParam();
  //改变矩形
  void ChangeRecStretching(float _X, float _Y, float _Z);
  void ChangeRecRotate(float _Angle, float _X, float _Y, float _Z);
  void ChangeRecTranslate(float _X, float _Y, float _Z);
  void ResetRecParam();
  
  //返回3个变换数据
  stretching returnStrenching();
  rotateAngle returnRotate();
  translate returntranslate();
  //返回Line的变换数据
  stretching getLineStretching();
  rotateAngle getLineRotate();
  translate getLineTranslate();
  //返回另一视图三角的变换数据
  rotateAngle getRecRotate();
  stretching getRecStretching();
  translate getRecTranslate();

private:
  //这里有一个问题 本来想用数组实现这样信号和槽函数的数量都会变少，只需要通过信号中的参数对应操作
  //osg图形为树状结构，这一组变换坐标属于最上层根节点
  rotateAngle m_rRotate;
  stretching m_sStrenching;
  translate m_tTranslate;
  //这一组属于线段的变换坐标
  rotateAngle m_rLineRotate;
  stretching m_sLineStrenching;
  translate m_tLineTranslate;
  //这一组属于三角形
  rotateAngle m_rRecRotate;
  stretching m_sRecStretching;
  translate m_tRecTranslate;
};

#endif // !_MODELDATA_H
