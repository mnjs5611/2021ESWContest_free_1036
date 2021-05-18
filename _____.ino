#include <Wire.h> 
#include "Adafruit_TCS34725.h"
#include <Servo.h>
Servo myservo;
 
// TCS34725 라이브러리 사용을 위한 객체 생성
Adafruit_TCS34725 TCS = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);
 
void setup() {
  Serial.begin(9600); // 9600bps 속도로 시리얼 통신 시작
  delay(100);         // 연결되고 인식될 때까지 대기
  myservo.attach(9);
  
  if (!TCS.begin()) { // TCS34725 센서가 인식되지 않는 경우
    Serial.println("No TCS34725 found ... check your connections"); 
    while (1);        // 연결 될 때까지 대기
  }
  else {              // TCS34725 센서가 인식된 경우
    Serial.println("Found sensor");
  }
  
}
 
void loop() { 
  uint16_t clear, red, green, blue; // unsigned short int형 변수 선언 
 
  delay(500); // 0.5초마다 측정하고 출력
  
  TCS.getRawData(&red, &green, &blue, &clear); // 색상 감지 센서에서 측정 값 받아오기 
 
  // 색상 감지 센서에서 받아온 데이터 값을 사용 가능하게끔 수치 변경
  int r = map(red, 0, 21504, 0, 10752);    // 빨간색 데이터 값
  int g = map(green, 0, 21504, 0, 10752);  // 초록색 데이터 값
  int b = map(blue, 0, 21504, 0, 10752);   // 파란색 데이터 값
  int rgb=r+g+b;
  Serial.print("   R: "); 
  Serial.print(r);        // 시리얼 모니터에 빨간색 값 출력 
  Serial.print("   G: "); 
  Serial.print(g);        // 시리얼 모니터에 초록색 값 출력 
  Serial.print("   B: "); 
  Serial.println(b);      // 시리얼 모니터에 파란색 값 출력 
   Serial.print("   RGB SUMMARY: ");
  Serial.println(rgb);

 if (rgb<67){
    delay(1000);
    myservo.write(0);
    delay(10000);
    myservo.write(90);
    delay(1000);

    
 }
}
