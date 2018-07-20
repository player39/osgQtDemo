#ifndef _CONTROLRECGROUP_H
#define _CONTROLRECGROUP_H
#include "Model/ModelData.h"
#include "Control/ControlBase.h"
class jyControlRecGroup :public jyControllerBase<jyModelData>
{
public:
  jyControlRecGroup() :jyControllerBase<jyModelData>() {};
  //实现对根节点的操作
  virtual void setDataRotate(float _r, float _x, float _y, float _z);
  //信号
  boostSig sigRootRotate;

private:
};

#endif // !_CONTROLRECGROUP_H
