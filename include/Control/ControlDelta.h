#ifndef _CONTROLDELTA_H
#define _CONTROLDELTA_H

#include "Control/ControlBase.h"

class jyControlDelta :public jyControllerBase
{
public:
  jyControlDelta();
  point *getDeltaPoint();
  void setDeltaPoint(point deltapoint[3]);
private:
  point m_pDelta[3];
};
#endif // !_CONTROLDELTA_H
