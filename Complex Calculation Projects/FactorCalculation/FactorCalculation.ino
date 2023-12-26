int number; // Variable to store the number for which to find the factors //1W

void setup() {                                                            //1E
  Serial.begin(9600);                                                     //1W
  while (!Serial) {                                                       //1W
    ; // wait for serial port to connect
  }
  
  Serial.println("Enter a number to find its factors:");                  //1X
  while (!Serial.available()) {                                           //1E
    ; // wait for user input
  }
  number = Serial.parseInt(); // Read the number from the Serial monitor  //1E+1W
  
  Serial.print("Factors of ");                                            //1X
  Serial.print(number);                                                   //1X
  Serial.print(" are: ");                                                 //1X
  
  for (int i = 1; i <= number; i++) {                                     //1R
    if (number % i == 0) {                                                //1R       
      Serial.print(i);                                                    //1X
      Serial.print(" ");                                                  //1X
    }
  }
}

void loop() {                                                             //1E
  // Empty because we only want to find and print the factors once in the setup
}


                                                                          //WITHOUT EXIT - 16
                                                                          //WITH EXIT - 25


// . Variables and constants in RAM (global, static), used 28140 / 80192 bytes (35%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╠══ DATA     1496     initialized variables
// ╠══ RODATA   980      constants       
// ╚══ BSS      25664    zeroed variables
// . Instruction RAM (IRAM_ATTR, ICACHE_RAM_ATTR), used 59747 / 65536 bytes (91%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╠══ ICACHE   32768    reserved space for flash instruction cache
// ╚══ IRAM     26979    code in IRAM    
// . Code in flash (default, ICACHE_FLASH_ATTR), used 236388 / 1048576 bytes (22%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╚══ IROM     236388   code in flash   
