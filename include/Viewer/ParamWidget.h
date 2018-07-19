#ifndef _PARAMWIDGET_H
#define _PARAMWIDGET_H


#include<QtWidgets/QWidget>
#include<QtWidgets/QLineEdit>
#include<QtWidgets/QLabel>
#include<QtWidgets/QPushButton>
#include"ui_ParamWidget.h"
#include "Control/ControlGroup.h"


class jyParamWidget :public QWidget
{

  Q_OBJECT

public:
  jyParamWidget(jyControlGroup* controller, QObject *parent = Q_NULLPTR);
  ~jyParamWidget();
  void setControl(jyControlGroup* controller);
  jyControlGroup *getControl();
public slots:
  void slotChangeStretching();
  void slotChangeRotate();
  void slotChangeTranslate();
  void slotReset();

private:
//  jyControlShow *m_pCon=NULL;
  Ui::ParamWidget ui;
  jyControlGroup *m_pControl=NULL;

};


#endif // !_PARAMWIDGET_H
