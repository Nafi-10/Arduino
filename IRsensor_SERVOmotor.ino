#include <Servo.h>

const int trigPin = 9;
const int echoPin = 10;
long duration;
int distance;

Servo myServo;

void setup() {
  myServo.attach(6);            // Servo connected to pin 6
  pinMode(trigPin, OUTPUT);     // Trig pin as output
  pinMode(echoPin, INPUT);      // Echo pin as input
  Serial.begin(9600);           // Serial monitor for debugging
}

void loop() {
  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read pulse time
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance in cm
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Control servo based on distance
  if (distance <= 10 && distance > 0) {
    myServo.write(180);  // Rotate to 180°
  } else {
    myServo.write(0);    // Go back to 0°
  }

  delay(200); // Small delay for stability
}
