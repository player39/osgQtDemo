#ifndef _CONTROLRECTANGLE_H
#define _CONTROLRECTANGLE_H

#include "Control/ControlBase.h"

class jyControlGroup :public jyControllerBase<jyModelData>
{
public:
  jyControlGroup() :jyControllerBase<jyModelData>(){};
  //set���� ��������Ӷ��ӽڵ������һ���Ƕ��߶β���
  void setLineStretching(float _x, float _y, float _z);
  void setLineRotate(float _Angle, float _x, float _y, float _z);
  void setLineTranslate(float _x, float _y, float _z);
  //�Ծ��εĲ�����δʵ��
  void setRectangleStretching(float _x, float _y, float _z);
  void settRectangleRotate(float _Angle, float _x, float _y, float _z);
  void settRectangleTranslate(float _x, float _y, float _z);
  //ʵ��һ���Ը��ڵ�Ĳ���,��ʵ����rotate
  virtual void setDataRotate(float _r, float _x, float _y, float _z);
  virtual void setDataStretching(float _x, float _y, float _z);
  virtual void setDataTranslate(float _x, float _y, float _z);
  //����Line���ź�
   boostSig sigLineStretching;
   boostSig sigLineTranslate;
   boostSig sigLineRotate;
   boostSig sigLineReset;
private:
  

};
#endif // !_CONTROLRECTANGLE_H
