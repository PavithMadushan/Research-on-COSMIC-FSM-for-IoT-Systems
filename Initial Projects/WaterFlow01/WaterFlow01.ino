int sensorPin = D2;                                                     //2W
volatile long pulse;                                                    //1W
float volume;                                                           //1W

void setup() {                                                          //1E
  pinMode(sensorPin, INPUT);                                            //1W
  Serial.begin(9600);                                                   //1W
  //attachInterrupt(digitalPinToInterrupt(sensorPin), increase, RISING);  //1W
}

void loop() {                                                           //1E
  volume = 2.663 * pulse;                                               //1R,1W
  Serial.print(volume);                                                 //1X
  Serial.println(" mL");                                                //1X
  delay(500);                                                           //1X
}

// ICACHE_RAM_ATTR void increase() {                                      
//   pulse++;                                                              //1R,1W
// }
                                                                        //17CFP

                                                                        //WITHOUT EXIT AND LOCAL VARIABLES-13CFP
                                                                        //WITH EXIT - 17


// . Variables and constants in RAM (global, static), used 28108 / 80192 bytes (35%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╠══ DATA     1500     initialized variables
// ╠══ RODATA   928      constants       
// ╚══ BSS      25680    zeroed variables
// . Instruction RAM (IRAM_ATTR, ICACHE_RAM_ATTR), used 59747 / 65536 bytes (91%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╠══ ICACHE   32768    reserved space for flash instruction cache
// ╚══ IRAM     26979    code in IRAM    
// . Code in flash (default, ICACHE_FLASH_ATTR), used 237316 / 1048576 bytes (22%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╚══ IROM     237316   code in flash   
