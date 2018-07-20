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
  //����ͼ�Ϳ�����
  void setViewer(jyViewerGroup *viewerWidget);
  void setControl(jyControlGroup * controller);
  void setViewerRec(jyViewerRectangleGroup *viewerWidget);
  void setControlRec(jyControlRecGroup *controller);
  jyViewerGroup* getViewer();
  jyControlGroup* getControl();
  jyViewerRectangleGroup *getViewerRec();
  jyControlRecGroup* getControlRec();
  //��ʼ��
  void initWidget();
protected:
  virtual void paintEvent(QPaintEvent *event);
  virtual void closeEvent(QCloseEvent *event);
private:
  //�趨��ʱ�� ÿ��һ��ʱ��ˢ��һ�� ��ʾ����Ч��
  QTimer *m_pFlushTime=NULL;
  Ui::OSGQt ui;
  //��������ͼ
  jyViewerGroup *m_pViewer = NULL;
  jyViewerRectangleGroup *m_pViewerRec = NULL;
  //һ������
  jyParamWidget *m_pTranslateWidget=NULL;
  //�������������ã����޸�����
  jyControlGroup *m_pController = NULL;
  jyControlRecGroup *m_pControllerRec = NULL;

public slots:
  //��ʾ����
  void slotShowTranslateWidget(); 
};
#endif // !_OSGQtWindow_H
