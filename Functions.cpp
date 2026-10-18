#include <Arduino.h>
#include <Keyboard.h>
#include "MacroPad.h"
#include "Functions.h"


// Static Variables
static bool pwrCtrlEn = false;



// Local Functions

static void typeUnicodeLinux(uint32_t grapheme) {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press('u');
  Keyboard.releaseAll();
  Keyboard.printf("%x", grapheme);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
}

static void typeUnicodeWindows(uint32_t grapheme) {
  Keyboard.printf("%x", grapheme);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('x');
  Keyboard.releaseAll();
}



// Linux Box Drawing Functions

void boxCharDownRightLinuxFn(KeyEvent event) {
  switch (event) {
    case KEY_PRESSED: typeUnicodeLinux(0x250C); break;
    default: break;
  }
}

void boxCharDownHorizLinuxFn(KeyEvent event) {
  switch (event) {
    case KEY_PRESSED: typeUnicodeLinux(0x252C); break;
    default: break;
  }
}

void boxCharDownLeftLinuxFn(KeyEvent event) {
  switch (event) {
    case KEY_PRESSED: typeUnicodeLinux(0x2510); break;
    default: break;
  }
}

void boxCharVertRightLinuxFn(KeyEvent event) {
  switch (event) {
    case KEY_PRESSED: typeUnicodeLinux(0x251C); break;
    default: break;
  }
}

void boxCharVertHorizLinuxFn(KeyEvent event) {
  switch (event) {
    case KEY_PRESSED: typeUnicodeLinux(0x253C); break;
    default: break;
  }
}

void boxCharVertLeftLinuxFn(KeyEvent event) {
  switch (event) {
    case KEY_PRESSED: typeUnicodeLinux(0x2524); break;
    default: break;
  }
}

void boxCharUpRightLinuxFn(KeyEvent event) {
  switch (event) {
    case KEY_PRESSED: typeUnicodeLinux(0x2514); break;
    default: break;
  }
}

void boxCharUpHorizLinuxFn(KeyEvent event) {
  switch (event) {
    case KEY_PRESSED: typeUnicodeLinux(0x2534); break;
    default: break;
  }
}

void boxCharUpLeftLinuxFn(KeyEvent event) {
  switch (event) {
    case KEY_PRESSED: typeUnicodeLinux(0x2518); break;
    default: break;
  }
}

void boxCharHorizLinuxFn(KeyEvent event) {
  switch (event) {
    case KEY_PRESSED: typeUnicodeLinux(0x2500); break;
    default: break;
  }
}

void boxCharVertLinuxFn(KeyEvent event) {
  switch (event) {
    case KEY_PRESSED: typeUnicodeLinux(0x2502); break;
    default: break;
  }
}



// Windows Box Drawing Functions

void boxCharDownRightWindowsFn(KeyEvent event) {
  switch (event) {
    case KEY_PRESSED: typeUnicodeWindows(0x250C); break;
    default: break;
  }
}

void boxCharDownHorizWindowsFn(KeyEvent event) {
  switch (event) {
    case KEY_PRESSED: typeUnicodeWindows(0x252C); break;
    default: break;
  }
}

void boxCharDownLeftWindowsFn(KeyEvent event) {
  switch (event) {
    case KEY_PRESSED: typeUnicodeWindows(0x2510); break;
    default: break;
  }
}

void boxCharVertRightWindowsFn(KeyEvent event) {
  switch (event) {
    case KEY_PRESSED: typeUnicodeWindows(0x251C); break;
    default: break;
  }
}

void boxCharVertHorizWindowsFn(KeyEvent event) {
  switch (event) {
    case KEY_PRESSED: typeUnicodeWindows(0x253C); break;
    default: break;
  }
}

void boxCharVertLeftWindowsFn(KeyEvent event) {
  switch (event) {
    case KEY_PRESSED: typeUnicodeWindows(0x2524); break;
    default: break;
  }
}

void boxCharUpRightWindowsFn(KeyEvent event) {
  switch (event) {
    case KEY_PRESSED: typeUnicodeWindows(0x2514); break;
    default: break;
  }
}

