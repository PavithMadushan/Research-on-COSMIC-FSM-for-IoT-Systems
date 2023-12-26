#include <Servo.h>                         
Servo myservo;                            //1W               //1W
int pos = 0;                              //2W               //2W
  
void setup() {                            //1E               //1E
  myservo.attach(26);                     //1X               //1X+1W
}

void loop() {                             //1E               //1E
  for (pos = 0; pos <= 180; pos += 1) {   //1E,1W,1R,1W      //1W+1R+1W
    myservo.write(pos);                   //1X               //2X
    delay(15);                            //1X               //1X
  }
  for (pos = 180; pos >= 0; pos -= 1) {   //1E,1W,1R,1W      //1W+1R+1W
    myservo.write(pos);                   //1X               //2X
    delay(15);                            //1X               //1X
  }
}
                                          //18CFP            //19CFP

                                          //WITHOUT EXIT AND LOCAL VARIABLES- 18CFP
                                          //with exit - 21


                                        
// . Variables and constants in RAM (global, static), used 28120 / 80192 bytes (35%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╠══ DATA     1496     initialized variables
// ╠══ RODATA   920      constants       
// ╚══ BSS      25704    zeroed variables
// . Instruction RAM (IRAM_ATTR, ICACHE_RAM_ATTR), used 60583 / 65536 bytes (92%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╠══ ICACHE   32768    reserved space for flash instruction cache
// ╚══ IRAM     27815    code in IRAM    
// . Code in flash (default, ICACHE_FLASH_ATTR), used 233236 / 1048576 bytes (22%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╚══ IROM     233236   code in flash   
