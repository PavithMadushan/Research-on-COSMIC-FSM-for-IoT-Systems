#define LED_PIN 8                         //2W
#define BUTTON_PIN 7                      //2W

void setup() {                            //1E
  pinMode(LED_PIN, OUTPUT);               //1X
  pinMode(BUTTON_PIN, INPUT);             //1X
}

void loop() {                             //1E
  if (digitalRead(BUTTON_PIN) == HIGH) {  //1E
    digitalWrite(LED_PIN, HIGH);          //1X
  }
  else {
    digitalWrite(LED_PIN, LOW);           //1X
  }
}
                                          //11X