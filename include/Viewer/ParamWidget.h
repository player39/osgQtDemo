#ifndef _PARAMWIDGET_H
#define _PARAMWIDGET_H

#include<QtWidgets/QWidget>
#include<QtWidgets/QLineEdit>
#include<QtWidgets/QLabel>
#include<QtWidgets/QPushButton>
#include"ui_ParamWidget.h"
#include "Control/ControlGroup.h"
#include "Control/ControlRecGroup.h"

class jyParamWidget :public osg::Group, public xxxView
{

  Q_OBJECT

public:
  jyParamWidget(jyControlGroup* controller, QObject *parent = Q_NULLPTR);
  ~jyParamWidget();
  void setControl(jyControlGroup* controller);
  void setRecControl(jyControlRecGroup* controller);
  jyControlGroup *getControl();
  jyControlRecGroup *getRecControl();

public slots:
  //�߶�
  void slotChangeStretching();
  void slotChangeRotate();
  void slotChangeTranslate();
  void slotReset();
  //���ڵ�
  void slotChangeDataStretching();
  void slotChangeDataRotate();
  void slotChangeDataTranslate();
  void slotDateReset();
  //��һ��ͼ
  void slotChangeRootRotate();

private:
  Ui::ParamWidget ui;
  jyControlGroup *m_pControl=NULL;
  jyControlRecGroup *m_pControlRec = NULL;
};


#endif // !_PARAMWIDGET_H
