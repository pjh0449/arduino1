// 초음파 센서 핀 정의
const int trigPin = 11;
const int echoPin = 10;

// LED 핀 정의
const int ledPin = 8;

void setup() {
  // 핀 설정
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  
  // 시리얼 통신 시작
  Serial.begin(9600);
}

void loop() {
  // 초음파 센서로 거리 측정
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;  // 음속 속도 기준으로 거리 계산 (단위: 센티미터)

  // 측정된 거리 출력 (디버깅용)
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // 거리가 100 이하일 때 LED를 켬
  if (distance <= 20) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  // 측정 주기 (변경 가능)
  delay(20); // 0.2초마다 거리를 측정
}
