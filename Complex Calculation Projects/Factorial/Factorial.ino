int number; // Variable to store the number for which to calculate the factorial    //1W
unsigned long factorial; // Variable to store the factorial                         //1W

void setup() {                                                                      //1E
  Serial.begin(9600);                                                               //1W
  while (!Serial) {                                                                 //1W
    ; // wait for serial port to connect. Needed for native USB port only
  }

  number = 5; // Replace 5 with the number for which want to calculate the facto    //1W
  factorial = 1;                                                                    //1W

  for (int i = 1; i <= number; i++) {                                               //1R
    factorial *= i;                                                                 //1R+1W
  }

  Serial.print("Factorial of ");                                                    //1X
  Serial.print(number);                                                             //1X
  Serial.print(" is: ");                                                            //1X
  Serial.println(factorial);                                                        //1X
}

void loop() {                                                                       //1E
  // Empty because we only want to calculate the factorial once in the setup
}

                                                                                    //WITHOUT EXIT - 15
                                                                                    //WITH EXIT - 20

// . Variables and constants in RAM (global, static), used 28096 / 80192 bytes (35%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╠══ DATA     1496     initialized variables
// ╠══ RODATA   944      constants       
// ╚══ BSS      25656    zeroed variables
// . Instruction RAM (IRAM_ATTR, ICACHE_RAM_ATTR), used 59747 / 65536 bytes (91%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╠══ ICACHE   32768    reserved space for flash instruction cache
// ╚══ IRAM     26979    code in IRAM    
// . Code in flash (default, ICACHE_FLASH_ATTR), used 236068 / 1048576 bytes (22%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╚══ IROM     236068   code in flash   

