int sensorPin = D2;                                                     //2W
volatile long pulse;                                                    //1W
float volume;                                                           //1W

void setup() {                                                          //1E
  pinMode(sensorPin, INPUT);                                            //1X
  Serial.begin(9600);                                                   //1X
  attachInterrupt(digitalPinToInterrupt(sensorPin), increase, RISING);  //1X
}

void loop() {                                                           //1E
  volume = 2.663 * pulse;                                               //1R,1W
  Serial.print(volume);                                                 //1X
  Serial.println(" mL");                                                //1X
  delay(500);                                                           //1X
}

ICACHE_RAM_ATTR void increase() {                                      
  pulse++;                                                              //1R,1W
}
                                                                        //16CFP
