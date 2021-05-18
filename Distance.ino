
#include <Wire.h>
#include <VL53L0X.h>
#include <Servo.h>
Servo myservo;
VL53L0X sensor;

void setup()
{
  Serial.begin(9600);
  Wire.begin();
myservo.attach(9);
  sensor.setTimeout(500);
  if (!sensor.init())
  {
    Serial.println("Failed to detect and initialize sensor!");
    while (1) {}
  }
  sensor.startContinuous();
}

void loop()
{
  Serial.println(sensor.readRangeContinuousMillimeters());
   delay(300);
  if(sensor.readRangeContinuousMillimeters()<100){
  delay(2200);
  for(int j=0;j<=5;j=j+1){
    Serial.println(sensor.readRangeContinuousMillimeters());
    delay(300);
    if(sensor.readRangeContinuousMillimeters()<57){
      
    myservo.write(0);
    delay(10000);
    myservo.write(90);
    delay(1000);
    }
  }
  delay(1000);

}
}
