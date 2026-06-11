// Ultrasonic sensor pins
const int trig = 6;    // Trig pin for ultrasonic sensor (changed to D6)
const int echo = 7;    // Echo pin for ultrasonic sensor (changed to D7)

// LED pins for ultrasonic distance warnings
const int LED1 = 9;    // LED1 for level 1 warning (connected to D9)
const int LED2 = 10;   // LED2 for level 2 warning (connected to D10)
const int LED3 = 11;   // LED3 for level 3 warning (connected to D11)

// Smoke sensor pins
int smokeLed = 12;     // Smoke sensor LED pin
int smokeA0 = A5;      // Smoke sensor pin
int smokeThres = 500;  // Smoke sensor threshold

// Rain sensor pins
int rainLed = 4;       // Rain sensor LED pin
int rainA3 = A3;       // Rain sensor pin
int rainThres = 400;   // Rain sensor threshold

// MQ4 gas sensor pins
int mq4Led = 8;        // MQ4 sensor LED pin
int mq4A1 = A1;        // MQ4 sensor pin
int mq4Thres = 250;    // MQ4 gas sensor threshold

// Ultrasonic distance variables
int duration = 0;
int distance = 0;

void setup() {
  // Initialize pins for ultrasonic sensor
  pinMode(trig, OUTPUT);  // Set trig pin as OUTPUT
  pinMode(echo, INPUT);   // Set echo pin as INPUT
  
  // Initialize pins for smoke, rain, and MQ4 sensors
  pinMode(smokeLed, OUTPUT);  
  pinMode(rainLed, OUTPUT);  
  pinMode(mq4Led, OUTPUT);   
  pinMode(smokeA0, INPUT);   
  pinMode(rainA3, INPUT);    
  pinMode(mq4A1, INPUT);     

  // Initialize Serial Monitor
  Serial.begin(9600); 
}

void loop() {
  // Ultrasonic sensor logic
  digitalWrite(trig, HIGH); 
  delayMicroseconds(1000);  // Short pulse to trigger the sensor
  digitalWrite(trig, LOW);  // Stop sending pulse

  duration = pulseIn(echo, HIGH); 
  distance = (duration / 2) / 28.5;  // Calculate distance in cm
  
  // Print the distance in the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);

  // Logic for controlling LEDs based on distance
  if (distance <= 7) {
    digitalWrite(LED1, HIGH);  // Turn on LED1 for close distance
  } else {
    digitalWrite(LED1, LOW);  // Turn off LED1
  }

  if (distance <= 14) {
    digitalWrite(LED2, HIGH);  // Turn on LED2 for medium distance
  } else {
    digitalWrite(LED2, LOW);  // Turn off LED2
  }

  if (distance <= 21) {
    digitalWrite(LED3, HIGH);  // Turn on LED3 for far distance
  } else {
    digitalWrite(LED3, LOW);  // Turn off LED3
  }

  // Smoke sensor logic
  int smokeValue = analogRead(smokeA0);
  if (smokeValue > smokeThres) {
    digitalWrite(smokeLed, HIGH);  // Turn on smoke LED
    Serial.println("Smoke detected! Smoke LED ON.");
  } else {
    digitalWrite(smokeLed, LOW);   // Turn off smoke LED
  }

  // Rain sensor logic
  int rainValue = analogRead(rainA3);
  if (rainValue < rainThres) {
    digitalWrite(rainLed, HIGH);  // Turn on rain LED
    Serial.println("Heavy rain detected! Rain LED ON.");
  } else {
    digitalWrite(rainLed, LOW);   // Turn off rain LED
  }

  // MQ4 gas sensor logic
  int mq4Value = analogRead(mq4A1);
  mq4SensorLogic(mq4Value);  // Handle MQ4 gas sensor logic
  
  delay(100); // Short delay for stability
}

// Function to handle MQ4 sensor logic
void mq4SensorLogic(int mq4Value) {
  if (mq4Value > mq4Thres) {
    Serial.println("Gas leak detected by MQ4! MQ4 LED ON.");
    digitalWrite(mq4Led, HIGH);  // Turn on MQ4 LED when gas is detected
  } else {
    digitalWrite(mq4Led, LOW);   // Turn off MQ4 LED when no gas is detected
  }
}
