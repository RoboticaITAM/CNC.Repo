#include "BNO055_support.h" 
#include <Wire.h>
 
struct bno055_t myBNO;
struct bno055_euler myEulerData; 
 
unsigned long lastTime = 0;
 
#define BNO055_SAMPLERATE_DELAY_MS (300)
 
void setup(){
  Serial.begin(115200);
  Wire.begin();
 
  //Iniciar el BNO055
  BNO_Init(&myBNO);
 
  //Configuramos el modo en el que vamos a trabajar 
  bno055_set_operation_mode(OPERATION_MODE_NDOF);
 
  delay(1);
}
 
 
void loop(){
    bno055_read_euler_hrp(&myEulerData);   
 
    //Mostramos la posicion con respecto a x,y,z en ese orden 
    Serial.print(F("Orientation: z "));
    Serial.print((float(myEulerData.h) / 16.00)-180);
    Serial.print(F(", y "));
    Serial.print((float(myEulerData.p) / 16.00));
    Serial.print(F(", x "));
    Serial.print((float(myEulerData.r) / 16.00));
    Serial.println(F(""));

    delay(100);
    
}
