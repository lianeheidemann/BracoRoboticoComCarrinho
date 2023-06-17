8#include <Servo.h>

Servo myservo1, myservo2; 
int pos = 0;
int servo1 = 100; 
int servo2 = 80;
int Pin4 = 4; 
int Pin5 = 5; 
int Pin6 = 6; 
int Pin7 = 7; 
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
        else if (val == 'L')
        {
            digitalWrite(Pin4,LOW); 
            digitalWrite(Pin5,LOW); 
            digitalWrite(Pin6,HIGH); 
            digitalWrite(Pin7,LOW);
        }
        
        //Garra FECHAR
        if(val=='8') {
            for (servo1=100; servo1 <= 130; servo1 += 1) {
                myservo1.write(servo1); 
                delay(15);
            }
            for (servo2=80; servo2 >= 60; servo2 -= 1) {
                myservo2.write(servo2);    //angulo 60 
                delay(15);
            }
        }
        //Garra ABRIR
        else if (val=='7'){
            myservo1.write(100); 
            myservo2.write(80);
        }
    }
}
