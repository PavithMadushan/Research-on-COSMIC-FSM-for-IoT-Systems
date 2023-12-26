#include <Wire.h> 
#include "Adafruit_VEML6075.h"

Adafruit_VEML6075 uv = Adafruit_VEML6075();      //1X+1R+2W

void setup() {                                   //1E
  Serial.begin(9600);                            //2X
  Serial.println("VEML6075 Test");               //2X

  if (! uv.begin()) {                            //1W
    Serial.println("Failed to communicate");     //2X
  }
  Serial.println("Found the VEML6075 sensor");   //2X
}

void loop() {                                    //1E
  Serial.print("UV Index reading: ");            //2X
  Serial.println(uv.readUVI());                  //2X
  delay(1000);                                   //1X
}

//With FC Exits - 20CFP
//Without       - 13CFP


// . Variables and constants in RAM (global, static), used 28808 / 80192 bytes (35%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╠══ DATA     1504     initialized variables
// ╠══ RODATA   1024     constants       
// ╚══ BSS      26280    zeroed variables
// . Instruction RAM (IRAM_ATTR, ICACHE_RAM_ATTR), used 60931 / 65536 bytes (92%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╠══ ICACHE   32768    reserved space for flash instruction cache
// ╚══ IRAM     28163    code in IRAM    
// . Code in flash (default, ICACHE_FLASH_ATTR), used 244584 / 1048576 bytes (23%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╚══ IROM     244584   code in flash   
