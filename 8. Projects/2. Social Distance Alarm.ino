// C++ code
//
int distance = 0;

int ultrasonic = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);

  pinMode(4, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(2, OUTPUT);
}

void loop()
{
  ultrasonic = 0.01723 * readUltrasonicDistance(A1, A3);

  distance = 0.01723 * readUltrasonicDistance(A0, A1);
  Serial.println(distance);
  if (distance < 50) {
    digitalWrite(4, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(2, HIGH);
  } else {
    digitalWrite(4, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(2, LOW);
  }
  delay(10); // Delay a little bit to improve simulation performance
}
