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
  virtual osgQt::GraphicsWindowQt * creatGraphicsWinQt(int x, int y, int w, int h, const std::string& name = "", bool windowDecoration = false)=0;
  virtual QWidget * addWidget()=0;
  //�󶨷���
  virtual void bindDataChangeSig()=0;
  //���յ����Ʋ㷢�����ĵײ����ݸ����źţ����⼸���ۺ���������ͼ
  void stretchingChange();
  void rotateChange();
  void translateChange();
  void paramReset();

  void setGraphics(osgQt::GraphicsWindowQt *Graphics);
  osgQt::GraphicsWindowQt *getGranphics();
  //get\set������
  void setModel(ModelType *modelData);
  ModelType *  getModel();
  void setControl(controllerType *Control);
  controllerType *  getControl();

private:
  osg::ref_ptr<osgQt::GraphicsWindowQt> m_pGraphics = NULL;
  osg::ref_ptr<osg::Node> m_pNode = NULL;
  //�ĸ�����
  boost::signals2::connection m_cConStretching;
  boost::signals2::connection m_cConTranslate;
  boost::signals2::connection m_cConRotate;
  boost::signals2::connection m_cConreset;
  //���������ʾ��osgģ�͵�����
  ModelType *m_pModel;
  //������������
  controllerType *m_pController;
};

#endif // !_VIEWERDELTA_H

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
