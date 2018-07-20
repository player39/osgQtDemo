#ifndef _CONTROLBASE_H
#define _CONTROLBASE_H

#include <boost/signals2.hpp>
#include <boost/bind.hpp>
#include "Model/ModelData.h"
typedef boost::signals2::signal<void()> boostSig;
template <class DataType>

class jyControllerBase
{
public:
  jyControllerBase();
  //�ײ�������Ҫgetset�������ҷ����źŵ�control���գ����ⲿ��ȡ����ʱ�ײ�����Ҳ�ᷢ���ı� ֪ͨcontrol����������ײ�������д���Ĳ���Ҫ��ȡ
  virtual void binDatasig();
  //get�����ٿصײ����ݺͰ󶨵ײ�����
  DataType * getSourceData();
  virtual rotateAngle  getRotate();
  virtual  stretching  getStretching();
  virtual  translate  getTranslate();
  //set����
  void setSourceData(DataType *sourceData);
  //����������Ϊosg���ڵ�任���󣬻����п��Ը���ʵ���������ӽڵ�任����
  virtual void setDataStretching(float _x, float _y, float _z);
  virtual void setDataRotate(float _r, float _x, float _y, float _z);
  virtual void setDataTranslate(float _x, float _y, float _z);
  virtual void DataReset();
  //�ź��ĸ������źŶ�Ӧ ���ڵ�任����
  boostSig sigStretching;
  boostSig sigRotate;
  boostSig sigTranslate;
  boostSig sigReset;

private:
  //�ײ����ݵ�����,��main�����а�����Դ
  DataType *m_pData;
};



template<class DataType>
inline jyControllerBase<DataType>::jyControllerBase()
{
}

template<class DataType>
inline void jyControllerBase<DataType>::binDatasig()
{
}

template<class DataType>
inline DataType* jyControllerBase<DataType>::getSourceData()
{
  return m_pData;
}

template<class DataType>
inline void jyControllerBase<DataType>::setSourceData(DataType* SourceData)
{
  m_pData = SourceData;
}

template<class DataType>
inline void jyControllerBase<DataType>::setDataStretching(float _x, float _y, float _z)
{
}

template<class DataType>
inline void jyControllerBase<DataType>::setDataRotate(float _r, float _x, float _y, float _z)
{
}

template<class DataType>
inline void jyControllerBase<DataType>::setDataTranslate(float _x, float _y, float _z)
{
}

template<class DataType>
inline void jyControllerBase<DataType>::DataReset()
{
}

template<class DataType>
inline rotateAngle jyControllerBase<DataType>::getRotate()
{
  return rotateAngle();
}

template<class DataType>
inline stretching jyControllerBase<DataType>::getStretching()
{
  return stretching();
}

template<class DataType>
inline translate jyControllerBase<DataType>::getTranslate()
{
  return translate();
}
#endif // !_CONTROLBASE_H
