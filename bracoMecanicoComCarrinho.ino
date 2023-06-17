#include <Servo.h>

Servo myservo1; //Abre e fecha GARRA
Servo myservo2; //Sobe e dece BRAÇO
int pos = 0;
int servo1 = 100; //Angulo da GARRA
int servo2 = 80; //Angulo do BRAÇO

//PENEUS DO CARRINHO
int Pin4 = 4; 
int Pin5 = 5; 
int Pin6 = 6; 
int Pin7 = 7; 

//OPÇÕES VIA BLUETOOTH 
int val; 

void setup(){
    Serial.begin(9600);
    pinMode(Pin4,OUTPUT); 
    pinMode(Pin5,OUTPUT); 
    pinMode(Pin6,OUTPUT); 
    pinMode(Pin7,OUTPUT);
    digitalWrite(Pin4,LOW); 
    digitalWrite(Pin5,LOW); 
    digitalWrite(Pin6,LOW); 
    digitalWrite(Pin7,LOW);
    myservo2.attach(8); 
    myservo1.attach(9); 
    myservo1.write(servo1); 
    myservo2.write(servo2);
}

void loop(){
    if (Serial.available()>0) {
        val = Serial.read();
        
        //Carrinho ir para FRENTE 
        if (val == 'G') {
            digitalWrite(Pin4,LOW);
            digitalWrite(Pin5,HIGH); 
            digitalWrite(Pin6,LOW); 
            digitalWrite(Pin7,HIGH);
        }
        //Carrinho ir para TRÁS
        else if (val == 'F') {
            digitalWrite(Pin4,HIGH);
            digitalWrite(Pin5,LOW);
            digitalWrite(Pin6,HIGH);
            digitalWrite(Pin7,LOW);
        }
        //Carrinho PARAR
        else if (val == 'S') {
            digitalWrite(Pin4,LOW); 
            digitalWrite(Pin5,LOW); 
            digitalWrite(Pin6,LOW); 
            digitalWrite(Pin7,LOW);
        }
        //Carrinho virar para ESQUERDA 
        else if (val == 'R') {
            digitalWrite(Pin4,HIGH); 
            digitalWrite(Pin5,LOW); 
            digitalWrite(Pin6,LOW); 
            digitalWrite(Pin7,LOW);
        }
        //Carrinho virar para DIREITA 
        else if (val == 'L') {
            digitalWrite(Pin4,LOW); 
            digitalWrite(Pin5,LOW); 
            digitalWrite(Pin6,HIGH); 
            digitalWrite(Pin7,LOW);
        }
        
        //FECHAR garra
        if(val=='8') {
            for (servo1=100; servo1 <= 130; servo1 += 1) {
                delay(150);
                myservo1.write(servo1); 
            }
            for (servo2=80; servo2 >= 60; servo2 -= 1) {
                delay(150);
                myservo2.write(servo2);    //angulo 60°           
            }
        }
        //ABRIR garra 
        else if (val=='7') {
            delay(150);
            myservo1.write(100); 
            myservo2.write(80);
        }
    }
}
