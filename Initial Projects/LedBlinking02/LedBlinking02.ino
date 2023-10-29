#define LED1 D7                   //2W
#define LED2 D8                   //2W

void setup() {                    //1E
  pinMode(LED1, OUTPUT);          //1X
  pinMode(LED2, OUTPUT);          //1X           
  Serial.begin(9600);             //1X
}

void loop() {                     //1E
  digitalWrite(LED1, HIGH);       //1X
  digitalWrite(LED2, HIGH);       //1X
  delay(20000);                   //1X
  digitalWrite(LED1, LOW);        //1X
  digitalWrite(LED2, LOW);        //1X
  Serial.print("Hello World");    //1X
  delay(20000);                   //1X
}
                                  //16CFP




