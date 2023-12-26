#define USE_ARDUINO_INTERRUPTS true    // Set-up low-level interrupts for most acurate BPM math
#include <PulseSensorPlayground.h>     // Includes the PulseSensorPlayground Library

const int PulseWire = 0;                              //2W 
const int LED13 = 13;                                 //2W 
int Threshold = 550;                                  //2W 
                               
PulseSensorPlayground pulseSensor;                    //1W

void setup() {                                        //1E
	Serial.begin(9600);                              //1X+1W

	// Configure the PulseSensor object, by assigning our variables to it
	pulseSensor.analogInput(PulseWire);              //1X+1W
	pulseSensor.blinkOnPulse(LED13);                 //1X+1W 
	pulseSensor.setThreshold(Threshold);             //1X+1W

	// Double-check the "pulseSensor" object was created and began seeing a signal
	if (pulseSensor.begin()) {                       //1X+1W
		Serial.println("PulseSensor object created!"); //2X
	}
}

void loop() {                                         //1E
	int myBPM = pulseSensor.getBeatsPerMinute();      //1X+1E+2W

	if (pulseSensor.sawStartOfBeat()) {               //1X+1E
		Serial.println("♥  A HeartBeat Happened ! "); //2X 
		Serial.print("BPM: ");                        //2X 
		Serial.println(myBPM);                        //2X 
		}

	delay(20);                                        //1X
}

//With FC Exits - 34CFP
//Without       - 23CFP



// . Variables and constants in RAM (global, static), used 28272 / 80192 bytes (35%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╠══ DATA     1508     initialized variables
// ╠══ RODATA   988      constants       
// ╚══ BSS      25776    zeroed variables
// . Instruction RAM (IRAM_ATTR, ICACHE_RAM_ATTR), used 61195 / 65536 bytes (93%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╠══ ICACHE   32768    reserved space for flash instruction cache
// ╚══ IRAM     28427    code in IRAM    
// . Code in flash (default, ICACHE_FLASH_ATTR), used 238728 / 1048576 bytes (22%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╚══ IROM     238728   code in flash   
