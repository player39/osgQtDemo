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
  //底层数据需要getset方法并且发送信号到control接收，从外部获取数据时底层数据也会发生改变 通知control，但是这里底层数据是写死的不需要获取
  virtual void binDatasig();
  //get方法操控底层数据和绑定底层数据
  DataType * getSourceData();
  virtual rotateAngle  getRotate();
  virtual  stretching  getStretching();
  virtual  translate  getTranslate();
  //set方法
  void setSourceData(DataType *sourceData);
  //这三个方法为osg根节点变换矩阵，基类中可以根据实际情况添加子节点变换矩阵
  virtual void setDataStretching(float _x, float _y, float _z);
  virtual void setDataRotate(float _r, float _x, float _y, float _z);
  virtual void setDataTranslate(float _x, float _y, float _z);
  virtual void DataReset();
  //信号四个基本信号对应 根节点变换矩阵
  boostSig sigStretching;
  boostSig sigRotate;
  boostSig sigTranslate;
  boostSig sigReset;

private:
  //底层数据的引用,在main函数中绑定数据源
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
