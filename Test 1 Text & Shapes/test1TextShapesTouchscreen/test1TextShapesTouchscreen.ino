#include <Adafruit_GFX.h>
#include <MCUFRIEND_kbv.h>

#define COLOUR 0x0000

MCUFRIEND_kbv display;

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
  display.begin(display.readID());
  display.fillScreen(0xFFFF);
  display.setRotation(1);
  initialiseTime = millis() - beforeInitialiseTime;
  
  // Running the text test and recording the time taken
  beforeTextTime = millis();
  textTest();
  textTime = millis() - beforeTextTime;
  
  // Running the shape test and recording the time taken
  beforeGraphicsTime = millis();
  shapeTest();
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
  display.fillTriangle(30, 30, 70, 70, 50, 50, COLOUR);
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
