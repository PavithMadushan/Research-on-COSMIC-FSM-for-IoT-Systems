// Arduino IR Sensor Code
int IRSensor = 9;  // connect ir sensor module to ArduinO   //2W
int LED = 13;  // conect LED to Arduino pin 13              //2W

void setup()                                                //1E

{
  Serial.begin(115200);  // Init Serila at 115200 Baud      //2X
  Serial.println("Serial Working");  // Test                //2X
  pinMode(IRSensor, INPUT);  // IR Sensor pin INPUT         //1X+1W
  pinMode(LED, OUTPUT);  // LED Pin Output                  //1X+1W
}


  void loop(){                                              //1E

  int sensorStatus = digitalRead(IRSensor);  // Set         //1X+1E+1W
if (sensorStatus == 1)  // Check if the pin high or not     //1R
{
// if the pin is high turn off the onboard Led

    digitalWrite(LED, LOW);  // LED LOW                     //2X
    Serial.println("Motion Ended!");//print Motion Detected!//2X
    
  }
  else
{

//else turn on the onboard LED
    digitalWrite(LED, HIGH);  // LED High                   //2X
    Serial.println("Motion Detected!");  // print Motion    //2X
    
  }
}

//With FC Exits - 26CFP
//Without       - 17CFP



// . Variables and constants in RAM (global, static), used 28196 / 80192 bytes (35%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╠══ DATA     1504     initialized variables
// ╠══ RODATA   972      constants       
// ╚══ BSS      25720    zeroed variables
// . Instruction RAM (IRAM_ATTR, ICACHE_RAM_ATTR), used 60331 / 65536 bytes (92%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╠══ ICACHE   32768    reserved space for flash instruction cache
// ╚══ IRAM     27563    code in IRAM    
// . Code in flash (default, ICACHE_FLASH_ATTR), used 235876 / 1048576 bytes (22%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╚══ IROM     235876   code in flash   
