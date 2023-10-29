int relay_pin = 7;                 //2W

void setup() {                     //1E
  pinMode(relay_pin,OUTPUT);       //1X
}

void loop() {                      //1E
  digitalWrite(relay_pin,HIGH);    //1X
  delay(2000);                     //1X
  digitalWrite(relay_pin,LOW);     //1X
  delay(2000);                     //1X
}
                                   //8CFP