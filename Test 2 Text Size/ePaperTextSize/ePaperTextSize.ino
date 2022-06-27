#include <Adafruit_GFX.h>
#include <GxEPD.h>
#include <GxGDEW0213Z16/GxGDEW0213Z16.h>
#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>

#define TEXT_COLOUR GxEPD_BLACK
#define BACKGROUND_COLOUR	GxEPD_WHITE

GxIO_Class io(SPI, SS, 8, 9);
GxEPD_Class display(io, 9, 7);

void nextTextSize();

#define BUTTON_PIN 3
bool pressed = false;
uint8_t currentTextSize = 1;

void setup() {
  // put your setup code here, to run once:
  pinMode(BUTTON_PIN, INPUT);

  display.init();
  display.setRotation(3);
  display.eraseDisplay();
}

void loop() {
  // put your main code here, to run repeatedly:
  pressed = digitalRead(BUTTON_PIN);

  if (pressed && currentTextSize <= 5) {
    display.drawPaged(nextTextSize);
    currentTextSize ++;
    pressed = false;
  }
}

void nextTextSize() {
  String text = "Hello world! " + String(currentTextSize); 

  display.setCursor(10, 10);
  display.setTextSize(currentTextSize);
  display.setTextColor(TEXT_COLOUR, BACKGROUND_COLOUR);
  display.fillScreen(BACKGROUND_COLOUR);

  display.println(text);
}