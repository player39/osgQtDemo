#include "..\..\include\QtWin\ParamWidget.h"

void jyParamWidget::emitparamRsig()
{
  
}

void jyParamWidget::emitparamTsig()
{
  emit paramTranslate(ui.lineEdit_tx->text().toFloat(), ui.lineEdit_ty->text().toFloat(), ui.lineEdit_tz->text().toFloat());
}

jyParamWidget::jyParamWidget(QObject *parent)
{
  connect(ui.QPushButton_Translate, &QPushButton::clicked, this, &jyParamWidget::emitparamTsig);
  connect(ui.pushButton_Stretchin, &QPushButton::clicked, this, &jyParamWidget::emitparamSsig);
  connect(ui.pushButton_Rotate, &QPushButton::clicked, this, &jyParamWidget::emitparamRsig);
}
