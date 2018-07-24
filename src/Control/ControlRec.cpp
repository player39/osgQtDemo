#include "Control/ControlRec.h"

jyControlRec::jyControlRec()
{}

void jyControlRec::setRecPoint(point rec[2])
{
  for (int i = 0; i < 2; ++i)
  {
    m_pRec[i] = rec[i];
  }
}
point* jyControlRec::getRecPoint()
{
  return m_pRec;
}