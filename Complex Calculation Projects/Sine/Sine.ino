int angleInDegrees = 30; // Variable to store the angle in degrees                       //2W
double sineValue; // Variable to store the sine value                                    //1W

void setup() {                                                                           //1E
  Serial.begin(9600);                                                                    //1W
  while (!Serial) {                                                                      //1W
    ; // wait for serial port to connect
  }
  
  double angleInRadians = angleInDegrees * 3.141592 / 180.0; // Convert to radians       //1R+1W
  sineValue = sin(angleInRadians); // Calculate sine value                               //1X+1W
  
  Serial.print("Sine value of ");                                                        //1X
  Serial.print(angleInDegrees);                                                          //1X
  Serial.print(" degrees is: ");                                                         //1X
  Serial.println(sineValue, 4); // Print the sine value with 4 decimal places            //1X
}

void loop() {                                                                            //1E
  // Empty because we only want to calculate the sine value once in the setup
}

                                                                                        //WITHOUT EXIT - 15
                                                                                        //WITH EXIT - 21


// . Variables and constants in RAM (global, static), used 28580 / 80192 bytes (35%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╠══ DATA     1500     initialized variables
// ╠══ RODATA   1424     constants       
// ╚══ BSS      25656    zeroed variables
// . Instruction RAM (IRAM_ATTR, ICACHE_RAM_ATTR), used 59747 / 65536 bytes (91%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╠══ ICACHE   32768    reserved space for flash instruction cache
// ╚══ IRAM     26979    code in IRAM    
// . Code in flash (default, ICACHE_FLASH_ATTR), used 242132 / 1048576 bytes (23%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╚══ IROM     242132   code in flash   
