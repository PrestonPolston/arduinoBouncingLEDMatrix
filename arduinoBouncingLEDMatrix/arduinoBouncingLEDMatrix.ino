#include "Arduino_LED_Matrix.h"

ArduinoLEDMatrix matrix;
int br = 115200;
int delayTime = 75;
int xPos = 3;
int yPos = 2;
int deltaX = 1;
int deltaY = 1;
int i;
int j;
byte frame[8][12];

void setup() {
  Serial.begin(br);
  matrix.begin();
}

void loop() {
  for(i = 0; i < 8; i= i + 1) {
    for(j = 0; j < 12; j = j + 1) {
      frame[i][j] = 0;
      if(i == xPos && j == yPos){
        frame[i][j] = 1;
      }
    }
  }
  matrix.renderBitmap(frame, 8, 12);
  if(xPos >= 7 || xPos <= 0){
    deltaX = -deltaX;
  }
  if(yPos >= 11 || yPos <= 0){
    deltaY = -deltaY;
  }

  xPos += deltaX;
  yPos += deltaY;

  delay(delayTime);
}
