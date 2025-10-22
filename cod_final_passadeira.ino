#define velmotor 3
#define mla 9
#define mlb 10
#define tmp 3000
int vel=0;


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
  pinMode(velmotor,OUTPUT);
  pinMode(mla,OUTPUT);
  pinMode(mlb,OUTPUT);
  digitalWrite(mla,LOW);
  digitalWrite(mlb,LOW);
  analogWrite(velmotor,vel);
 
  pinMode(0, OUTPUT);
  Serial.begin(9600);

}

void loop()
{
  tone(0, 523, 1000); // play tone 60 (C5 = 523 Hz)
  Serial.println(0.01723 * readUltrasonicDistance(5, 4));
  if (0.01723 * readUltrasonicDistance(5, 4) < 10) {
        vel=255;
        digitalWrite(mla,LOW);
        digitalWrite(mlb,LOW);


  } else {
       analogWrite(velmotor,vel);
       digitalWrite(mla,LOW);
       digitalWrite(mlb,HIGH);

  }
  delay(10); // Delay a little bit to improve simulation performance
}
