#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// LCD 설정
LiquidCrystal_I2C lcd(0x27, 16, 2);  // LCD 주소는 0x27이며, 16x2 크기의 LCD 사용

// DHT 센서 핀 정의
const int dhtPin = 2;  // DHT 센서 신호선이 아두이노의 2번 핀에 연결된 경우

// DHT 센서 설정
DHT dht(dhtPin, DHT11);  // DHT11 또는 DHT22를 사용하려면 DHT11 대신 DHT22로 변경

void setup() {
  // 시리얼 통신 시작
  Serial.begin(9600);

  // LCD 초기화
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("Temperature:");
}

void loop() {
  // 온도 측정
  float temperature = dht.readTemperature();  // 온도를 읽어옴

  // 온도 출력 (시리얼 모니터에도 출력)
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  // LCD에 온도 표시
  lcd.setCursor(0, 1);
  lcd.print("      "); // 이전에 출력한 온도 지우기
  lcd.setCursor(0, 1);
  lcd.print(temperature);
  lcd.print("C");

  // 측정 주기 (변경 가능)
  delay(1000);  // 1초마다 온도를 측정하여 LCD에 표시
}
