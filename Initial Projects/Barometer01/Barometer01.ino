#include <Wire.h>
#include <Adafruit_BMP085.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);      //1W
Adafruit_BMP085 bmp;                   //1W 
  
void setup() {                         //1E

  lcd.init();                          //1X+1W
  lcd.backlight();                     //1X+1W
  if (!bmp.begin()) {                  //1X+1W
  lcd.print("ERROR, check wiring!");   //2X
	while (1) {}
  }
  lcd.print(" tutorial45.com");        //2X
  delay(3000);                         //1X
  lcd.clear();                         //2X
}
  
void loop() {                          //1E
/*
 * this sensor is very powerful, you can even read temperature with it with this function:
 * bmp.readTemperature()
 */

    //read pressure
    lcd.setCursor(0, 0);               //2X
    lcd.print("P: ");                  //2X
    lcd.print(bmp.readPressure()/100); //1X+1E+2X
    lcd.print(" hPa");                 //2X

    //read altitude
    lcd.setCursor(0, 1);               //2X
    lcd.print("A: ");                  //2X
    lcd.print(bmp.readAltitude());     //1X+1E+2X
    lcd.print(" m");                   //2X

  delay(1000);                         //1X
}

//With FC Exits - 38CFP
//Without       - 22CFP

// WARNING: library LiquidCrystal I2C claims to run on avr architecture(s) and may be incompatible with your current board which runs on esp8266 architecture(s).
// . Variables and constants in RAM (global, static), used 28672 / 80192 bytes (35%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╠══ DATA     1504     initialized variables
// ╠══ RODATA   1040     constants       
// ╚══ BSS      26128    zeroed variables
// . Instruction RAM (IRAM_ATTR, ICACHE_RAM_ATTR), used 59815 / 65536 bytes (91%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╠══ ICACHE   32768    reserved space for flash instruction cache
// ╚══ IRAM     27047    code in IRAM    
// . Code in flash (default, ICACHE_FLASH_ATTR), used 244200 / 1048576 bytes (23%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╚══ IROM     244200   code in flash   
