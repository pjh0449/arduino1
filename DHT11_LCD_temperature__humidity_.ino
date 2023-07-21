#include <SimpleDHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,16,2);
int pinDHT11=2;
SimpleDHT11 dht11(pinDHT11);
void setup() {
 Serial.begin(115200);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("Hello,world!");
  lcd.setCursor(2,1);
  lcd.print("Myeungmun!");
}
void loop() {
Serial.println("=========================");
Serial.println("Sample DHT11...");
byte temperature=0;
byte humidity=0;
int err = SimpleDHTErrSuccess;
if ((err = dht11.read(&temperature, &humidity, NULL))!=SimpleDHTErrSuccess) {
Serial.print("Read DHT11 failed, err="); Serial.print(SimpleDHTErrCode(err));delay(1000);
Serial.print(","); Serial.println(SimpleDHTErrDuration(err)); delay(1000);
return;
}
Serial.print("Sample OK; ");
Serial.print((int)temperature); Serial.print(" *C, ");
Serial.print((int)humidity); Serial.print(" H ");
int t =temperature;

lcd.init (); 
// Print a message to the LCD. 
lcd.backlight () ; 
lcd.setCursor (0, 0) ; 
lcd.print ("Temp = "); 
lcd.setCursor (7, 0) ; 
lcd.println (t); 
lcd.setCursor(9,0);
lcd.write(223);
lcd.setCursor(10,0);
lcd.println ("C"); 
lcd. setCursor (0,1);
lcd.print("Humi = "); 
lcd.setCursor (7, 1) ; 
lcd.println (humidity);
lcd.setCursor (11, 1) ; 
lcd.print ("%"); 
delay(1500);
}

 
