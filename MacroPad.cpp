#include <Arduino.h>
#include <Adafruit_SH110X.h>
#include <Adafruit_NeoPixel.h>
#include <RotaryEncoder.h>
#include <Keyboard.h>
#include "MacroPad.h"
#include "Colors.h"



// Static Variables
static Page *_pageList = NULL;
static size_t _numPages = 0;

// Object Creation
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_NEOPIXEL, PIN_NEOPIXEL, NEO_GRB + NEO_KHZ800);
Adafruit_SH1106G display = Adafruit_SH1106G(128, 64, &SPI1, OLED_DC, OLED_RST, OLED_CS);
RotaryEncoder encoder(PIN_ROTB, PIN_ROTA, RotaryEncoder::LatchMode::FOUR3);



// Local Functions

static void drawIcon(uint8_t index, const uint8_t icon[], bool invert = false) {
  int16_t x = (index % 3) * 16 + 80;
  int16_t y = (index / 3) * 16;
  if (invert == false) {
    display.drawRect(x, y, 15, 15, SH110X_WHITE);
    display.drawBitmap(x + 2, y + 2, icon, ICON_WIDTH, ICON_HEIGHT, SH110X_WHITE, SH110X_BLACK);
  }
  else {
    display.fillRect(x, y, 15, 15, SH110X_WHITE);
    display.drawBitmap(x + 2, y + 2, icon, ICON_WIDTH, ICON_HEIGHT, SH110X_BLACK, SH110X_WHITE);
  }
}

static void encoderCb() {
  encoder.tick();
}



// Setup Function

void setupMacroPad(Page pageList[], size_t numPages) {

  if (pageList == NULL || numPages == 0) return;
  _pageList = pageList;
  _numPages = numPages;

  // start rgb leds, oled display, and keyboard
  pixels.begin();
  display.begin(0, true);
  Keyboard.begin();

  // configure the display
  display.setTextSize(1);
  display.setTextWrap(false);

  // bind the encodet callback to interrupts
  attachInterrupt(digitalPinToInterrupt(PIN_ROTA), encoderCb, CHANGE);
  attachInterrupt(digitalPinToInterrupt(PIN_ROTB), encoderCb, CHANGE);

  // set the rgb led brightness and initial values
  pixels.setBrightness(32);
  for (uint8_t i = 0; i < NUM_KEYS; i++) {
    pinMode(KEY_PINS[i], INPUT_PULLUP);
    pixels.setPixelColor(i, _pageList[0].keyBindList[i].color);
  }
  
  // update the rgb leds and display
  pixels.show();
  display.display();

}



// Run Function

void runMacroPad() {

  // check that _pageList and _numPages were initialized properly
  if (_pageList == NULL || _numPages == 0) return;

  // static variables
  static KeyBind savedKeyBindList[NUM_KEYS] = {NULL, NULL, 0x000000};
  static bool oldKeyStates[NUM_KEYS];
  static unsigned long keyDebounceMillisStart[NUM_KEYS];
  static long oldEncoderPosition;
  static long pageIndex;

  // reset the display and get the time for the current loop
  display.clearDisplay();
  unsigned long millisNow = millis();

  // get current page
  long newEncoderPosition = encoder.getPosition();
  pageIndex += newEncoderPosition - oldEncoderPosition;
  if (pageIndex < 0) pageIndex = 0;
  else if ((size_t)pageIndex >= _numPages) pageIndex = _numPages - 1;
  oldEncoderPosition = newEncoderPosition;

  // print header
  display.setCursor(0,0);
  display.setTextColor(SH110X_WHITE, SH110X_BLACK);
  display.printf("Page: %ld\n\n", pageIndex);
  display.println(_pageList[pageIndex].summary);

  // for each key
  for (uint8_t keyIndex = 0; keyIndex < NUM_KEYS; keyIndex++) {

    // determine key event
    KeyEvent event = KEY_IDLE;
    if (oldKeyStates[keyIndex]) event = KEY_HELD;
    bool newKeyState = !digitalRead(KEY_PINS[keyIndex]);
    if (newKeyState == oldKeyStates[keyIndex]) keyDebounceMillisStart[keyIndex] = millisNow;
    else if (millisNow - keyDebounceMillisStart[keyIndex] >= DEBOUNCE_MILLIS) {
      if (newKeyState > oldKeyStates[keyIndex]) event = KEY_PRESSED;
      if (newKeyState < oldKeyStates[keyIndex]) event = KEY_RELEASED;
      oldKeyStates[keyIndex] = newKeyState;
    }

    // if the key was just pressed, save the keybind
    if (event == KEY_PRESSED) {
      memcpy((void*)&savedKeyBindList[keyIndex], (void*)&_pageList[pageIndex].keyBindList[keyIndex], sizeof(KeyBind));
    }

    // set the rgb value and draw the icon
    switch (event) {
      case KEY_PRESSED:
      case KEY_HELD:
        pixels.setPixelColor(keyIndex, COLOR_WHITE);
        drawIcon(keyIndex, savedKeyBindList[keyIndex].icon, true);
        break;
      case KEY_RELEASED:
      case KEY_IDLE:
        pixels.setPixelColor(keyIndex, _pageList[pageIndex].keyBindList[keyIndex].color);
        drawIcon(keyIndex, _pageList[pageIndex].keyBindList[keyIndex].icon);
        break;
    }

    // run the key function from the keybind
    switch (event) {
      case KEY_PRESSED:
      case KEY_HELD:
      case KEY_RELEASED:
        savedKeyBindList[keyIndex].keyFn(event);
        break;
      case KEY_IDLE:
        _pageList[pageIndex].keyBindList[keyIndex].keyFn(event);
        break;
    }

  }

  // update the rgb leds and display
  pixels.show();
  display.display();

}