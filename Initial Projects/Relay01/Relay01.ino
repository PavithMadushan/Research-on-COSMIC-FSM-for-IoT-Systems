int relay_pin = 7;                 //2W          

void setup() {                     //1E
  pinMode(relay_pin,OUTPUT);       //1W
}

void loop() {                      //1E
  digitalWrite(relay_pin,HIGH);    //1X
  delay(2000);                     //1X
  digitalWrite(relay_pin,LOW);     //1X
  delay(2000);                     //1X
}
                                   //8CFP       //12CFP

                                   //WITHOUT EXIT AND LOCAL VARIABLES- 9CFP
                                   //with exit - 12

// . Variables and constants in RAM (global, static), used 28108 / 80192 bytes (35%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╠══ DATA     1500     initialized variables
// ╠══ RODATA   920      constants       
// ╚══ BSS      25688    zeroed variables
// . Instruction RAM (IRAM_ATTR, ICACHE_RAM_ATTR), used 59667 / 65536 bytes (91%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╠══ ICACHE   32768    reserved space for flash instruction cache
// ╚══ IRAM     26899    code in IRAM    
// . Code in flash (default, ICACHE_FLASH_ATTR), used 232180 / 1048576 bytes (22%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╚══ IROM     232180   code in flash   
                                   