#include "QtWin/OSGQtWindow.h"

int main(int argc, char** argv)
{
  QApplication app(argc, argv);
  jyOSGQtWindow osgwin = new jyOSGQtWindow();
  osgwin.show();
  return app.exec();
}

