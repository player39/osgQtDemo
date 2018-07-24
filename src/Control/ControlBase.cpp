#include "control/ControlBase.h"

jyControllerBase::jyControllerBase()
{
}

boost::signals2::connection jyControllerBase::connectStretching(slotType &type)
{
  sig_Stretching.connect(boost::bind(&type,this));
}

boost::signals2::connection jyControllerBase::connectTranslate(slotType &type)
{
  sig_Translate.connect(boost::bind(&type, this));
}

boost::signals2::connection jyControllerBase::connectRotate(slotType &type)
{
  sig_Rotate.connect(boost::bind(&type, this));
}

boost::signals2::connection jyControllerBase::connectReset(slotType &type)
{
  sig_Reset.connect(boost::bind(&type, this));
}

stretching jyControllerBase::getStretching()
{
  return m_sStretching;
}

translate jyControllerBase::getTranslate()
{
  return m_tTranslate;
}

rotateAngle jyControllerBase::getRotate()
{
  return m_rRotate;
}

void jyControllerBase::setStretching(float _X, float _Y, float _Z)
{
  m_sStretching._x = _X;
  m_sStretching._y = _Y;
  m_sStretching._z = _Z;
}

void jyControllerBase::setTranslate(float _X, float _Y, float _Z)
{
  m_tTranslate._x = _X;
  m_tTranslate._y = _Y;
  m_tTranslate._z = _Z;
}

void jyControllerBase::setRotate(float _Angle, float _X, float _Y, float _Z)
{
  m_rRotate._angle = _Angle;
  m_rRotate._x = _X;
  m_rRotate._y = _Y;
  m_rRotate._z = _Z;
}

void jyControllerBase::Reset()
{
  m_sStretching._x = 1;
  m_sStretching._y = 1;
  m_sStretching._z = 1;
  m_tTranslate._x = 0;
  m_tTranslate._y = 0;
  m_tTranslate._z = 0;
  m_rRotate._angle = 0;
  m_rRotate._x = 0;
  m_rRotate._y = 0;
  m_rRotate._z = 0;
}