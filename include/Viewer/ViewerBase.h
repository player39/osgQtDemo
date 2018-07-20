#ifndef _VIEWERDELTA_H
#define _VIEWERDELTA_H

#include <osgViewer/Viewer>
#include <osgQt/GraphicsWindowQt>
#include <osgGA/TrackballManipulator>
#include <osgViewer/ViewerEventHandlers>
#include <boost/signals2.hpp>
#include "Viewer/OSGModel.h"

template<class controllerType,class ModelType>

class jyViewerBase :public osgViewer::Viewer
{

public:
  jyViewerBase();
  //实现qt和osg结合
  virtual osgQt::GraphicsWindowQt * creatGraphicsWinQt(int x, int y, int w, int h, const std::string& name = "", bool windowDecoration = false)=0;
  virtual QWidget * addWidget()=0;
  //绑定信号
  virtual void bindDataChangeSig()=0;
  //接收到底层数据的信号后更新变换矩阵实现效果
  virtual void stretchingChange();
  virtual void rotateChange();
  virtual void translateChange();
  virtual void paramReset();
  //get/set
  void setGraphics(osgQt::GraphicsWindowQt *Graphics);
  void setModel(ModelType *modelData);
  void setControl(controllerType *Control);
  osgQt::GraphicsWindowQt *getGranphics();
  ModelType *  getModel();
  controllerType *  getControl();

private:
  osg::ref_ptr<osgQt::GraphicsWindowQt> m_pGraphics = NULL;
  osg::ref_ptr<osg::Node> m_pNode = NULL;
  //四个连接
  boost::signals2::connection m_cConStretching;
  boost::signals2::connection m_cConTranslate;
  boost::signals2::connection m_cConRotate;
  boost::signals2::connection m_cConreset;
  //存放用于显示的osg模型的引用
  ModelType *m_pModel;
  //控制器的引用
  controllerType *m_pController;
};



template<class controllerType, class ModelType>
inline jyViewerBase<controllerType, ModelType>::jyViewerBase()
{
}

template<class controllerType, class ModelType>
inline void jyViewerBase<controllerType, ModelType>::stretchingChange()
{
}

template<class controllerType, class ModelType>
inline void jyViewerBase<controllerType, ModelType>::rotateChange()
{
}

template<class controllerType, class ModelType>
inline void jyViewerBase<controllerType, ModelType>::translateChange()
{
}

template<class controllerType, class ModelType>
inline void jyViewerBase<controllerType, ModelType>::paramReset()
{
}

template<class controllerType, class ModelType>
inline void jyViewerBase<controllerType, ModelType>::setGraphics(osgQt::GraphicsWindowQt * Graphics)
{
  m_pGraphics = Graphics;
}

template<class controllerType, class ModelType>
inline osgQt::GraphicsWindowQt * jyViewerBase<controllerType, ModelType>::getGranphics()
{
  return m_pGraphics;
}

template<class controllerType, class ModelType>
inline void jyViewerBase<controllerType, ModelType>::setModel(ModelType * modelData)
{
  m_pModel = modelData;
}

template<class controllerType, class ModelType>
inline ModelType * jyViewerBase<controllerType, ModelType>::getModel()
{
  return m_pModel;
}

template<class controllerType, class ModelType>
inline void jyViewerBase<controllerType, ModelType>::setControl(controllerType * Control)
{
  m_pController = Control;
}

template<class controllerType, class ModelType>
inline controllerType * jyViewerBase<controllerType, ModelType>::getControl()
{
  return m_pController;
}
#endif // !_VIEWERDELTA_H
