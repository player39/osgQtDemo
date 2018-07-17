#include "SourceData/ModelData.h"

jyModelData::jyModelData()
{
  //存三个面,其余三个通过变换得到
  float _temPoint[12][3] = {
    { 1.0,-1.0,-1.0},{1.0, 1.0,-1.0},{ 1.0, 1.0, 1.0},{ 1.0,-1.0,1.0},
    { -1.0,-1.0,-1.0 },{ 1.0,-1.0,-1.0 },{ 1.0,-1.0, 1.0 },{ -1.0,-1.0,1.0 },
    {-1.0,-1.0,-1.0},{1.0,-1.0,-1.0},{ 1.0, 1.0,-1.0},{-1.0,1.0,-1.0}
  };
  int _k=0;
  for (int j = 0; j < 3; ++j)
  {
    for (int i = 0; i < 4; ++i)
    {
      m_pPoint[j][i]._x = _temPoint[_k][0];
      m_pPoint[j][i]._y = _temPoint[_k][1];
      m_pPoint[j][i]._z = _temPoint[_k][2];
      ++_k;
    }
  }
}
//数据改变后发出一个信号
void jyModelData::ChangeStretching(float _X, float _Y, float _Z)
{
  m_sStrenching._x = _X;
  m_sStrenching._y = _Y;
  m_sStrenching._z = _Z;
  m_sStrenchingSignal();
}

void jyModelData::ChangeRotate(float _Angle, float _X, float _Y, float _Z)
{
  m_rRotate._angle = _Angle;
  m_rRotate._x = _X;
  m_rRotate._y = _Y;
  m_rRotate._z = _Z;
  m_rRotateSignal();
}

void jyModelData::ChangeTranslate(float _X, float _Y, float _Z)
{
  m_tTranslate._x = _X;
  m_tTranslate._y = _Y;
  m_tTranslate._z = _Z;
  m_tTranslateSignal();
}

void jyModelData::ResetParam()
{
  m_tTranslate._x = 0;
  m_tTranslate._y = 0;
  m_tTranslate._z = 0;
  m_rRotate._angle = 0;
  m_rRotate._x = 0;
  m_rRotate._y = 0;
  m_rRotate._z = 0;
  m_sStrenching._x = 0;
  m_sStrenching._y = 0;
  m_sStrenching._z = 0;
  m_Reset();
}

strenching jyModelData::returnStrenching()
{
  return m_sStrenching;
}

rotateAngle jyModelData::returnRotate()
{
  return m_rRotate;
}

translate jyModelData::returntranslate()
{
  return m_tTranslate;
}
