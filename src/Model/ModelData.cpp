#include "Model/ModelData.h"

jyModelData::jyModelData()
{
  //Rec
  m_pRec[0]._x = -1;
  m_pRec[0]._y = 0;
  m_pRec[0]._z = 0;

  m_pRec[1]._x = 1;
  m_pRec[1]._y = 0;
  m_pRec[1]._z = 0;

  m_pRec[2]._x = 0;
  m_pRec[2]._y = 0;
  m_pRec[2]._z = 1.7;
  //Line
  m_pLine[0]._x = 2;
  m_pLine[0]._y = -2;
  m_pLine[0]._z = 2;

  m_pLine[1]._x = -2;
  m_pLine[1]._y = -2;
  m_pLine[1]._z = 2;
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

void jyModelData::ChangeStretching(float _X, float _Y, float _Z)
{
  m_sStrenching._x = _X;
  m_sStrenching._y = _Y;
  m_sStrenching._z = _Z;
}

void jyModelData::ChangeRotate(float _Angle, float _X, float _Y, float _Z)
{
  m_rRotate._angle = _Angle;
  m_rRotate._x = _X;
  m_rRotate._y = _Y;
  m_rRotate._z = _Z;
}

void jyModelData::ChangeTranslate(float _X, float _Y, float _Z)
{
  m_tTranslate._x = _X;
  m_tTranslate._y = _Y;
  m_tTranslate._z = _Z;
}

void jyModelData::ChangeLineStretching(float _X, float _Y, float _Z)
{
  m_sLineStrenching._x = _X;
  m_sLineStrenching._y = _Y;
  m_sLineStrenching._z = _Z;
}

void jyModelData::ChangeLineRotate(float _Angle, float _X, float _Y, float _Z)
{
  m_rLineRotate._angle = _Angle;
  m_rLineRotate._x = _X;
  m_rLineRotate._y = _Y;
  m_rLineRotate._z = _Z;
}

void jyModelData::ChangeLineTranslate(float _X, float _Y, float _Z)
{
  m_tLineTranslate._x = _X;
  m_tLineTranslate._y = _Y;
  m_tLineTranslate._z = _Z;
}

void jyModelData::ResetLineParam()
{
  m_tLineTranslate._x = 0;
  m_tLineTranslate._y = 0;
  m_tLineTranslate._z = 0;
  m_rLineRotate._angle = 0;
  m_rLineRotate._x = 0;
  m_rLineRotate._y = 0;
  m_rLineRotate._z = 0;
  m_sLineStrenching._x = 0;
  m_sLineStrenching._y = 0;
  m_sLineStrenching._z = 0;
}

void jyModelData::ChangeRecStretching(float _X, float _Y, float _Z)
{
  m_sRecStretching._x = _X;
  m_sRecStretching._y = _Y;
  m_sRecStretching._z = _Z;
}

void jyModelData::ChangeRecRotate(float _Angle, float _X, float _Y, float _Z)
{
  m_rRecRotate._angle = _Angle;
  m_rRecRotate._x = _X;
  m_rRecRotate._y = _Y;
  m_rRecRotate._z = _Z;
}

void jyModelData::ChangeRecTranslate(float _X, float _Y, float _Z)
{
  m_tRecTranslate._x = _X;
  m_tRecTranslate._y = _Y;
  m_tRecTranslate._z = _Z;
}

void jyModelData::ResetRecParam()
{
  m_tRecTranslate._x = 0;
  m_tRecTranslate._y = 0;
  m_tRecTranslate._z = 0;
  m_rRecRotate._angle = 0;
  m_rRecRotate._x = 0;
  m_rRecRotate._y = 0;
  m_rRecRotate._z = 0;
  m_sRecStretching._x = 0;
  m_sRecStretching._y = 0;
  m_sRecStretching._z = 0;
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
}

stretching jyModelData::returnStrenching()
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

stretching jyModelData::getLineStretching()
{
  return m_sLineStrenching;
}

rotateAngle jyModelData::getLineRotate()
{
  return m_rLineRotate;
}

translate jyModelData::getLineTranslate()
{
  return m_tLineTranslate;
}

rotateAngle jyModelData::getRecRotate()
{
  return m_rRecRotate;
}

stretching jyModelData::getRecStretching()
{
  return m_sRecStretching;
}

translate jyModelData::getRecTranslate()
{
  return m_tRecTranslate;
}
