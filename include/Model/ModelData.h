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
struct stretching
{
  float _x;
  float _y;
  float _z;
  stretching(): _x(0.0), _y(0.0), _z(0.0) {};
};
//��ƽ������
struct translate
{
  float _x;
  float _y;
  float _z;
  translate() : _x(0.0), _y(0.0), _z(0.0) {};
};

typedef boost::signals2::signal<void ()> boostSig;
//�������Դ��������ͼ�� һ���߶�һ������ͨ��һ���̳������Ŀ��������ֱ��������ͼ�εı任
class jyModelData
{

public:
  jyModelData();
  //�ı����ݺ��Ӧ����4���ź�
  boostSig m_sStrenchingSignal;
  boostSig m_rRotateSignal;
  boostSig m_tTranslateSignal;
  boostSig m_Reset;
  //��Ϊһ���ź�
 // boostSig m_sigChangeData;
  //�������ݣ�����
  point m_pPoint[3][4];
  point m_pLine[2];
  point m_pRec[3];
  //�ı�3������
  void ChangeStretching(float _X, float _Y, float _Z);
  void ChangeRotate(float _Angle, float _X, float _Y, float _Z);
  void ChangeTranslate(float _X, float _Y, float _Z);
  void ResetParam();
  //�ı��߶εĽӿ�
  void ChangeLineStretching(float _X, float _Y, float _Z);
  void ChangeLineRotate(float _Angle, float _X, float _Y, float _Z);
  void ChangeLineTranslate(float _X, float _Y, float _Z);
  void ResetLineParam();
  //�ı����
  void ChangeRecStretching(float _X, float _Y, float _Z);
  void ChangeRecRotate(float _Angle, float _X, float _Y, float _Z);
  void ChangeRecTranslate(float _X, float _Y, float _Z);
  void ResetRecParam();
  
  //����3���任����
  stretching returnStrenching();
  rotateAngle returnRotate();
  translate returntranslate();
  //����Line�ı任����
  stretching getLineStretching();
  rotateAngle getLineRotate();
  translate getLineTranslate();
  //������һ��ͼ���ǵı任����
  rotateAngle getRecRotate();
  stretching getRecStretching();
  translate getRecTranslate();

private:
  //������һ������ ������������ʵ�������źźͲۺ���������������٣�ֻ��Ҫͨ���ź��еĲ�����Ӧ����
  //osgͼ��Ϊ��״�ṹ����һ��任�����������ϲ���ڵ�
  rotateAngle m_rRotate;
  stretching m_sStrenching;
  translate m_tTranslate;
  //��һ�������߶εı任����
  rotateAngle m_rLineRotate;
  stretching m_sLineStrenching;
  translate m_tLineTranslate;
  //��һ������������
  rotateAngle m_rRecRotate;
  stretching m_sRecStretching;
  translate m_tRecTranslate;
};

#endif // !_MODELDATA_H
