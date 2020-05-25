/*
* bluetooth.ino
* Status: 
* Date: 23/05/2020
* Fuente: https://naylampmechatronics.com/blog/24_configuracion-del-modulo-bluetooth-hc-05-usa.html
*/

int ledPin = 8; //LED connected to digital pin 8
int statusPin = 9; //Status of Bluetooth device [connected|disconected]
int testPin = 13; //Test 
int irPin = 4; //Infrared interruptor power suppy 
int AS5040Pin = 5; //AS5040  power suppy 
int val = 0;


#include <SoftwareSerial.h>   // Incluimos la librería  SoftwareSerial  
SoftwareSerial BT(10,11);    // Definimos los pines RX y TX del Arduino conectados al Bluetooth
 
void setup()
{
  BT.begin(9600);       // Inicializamos el puerto serie BT (Para Modo AT 2)
  Serial.begin(9600);   // Inicializamos  el puerto serie  
  pinMode(statusPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(testPin, OUTPUT);
  pinMode(irPin, OUTPUT);
  pinMode(AS5040Pin, OUTPUT);
}
 
void loop()
{
  digitalWrite(testPin, HIGH);
  digitalWrite(irPin, LOW);
  digitalWrite(AS5040Pin, HIGH);

  val = analogRead(A0);   // Read anenometer
  if (val<=150)
  {
    digitalWrite(ledPin, HIGH);  // sets the LED to the sstatus value 
  } else {
    digitalWrite(ledPin, LOW);
  }

  if(BT.available())    // Si llega un dato por el puerto BT se envía al monitor serial
  {
    Serial.write(BT.read());
  }
  if(Serial.available())  // Si llega un dato por el monitor serial se envía al puerto BT
  {
     BT.write(Serial.read());
  }
  //delay(250);
  //digitalWrite(testPin, LOW);
  //delay(250);


}
