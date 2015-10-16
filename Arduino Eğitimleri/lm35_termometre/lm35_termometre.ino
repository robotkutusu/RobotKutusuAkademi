//Robot Kutusu LM35 Okuma ve gösterim dersi.

//sensörün yüzü bize bakılı iken, en sola 5V, oraya pin, sağa ground bağlanıyor.

int val;
int sicaklikPin = A1;
int derece=0;

int i=0;
void setup()
{
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);


}
void loop()
{
  int seviye=0;
  val = analogRead(sicaklikPin);
  float mv = ( val/1024.0)*5000; 
  float cel = mv/10;
  float farh = (cel*9)/5 + 32;

  Serial.print("TEMPRATURE = ");
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
  delay(100);
  
}




