// Henry's Bench
// Capacitive Touch Sensor Tutorial

#define ctsPin 2                         //2W

int ledPin = 13;                         //2W

void setup()                             //1E

{
  Serial.begin(9600);                    //2X
  pinMode(ledPin, OUTPUT);               //2X
  pinMode(ctsPin, INPUT);                //2X
}

void loop()                              //1E

{

  int ctsValue = digitalRead(ctsPin);    //1X+1E+1W

  if (ctsValue == HIGH)                  //1R

  {
    digitalWrite(ledPin, HIGH);          //2X
    Serial.println("TOUCHED");           //2X

  }

  else {

    digitalWrite(ledPin, LOW);           //2X
    Serial.println("not touched");       //2X
  }

  delay(500);                            //1X
}

//With FC Exits - 25CFP
//Without       - 17CFP



// . Variables and constants in RAM (global, static), used 28188 / 80192 bytes (35%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╠══ DATA     1500     initialized variables
// ╠══ RODATA   944      constants       
// ╚══ BSS      25744    zeroed variables
// . Instruction RAM (IRAM_ATTR, ICACHE_RAM_ATTR), used 60331 / 65536 bytes (92%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╠══ ICACHE   32768    reserved space for flash instruction cache
// ╚══ IRAM     27563    code in IRAM    
// . Code in flash (default, ICACHE_FLASH_ATTR), used 236244 / 1048576 bytes (22%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╚══ IROM     236244   code in flash   
