const int pirPin = 5;                     //2W

void setup() {                            //1E
  pinMode(pirPin, INPUT);                 //1X
  Serial.begin(9600);                     //1X
  delay(20000);                           //1X
}

void loop() {                             //1E
  int pirState = digitalRead(pirPin);     //1E,1W
  if (pirState == HIGH) {                 //1R
    Serial.println("Motion detected!");   //1X
    delay(1000);                          //1X
  } else {
    Serial.println("No motion detected.");//1X
  }
}
                                          //13CFP