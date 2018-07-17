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
  //�趨��ʱ�� ÿ��һ��ʱ��ˢ��һ�� ��ʾ����Ч��
  QTimer *m_pFlushTime=NULL;
  Ui::OSGQt ui;
  //��ʾ�������ָ��
  jyControlRectangle *m_pControl=NULL;
  //translate���ڿ�����תƽ������
  jyParamWidget *m_pTranslateWidget=NULL;

public slots:
  //��ʾ����
  void slotShowTranslateWidget();
  //�ı�ײ����ݵ���������������һ����λ��������������
  void slotChangeStretching(float _x, float _y, float _z);
  void slotChangeTranslate(float _x, float _y, float _z);
  void slotChangeRotate(float _angle, float _x, float _y, float _z);
  void slotChangeParamReset();
 
};
#endif // !_OSGQtWindow_H