void boxCharUpHorizWindowsFn(KeyEvent event) {
  switch (event) {
    case KEY_PRESSED: typeUnicodeWindows(0x2534); break;
    default: break;
  }
}

void boxCharUpLeftWindowsFn(KeyEvent event) {
  switch (event) {
    case KEY_PRESSED: typeUnicodeWindows(0x2518); break;
    default: break;
  }
}

void boxCharHorizWindowsFn(KeyEvent event) {
  switch (event) {
    case KEY_PRESSED: typeUnicodeWindows(0x2500); break;
    default: break;
  }
}

void boxCharVertWindowsFn(KeyEvent event) {
  switch (event) {
    case KEY_PRESSED: typeUnicodeWindows(0x2502); break;
    default: break;
  }
}



// Number Functions

void zeroFn(KeyEvent event) {
  switch (event) {
    case KEY_PRESSED: Keyboard.print('0'); break;
    default: break;
  }
}

void oneFn(KeyEvent event) {
  switch (event) {
    case KEY_PRESSED: Keyboard.print('1'); break;
    default: break;
  }
}

void twoFn(KeyEvent event) {
  switch (event) {
    case KEY_PRESSED: Keyboard.print('2'); break;
    default: break;
  }
}

void threeFn(KeyEvent event) {
  switch (event) {
    case KEY_PRESSED: Keyboard.print('3'); break;
    default: break;
  }
}

void fourFn(KeyEvent event) {
  switch (event) {
    case KEY_PRESSED: Keyboard.print('4'); break;
    default: break;
  }
}

void fiveFn(KeyEvent event) {
  switch (event) {
    case KEY_PRESSED: Keyboard.print('5'); break;
    default: break;
  }
}

void sixFn(KeyEvent event) {
  switch (event) {
    case KEY_PRESSED: Keyboard.print('6'); break;
    default: break;
  }
}

void sevenFn(KeyEvent event) {
  switch (event) {
    case KEY_PRESSED: Keyboard.print('7'); break;
    default: break;
  }
}

void eightFn(KeyEvent event) {
  switch (event) {
    case KEY_PRESSED: Keyboard.print('8'); break;
    default: break;
  }
}

void nineFn(KeyEvent event) {
  switch (event) {
    case KEY_PRESSED: Keyboard.print('9'); break;
    default: break;
  }
}



// Misc. Functions

void dummyFn(KeyEvent event) {
  // does nothing
}

void enterFn(KeyEvent event) {
  switch (event) {
    case KEY_PRESSED: Keyboard.press(KEY_RETURN); break;
    case KEY_RELEASED: Keyboard.release(KEY_RETURN); break;
    default: break;
  }
}

void starFn(KeyEvent event) {
  switch (event) {
    case KEY_PRESSED: Keyboard.print('*'); break;
    default: break;
  }
}

void poundFn(KeyEvent event) {
  switch (event) {
    case KEY_PRESSED: Keyboard.print('#'); break;
    default: break;
  }
}

void periodFn(KeyEvent event) {
  switch (event) {
    case KEY_PRESSED: Keyboard.print('.'); break;
    default: break;
  }
}

void powerFn(KeyEvent event) {
  switch (event) {
    case KEY_PRESSED: if (pwrCtrlEn) Keyboard.consumerPress(KEY_POWER); break;
    case KEY_RELEASED: Keyboard.consumerRelease(); break;
    default: break;
  }
}

void resetFn(KeyEvent event) {
  switch (event) {
    case KEY_PRESSED: if (pwrCtrlEn) Keyboard.consumerPress(KEY_RESET); break;
    case KEY_RELEASED: Keyboard.consumerRelease(); break;
    default: break;
  }
}

void sleepFn(KeyEvent event) {
  switch (event) {
    case KEY_PRESSED: if (pwrCtrlEn) Keyboard.consumerPress(KEY_SLEEP); break;
    case KEY_RELEASED: Keyboard.consumerRelease(); break;
    default: break;
  }
}

void pwrCtrlEnFn(KeyEvent event) {
  switch (event) {
    case KEY_PRESSED: pwrCtrlEn = true; break;
    case KEY_RELEASED: pwrCtrlEn = false; break;
    default: break;
  }
}


