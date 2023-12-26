#define LED_PIN 8                         //2W       //2W
#define BUTTON_PIN 7                      //2W       //2W

void setup() {                            //1E       //1E
  pinMode(LED_PIN, OUTPUT);               //1X       //1X+1W
  pinMode(BUTTON_PIN, INPUT);             //1X       //1X+1W
}

void loop() {                             //1E       //1E
  if (digitalRead(BUTTON_PIN) == HIGH) {  //1E       //1X+1E
    digitalWrite(LED_PIN, HIGH);          //1X       //2X
  }
  else {
    digitalWrite(LED_PIN, LOW);           //1X       //2X
  }
}
                                          //11X      //16CFP

                                          

                                          //without exit and local memory-11CFP
                                          //with exit - 16

// . Variables and constants in RAM (global, static), used 28080 / 80192 bytes (35%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╠══ DATA     1496     initialized variables
// ╠══ RODATA   920      constants       
// ╚══ BSS      25664    zeroed variables
// . Instruction RAM (IRAM_ATTR, ICACHE_RAM_ATTR), used 59731 / 65536 bytes (91%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╠══ ICACHE   32768    reserved space for flash instruction cache
// ╚══ IRAM     26963    code in IRAM    
// . Code in flash (default, ICACHE_FLASH_ATTR), used 231780 / 1048576 bytes (22%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╚══ IROM     231780   code in flash   

                                          