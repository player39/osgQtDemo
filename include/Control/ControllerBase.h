#ifndef _CONTROLLERBASE_H
#define _CONTROLLERBASE_H

#include <boost/signals2.hpp>
#include <boost/bind.hpp>
#include "Model/ModelData.h"

typedef boost::signals2::signal<void()> boostSig;

class jyControllerBase
{
public:
  jyControllerBase();
  //�ײ�������Ҫgetset�������ҷ����źŵ�control���գ����ⲿ��ȡ����ʱ�ײ�����Ҳ�ᷢ���ı� ֪ͨcontrol����������ײ�������д���Ĳ���Ҫ��ȡ
  virtual void bindDatasig();
//virtual void emitSigSourceDataChange(int i);
  //get,set�����ٿصײ����ݺͰ󶨵ײ�����
  jyModelData * getSourceData();
  //�󶨵ײ�����
  void setSourceData(jyModelData *sourceData);
  //����������Ϊosg���ڵ�任���󣬻����п��Ը���ʵ���������ӽڵ�任����
  virtual void setDataStretching(float _x, float _y, float _z);
  virtual void setDataRotate(float _r, float _x, float _y, float _z);
  virtual void setDataTranslate(float _x, float _y, float _z);
  virtual void DataReset();
  //get
  rotateAngle  getRotate();
  stretching  getStretching();
  translate  getTranslate();
private:
  //�ײ����ݵ�����,��main�����а�����Դ
  jyModelData *m_pData;
  //�������ź�,�۲��߽��е���һ������ �ĸ������ź�
  boostSig sigStretching;
  boostSig sigRotate;
  boostSig sigTranslate;
  boostSig sigReset;
  //connecting������Ҫ�������ж���
 
};

#endif // !_CONTROLLERBASE_H
