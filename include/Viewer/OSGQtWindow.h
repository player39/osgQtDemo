#ifndef _OSGQtWindow_H
#define _OSGQtWindow_H

#include <QtWidgets/QWidget>
#include <QtCore/Qtimer>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QVBoxLayout>
#include "ui_OSGQt.h"
#include "Viewer/ViewerGroup.h"
#include "Viewer/ParamWidget.h"
#include "Control/ControlGroup.h"
//#include "OSGLayer/ControlRectangle.h"

class jyOSGQtWindow :public QMainWindow
{
  Q_OBJECT
public:
  jyOSGQtWindow(QWidget *parent = Q_NULLPTR);
  ~jyOSGQtWindow();
  //
  void setViewer(jyViewerGroup *viewerWidget);
  jyViewerGroup* getViewer();
  //
  void setControl(jyControlGroup * controller);
  jyControlGroup* getControl();
  void initWidget();

protected:
  virtual void paintEvent(QPaintEvent *event);
  virtual void closeEvent(QCloseEvent *event);
private:
  //�趨��ʱ�� ÿ��һ��ʱ��ˢ��һ�� ��ʾ����Ч��
  QTimer *m_pFlushTime=NULL;
  Ui::OSGQt ui;
  //��ʾ�������ָ��
//  jyControlRectangle *m_pControl=NULL;
  jyViewerGroup *m_pViewer = NULL;
  //translate���ڿ�����תƽ������
  jyParamWidget *m_pTranslateWidget=NULL;
  
  jyControlGroup *m_pController = NULL;

public slots:
  //��ʾ����
  void slotShowTranslateWidget();
  //�ı�ײ����ݵ���������������һ����λ��������������
 
};
#endif // !_OSGQtWindow_H
