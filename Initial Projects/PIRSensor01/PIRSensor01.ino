const int pirPin = 5;                     //2W         //2W

void setup() {                            //1E         //1E
  pinMode(pirPin, INPUT);                 //1X         //1X+1W
  Serial.begin(9600);                     //1X         //1X+1W
  delay(20000);                           //1X         //1X
}

void loop() {                             //1E         //1E
  int pirState = digitalRead(pirPin);     //1E,1W      //1X+1E+2W
  if (pirState == HIGH) {                 //1R         //1R
    Serial.println("Motion detected!");   //1X         //2X
    delay(1000);                          //1X         //1X
  } else {
    Serial.println("No motion detected.");//1X         //2X
  }
}
                                          //13CFP      //19CFP

                                          //WITHOUT EXIT AND LOCAL VARIABLES-10CFP
                                          //with exit -15

// . Variables and constants in RAM (global, static), used 28124 / 80192 bytes (35%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╠══ DATA     1496     initialized variables
// ╠══ RODATA   956      constants       
// ╚══ BSS      25672    zeroed variables
// . Instruction RAM (IRAM_ATTR, ICACHE_RAM_ATTR), used 59811 / 65536 bytes (91%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╠══ ICACHE   32768    reserved space for flash instruction cache
// ╚══ IRAM     27043    code in IRAM    
// . Code in flash (default, ICACHE_FLASH_ATTR), used 236196 / 1048576 bytes (22%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╚══ IROM     236196   code in flash   

                                          