//Gamepad
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <DabbleESP32.h>

//Definicion de pines
#define AIN1 32
#define AIN2 33 
#define BIN1 26
#define BIN2 25

//Disparador
#define AIN_1 18
#define AIN_2 4

#define BIN_1 27
#define BIN_2 14 

int tiempoPruebas = 100;

void setup() {
  //Activador monitor de serie
  Serial.begin(115200);
  //Nombre del la conexion del servidor de la esp32
  Dabble.begin("LPL-001");

  //Declaracion de pines de motor de movimiento
  pinMode(AIN1,OUTPUT);
  pinMode(AIN2,OUTPUT);
  pinMode(BIN1,OUTPUT);
  pinMode(BIN2,OUTPUT);

  //Declaracion de pines de motor de lanzadora
  pinMode(AIN_1,OUTPUT);
  pinMode(AIN_2,OUTPUT);
  pinMode(BIN_1,OUTPUT);
  pinMode(BIN_2,OUTPUT);
}

void loop() {
  Dabble.processInput();
  Serial.println("Tecla presionada: ");
  if (GamePad.isUpPressed()) {
   Serial.println("Arriba"); 
    adelante();
  }

  if (GamePad.isDownPressed()) {
    Serial.println("Abajo");
    atras();
  }

  if (GamePad.isLeftPressed()) {
    Serial.println("Izquierda");
    izquierda();
  }

  if (GamePad.isRightPressed()) {
    Serial.println("Derecha");
    derecha();
  }

  if (GamePad.isSquarePressed()) {
    Serial.println("Cuadrado");
    activado_disparador();
  }

  if (GamePad.isCirclePressed()){
    Serial.println("Circulo"); 
    activado_subcionador();
  }

  if (GamePad.isCrossPressed()){
    Serial.println("Cruz");
    detener_disparadores();  
  }

  if (GamePad.isTrianglePressed()){
    Serial.println("Triagulo");

  }

  if (GamePad.isStartPressed()){
    Serial.println("Inicio");
   
  }

  if (GamePad.isSelectPressed()){
    Serial.println("Selecionar");
detener_todo();
  }

else{
 detener_movimineto();
    }
}

//Declaracion de acciones de los motores 
// Movimientos 
void adelante(){
 //Arriba
 digitalWrite(AIN1,HIGH);
 digitalWrite(AIN2,LOW);
 digitalWrite(BIN1,HIGH);
 digitalWrite(BIN2,LOW);
 delay(tiempoPruebas);
  }

void atras(){
//Abajo
 digitalWrite(AIN1,LOW);
 digitalWrite(AIN2,HIGH);
 digitalWrite(BIN1,LOW);
 digitalWrite(BIN2,HIGH);
 delay(tiempoPruebas);
  }

 void izquierda(){
//Izquierda
 digitalWrite(AIN1,HIGH);
 digitalWrite(AIN2,LOW);
 digitalWrite(BIN1,LOW);
 digitalWrite(BIN2,HIGH);
 delay(tiempoPruebas);
  }

 void derecha(){
//Derecha
 digitalWrite(AIN1,LOW);
 digitalWrite(AIN2,HIGH);
 digitalWrite(BIN1,HIGH);
 digitalWrite(BIN2,LOW);
 delay(tiempoPruebas);
  }

  
void detener_movimineto(){
//Detener motores
digitalWrite(AIN1,LOW);
digitalWrite(AIN2,LOW);
digitalWrite(BIN1,LOW);
digitalWrite(BIN2,LOW);
  }
  
// Disparadores   
void activado_disparador(){
//Activar Disparadores
digitalWrite(AIN_1,HIGH);
digitalWrite(AIN_2,LOW);
digitalWrite(BIN_1,HIGH);
digitalWrite(BIN_2,LOW);
delay(tiempoPruebas);
  }
  
void activado_subcionador(){
//Activar Subcionador
digitalWrite(AIN_1,LOW);
digitalWrite(AIN_2,HIGH);
digitalWrite(BIN_1,LOW);
digitalWrite(BIN_2,HIGH);
delay(tiempoPruebas);
  }  
  
void detener_disparadores(){
//Desactivar Disparador y Subcionador
digitalWrite(AIN_1,LOW);
digitalWrite(AIN_2,LOW);
digitalWrite(BIN_1,LOW);
digitalWrite(BIN_2,LOW);
delay(tiempoPruebas);
  }

 //Detener todo
 void detener_todo(){
 digitalWrite(AIN1,LOW);
 digitalWrite(AIN2,LOW);
 digitalWrite(BIN1,LOW);
 digitalWrite(BIN2,LOW);
 
 digitalWrite(AIN_1,LOW);
 digitalWrite(AIN_2,LOW);
 digitalWrite(BIN_1,LOW);
 digitalWrite(BIN_2,LOW);
 delay(tiempoPruebas);
  } 
