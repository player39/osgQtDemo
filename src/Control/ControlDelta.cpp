#include "control/ControlDelta.h"

jyControlDelta::jyControlDelta()
{
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
