int pot1=A5;
int pot2=A4;
int a,b;
void setup() 
{
pinMode(pot1,INPUT);
pinMode(pot2,INPUT);
Serial.begin(9600);
Serial.println("start");


Serial.println("AT+CSQ");

delay(100);
Serial.println("AT+CGATT?");
delay(100);
Serial.println("AT+SAPBR=3,1,\"CONTYPE\",\"gprs\"");
delay(2000);
Serial.println("AT+SAPBR=3,1,\"APN\",\"airtelgprs.com\"");
delay(4000);
Serial.println("AT+SAPBR=1,1");
delay(4000);
Serial.println("AT+HTTPINIT");
delay(3000);
}

void loop()
{

a=analogRead(pot1);
b=analogRead(pot2);
String s ="device.php?temp="+String(a)+"&gas="+String(b);
Serial.print("AT+HTTPPARA=\"URL\",\"http://muleyankit.000webhostapp.com/");
Serial.print(s);
Serial.print("\"\r\n");

delay(1000);
while(Serial.available()!=0)
Serial.write((Serial.read()));

Serial.println("AT+HTTPACTION=0");
delay(5000);
while(Serial.available()!=0)
Serial.write((Serial.read()));

Serial.println("AT+HTTPREAD");
delay(3000);
while(Serial.available()!=0)
Serial.write((Serial.read()));

}
