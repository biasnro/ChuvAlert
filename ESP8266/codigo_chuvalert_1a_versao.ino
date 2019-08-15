#include <Servo.h>
#include "MyServo.h"

const int sensor = A0;

MyServo janela(D4);

void setup() {
  
  pinMode(sensor,INPUT); 
  Serial.begin(115200);
  
}

void loop() {

double analogSensor = analogRead(sensor);

if(analogSensor < 590){
  janela.fechar();
  delay(200);
}else{
  janela.abrir();
  delay(200);
}

janela.uploadSENSOR(analogSensor);
delay(10);
janela.uploadJANELA();

}
