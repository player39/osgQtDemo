#ifndef _OSGQtWindow_H
#define _OSGQtWindow_H

#include <QtWidgets/QWidget>
#include <QtCore/Qtimer>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QVBoxLayout>
#include "ui_OSGQt.h"
#include "OSGLayer/ControlShow.h"
#include "QtWin/ParamWidget.h"
#include "OSGLayer/ControlRectangle.h"

class jyOSGQtWindow :public QMainWindow
{
  Q_OBJECT
public:
  jyOSGQtWindow(QWidget *parent = Q_NULLPTR);

protected:
  virtual void paintEvent(QPaintEvent *event);

private:
  //设定定时器 每过一定时间刷新一次 显示控制效果
  QTimer *m_pFlushTime=NULL;
  Ui::OSGQt ui;
  //显示控制类的指针
  jyControlRectangle *m_pControl=NULL;
  //translate窗口控制旋转平移缩放
  jyParamWidget *m_pTranslateWidget=NULL;

public slots:
  //显示窗口
  void slotShowTranslateWidget();
  //改变底层数据的三个函数，还有一个复位函数将数据清零
  void slotChangeStretching(float _x, float _y, float _z);
  void slotChangeTranslate(float _x, float _y, float _z);
  void slotChangeRotate(float _angle, float _x, float _y, float _z);
  void slotChangeParamReset();
 
};
#endif // !_OSGQtWindow_H
