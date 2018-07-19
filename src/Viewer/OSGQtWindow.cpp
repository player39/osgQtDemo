#include "..\..\include\Viewer\OSGQtWindow.h"

jyOSGQtWindow::jyOSGQtWindow(QWidget *parent)
{
  //��ʼ����graphics���õ�widget
  ui.setupUi(this);
  //ˢ�»���
  m_pFlushTime = new QTimer();
  m_pFlushTime->start(40);
  connect(m_pFlushTime, &QTimer::timeout, this, static_cast<void (QMainWindow::*)()>(&QMainWindow::update));
  connect(ui.QAction_Translate, &QAction::triggered, this, &jyOSGQtWindow::slotShowTranslateWidget);

}

jyOSGQtWindow::~jyOSGQtWindow()
{

}

void jyOSGQtWindow::setViewer(jyViewerGroup *viewerWidget)
{
  m_pViewer = viewerWidget;
}

jyViewerGroup* jyOSGQtWindow::getViewer()
{
  return m_pViewer;
}
void jyOSGQtWindow::setControl(jyControlGroup * controller)
{
  m_pController = controller;
}
jyControlGroup *jyOSGQtWindow::getControl()
{
  return m_pController;
}
//��ʼ������
void jyOSGQtWindow::initWidget()
{
  QVBoxLayout *_centralLayout = new QVBoxLayout();
  m_pViewer->creatGraphicsWinQt(0, 0, 800, 600, "mainViewer", false);
  _centralLayout->addWidget(m_pViewer->addWidget());
  ui.QWidget_LockWidget->setLayout(_centralLayout);
  m_pFlushTime = new QTimer();
  m_pFlushTime->start(40);
  connect(m_pFlushTime, &QTimer::timeout, this, static_cast<void (QMainWindow::*)()>(&QMainWindow::update));
}

void jyOSGQtWindow::paintEvent(QPaintEvent * event)
{
  m_pViewer->frame();
}

void jyOSGQtWindow::closeEvent(QCloseEvent *event)
{
  m_pTranslateWidget->close();
}

void jyOSGQtWindow::slotShowTranslateWidget()
{
  //�ǵ�֮�����ùرմ��ں����ۺ����ȵȲ������������һ��control������
  m_pTranslateWidget = new jyParamWidget(m_pController,this);
  m_pTranslateWidget->show();
  //�󶨲ۺ������ݵײ�����,��ParamWidget�������ٵ��Ժ���Ҫ�������
}

