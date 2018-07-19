#include "..\..\include\Viewer\OSGQtWindow.h"

jyOSGQtWindow::jyOSGQtWindow(QWidget *parent)
{
  //初始化将graphics设置到widget
  ui.setupUi(this);
  //刷新画面
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
//初始化窗口
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
  //记得之后设置关闭窗口后解除槽函数等等操作，传入参数一个control的引用
  m_pTranslateWidget = new jyParamWidget(m_pController,this);
  m_pTranslateWidget->show();
  //绑定槽函数操纵底层数据,在ParamWidget窗口销毁掉以后需要解除绑定吗
}

