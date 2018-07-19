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
  //底层数据需要getset方法并且发送信号到control接收，从外部获取数据时底层数据也会发生改变 通知control，但是这里底层数据是写死的不需要获取
  virtual void bindDatasig();
//virtual void emitSigSourceDataChange(int i);
  //get,set方法操控底层数据和绑定底层数据
  jyModelData * getSourceData();
  //绑定底层数据
  void setSourceData(jyModelData *sourceData);
  //这三个方法为osg根节点变换矩阵，基类中可以根据实际情况添加子节点变换矩阵
  virtual void setDataStretching(float _x, float _y, float _z);
  virtual void setDataRotate(float _r, float _x, float _y, float _z);
  virtual void setDataTranslate(float _x, float _y, float _z);
  virtual void DataReset();
  //get
  rotateAngle  getRotate();
  stretching  getStretching();
  translate  getTranslate();
private:
  //底层数据的引用,在main函数中绑定数据源
  jyModelData *m_pData;
  //发出的信号,观察者进行的下一步操作 四个基本信号
  boostSig sigStretching;
  boostSig sigRotate;
  boostSig sigTranslate;
  boostSig sigReset;
  //connecting根据需要在子类中定义
 
};

#endif // !_CONTROLLERBASE_H
