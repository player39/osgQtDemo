#include "..\..\include\QtWin\OSGQtWindow.h"

jyOSGQtWindow::jyOSGQtWindow(QWidget *parent)
{
  //��ʼ����graphics���õ�widget
  ui.setupUi(this);
  //ʵ������ʾ������
  m_pControl = new jyControlShow();
  QVBoxLayout *_centralLayout = new QVBoxLayout();
  //����һ��GraphicsWinQt
  m_pControl->CreatGraphicsWinQt(0, 0, 800, 600, "mainViewer", false);
  //addViewidget�᷵��һ��GLWidget
  _centralLayout->addWidget(m_pControl->addViewWidget());
  ui.QWidget_LockWidget->setLayout(_centralLayout);
  //ˢ�»���
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
  //�ǵ�֮�����ùرմ��ں����ۺ����ȵȲ���
  m_pTranslateWidget = new jyParamWidget(this);
  m_pTranslateWidget->show();
  //�󶨲ۺ������ݵײ�����,��ParamWidget�������ٵ��Ժ���Ҫ�������
  connect(m_pTranslateWidget, &jyParamWidget::paramStretchingPass, this,&jyOSGQtWindow::slotChangeStretching);
  connect(m_pTranslateWidget, &jyParamWidget::paramRotatePass, this, &jyOSGQtWindow::slotChangeRotate);
  connect(m_pTranslateWidget, &jyParamWidget::paramTranslate, this, &jyOSGQtWindow::slotChangeTranslate);
  connect(m_pTranslateWidget, &jyParamWidget::paramReset, this, &jyOSGQtWindow::slotChangeParamReset);
}
//���ĵײ�����
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

