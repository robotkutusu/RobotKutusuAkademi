//sensörün yüzü bize bakılı iken, en sola 5V, oraya pin, sağa ground bağlanıyor.
/*Robot Kutusu Akademi lm35 okuma ve led yazdırma projesi dersi */
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


}
void loop()
{
val = analogRead(sicaklikPin);
float mv = ( val/1024.0)*5000; 
float cel = mv/10;
float farh = (cel*9)/5 + 32;

Serial.print("Sıcaklık = ");
Serial.print(cel);
Serial.print("*C");
Serial.println();
delay(1000);

}


