#ifndef _CONTROLRECTANGLE_H
#define _CONTROLRECTANGLE_H

#include "Control/ControlBase.h"

class jyControlGroup :public jyControllerBase<jyModelData>
{
public:
  jyControlGroup() :jyControllerBase<jyModelData>(){};
  //set方法 子类中添加对子节点操作，一个是对线段操作
  void setLineStretching(float _x, float _y, float _z);
  void setLineRotate(float _Angle, float _x, float _y, float _z);
  void setLineTranslate(float _x, float _y, float _z);
  //对矩形的操作，未实现
  void setRectangleStretching(float _x, float _y, float _z);
  void settRectangleRotate(float _Angle, float _x, float _y, float _z);
  void settRectangleTranslate(float _x, float _y, float _z);
  //实现一个对根节点的操作,仅实现了rotate
  virtual void setDataRotate(float _r, float _x, float _y, float _z);
  virtual void setDataStretching(float _x, float _y, float _z);
  virtual void setDataTranslate(float _x, float _y, float _z);
  //属于Line的信号
   boostSig sigLineStretching;
   boostSig sigLineTranslate;
   boostSig sigLineRotate;
   boostSig sigLineReset;
private:
  

};
#endif // !_CONTROLRECTANGLE_H
