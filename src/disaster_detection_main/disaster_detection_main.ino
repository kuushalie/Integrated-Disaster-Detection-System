#include <SoftwareSerial.h>

SoftwareSerial bluetooth(10, 11); // RX, TX

const int trigPin = 8;
const int echoPin = 9;
const int mq2Pin = A0;
const int mq4Pin = A1;
const int rainS = A2;
const int led1 = 2;
const int led2 = 3;
const int led3 = 4;
const int led4 = 5;
const int Buzzer =6;

const int gasThreshold = 300; 
const int gasThreshold1 = 150;
const int distanceThreshold = 5;
const int rain = 450;

void setup() {
  
  Serial.begin(9600);

  
  bluetooth.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(Buzzer,OUTPUT);

}

void loop() {
  long duration;
  int distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  int mq2Value = analogRead(mq2Pin);
  int mq4Value = analogRead(mq4Pin);
  int rainValue = analogRead(rainS);

  if (distance < distanceThreshold) {
    bluetooth.println("ALERT: Water level is rising!");
    digitalWrite(led1,HIGH);
    digitalWrite(Buzzer,HIGH);
  }

  if (mq2Value > gasThreshold) {
    bluetooth.println("ALERT: High MQ2 gas levels detected!");
    digitalWrite(led2,HIGH);
    digitalWrite(Buzzer,HIGH);
    delay(100);
    digitalWrite(Buzzer,LOW);
    delay(100);
    digitalWrite(Buzzer,HIGH);
    delay(100);
    digitalWrite(Buzzer,LOW);
  }

  if (mq4Value > gasThreshold1) {
    bluetooth.println("ALERT: High MQ4 gas levels detected!");
    digitalWrite(led3,HIGH);
    digitalWrite(Buzzer,HIGH);
    delay(100);
    digitalWrite(Buzzer,LOW);
    delay(100);
    digitalWrite(Buzzer,HIGH);
    delay(100);
    digitalWrite(Buzzer,LOW);
  }

  if (rainValue < rain) {
    bluetooth.println("ALERT: Rain detected!");
    digitalWrite(led4,HIGH);
    digitalWrite(Buzzer,HIGH);
    delay(100);
    digitalWrite(Buzzer,LOW);
    delay(100);
    digitalWrite(Buzzer,HIGH);
    delay(100);
    digitalWrite(Buzzer,LOW);
    delay(100);
    digitalWrite(Buzzer,HIGH);
    delay(100);
    digitalWrite(Buzzer,LOW);
    delay(100);
    digitalWrite(Buzzer,HIGH);
    delay(100);
    digitalWrite(Buzzer,LOW);
  }

  // Debugging
  Serial.print("Distance: ");
  Serial.println(distance);
  Serial.print("MQ2 Value: ");
  Serial.println(mq2Value);
  Serial.print("MQ4 Value: ");
  Serial.println(mq4Value);
  Serial.print("Rain Value: ");
  Serial.println(rainValue);

  delay(1000);
  
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
    digitalWrite(Buzzer,LOW);
  
  if (bluetooth.available()) {
    char receivedChar = bluetooth.read();
    Serial.print("Received: ");
    Serial.println(receivedChar); 
  }
  delay(0); 
}