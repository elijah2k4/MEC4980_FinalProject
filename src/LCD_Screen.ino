/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 7 Nov 2016
 by Arturo Guadalupi

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalHelloWorld

*/

#include <LiquidCrystal.h>

// Pins
const int rs1 = 13;
const int en1 = 7;
const int d41 = 12;
const int d51 = 11;
const int d61 = 10;
const int d71 = 9;
const int rs2 = 13;
const int en2 = 6;
const int d42 = 12;
const int d52 = 11;
const int d62 = 10;
const int d72 = 9;
const int rs3 = 8;
const int en3 = 5;
const int d43 = 4;
const int d53 = 3;
const int d63 = 2;
const int d73 = 1;

// LCD objects
LiquidCrystal lcd1(rs1, en1, d41, d51, d61, d71);
LiquidCrystal lcd2(rs2, en2, d42, d52, d62, d72);
LiquidCrystal lcd3(rs3, en3, d43, d53, d63, d73);


// Messages
String msg1 = "Press the button for Skittles!       ";
String msg2 = "Press the button for M&Ms!       ";
String msg3 = "Press the button for Starbursts!       ";

const int width = 16;

void setup() {
  lcd1.begin(width, 2);
  lcd2.begin(width, 2);
  lcd3.begin(width, 2);

}

void loop() {
  static int offset1 = 0;
  static int offset2 = 0;
  static int offset3 = 0;


  // --- LCD1 window ---
  String window1 = "";
  for (int i = 0; i < width; i++) {
    window1 += msg1[(offset1 + i) % msg1.length()];
  }
  lcd1.setCursor(0, 0);
  lcd1.print(window1);

  // --- LCD2 window ---
  String window2 = "";
  for (int i = 0; i < width; i++) {
    window2 += msg2[(offset2 + i) % msg2.length()];
  }
  lcd2.setCursor(0, 0);
  lcd2.print(window2);

  // --- LCD3 window ---
  String window3 = "";
  for (int i = 0; i < width; i++) {
    window3 += msg3[(offset3 + i) % msg3.length()];
  }
  lcd3.setCursor(0, 0);
  lcd3.print(window3);

  // Advance offsets independently
  offset1 = (offset1 + 1) % msg1.length();
  offset2 = (offset2 + 1) % msg2.length();
  offset3 = (offset3 + 1) % msg3.length();


  delay(200); // scrolling speed
}
