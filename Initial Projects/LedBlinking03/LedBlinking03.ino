#define LED1 D7                   //2W         //2W

void setup() {                    //1E         //1E
  pinMode(LED1, OUTPUT);          //1X         //1x+1W
  Serial.begin(9600);             //1X         //1X+1W
}

void loop() {                     //1E         //1E
  digitalWrite(LED1, HIGH);       //1X         //2X
  delay(40000);                   //1X         //1X
  digitalWrite(LED1, LOW);        //1X         //2X
  Serial.print("Hello World");    //1X         //2X
  delay(40000);                   //1X         //1X
}
                                       

                                  //without exit - 10cfp
                                  //with exit - 15


// . Variables and constants in RAM (global, static), used 28180 / 80192 bytes (35%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╠══ DATA     1496     initialized variables
// ╠══ RODATA   932      constants       
// ╚══ BSS      25752    zeroed variables
// . Instruction RAM (IRAM_ATTR, ICACHE_RAM_ATTR), used 60267 / 65536 bytes (91%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╠══ ICACHE   32768    reserved space for flash instruction cache
// ╚══ IRAM     27499    code in IRAM    
// . Code in flash (default, ICACHE_FLASH_ATTR), used 236148 / 1048576 bytes (22%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╚══ IROM     236148   code in flash   



