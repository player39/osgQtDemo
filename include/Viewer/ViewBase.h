#ifndef _VIEWBASE_H
#define  _VIEWBASE_H

#include "boost/signals2.hpp"
#include "boost/bind.hpp"
#include "Control/ControlBase.h"

typedef boost::signals2::signal<void()>::slot_type slotType;

template<class ControlType>

class jyViewBase
{
public:
  jyViewBase(ControlType *mControl);
  //get
  ControlType *getController();
  //set
  void setController(ControlType *controller);
  //更新视图
  virtual void updataViewStretching();
  virtual void updataViewTranslate();
  virtual void updataViewRotate();
  virtual void updataViewReset();
  //发送任务到控制器
  virtual void TaskToController();
  //初始化视图
  virtual void initView();

private:
  ControlType *m_pController=NULL;
};

template<class ModelType, class ControlType>
inline jyViewBase<ModelType, ControlType>::jyViewBase(ControlType *mControl)
{
  setController(mControl);
}

template<class ModelType, class ControlType>
inline ModelType * jyViewBase<ModelType, ControlType>::getSouceData()
{
  return m_pSourceData;
}

template<class ModelType, class ControlType>
inline ControlType * jyViewBase<ModelType, ControlType>::getController()
{
  return m_pController;
}

template<class ModelType, class ControlType>
inline void jyViewBase<ModelType, ControlType>::setSouceData(ModelType *model)
{
  m_pSourceData = model;
}

template<class ModelType, class ControlType>
inline void jyViewBase<ModelType, ControlType>::setController(ControlType * controller)
{
  m_pController = controller;
  jyControllerBase::connectReset(updataViewReset);
  jyControllerBase::connectTranslate(updataViewTranslate);
  jyControllerBase::connectRotate(updataViewRotate);
  jyControllerBase::connectStretching(updataViewStretching);
}

template<class ControlType>
inline void jyViewBase<ControlType>::updataViewStretching()
{
}

template<class ControlType>
inline void jyViewBase<ControlType>::updataViewTranslate()
{
}

template<class ControlType>
inline void jyViewBase<ControlType>::updataViewRotate()
{
}

template<class ControlType>
inline void jyViewBase<ControlType>::updataViewReset()
{
}

template<class ModelType, class ControlType>
inline void jyViewBase<ModelType, ControlType>::TaskToController()
{
}

template<class ModelType, class ControlType>
inline void jyViewBase<ModelType, ControlType>::initView()
{
}

#endif // !_VIEWBASE_H
