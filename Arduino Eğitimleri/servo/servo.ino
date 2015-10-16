/*
Robot Kutusu Akademi Servo Dersi
*/
 
#include <Servo.h> 
 //kahverengi GNd
 //siyah 3.3V
 //turuncu Pin (9)
int servoPin = 9;
 
Servo servo;  
 
int derece = 0;   // servo position in degrees 
 
void setup() 
{ 
  servo.attach(servoPin); 
} 
 
 
void loop() 
{ 
  // scan from 0 to 180 degrees
  for(derece = 0; derece < 180; derece++)  
  {                                  
    servo.write(derece);               
    delay(10);                   
  } 
  // now scan back from 180 to 0 degrees
  for(derece = 180; derece > 0; derece--)    
  {                                
    servo.write(derece);           
    delay(10);       
  } 
} 
