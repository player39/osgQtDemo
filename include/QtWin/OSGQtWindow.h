#ifndef _OSGQtWindow_H
#define _OSGQtWindow_H

#include <QtWidgets/QWidget>
#include <QtCore/Qtimer>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QVBoxLayout>
#include "ui_OSGQt.h"
#include "OSGLayer/ControlShow.h"
class jyOSGQtWindow :public QMainWindow
{
  Q_OBJECT
public:
  jyOSGQtWindow(QWidget *parent = Q_NULLPTR);


protected:
  virtual void paintEvent(QPaintEvent *event);

private:
  QTimer *m_pFlushTime;
  Ui::OSGQt ui;
  jyControlShow *m_pControl;

public slots:
  void changeModel();

signals:
  

 
};
#endif // !_OSGQtWindow_H
