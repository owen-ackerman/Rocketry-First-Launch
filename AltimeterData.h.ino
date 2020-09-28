#include <Wire.h>
#include <Adafruit_MPL3115A2.h>
#include "Ejection.h"


Adafruit_MPL3115A2 baro = Adafruit_MPL3115A2();
float h;
float R;
float b = (float)1 / 5.257435;
int o = - 53;
int c = 0;
int a = 0;
unsigned long time = millis();
//time = mills();

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
float Ejection(float h);
pinMode(LED_BUILTIN, OUTPUT);

if (! baro.begin()){
  Serial.println("error");
}
}

void loop() {
  // put your main code here, to run repeatedly:
  float p = baro.getPressure();
  float T = baro.getTemperature();
  float R = (float)101325 / p;
  float h = o+(float)((pow(R, b)-1)*(T+273.15)) / .0065;
 // float Ejection(float h);
 if(2.5 <= h && h <= 4.5 && c < 1){
  Serial.print(h, 4);
  Serial.println("eee");
  c =+ 1;
Serial.println(c);
      delay(5000);
    }
p = baro.getPressure();
T = baro.getTemperature();
R = (float)101325 / p;
h = o+(float)((pow(R, b)-1)*(T+273.15)) / .0065;
p = baro.getPressure();
T = baro.getTemperature();
R = (float)101325 / p;
h = o+(float)((pow(R, b)-1)*(T+273.15)) / .0065;

Serial.println(h, 4);
   if (3.5 <= h && h <= 4){
      digitalWrite(LED_BUILTIN, HIGH);
      Serial.println("BOOM");
      delay(500);
      digitalWrite(LED_BUILTIN, LOW);
      Serial.println("OFF");
      delay(500);
   }
   else if(millis() - time > 5000 && c < 1){
    Serial.println("TIME");
    c = 1;
   }
 

  Serial.println(h, 4);
 
  delay(250);
}
