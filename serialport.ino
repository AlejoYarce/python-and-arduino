int testingLevel=A0;
int testingLed=8;
int inValue=0;
float outValue=0;

void setup() {
  Serial.begin(9600);

  pinMode(testingLevel, INPUT);
  pinMode(testingLed, OUTPUT);
}

void loop() {
    inValue = analogRead(testingLevel);
    outValue = inValue*5.0/1023; //map(inValue, 0, 1023, 0, 255);
    Serial.print(outValue);
    Serial.println(" volts.");
    changeLights(true);
    delay(1000);
    changeLights(false);
    delay(1000);
}

void changeLights(boolean isFW) {
  if ( isFW ) {
    digitalWrite(testingLed, HIGH);
  } else {
    digitalWrite(testingLed, LOW);
  }
}
