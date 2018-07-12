#include "..\..\include\QtWin\OSGQtWindow.h"
#include <iostream>
jyOSGQtWindow::jyOSGQtWindow(QWidget *parent)
{
  //--------------------初始化---------------------将graphics设置到widget
  ui.setupUi(this);
  m_pControl = new jyControlShow();
  QVBoxLayout *_centralLayout = new QVBoxLayout();
  osg::Node* scene = osgDB::readNodeFile("C://Users//Administrator//Downloads//OpenSceneGraph-Data-3.0.0//OpenSceneGraph-Data-3.0.0//cessna.osg");
  m_pControl->CreatGraphicsWinQt(0, 0, 800, 600, "mainViewer", false);
  _centralLayout->addWidget(m_pControl->addViewWidget(scene));
  ui.QWidget_LockWidget->setLayout(_centralLayout);
  m_pFlushTime = new QTimer();
  m_pFlushTime->start(40);
  connect(m_pFlushTime, &QTimer::timeout, this, static_cast<void (QMainWindow::*)()>(&QMainWindow::update));
  connect(ui.QAction_Open, &QAction::triggered, this, &jyOSGQtWindow::changeModel);
  connect(ui.QAction_Stretching, &QAction::triggered, m_pControl, &jyControlShow::stretchingChange);
  //-----------------初始化结束-------------------
}

void jyOSGQtWindow::paintEvent(QPaintEvent * event)
{
  m_pControl->flashWindow();
}

void jyOSGQtWindow::changeModel()
{
  //test
  m_pControl->changeGraphics();
}
