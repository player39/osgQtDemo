#include "..\..\include\QtWin\OSGQtWindow.h"

jyOSGQtWindow::jyOSGQtWindow(QWidget *parent)
{
  //初始化将graphics设置到widget
  ui.setupUi(this);
  //实例化显示控制类
  m_pControl = new jyControlShow();
  QVBoxLayout *_centralLayout = new QVBoxLayout();
  //创建一个GraphicsWinQt
  m_pControl->CreatGraphicsWinQt(0, 0, 800, 600, "mainViewer", false);
  //addViewidget会返回一个GLWidget
  _centralLayout->addWidget(m_pControl->addViewWidget());
  ui.QWidget_LockWidget->setLayout(_centralLayout);
  //刷新画面
  m_pFlushTime = new QTimer();
  m_pFlushTime->start(40);
  connect(m_pFlushTime, &QTimer::timeout, this, static_cast<void (QMainWindow::*)()>(&QMainWindow::update));
  connect(ui.QAction_Translate, &QAction::triggered, this, &jyOSGQtWindow::slotShowTranslateWidget);
}

void jyOSGQtWindow::paintEvent(QPaintEvent * event)
{
  m_pControl->flashWindow();
}

void jyOSGQtWindow::slotShowTranslateWidget()
{
  //记得之后设置关闭窗口后解除槽函数等等操作
  m_pTranslateWidget = new jyParamWidget(this);
  m_pTranslateWidget->show();
  //绑定槽函数操纵底层数据,在ParamWidget窗口销毁掉以后需要解除绑定吗
  connect(m_pTranslateWidget, &jyParamWidget::paramStretchingPass, this,&jyOSGQtWindow::slotChangeStretching);
  connect(m_pTranslateWidget, &jyParamWidget::paramRotatePass, this, &jyOSGQtWindow::slotChangeRotate);
  connect(m_pTranslateWidget, &jyParamWidget::paramTranslate, this, &jyOSGQtWindow::slotChangeTranslate);
  connect(m_pTranslateWidget, &jyParamWidget::paramReset, this, &jyOSGQtWindow::slotChangeParamReset);
}
//更改底层数据
void jyOSGQtWindow::slotChangeStretching(float _x, float _y, float _z)
{
  m_pControl->returnOSGModel()->returnModelData()->ChangeStretching(_x, _y, _z);
}

void jyOSGQtWindow::slotChangeTranslate(float _x, float _y, float _z)
{
  m_pControl->returnOSGModel()->returnModelData()->ChangeTranslate(_x, _y, _z);
}

void jyOSGQtWindow::slotChangeRotate(float _angle, float _x, float _y, float _z)
{
  m_pControl->returnOSGModel()->returnModelData()->ChangeRotate(_angle, _x, _y, _z);
}

void jyOSGQtWindow::slotChangeParamReset()
{
  m_pControl->returnOSGModel()->returnModelData()->ResetParam();
}

