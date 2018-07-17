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
  //����4���ź�������������һ��reset���������н��� �Դ˸��ĵײ�����
  void slotEmitParamSsig();
  void slotEmitParamRsig();
  void slotEmitParamTsig();
  void slotEmitResetSig();

private:
  jyControlShow *m_pCon=NULL;
  Ui::ParamWidget ui;

signals:
  //4���ź� ָʾ��������
  void paramStretchingPass(float _x, float _y, float _z);
  void paramRotatePass(float _angle, float _x, float _y, float _z);
  void paramTranslate(float _x, float _y, float _z);
  void paramReset();

};


#endif // !_PARAMWIDGET_H
