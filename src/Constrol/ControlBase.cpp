#include "Control/ControllerBase.h"

jyControllerBase::jyControllerBase()
{

}

void jyControllerBase::bindDatasig()
{

}

jyModelData * jyControllerBase::getSourceData()
{
return m_pData;
}

void jyControllerBase::setSourceData(jyModelData *sourceData)
{
m_pData = sourceData;
}

void jyControllerBase::setDataStretching(float _x, float _y, float _z)
{
m_pData->ChangeStretching(_x, _y, _z);
sigStretching();
}

void jyControllerBase::setDataRotate(float _r, float _x, float _y, float _z)
{
m_pData->ChangeRotate(_r, _x, _y, _z);
sigRotate();
}

void jyControllerBase::setDataTranslate(float _x, float _y, float _z)
{
m_pData->ChangeTranslate(_x, _y, _z);
sigTranslate();
}

void jyControllerBase::DataReset()
{
m_pData->ResetParam();
sigReset();
}

rotateAngle jyControllerBase::getRotate()
{
return getSourceData()->returnRotate();
}

stretching jyControllerBase::getStretching()
{
return getSourceData()->returnStrenching();
}

translate jyControllerBase::getTranslate()
{
return getSourceData()->returntranslate();
}