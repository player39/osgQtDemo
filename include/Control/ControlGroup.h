#ifndef _CONTROLRECTANGLE_H
#define _CONTROLRECTANGLE_H

#include "Control/ControllerBase.h"
#include "Model/ModelData.h"

class jyControlGroup :public jyControllerBase
{
public:
  jyControlGroup() {};
  void setLineStretching(float _x, float _y, float _z);
  void setLineRotate(float _Angle, float _x, float _y, float _z);
  void setLineTranslate(float _x, float _y, float _z);
  //--
  void setRectangleStretching(float _x, float _y, float _z);
  void settRectangleRotate(float _Angle, float _x, float _y, float _z);
  void settRectangleTranslate(float _x, float _y, float _z);
  //
   boostSig sigLineStretching;
   boostSig sigLineTranslate;
   boostSig sigLineRotate;
   boostSig sigLineReset;
private:
  

};
#endif // !_CONTROLRECTANGLE_H
