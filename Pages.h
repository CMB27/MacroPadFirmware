#ifndef Pages_h
#define Pages_h

#include "MacroPad.h"
#include "Functions.h"
#include "Icons.h"
#include "Colors.h"
#include "KeyBinds.h"

const Page testPage = {
  .summary = "Test",
  .keyBindList = {
    dummyKeyBind,
    dummyKeyBind,
    dummyKeyBind,
    dummyKeyBind,
    dummyKeyBind,
    dummyKeyBind,
    dummyKeyBind,
    dummyKeyBind,
    dummyKeyBind,
    dummyKeyBind,
    dummyKeyBind,
    dummyKeyBind
  }
};

const Page boxCharsLinuxPage = {
  .summary = "Linux Box\nCharacters",
  .keyBindList = {
    {boxCharDownRightLinuxFn, boxCharDownRightIcon, COLOR_RED},
    {boxCharDownHorizLinuxFn, boxCharDownHorizIcon, COLOR_RED},
    {boxCharDownLeftLinuxFn, boxCharDownLeftIcon, COLOR_RED},
    {boxCharVertRightLinuxFn, boxCharVertRightIcon, COLOR_RED},
    {boxCharVertHorizLinuxFn, boxCharVertHorizIcon, COLOR_RED},
    {boxCharVertLeftLinuxFn, boxCharVertLeftIcon, COLOR_RED},
    {boxCharUpRightLinuxFn, boxCharUpRightIcon, COLOR_RED},
    {boxCharUpHorizLinuxFn, boxCharUpHorizIcon, COLOR_RED},
    {boxCharUpLeftLinuxFn, boxCharUpLeftIcon, COLOR_RED},
    {boxCharHorizLinuxFn, boxCharHorizIcon, COLOR_RED},
    {boxCharVertLinuxFn, boxCharVertIcon, COLOR_RED},
    enterKeyBind
  }
};

const Page boxCharsWindowsPage = {
  .summary = "Windows Box\nCharacters",
  .keyBindList = {
    {boxCharDownRightWindowsFn, boxCharDownRightIcon, COLOR_BLUE},
    {boxCharDownHorizWindowsFn, boxCharDownHorizIcon, COLOR_BLUE},
    {boxCharDownLeftWindowsFn, boxCharDownLeftIcon, COLOR_BLUE},
    {boxCharVertRightWindowsFn, boxCharVertRightIcon, COLOR_BLUE},
    {boxCharVertHorizWindowsFn, boxCharVertHorizIcon, COLOR_BLUE},
    {boxCharVertLeftWindowsFn, boxCharVertLeftIcon, COLOR_BLUE},
    {boxCharUpRightWindowsFn, boxCharUpRightIcon, COLOR_BLUE},
    {boxCharUpHorizWindowsFn, boxCharUpHorizIcon, COLOR_BLUE},
    {boxCharUpLeftWindowsFn, boxCharUpLeftIcon, COLOR_BLUE},
    {boxCharHorizWindowsFn, boxCharHorizIcon, COLOR_BLUE},
    {boxCharVertWindowsFn, boxCharVertIcon, COLOR_BLUE},
    enterKeyBind
  }
};

const Page dialPadPage = {
  .summary = "Dial Pad",
  .keyBindList = {
    {oneFn, oneIcon, COLOR_ORANGE},
    {twoFn, twoIcon, COLOR_ORANGE},
    {threeFn, threeIcon, COLOR_ORANGE},
    {fourFn, fourIcon, COLOR_ORANGE},
    {fiveFn, fiveIcon, COLOR_ORANGE},
    {sixFn, sixIcon, COLOR_ORANGE},
    {sevenFn, sevenIcon, COLOR_ORANGE},
    {eightFn, eightIcon, COLOR_ORANGE},
    {nineFn, nineIcon, COLOR_ORANGE},
    {starFn, starIcon, COLOR_AMBER},
    {zeroFn, zeroIcon, COLOR_ORANGE},
    {poundFn, poundIcon, COLOR_AMBER}
  }
};

const Page numPadPage = {
  .summary = "Num Pad",
  .keyBindList = {
    {sevenFn, sevenIcon, COLOR_TEAL},
    {eightFn, eightIcon, COLOR_TEAL},
    {nineFn, nineIcon, COLOR_TEAL},
    {fourFn, fourIcon, COLOR_TEAL},
    {fiveFn, fiveIcon, COLOR_TEAL},
    {sixFn, sixIcon, COLOR_TEAL},
    {oneFn, oneIcon, COLOR_TEAL},
    {twoFn, twoIcon, COLOR_TEAL},
    {threeFn, threeIcon, COLOR_TEAL},
    dummyKeyBind,
    {zeroFn, zeroIcon, COLOR_TEAL},
    {periodFn, periodIcon, COLOR_MAGENTA}
  }
};

const Page pwrCtrlPage = {
  .summary = "Power\nControl",
  .keyBindList = {
    {powerFn, powerIcon, COLOR_GREEN},
    {resetFn, resetIcon, COLOR_ORANGE},
    {sleepFn, sleepIcon, COLOR_PURPLE},
    dummyKeyBind,
    dummyKeyBind,
    dummyKeyBind,
    dummyKeyBind,
    dummyKeyBind,
    dummyKeyBind,
    dummyKeyBind,
    dummyKeyBind,
    {pwrCtrlEnFn, enIcon, COLOR_RED}
  }
};

const Page colorTestPage = {
  .summary = "Color Test",
  .keyBindList = {
    {dummyFn, emptyIcon, COLOR_RED},
    {dummyFn, emptyIcon, COLOR_ORANGE},
    {dummyFn, emptyIcon, COLOR_YELLOW},
    {dummyFn, emptyIcon, COLOR_GREEN},
    {dummyFn, emptyIcon, COLOR_TEAL},
    {dummyFn, emptyIcon, COLOR_CYAN},
    {dummyFn, emptyIcon, COLOR_BLUE},
    {dummyFn, emptyIcon, COLOR_PURPLE},
    {dummyFn, emptyIcon, COLOR_MAGENTA},
    {dummyFn, emptyIcon, COLOR_BLACK},
    {dummyFn, emptyIcon, COLOR_GRAY},
    {dummyFn, emptyIcon, COLOR_WHITE}
  }
};

#endif


