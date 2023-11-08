#include <PS4Controller.h>
#include <ps4.h>
#include <ps4_int.h>


#include <analogWrite.h>
const int AIN1=18;
const int AIN2=4;
const int BIN1=27;
const int BIN2=14;
int tiempoAccion=1000;

const int AIN1D=32;
const int AIN2D=33;
const int BIN1D=25;
const int BIN2D=26;


void notify()

{



  //motores de pelotas
  if (PS4.Circle()==1){
int speed = 255;
    analogWrite(AIN1D, speed);
    analogWrite(AIN2D, 0);
    analogWrite(BIN1D, speed);
    analogWrite(BIN2D, 0);
    Serial.println("DISPARAR");
   
  }else if (PS4.Cross()==1){
     int speed = 255;
    analogWrite(AIN1D, 0);
    analogWrite(AIN2D, speed);
    analogWrite(BIN1D, 0);
    analogWrite(BIN2D, speed);
    Serial.println("AGARRAR");
    }else if (PS4.Triangle()==1){
     int speed = 255;
    analogWrite(AIN1D, speed);
    analogWrite(AIN2D, speed);
    analogWrite(BIN1D, speed);
    analogWrite(BIN2D, speed);
  }

  //motores de llantas
  if (PS4.Left()==1){
    int speed = 255;
    analogWrite(AIN1, 160);
    analogWrite(AIN2, speed);
    analogWrite(BIN1, speed);
    analogWrite(BIN2, 160);
     
  }else if (PS4.Right()==1){
    int speed = 255;
    analogWrite(AIN1, speed);
    analogWrite(AIN2, 160);
    analogWrite(BIN1, 160);
    analogWrite(BIN2, speed);
  }else if (PS4.Up()==1){
     int speed = 255;
    analogWrite(AIN1, speed);
    analogWrite(AIN2, 136);
    analogWrite(BIN1, speed);
    analogWrite(BIN2, 160);
 
  }else if (PS4.Down()==1){
    int speed = 255;
    analogWrite(AIN1, 125);
    analogWrite(AIN2, speed);
    analogWrite(BIN1, 160);
    analogWrite(BIN2, speed);
    }else if (PS4.Square()==1){
    int speed = 255;
     analogWrite(AIN1, speed);
    analogWrite(AIN2, 75);
    analogWrite(BIN1, speed);
    analogWrite(BIN2, 100);
   
  }else{
    int speed = 255;
    analogWrite(AIN1, speed);
    analogWrite(AIN2, speed);
    analogWrite(BIN1, speed);
    analogWrite(BIN2, speed);
   

  }
}


void onConnect()
{
  Serial.println("Connected!.");
}
void onDisConnect()
{
  Serial.println("Disconnected!.");    
}
void setUpPinModes()
{
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);

  pinMode(AIN1D, OUTPUT);
  pinMode(AIN2D, OUTPUT);
  pinMode(BIN1D, OUTPUT);
  pinMode(BIN2D, OUTPUT);

 
 




}

void setup() 
{
  setUpPinModes();
  Serial.begin(115200);
  PS4.attach(notify);
  PS4.attachOnConnect(onConnect);
  PS4.attachOnDisconnect(onDisConnect);
  PS4.begin();
  Serial.println("Ready.");


 

 }
void loop() 
{

}
 