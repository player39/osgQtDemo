#include "control/ControlDelta.h"

jyControlDelta::jyControlDelta()
{
  m_pDelta[0]._x = -1;
  m_pDelta[0]._y = 0;
  m_pDelta[0]._z = 0;

  m_pDelta[1]._x = 1;
  m_pDelta[1]._y = 0;
  m_pDelta[1]._z = 0;

  m_pDelta[2]._x = 0;
  m_pDelta[2]._y = 0;
  m_pDelta[2]._z = 1.7f;
}

point * jyControlDelta::getDeltaPoint()
{
  return m_pDelta;
}

void jyControlDelta::setDeltaPoint(point deltapoint[3])
{
  for (int i = 0; i < 3; ++i)
  {
    m_pDelta[i] = deltapoint[i];
  }
}
