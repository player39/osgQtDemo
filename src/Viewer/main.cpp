#include "Viewer/OSGQtWindow.h"
#include "Control/ControlGroup.h"

int main(int argc, char** argv)
{
  QApplication app(argc, argv);
  jyModelData *_mData = new jyModelData();
  jyControlGroup *_mControl = new jyControlGroup();
  jyViewerGroup *_mViewer = new jyViewerGroup();
  jyOSGModel *_mModel = new jyOSGModel();
  jyOSGQtWindow osgwin = new jyOSGQtWindow();
  _mViewer->setControl(_mControl);
  _mViewer->setModel(_mModel);
  osgwin.setViewer(_mViewer);
  osgwin.setControl(_mControl);
  _mControl->setSourceData(_mData);
  _mModel->setModelData(_mData);

  _mModel->initModel();
  osgwin.initWidget();
  _mViewer->bindDataChangeSig();
  
  osgwin.show();
  return app.exec();
}

