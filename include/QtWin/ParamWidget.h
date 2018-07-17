#ifndef _PARAMWIDGET_H
#define _PARAMWIDGET_H
//#define _SCL_SECURE_NO_WARNINGS

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
  ~jyParamWidget();
public slots:
  //发送4个信号三个更改数据一个reset在主窗口中接收 以此更改底层数据
  void slotEmitParamSsig();
  void slotEmitParamRsig();
  void slotEmitParamTsig();
  void slotEmitResetSig();

private:
  jyControlShow *m_pCon=NULL;
  Ui::ParamWidget ui;

signals:
  //4个信号 指示更改数据
  void paramStretchingPass(float _x, float _y, float _z);
  void paramRotatePass(float _angle, float _x, float _y, float _z);
  void paramTranslate(float _x, float _y, float _z);
  void paramReset();

};


#endif // !_PARAMWIDGET_H
