#include "..\..\include\Control\ControlRecGroup.h"

void jyControlRecGroup::setDataRotate(float _r, float _x, float _y, float _z)
{
  getSourceData()->ChangeRecRotate(_r, _x, _y, _z);
  sigRootRotate();
}
