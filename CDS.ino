#include <Servo.h>
Servo myservo;

int CDS = A1; // 조도 센서 연결한 핀


void setup() {
  Serial.begin(9600);
  pinMode(CDS, INPUT);
  myservo.attach(9);
}

void loop() {
  
  CDS = analogRead(A1);

  Serial.print("CDS_Sensor: "); 
  Serial.println(CDS);
  delay(500);

  if(CDS>260 & CDS<300){  //차량 입장할때 조도 좀 낮아지는 값 잡는거
    delay(5800);          //이때부터 6.2초 뒤에 딱 회전판 돌고 조도 체크하는 타이밍  
   for(int j=0; j<=3; j=j+1){      //딜레이 0.4초로 빠르게 4번 측정하기 위해 반복문
      CDS = analogRead(A1);
    Serial.print("CDS_Sensor: "); 
    Serial.println(CDS);
    delay(400);
  if(CDS>240 & CDS<270){       //4번의 빠른 반복중에 이제 조도 값 체크하는거 이 범위가 불량의 조도  
  myservo.write(0);
  delay(8000);
  myservo.write(90);
  delay(5000);
   break;                       //불량체크하면 바로 반복문 탈출, 불량체크 안하면 그냥 4번 측정하고 끝남
  }
  }
  delay (4000);                  //차가 완전히 다 나갈때까지 기다렸다가 다시 조도 측정하기 위해서 딜레이
  }
  
}
