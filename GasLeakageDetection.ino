// Pin Definitions
const int mq2AnalogPin = A0;  // Analog input pin connected to A0 of MQ-2
const int buzzerPin = 3;      // Digital pin connected to Buzzer

// Threshold value (calibrate based on environment)
int threshold = 300;  

void setup() {
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);  // Initialize serial communication
}

void loop() {
  int sensorValue = analogRead(mq2AnalogPin); // Read MQ-2 sensor

  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);

  if (sensorValue > threshold) {
    Serial.println("Gas Leak Detected!");
    digitalWrite(buzzerPin, HIGH);
    Serial.println("YES"); // Send YES to Python
    delay(5000);  
    digitalWrite(buzzerPin, LOW);
  } else {
    Serial.println("No gas detected.");
    Serial.println("NO"); // Send NO to Python
  }
  delay(1000);
}
