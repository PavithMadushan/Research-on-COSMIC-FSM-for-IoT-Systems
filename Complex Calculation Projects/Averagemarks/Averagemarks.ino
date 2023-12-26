int mark1;                                                //1W
int mark2;                                                //1W
int mark3;                                                //1W
float average;                                            //1W
float percentage;                                         //1W

void setup() {                                            //1E
  Serial.begin(9600);                                     //1W
  while (!Serial) {                                       //1w
    ; // wait for serial port to connect
  }

  Serial.println("Enter the marks for three subjects:");  //1X
  while (!Serial.available()) {                           //1E
    ; // wait for user input
  }
  mark1 = Serial.parseInt();                              //1E
  while (!Serial.available()) {                           //1E
    ; // wait for user input
  }
  mark2 = Serial.parseInt();                              //1E
  while (!Serial.available()) {                           //1E
    ; // wait for user input
  }
  mark3 = Serial.parseInt();                              //1E

  average = (mark1 + mark2 + mark3) / 3.0;                //3R+1W
  percentage = (mark1 + mark2 + mark3) / 3.0;             //3R+1W

  Serial.print("Average mark is: ");                      //1X
  Serial.println(average);                                //1X
  Serial.print("Percentage mark is: ");                   //1X
  Serial.println(percentage);                             //1X
}

void loop() {                                             //1E
  // Empty because we only want to calculate the average and percentage marks once in the setup
}


//without exits - 28cfp
//with exits    - 40cfp







// . Variables and constants in RAM (global, static), used 28176 / 80192 bytes (35%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╠══ DATA     1496     initialized variables
// ╠══ RODATA   1000     constants       
// ╚══ BSS      25680    zeroed variables
// . Instruction RAM (IRAM_ATTR, ICACHE_RAM_ATTR), used 59747 / 65536 bytes (91%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╠══ ICACHE   32768    reserved space for flash instruction cache
// ╚══ IRAM     26979    code in IRAM    
// . Code in flash (default, ICACHE_FLASH_ATTR), used 237380 / 1048576 bytes (22%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╚══ IROM     237380   code in flash   

