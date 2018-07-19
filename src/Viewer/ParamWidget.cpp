#include "..\..\include\Viewer\ParamWidget.h"

jyParamWidget::~jyParamWidget()
{
}

void jyParamWidget::setControl(jyControlGroup * controller)
{
  m_pControl = controller;
}

jyControlGroup * jyParamWidget::getControl()
{
  return m_pControl;
}

void jyParamWidget::slotChangeRotate()
{
  m_pControl->setLineRotate(ui.lineEdit_angle->text().toFloat(), ui.lineEdit_rx->text().toFloat(), ui.lineEdit_ry->text().toFloat(), ui.lineEdit_rz->text().toFloat());
}

void jyParamWidget::slotChangeTranslate()
{
  m_pControl->setLineTranslate(ui.lineEdit_tx->text().toFloat(), ui.lineEdit_ty->text().toFloat(), ui.lineEdit_tz->text().toFloat());
}

void jyParamWidget::slotChangeStretching()
{
  m_pControl->setLineStretching(ui.lineEdit_sx->text().toFloat(), ui.lineEdit_sy->text().toFloat(), ui.lineEdit_sz->text().toFloat());
}

void jyParamWidget::slotReset()
{
//  m_pControl->DataReset();
}


jyParamWidget::jyParamWidget(jyControlGroup *controller, QObject *parent)
{
  ui.setupUi(this);
  setControl(controller);
  connect(ui.QPushButton_Translate, &QPushButton::clicked, this, &jyParamWidget::slotChangeTranslate);
  connect(ui.pushButton_Stretchin, &QPushButton::clicked, this, &jyParamWidget::slotChangeStretching);
  connect(ui.pushButton_Rotate, &QPushButton::clicked, this, &jyParamWidget::slotChangeRotate);
  connect(ui.pushButton_reset, &QPushButton::clicked, this, &jyParamWidget::slotReset);
}
