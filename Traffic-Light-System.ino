//------ Traffic Light For Transportation ------

//defines pins numbers
int r = 2, y = 3, g = 4;
const int trigPin = 6;
const int echoPin = 7;
int buzzer = 8;

//defines variables
long duration;
int distance;

void setup() {
  pinMode(r, OUTPUT);
  pinMode(y, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  //Sets trigPin on HIGH State for 10 micro
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, return the sound wave travel
  duration = pulseIn(echoPin, HIGH);

  //Calculate the distance
  distance = duration * 0.034 / 2;

  //Got transportation detected then green
  if (distance <= 50) {
    //Blink 3 Red
    digitalWrite(r, LOW);
    delay(1000);
    digitalWrite(r, HIGH);
    delay(1000);
    digitalWrite(r, LOW);
    delay(1000);

    digitalWrite(r, HIGH);
    delay(1000);
    digitalWrite(r, LOW);
    delay(1000);

    digitalWrite(r, HIGH);
    delay(1000);
    digitalWrite(r, LOW);
    digitalWrite(y, LOW);
    digitalWrite(y, LOW);
    digitalWrite(g, HIGH);
    delay(10000);

    // Green to Blinking Yellow
    digitalWrite(g, LOW);

    digitalWrite(y, HIGH);
    tone(buzzer, 1000);
    delay(1000);
    digitalWrite(y, LOW);
    noTone(buzzer);
    delay(1000);

    digitalWrite(y, HIGH);
    tone(buzzer, 1000);
    delay(1000);
    digitalWrite(y, LOW);
    noTone(buzzer);
    delay(1000);

    digitalWrite(y, HIGH);
    tone(buzzer, 1000);
    delay(1000);
    digitalWrite(y, LOW);
    noTone(buzzer);
    delay(1000);

    digitalWrite(y, HIGH);
    tone(buzzer, 1000);
    delay(1000);
    digitalWrite(y, LOW);
    noTone(buzzer);
    delay(1000);

    digitalWrite(y, HIGH);
    tone(buzzer, 1000);
    delay(1000);
    digitalWrite(y, LOW);
    noTone(buzzer);
    digitalWrite(r, LOW);
    delay(1000);

    //Yellow to Red
    digitalWrite(y, LOW);
    digitalWrite(r, HIGH);
    digitalWrite(g, LOW);
    delay(10000);
  }

  else {
    //No transportation detected then red
    digitalWrite(r, HIGH);
    digitalWrite(y, LOW);
    digitalWrite(g, LOW);
  }
}

