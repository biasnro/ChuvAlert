#include "MyServo.h"

MyServo :: MyServo(int porta){
  x.attach(porta);
  _SENSOR = "\"SENSOR\":";
  _JANELA =  "\"JANELA\":";;
}

void MyServo:: abrir(){
		x.write(180);
}

void MyServo:: fechar(){
		x.write(5);
}

bool MyServo :: status(){
        if(x.read() == 180){
            return 1;
        }else{
            return 0;
        }
}
  
String MyServo :: JSON_SENSOR(double temp_s){
  return "{" + _SENSOR + String(temp_s) + "}";
}

String MyServo :: JSON_JANELA(){
  if (status()== 1){
    return "{" + _JANELA + "1" + "}";
  }else{
    return "{" + _JANELA + "0" + "}";
    }
}

void MyServo :: uploadSENSOR(double temp_s){
  Serial.print(JSON_SENSOR(temp_s));
}

void MyServo :: uploadJANELA(){
  Serial.println(JSON_JANELA());

}
