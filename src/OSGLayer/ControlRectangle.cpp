#include "..\..\include\OSGLayer\ControlRectangle.h"

jyControlRectangle::jyControlRectangle()
{
}

void jyControlRectangle::Signals2Connect()
{
  returnOSGModel()->returnModelData()->m_rRotateSignal.connect(boost::bind(&jyControlRectangle::rotateChange, this));
  returnOSGModel()->returnModelData()->m_sStrenchingSignal.connect(boost::bind(&jyControlRectangle::stretchingChange, this));
  returnOSGModel()->returnModelData()->m_tTranslateSignal.connect(boost::bind(&jyControlRectangle::translateChange, this));
}
