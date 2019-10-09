#include "Button.h"
#include "Pixels.h"

#ifdef __AVR__
  #include <avr/power.h>
#endif

#define LED_PIN            0
#define NUMPIXELS      100
#define BRIGHTNESS_MIN 0
#define BRIGHTNESS_QUARTER 64
#define BRIGHTNESS_HALF 128
#define BRIGHTNESS_MAX 255

#define BUTTON_PIN 2

// 0: loop
// 1: rainbow
// 2: blue
// 3: bead
// 4: blue and purple pattern
// 5: fire pattern
// 6: rainbow tetris pattern
int buttonCounter = 0;
Button button(BUTTON_PIN);
Pixels pixels(LED_PIN, NUMPIXELS, BRIGHTNESS_QUARTER);

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  
  pixels.setup();
}

// use -1 for no limit
unsigned long maxHoopingSeconds = -1;
// unsigned long maxHoopingSeconds = 20 * 60;

void loop() {
  if (button.wasClicked()) {
    buttonCounter++;
  }

  unsigned long currentHoopingSeconds = millis() / 1000;
  if (maxHoopingSeconds != -1 && currentHoopingSeconds >= maxHoopingSeconds) {
    drawMaxHoopingPattern();
  } else {
    draw();
  }
}

void drawMaxHoopingPattern() {
  uint32_t black = pixels.createColor(0, 0, 0);
  uint32_t red = pixels.createColor(255, 0, 0);
  pixels.one(20, red);
  delay(1000);
  pixels.one(20, black);
  delay(1000);
}

unsigned long loopLastChangeMs = 0;
const unsigned long loopIntervalMs = 5000;
int loopCounter = 0;

int nonImagePatterns = 3;
int imagePatterns = 3;
int buttonStates = nonImagePatterns + imagePatterns;

void draw() {
  unsigned long loopCurrentMs = millis();
  bool isLoopPattern = buttonCounter % 7 == 0;

  if (isLoopPattern) {
    bool intervalHasPassed = loopCurrentMs - loopLastChangeMs >= loopIntervalMs;
    if (intervalHasPassed) {
      loopCounter++;
      loopLastChangeMs = loopCurrentMs;
    }
    
    drawForButtonCounter(loopCounter);
  } else {
    drawForButtonCounter(buttonCounter - 1);
  }
}

void drawForButtonCounter(int counter) {
  uint32_t blue = pixels.createColor(0, 0, 255);
  int patternNumber = counter % buttonStates;
  switch (counter % buttonStates) {
    case 0:
      pixels.rainbow(20);
      break;
    case 1:
      pixels.all(blue);
      break;
    case 2:
      pixels.bead();
      break;
    default:
      pixels.pattern(patternNumber - nonImagePatterns);
      break;
  }
}
