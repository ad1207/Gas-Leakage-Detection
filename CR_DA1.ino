// Pin Definitions
const int mq2AnalogPin = A0;  // Analog input pin connected to A0 of MQ-2
const int buzzerPin = 3;      // Digital pin connected to Buzzer
 
// Threshold value (you will need to calibrate this based on your environment)
int threshold = 300;  // Adjust this value as per your needs based on sensor readings
 
void setup() {
  // Set up buzzer pin
  pinMode(buzzerPin, OUTPUT);
  // Begin Serial Monitor
  Serial.begin(9600);
}
 
void loop() {
  // Read analog value from MQ-2 sensor (A0 pin)
  int sensorValue = analogRead(mq2AnalogPin);
 
  // Print the sensor value to Serial Monitor
  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);
 
  // Check if sensor value exceeds threshold (gas detected)
  if (sensorValue > threshold) {
    Serial.println("Gas Leak Detected! Triggering Alarm...");
    digitalWrite(buzzerPin, HIGH);  // Turn on buzzer
    delay(2000);  // Buzzer on for 2 seconds
    digitalWrite(buzzerPin, LOW);   // Turn off buzzer
  } else {
    Serial.println("No gas detected.");
  }
 
  delay(1000);  // Wait for 1 second before checking again
}
