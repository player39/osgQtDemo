#ifndef _OSGQtWindow_H
#define _OSGQtWindow_H

#include <QtWidgets/QWidget>
#include <QtCore/Qtimer>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QVBoxLayout>
#include "ui_OSGQt.h"
#include "Viewer/ViewerGroup.h"
#include "Viewer/ParamWidget.h"
#include "Viewer/ViewerRectangleGroup.h"
#include "Control/ControlGroup.h"

class jyOSGQtWindow :public QMainWindow
{
  Q_OBJECT
public:
  jyOSGQtWindow(QWidget *parent = Q_NULLPTR);
  ~jyOSGQtWindow();
  //绑定视图和控制器
  void setViewer(jyViewerGroup *viewerWidget);
  void setControl(jyControlGroup * controller);
  void setViewerRec(jyViewerRectangleGroup *viewerWidget);
  void setControlRec(jyControlRecGroup *controller);
  jyViewerGroup* getViewer();
  jyControlGroup* getControl();
  jyViewerRectangleGroup *getViewerRec();
  jyControlRecGroup* getControlRec();
  //初始化
  void initWidget();
protected:
  virtual void paintEvent(QPaintEvent *event);
  virtual void closeEvent(QCloseEvent *event);
private:
  //设定定时器 每过一定时间刷新一次 显示控制效果
  QTimer *m_pFlushTime=NULL;
  Ui::OSGQt ui;
  //绑定两个视图
  jyViewerGroup *m_pViewer = NULL;
  jyViewerRectangleGroup *m_pViewerRec = NULL;
  //一个弹窗
  jyParamWidget *m_pTranslateWidget=NULL;
  //两个控制器引用，来修改数据
  jyControlGroup *m_pController = NULL;
  jyControlRecGroup *m_pControllerRec = NULL;

public slots:
  //显示窗口
  void slotShowTranslateWidget(); 
};
#endif // !_OSGQtWindow_H
