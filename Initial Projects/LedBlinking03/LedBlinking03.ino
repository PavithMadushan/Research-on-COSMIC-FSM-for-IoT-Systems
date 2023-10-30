#define LED1 D7                   //2W

void setup() {                    //1E
  pinMode(LED1, OUTPUT);          //1X
  Serial.begin(9600);             //1X
}

void loop() {                     //1E
  digitalWrite(LED1, HIGH);       //1X
  delay(40000);                   //1X
  digitalWrite(LED1, LOW);        //1X
  Serial.print("Hello World");    //1X
  delay(40000);                   //1X
}
                                  //11CFP




