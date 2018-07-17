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
struct strenching
{
  float _x;
  float _y;
  float _z;
  strenching(): _x(0.0), _y(0.0), _z(0.0) {};
};
//存平移坐标
struct translate
{
  float _x;
  float _y;
  float _z;
  translate() : _x(0.0), _y(0.0), _z(0.0) {};
};

typedef boost::signals2::signal<void ()> changeData;

class jyModelData
{

public:
  jyModelData();
  //改变数据后对应发送三个信号
  changeData m_sStrenchingSignal;
  changeData m_rRotateSignal;
  changeData m_tTranslateSignal;
  changeData m_Reset;
  //顶点数据
  point m_pPoint[3][4];
  //改变3个数据
  void ChangeStretching(float _X, float _Y, float _Z);
  void ChangeRotate(float _Angle, float _X, float _Y, float _Z);
  void ChangeTranslate(float _X, float _Y, float _Z);
  void ResetParam();
  //返回3个变换数据
  strenching returnStrenching();
  rotateAngle returnRotate();
  translate returntranslate();

private:
  //boost信号
  rotateAngle m_rRotate;
  strenching m_sStrenching;
  translate m_tTranslate;

};

#endif // !_MODELDATA_H
