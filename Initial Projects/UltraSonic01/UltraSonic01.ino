#define trigPin 13    <-------------------- 2W
#define echoPin 12    <-------------------- 2W
#define led 11        <-------------------- 2W

long duration, distance; <----------------- 2W

void setup(){  <--------------------------- 1E
  Serial.begin (9600); <------------------- 1X+1W
  pinMode(trigPin, OUTPUT); <-------------- 1X+1W
  pinMode(echoPin, INPUT); <--------------- 1X+1W
  pinMode(led, OUTPUT); <------------------ 1X+1W
}

void loop(){<------------------------------ 1E
                
  digitalWrite(trigPin, LOW); <------------ 2X
  delayMicroseconds(2);        <----------- 1X
  digitalWrite(trigPin, HIGH); <----------- 2X
  delayMicroseconds(10); <----------------- 1X
  digitalWrite(trigPin, LOW);  <----------- 2X
  duration = pulseIn(echoPin, HIGH); <----- 1X+1E+1W
  distance = (duration/2) / 29.1; <-------- 1R+1W

  if (distance < 10){  <------------------- 1R
     digitalWrite(led,HIGH);  <------------ 2X
  }

else {
     digitalWrite(led,LOW); <-------------- 2X
  }

     Serial.print(distance); <------------- 2X
     Serial.println(" cm"); <-------------- 2X
     delay(500); <------------------------- 1X
}


                                          //WITH EXIT    - 41CFP

                                          //WITHOUT EXIT - 29CFP

                                          //WITHOUT EXIT AND LOCAL VARIABLES - 29CFP


// . Variables and constants in RAM (global, static), used 28176 / 80192 bytes (35%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╠══ DATA     1496     initialized variables
// ╠══ RODATA   928      constants       
// ╚══ BSS      25752    zeroed variables
// . Instruction RAM (IRAM_ATTR, ICACHE_RAM_ATTR), used 60363 / 65536 bytes (92%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╠══ ICACHE   32768    reserved space for flash instruction cache
// ╚══ IRAM     27595    code in IRAM    
// . Code in flash (default, ICACHE_FLASH_ATTR), used 236772 / 1048576 bytes (22%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╚══ IROM     236772   code in flash   
                                          
                                          