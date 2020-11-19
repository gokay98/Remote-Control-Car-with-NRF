#include  <SPI.h> 
#include "nRF24L01.h"
#include "RF24.h"


RF24 verici(9,10);
int  mesaj[1];

const int kanal = 111;


int x_ekseni = A2;
int y_ekseni = A1 ;

int x_position;
int y_position;


void setup() {

  Serial.begin(9600);

  verici.begin();
  verici.openWritingPipe(kanal);
}


void loop() {
x_position=analogRead(x_ekseni);
y_position=analogRead(y_ekseni);

    if( (499 == x_position) && (494 == y_position)){
   mesaj[0]= 5 ;
    verici.write(&mesaj, sizeof(mesaj));      //stop
    Serial.println("stop");
  }

if (520 < y_position){            //forward
  mesaj[0]= 8;
  verici.write(&mesaj, sizeof(mesaj));
  Serial.println("forward");
  }

  if ((y_position < 480)){            //downward
  mesaj[0]= 2;
  verici.write(&mesaj, sizeof(mesaj));
  Serial.println("downward");
  }

  if (x_position >499){
  mesaj[0]= 6;
  verici.write(&mesaj, sizeof(mesaj));
  Serial.println("right");
  }

  if (x_position <499){
  mesaj[0]= 4;
  verici.write(&mesaj, sizeof(mesaj));
  Serial.println("left");
  }

 
  delay(100);
  Serial.print("x direction : ");
  Serial.println(x_position);
  Serial.print("y direction : ");
  Serial.println(y_position);
  Serial.println("********************");
  delay(500);
}
