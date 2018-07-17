#ifndef _MODELDATA_H
#define _MODELDATA_H

#include <iostream>
#include <boost/signals2.hpp>
#include <boost/bind.hpp>
//�涥��
struct point
{
  float _x;
  float _y;
  float _z;
};
//����ת�Ǻ���ת��
struct rotateAngle
{
  float _angle;
  float _x;
  float _y;
  float _z;
  rotateAngle() :_angle(0.0), _x(0.0), _y(0.0), _z(0.0) {};
};
//�����ű���
struct strenching
{
  float _x;
  float _y;
  float _z;
  strenching(): _x(0.0), _y(0.0), _z(0.0) {};
};
//��ƽ������
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
  //�ı����ݺ��Ӧ���������ź�
  changeData m_sStrenchingSignal;
  changeData m_rRotateSignal;
  changeData m_tTranslateSignal;
  changeData m_Reset;
  //��������
  point m_pPoint[3][4];
  //�ı�3������
  void ChangeStretching(float _X, float _Y, float _Z);
  void ChangeRotate(float _Angle, float _X, float _Y, float _Z);
  void ChangeTranslate(float _X, float _Y, float _Z);
  void ResetParam();
  //����3���任����
  strenching returnStrenching();
  rotateAngle returnRotate();
  translate returntranslate();

private:
  //boost�ź�
  rotateAngle m_rRotate;
  strenching m_sStrenching;
  translate m_tTranslate;

};

#endif // !_MODELDATA_H
