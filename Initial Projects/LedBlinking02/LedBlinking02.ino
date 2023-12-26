#define LED1 D7                   //2W          //2W
#define LED2 D8                   //2W          //2W
#include <SPI.h>

void setup() {                    //1E          //1E 
  pinMode(LED1, OUTPUT);          //1X          //1X+1W
  pinMode(LED2, OUTPUT);          //1X          //1X+1W  
  Serial.begin(9600);             //1X          //1X+1W
 

}

void loop() {                     //1E          //1E
  digitalWrite(LED1, HIGH);       //1X          //2X
  digitalWrite(LED2, HIGH);       //1X          //2X
  delay(40000);                   //1X          //1X
  digitalWrite(LED1, LOW);        //1X          //2X
  digitalWrite(LED2, LOW);        //1X          //2X
  Serial.print("Hello World");    //1X          //2X
  delay(40000);                   //1X          //1X
  
}
                                  //16CFP       //24CFP

                                  //without exit and local memory-16CFP
                                  //with exit - 24


// . Variables and constants in RAM (global, static), used 28188 / 80192 bytes (35%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╠══ DATA     1496     initialized variables
// ╠══ RODATA   932      constants       
// ╚══ BSS      25760    zeroed variables
// . Instruction RAM (IRAM_ATTR, ICACHE_RAM_ATTR), used 60267 / 65536 bytes (91%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╠══ ICACHE   32768    reserved space for flash instruction cache
// ╚══ IRAM     27499    code in IRAM    
// . Code in flash (default, ICACHE_FLASH_ATTR), used 236212 / 1048576 bytes (22%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╚══ IROM     236212   code in flash   


