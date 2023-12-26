/* Arduino pins where the LED is attached*/

#define LED_1 2                                //2W
#define LED_2 3                                //2W
#define LED_3 4                                //2W
#define LED_4 5                                //2W
#define LED_5 6                                //2W
#define sensorPin A0                           //2W  
// Analog input pin that the Sensor is attached to

/* boolean variables to hold the status of the pins*/

bool ledPin1Status;                            //1W
bool ledPin2Status;                            //1W
bool ledPin3Status;                            //1W
bool ledPin4Status;                            //1W
bool ledPin5Status;                            //1W

void setup() {                                 //1E

  pinMode(LED_1, OUTPUT);                      //1X+1W
  pinMode(LED_2, OUTPUT);                      //1X+1W
  pinMode(LED_3, OUTPUT);                      //1X+1W
  pinMode(LED_4, OUTPUT);                      //1X+1W
  pinMode(LED_5, OUTPUT);                      //1X+1W
  pinMode(sensorPin, INPUT);                   //1X+1W
  Serial.begin(9600);                          //1X+1W
}

void loop() {                                  //1E
  int sensorValue = analogRead(sensorPin);     //1X+1E+2W

  Serial.println(sensorValue);                 //2X+1R

  if (sensorValue > 555)                       //1R
    ledPin1Status = 1;                         //1W

  if (sensorValue > 558)                       //1R
    ledPin2Status = 1;                         //1W

  if (sensorValue > 560)                       //1R
    ledPin3Status = 1;                         //1W

  if (sensorValue > 562)                       //1R
    ledPin4Status = 1;                         //1W

  if (sensorValue > 564)                       //1R
    ledPin5Status = 1;                         //1W

  if (ledPin1Status == 1 || ledPin2Status == 1 || ledPin3Status == 1 || ledPin4Status == 1 || ledPin5Status == 1)
  {                                            //5R
    if (sensorValue > 555 || sensorValue < 537)//2R
      digitalWrite(LED_1, HIGH);               //2X

    if (sensorValue > 558 || sensorValue < 534)//2R
      digitalWrite(LED_2, HIGH);               //2X

    if (sensorValue > 560 || sensorValue < 534)//2R
      digitalWrite(LED_3, HIGH);               //2X

    if (sensorValue > 562 || sensorValue < 531)//2R
      digitalWrite(LED_3, HIGH);               //2X

    if (sensorValue > 564 || sensorValue < 528)//2R
      digitalWrite(LED_4, HIGH);               //2X

    if (sensorValue > 568 || sensorValue < 525)//2R
      digitalWrite(LED_5, HIGH);               //2X

    delay(200);                                //1X

    ledPin5Status = 0;                         //1W
    ledPin4Status = 0;                         //1W
    ledPin3Status = 0;                         //1W
    ledPin2Status = 0;                         //1W
    ledPin1Status = 0;                         //1W
  }

  digitalWrite(LED_1, LOW);                    //2X
  digitalWrite(LED_2, LOW);                    //2X
  digitalWrite(LED_3, LOW);                    //2X
  digitalWrite(LED_4, LOW);                    //2X
  digitalWrite(LED_5, LOW);                    //2X
}

//With FC Exits - 95CFP
//Without       - CFP


// . Variables and constants in RAM (global, static), used 28172 / 80192 bytes (35%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╠══ DATA     1496     initialized variables
// ╠══ RODATA   924      constants       
// ╚══ BSS      25752    zeroed variables
// . Instruction RAM (IRAM_ATTR, ICACHE_RAM_ATTR), used 60331 / 65536 bytes (92%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╠══ ICACHE   32768    reserved space for flash instruction cache
// ╚══ IRAM     27563    code in IRAM    
// . Code in flash (default, ICACHE_FLASH_ATTR), used 236820 / 1048576 bytes (22%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╚══ IROM     236820   code in flash   
