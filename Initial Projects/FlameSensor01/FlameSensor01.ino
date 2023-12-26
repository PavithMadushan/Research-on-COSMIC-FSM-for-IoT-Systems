void setup()                                    //1E         //1E
{
  pinMode(2, INPUT);                            //1X         //1X+1W
  pinMode(LED_BUILTIN, OUTPUT);                 //1X         //1X+1W
  Serial.begin(9600);                           //1X         //1X+1W
}

void loop()                                     //1E         //1E
{
  if (digitalRead(2) == 0 )                     //1E         //1X+1E
  {
    digitalWrite(LED_BUILTIN, HIGH);            //1X         //2X
    Serial.println("** Fire detected!!! **");   //1X         //2X
  }
  else
  {
    digitalWrite(LED_BUILTIN, LOW);             //1X         //2X
    Serial.println("No Fire detected");         //1X         //2X
  }
  delay(100);                                   //1X         //1X
}
                                                //11CFP      //19CFP

                                                //WITHOUT EXIT- 11CFP
                                                //with exit- 19

// . Variables and constants in RAM (global, static), used 28212 / 80192 bytes (35%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╠══ DATA     1496     initialized variables
// ╠══ RODATA   964      constants       
// ╚══ BSS      25752    zeroed variables
// . Instruction RAM (IRAM_ATTR, ICACHE_RAM_ATTR), used 60331 / 65536 bytes (92%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╠══ ICACHE   32768    reserved space for flash instruction cache
// ╚══ IRAM     27563    code in IRAM    
// . Code in flash (default, ICACHE_FLASH_ATTR), used 236228 / 1048576 bytes (22%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╚══ IROM     236228   code in flash   
                                                