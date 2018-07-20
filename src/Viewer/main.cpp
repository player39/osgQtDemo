#include "Viewer/OSGQtWindow.h"
#include "Control/ControlGroup.h"
#include "Control/ControlRecGroup.h"
#include "Viewer/ViewerRectangleGroup.h"
int main(int argc, char** argv)
{
  //初始化
  QApplication app(argc, argv);
  jyModelData *_mData = new jyModelData();
  jyControlGroup *_mControl = new jyControlGroup();
  jyControlRecGroup *_mRecControl = new jyControlRecGroup();
  jyViewerGroup *_mViewer = new jyViewerGroup();
  jyViewerRectangleGroup *_mViewerRec = new jyViewerRectangleGroup();
  jyOSGModel *_mModel = new jyOSGModel();
  jyOSGQtWindow osgwin = new jyOSGQtWindow();

  //做绑定
  _mViewer->setControl(_mControl);
  _mViewer->setModel(_mModel);
  _mViewerRec->setControl(_mRecControl);
  _mViewerRec->setModel(_mModel);
  osgwin.setViewer(_mViewer);
  osgwin.setControl(_mControl);
  osgwin.setViewerRec(_mViewerRec);
  osgwin.setControlRec(_mRecControl);
  _mControl->setSourceData(_mData);
  _mRecControl->setSourceData(_mData);
  _mModel->setModelData(_mData);

  _mModel->initModel();
  osgwin.initWidget();
  _mViewer->bindDataChangeSig();
  _mViewerRec->bindDataChangeSig();
  
  osgwin.show();
  return app.exec();
}

