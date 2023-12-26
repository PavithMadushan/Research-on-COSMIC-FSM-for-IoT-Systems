int length; // Variable to store the length of the rectangle                 //1W
int breadth; // Variable to store the breadth of the rectangle               //1W
int area; // Variable to store the area of the rectangle                     //1W
int perimeter; // Variable to store the perimeter of the rectangle           //1W

void setup() {                                                               //1E
  Serial.begin(9600);                                                        //1W
  while (!Serial) {                                                          //1W
    ; // wait for serial port to connect
  }
  
  Serial.println("Enter the length of the rectangle:");                      //1X
  while (!Serial.available()) {                                              //1E
    ; // wait for user input 
  }
  length = Serial.parseInt(); // Read the length from the Serial monitor     //1E+1W
  
  Serial.println("Enter the breadth of the rectangle:");                     //1X
  while (!Serial.available()) {                                              //1E
    ; // wait for user input
  }
  breadth = Serial.parseInt(); // Read the breadth from the Serial monitor   //1E+1W
  
  area = length * breadth; // Calculate the area                             //2R+1W
  perimeter = 2 * (length + breadth); // Calculate the perimeter             //2R+1W
  
  Serial.print("Area of the rectangle is: ");                                //1X
  Serial.println(area);                                                      //1X
  Serial.print("Perimeter of the rectangle is: ");                           //1X
  Serial.println(perimeter);                                                 //1X
}

void loop() {                                                                //1E
  // Empty because we only want to calculate the area and perimeter once in the setup
}

                                                                             //WITHOUT EXIT - 26
                                                                             //WITH EXIT - 37


// . Variables and constants in RAM (global, static), used 28216 / 80192 bytes (35%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╠══ DATA     1496     initialized variables
// ╠══ RODATA   1056     constants       
// ╚══ BSS      25664    zeroed variables
// . Instruction RAM (IRAM_ATTR, ICACHE_RAM_ATTR), used 59747 / 65536 bytes (91%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╠══ ICACHE   32768    reserved space for flash instruction cache
// ╚══ IRAM     26979    code in IRAM    
// . Code in flash (default, ICACHE_FLASH_ATTR), used 236436 / 1048576 bytes (22%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╚══ IROM     236436   code in flash   
