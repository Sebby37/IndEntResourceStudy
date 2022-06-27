#include <Adafruit_GFX.h>
#include <GxEPD.h>
#include <GxGDEW0213Z16/GxGDEW0213Z16.h>
#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>

#define COLOUR GxEPD_BLACK

GxIO_Class io(SPI, SS, 8, 9);
GxEPD_Class display(io, 9, 7);

void textTest();
void shapeTest();
void printResults();

unsigned long beforeInitialiseTime;
unsigned long initialiseTime;

unsigned long beforeTextTime;
unsigned long textTime;

unsigned long beforeGraphicsTime;
unsigned long graphicsTime;

void setup() {
  // Serial port initialisation
  Serial.begin(9600);

  // Display initialisation
  beforeInitialiseTime = millis();
  display.init();
  display.eraseDisplay();
  display.setRotation(1);
  initialiseTime = millis() - beforeInitialiseTime;
  
  // Running the text test and recording the time taken
  beforeTextTime = millis();
  display.drawPaged(textTest);
  textTime = millis() - beforeTextTime;

  // Running the shape test and recording the time taken
  beforeGraphicsTime = millis();
  display.drawPaged(shapeTest);
  graphicsTime = millis() - beforeGraphicsTime;

  // Printing the results to the serial monitor
  printResults();
}

void textTest() {
  // Text drawing
  display.setTextColor(COLOUR);
  display.setCursor(0, 0);
  display.println("Hello world!");
  display.setCursor(50, 50);
  display.println("Hello world!");
  display.setCursor(100, 100);
  display.println("Hello world!");
}

void shapeTest() {
  // Graphics drawing
  display.drawLine(10, 10, 20, 20, COLOUR);
  display.fillRect(10, 50, 20, 20, COLOUR);
  display.fillCircle(50, 10, 20, COLOUR);
  display.fillTriangle(50, 50, 30, 30, 70, 70, COLOUR);
}

void printResults() {
  Serial.print("The display initialised in (ms): ");
  Serial.println(initialiseTime);

  Serial.print("The display ran the text test in (ms): ");
  Serial.println(textTime);

  Serial.print("The display ran the graphics test in (ms): ");
  Serial.println(graphicsTime);
}

void loop() {}
