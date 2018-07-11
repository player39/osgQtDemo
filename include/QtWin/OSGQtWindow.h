#ifndef _OSGQtWindow_H
#define _OSGQtWindow_H

#include <QtWidgets/QWidget>
#include <QtCore/Qtimer>
#include <QtWidgets/QMainWindow>
#include "ui_OSGQt.h"
class jyOSGQtWindow :public QMainWindow
{
  Q_OBJECT
public:
  jyOSGQtWindow(QWidget *parent = Q_NULLPTR);
protected:
  virtual void paintEvent(QPaintEvent *event);
private:
  QTimer *m_pFlush_Time;
  Ui::OSGQt ui;
 
};
#endif // !_OSGQtWindow_H
