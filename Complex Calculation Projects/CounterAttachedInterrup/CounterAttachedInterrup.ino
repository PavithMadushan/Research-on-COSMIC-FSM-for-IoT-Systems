int counter = 0; // Variable to store the counter value            //2W

ICACHE_RAM_ATTR void myFunction(){                                 
  counter++; // Increment the counter value                        //1R+1W
}

void setup() {                                                     //1E
  Serial.begin(9600);                                              //1W
  pinMode(2, INPUT_PULLUP);                                        //1W
  attachInterrupt(digitalPinToInterrupt(2), myFunction, CHANGE);   //1W
}

void loop() {                                                      //1E
  // Your main code here
}

                                                                   //without exit - 9
                                                                   //with exit - 11

// . Variables and constants in RAM (global, static), used 28348 / 80192 bytes (35%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╠══ DATA     1496     initialized variables
// ╠══ RODATA   940      constants       
// ╚══ BSS      25912    zeroed variables
// . Instruction RAM (IRAM_ATTR, ICACHE_RAM_ATTR), used 60111 / 65536 bytes (91%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╠══ ICACHE   32768    reserved space for flash instruction cache
// ╚══ IRAM     27343    code in IRAM    
// . Code in flash (default, ICACHE_FLASH_ATTR), used 236004 / 1048576 bytes (22%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╚══ IROM     236004   code in flash   

