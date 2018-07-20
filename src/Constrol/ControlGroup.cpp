#include "Control/ControlGroup.h"

void jyControlGroup::setLineStretching(float _x, float _y, float _z)
{
  this->getSourceData()->ChangeLineStretching(_x, _y, _z);
  sigLineStretching();
}

void jyControlGroup::setLineRotate(float _Angle, float _x, float _y, float _z)
{
  this->getSourceData()->ChangeLineRotate(_Angle, _x, _y, _z);
  sigLineRotate();
}

void jyControlGroup::setLineTranslate(float _x, float _y, float _z)
{
  this->getSourceData()->ChangeLineTranslate(_x, _y, _z);
  sigLineTranslate();
}

void jyControlGroup::setRectangleStretching(float _x, float _y, float _z)
{
}

void jyControlGroup::settRectangleRotate(float _Angle, float _x, float _y, float _z)
{
}

void jyControlGroup::settRectangleTranslate(float _x, float _y, float _z)
{
}

void jyControlGroup::setDataRotate(float _r, float _x, float _y, float _z)
{
  getSourceData()->ChangeRotate(_r, _x, _y, _z);
  this->sigRotate();
}

void jyControlGroup::setDataStretching(float _x, float _y, float _z)
{
}

void jyControlGroup::setDataTranslate(float _x, float _y, float _z)
{
}

