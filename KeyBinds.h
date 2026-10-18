#ifndef KeyBinds_h
#define KeyBinds_h

#include "MacroPad.h"
#include "Functions.h"
#include "Icons.h"
#include "Colors.h"

const KeyBind dummyKeyBind = {
  .keyFn = dummyFn,
  .icon = emptyIcon,
  .color = COLOR_BLACK
};

const KeyBind enterKeyBind {
  .keyFn = enterFn,
  .icon = enterIcon,
  .color = COLOR_GRAY
};

#endif