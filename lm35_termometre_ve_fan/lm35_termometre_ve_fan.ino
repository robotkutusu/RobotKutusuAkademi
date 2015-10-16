//sensörün yüzü bize bakılı iken, en sola 5V, oraya pin, sağa ground bağlanıyor.

/*
Robot Kutusu Akademi Led'li Termometre ve serve fan dersi
*/
 
#include <Servo.h> 

//Bağlantı!!!
 //kahverengi GNd
 //siyah 3.3V
 //turuncu Pin (9)
int servoPin = 9;
 
Servo servo;  
int i=0; 
int derece = 0;   // servo konumu derece olarak
 


int val;
int sicaklikPin = A1;

void setup()
{
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  servo.attach(servoPin); 


}
void loop()
{
  int seviye=0;
  val = analogRead(sicaklikPin);
  float mv = ( val/1024.0)*5000; 
  float cel = mv/10;
  float farh = (cel*9)/5 + 32;

  Serial.print("SICAKLIK = ");
  Serial.print(cel);
  Serial.print("*C");
  Serial.println();
  delay(1000);



  
  if(cel>35)
  {
    Serial.println("Seviye 5");
    seviye=4;
  }
  else if(cel>30)
  {
    Serial.println("Seviye 4");
    seviye=4;
  }
  else if(cel>25)
  {
    Serial.println("Seviye 3");
    seviye=3;
  }
  else if (cel>20)
  {
    Serial.println("Seviye 2");
    seviye=2;
  }
  else if (cel>15)
  {
    Serial.println("Seviye 1");
    seviye=1;
  }
   
  for(i=0;i<seviye;i++)
  {
    digitalWrite(i+2,HIGH);
  }
  for(i=seviye;i<5;i++)
  {
    digitalWrite(i+2,LOW);
  }
   
  if(seviye>3)
  {
    i=0;
    for(i=0;i<5;i++){
      // 0'dan 180 dereceye tarar
      for(derece = 0; derece < 180; derece++)  
      {                                  
        servo.write(derece);               
        delay(5);                   
      } 
      // 180'den 0'a tarar.
      for(derece = 180; derece > 0; derece--)    
      {                                
        servo.write(derece);           
        delay(5);       
      } 
      delay(100);
    }
  }
}


