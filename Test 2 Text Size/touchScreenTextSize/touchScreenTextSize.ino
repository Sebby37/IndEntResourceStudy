#include <Adafruit_GFX.h>
#include <MCUFRIEND_kbv.h>

#define TEXT_COLOUR 0x0000
#define BACKGROUND_COLOUR	0xffff

MCUFRIEND_kbv display;

// Touchscreen stuff
#include <TouchScreen.h>

const int XP=7,XM=A1,YP=A2,YM=6; //240x320 ID=0x9341
const int TS_LEFT=951,TS_RT=168,TS_TOP=193,TS_BOT=940;

#define MINPRESSURE 200
#define MAXPRESSURE 1000

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

void nextTextSize(String text, uint8_t size);

bool pressed = false;
uint8_t currentTextSize = 1;

bool Touch_getXY(void)
{
    TSPoint p = ts.getPoint();
    pinMode(YP, OUTPUT);      //restore shared pins
    pinMode(XM, OUTPUT);
    digitalWrite(YP, HIGH);   //because TFT control pins
    digitalWrite(XM, HIGH);
    bool isPressed = (p.z > MINPRESSURE && p.z < MAXPRESSURE);
    return isPressed;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  uint16_t displayId = display.readID();
  display.begin(displayId);
  display.setRotation(3);
}

void loop() {
  // put your main code here, to run repeatedly:
  pressed = Touch_getXY();

  if (pressed && currentTextSize <= 5) {
    nextTextSize("Hello World! " + String(currentTextSize), currentTextSize);
    currentTextSize++;
    pressed = false;
    digitalWrite(LED_BUILTIN, HIGH);
    delay(250);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }
}

void nextTextSize(String text, uint8_t size) {
  display.setCursor(10, 10);
  display.setTextSize(size);
  display.setTextColor(TEXT_COLOUR, BACKGROUND_COLOUR);
  display.fillScreen(BACKGROUND_COLOUR);

  display.println(text);
}
