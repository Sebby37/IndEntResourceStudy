## Info
This is the source code for both of my tests for my Resource Study for SACE Stage 2 Industry & Entrepreneurial Solutions. 
The first test simply tests the speed in which both displays are able to draw shapes and text.
The second test tests the readability of both displays at larger and smaller text sizes.

## Displays
### Touchscreen
- https://au.banggood.com/2_8-Inch-TFT-LCD-Shield-Touch-Display-Screen-Module-Geekcreit-for-Arduino-products-that-work-with-official-Arduino-boards-p-989697.html
### E-Paper
- https://au.banggood.com/1_54-Inch-or-2_13-Inch-or-2_9-Inch-Flexible-Ink-Screen-LCD-Module-E-paper-Electronic-Paper-Display-Compatible-with-Arduino-or-STM32-or-Raspberry-p-1811238.html

## Wiring
### Touchscreen
- Simply plug the shield into the Arduino, making sure the 5v and reset pins on the shield line up with those on the Arduino
### E-Paper
- Wire the display to the Arduino using these pins: BUSY -> 7, RST -> 9, DC -> 8, CS-> 10, CLK -> 13, DIN -> 11
