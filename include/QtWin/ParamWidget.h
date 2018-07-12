#ifndef _PARAMWIDGET_H
#define _PARAMWIDGET_H

#include<QtWidgets/QWidget>
#include<QtWidgets/QLineEdit>
#include<QtWidgets/QLabel>
#include<QtWidgets/QPushButton>
#include"ui_ParamWidget.h"
#include"OSGLayer/ControlShow.h"
class jyParamWidget :public QWidget
{
  Q_OBJECT
public:
  jyParamWidget(QObject *parent = Q_NULLPTR);

public slots:
  void emitparamSsig();
  void emitparamRsig();
  void emitparamTsig();

private:
  jyControlShow *m_pCon=NULL;
  Ui::ParamWidget ui;
signals:
  void paramStretchingPass(float _x, float _y, float _z);
  void paramRotatePass();
  void paramTranslate(float _x, float _y, float _z);

};


#endif // !_PARAMWIDGET_H
