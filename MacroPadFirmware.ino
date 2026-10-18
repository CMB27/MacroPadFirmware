
#include "MacroPad.h"
#include "Pages.h"


const size_t NUM_PAGES = 6;
Page pageList[NUM_PAGES] = {
  boxCharsLinuxPage,
  boxCharsWindowsPage,
  dialPadPage,
  numPadPage,
  pwrCtrlPage,
  colorTestPage
};

void setup() {
  setupMacroPad(pageList, NUM_PAGES);
}

void loop() {
  runMacroPad();
}


