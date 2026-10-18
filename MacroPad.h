#ifndef MacroPad_h
#define MacroPad_h

#include <Arduino.h>


// Constants
const size_t NUM_KEYS = 12;
const uint8_t KEY_PINS[NUM_KEYS] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
const unsigned long DEBOUNCE_MILLIS = 10;
const int16_t ICON_WIDTH = 11;
const int16_t ICON_HEIGHT = 11;



// MacroPad Types

enum KeyEvent {
  KEY_IDLE,
  KEY_HELD,
  KEY_PRESSED,
  KEY_RELEASED
};

typedef void (*KeyFn)(KeyEvent event);

struct KeyBind {
  KeyFn keyFn;
  const uint8_t *icon;
  const uint32_t color;
};

struct Page {
  const char *summary;
  const KeyBind keyBindList[NUM_KEYS];
};



// MacroPad Functions
void setupMacroPad(Page pageList[], size_t numPages);
void runMacroPad();


#endif