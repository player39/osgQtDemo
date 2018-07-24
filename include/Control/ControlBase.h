#ifndef _CONTROLBASE_H
#define _CONTROLBASE_H

#include <boost/signals2.hpp>
#include <boost/bind.hpp>
#include "Model/Pixel.h"
#include "Viewer/ViewBase.h"

typedef boost::signals2::signal<void()>::slot_type slotType;
typedef boost::signals2::signal<void()> boostSig;

class jyControllerBase
{
public:
  jyControllerBase();
  friend class jyViewerBase;
  boost::signals2::connection connectStretching(slotType &type);
  boost::signals2::connection connectRotate(slotType &type);
  boost::signals2::connection connectTranslate(slotType &type);
  boost::signals2::connection connectReset(slotType &type);

  stretching getStretching();
  translate getTranslate();
  rotateAngle getRotate();

  void setStretching(float _X, float _Y, float _Z);
  void setTranslate(float _X, float _Y, float _Z);
  void setRotate(float _Angle, float _X, float _Y, float _Z);
  void Reset();

private:
  boostSig sig_Stretching;
  boostSig sig_Rotate;
  boostSig sig_Translate;
  boostSig sig_Reset;
  //
  stretching m_sStretching;
  translate m_tTranslate;
  rotateAngle m_rRotate;

};

#endif // !_CONTROLBASE_H
