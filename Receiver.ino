#include<SPI.h>
#include"nRF24L01.h"
#include"RF24.h"

int mesaj[1];

RF24 alici (9,10);

const int kanal = 111;

const int in1 = 6;
const int in2 = 7;
const int in3 = 3;
const int in4 = 4;

void setup(){
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  alici.begin();
  alici.openReadingPipe(1,kanal);
  alici.startListening();
  Serial.begin(9600);
  }

  void forward(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
    }

    void downward(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
    }

    void left(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
    }

    void right(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
    }
    

    void stay(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
    }

  
  void loop(){
    
    if(alici.available()){
      bool done = false;
      
      while (!done){

    alici.read(&mesaj, sizeof(mesaj));
     
     
         if(mesaj[0]==5){
          //Serial.println(mesaj[0]);
          stay();
          Serial.println("stop");
          Serial.println("**********************************");
          delay(100);
          }

         else if(mesaj[0]==6){
          right();
         // Serial.println(mesaj[0]);
          Serial.println("right");
          Serial.println("**********************************");
          delay(100);
          }

         else if(mesaj[0]==4){
          left();
         // Serial.println(mesaj[0]);
          Serial.println("left");
          Serial.println("**********************************");
          delay(100);
          }

         else if(mesaj[0]==8){
          forward();
         // Serial.println(mesaj[0]);
          Serial.println("forward");
          Serial.println("**********************************");
          delay(100);
          }

        else  if(mesaj[0]==2){
          downward();
         // Serial.println(mesaj[0]);
          Serial.println("downward");
          Serial.println("**********************************");
          delay(100);
          }

         
      
      
      }
      
    }
    }
