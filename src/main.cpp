#include <Arduino.h>
#include <DFRobot_RGBMatrix.h>
#include <RGBmatrixPanel.h>
#include <Wire.h>

#define OE   	9
#define LAT 	10
#define CLK 	11
#define A   	A0
#define B   	A1
#define C   	A2
#define D   	A3
#define E   	A4
#define WIDTH 64
#define _HIGH	64

RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false, 64);
// DFRobot_RGBMatrix matrix(A, B, C, D, E, CLK, LAT, OE, false, WIDTH, _HIGH);

int total_time;
int touch_count;

void screen_handler(int a){
  matrix.fillScreen(matrix.Color333(0,0,0)); // clear screen

  total_time = Wire.read();
  touch_count = Wire.read();
  Serial.print(total_time);
  Serial.print("\t");
  Serial.println(touch_count);

  matrix.setTextSize(1);
  matrix.setCursor(0,0);
  matrix.print("your time:");
  matrix.println(total_time);
  // matrix.print("\n \n \n");
  matrix.print("touch \ncounter:");
  matrix.println(touch_count);
}


void setup() {
  // put your setup code here, to run once:
  matrix.begin();
  Wire.begin(1);
  Serial.begin(9600);
  matrix.fillScreen(matrix.Color333(0, 0, 0));

  Wire.onReceive(screen_handler);
}

void loop() {
  // if (Wire.available() > 0){
  //   Serial.println("printing");
  //   total_time = Wire.read();
  //   touch_count = Wire.read();

  //   matrix.fillScreen(matrix.Color333(0, 0, 0));
  // }

}