#include "..\..\include\QtWin\ParamWidget.h"

void jyParamWidget::slotEmitParamRsig()
{
  emit paramRotatePass(ui.lineEdit_angle->text().toFloat(), ui.lineEdit_rx->text().toFloat(), ui.lineEdit_ry->text().toFloat(), ui.lineEdit_rz->text().toFloat());
}
//发送信号用于传递参数在OSGQtWindow接收
void jyParamWidget::slotEmitParamTsig()
{
  emit paramTranslate(ui.lineEdit_tx->text().toFloat(), ui.lineEdit_ty->text().toFloat(), ui.lineEdit_tz->text().toFloat());
}

void jyParamWidget::slotEmitResetSig()
{
  emit paramReset();
}

void jyParamWidget::slotEmitParamSsig()
{
  emit paramStretchingPass(ui.lineEdit_sx->text().toFloat(), ui.lineEdit_sy->text().toFloat(), ui.lineEdit_sz->text().toFloat());
}

jyParamWidget::jyParamWidget(QObject *parent)
{
  ui.setupUi(this);
  connect(ui.QPushButton_Translate, &QPushButton::clicked, this, &jyParamWidget::slotEmitParamTsig);
  connect(ui.pushButton_Stretchin, &QPushButton::clicked, this, &jyParamWidget::slotEmitParamSsig);
  connect(ui.pushButton_Rotate, &QPushButton::clicked, this, &jyParamWidget::slotEmitParamRsig);
  connect(ui.pushButton_reset, &QPushButton::clicked, this, &jyParamWidget::slotEmitResetSig);
}
