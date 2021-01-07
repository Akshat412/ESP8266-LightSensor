#include <DHT.h>

int DHTpin = 3;
int LDRpin = A0;

String readLightValue() {
  Serial.println("Function called");
  int val = analogRead(LDRpin);
  if (val <= 150){
    return String("EXTREMELY DARK");
  }

  else if (val <= 300){
    return String("VERY DARK");
  }

  else if (val <= 450){
    return String("DARK");
  }

  else if (val <= 700){
    return String("DIMLY LIT");
  }

  else if (val <= 900){
    return String("BRIGHT");
  }

  else {
    return String("VERY BRIGHT");
  }
}
