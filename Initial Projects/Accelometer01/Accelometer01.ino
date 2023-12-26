//TECHATRONIC.COM   
 int m=0, n=0;                  //4W
 void setup()                   //1E
 {  
   pinMode(A0, INPUT);          //1X+1W
   pinMode(A0, INPUT);          //1X+1W
   pinMode(4,OUTPUT);           //1X+1W            
   pinMode(5,OUTPUT);           //1X+1W 
   pinMode(6,OUTPUT);           //1X+1W  
   pinMode(7,OUTPUT);           //1X+1W 
   Serial.begin(9600);          //2X 
 }  
 void loop()                    //1E
 {  
   m = analogRead(A0);          //1E+1W
   n = analogRead(A0);          //1E+1W 
   Serial.println(m);           //2X
   delay(100);                  //1X
   Serial.println(n);           //2X
   delay(100);                  //1X

  if(n>=375){                   //1R

     digitalWrite(4,HIGH);      //2X
     Serial.println("F");       //2X
   }  
   else if(n<=320)              //1R
   {   
     digitalWrite(5,HIGH);      //2X
     Serial.println("B");       //2X
   }   
  else if(m>=375)               //1R
   {  
     digitalWrite(6,HIGH);      //2X
     Serial.println("R");       //2X
   }  
  else if(m<=315)               //1R
   {  
    digitalWrite(7,HIGH);       //2X
    Serial.println("L");        //2X
   }  
   else  
   {  
    digitalWrite(4, LOW);       //2X
    digitalWrite(5, LOW);       //2X  
    digitalWrite(6, LOW);       //2X  
    digitalWrite(7, LOW);       //2X  
    Serial.println("N");        //2X 
   }  
   }

   //with FC exits    - 60 CFP
   //without FC exits - 36 CFP

//    . Variables and constants in RAM (global, static), used 28176 / 80192 bytes (35%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╠══ DATA     1496     initialized variables
// ╠══ RODATA   928      constants       
// ╚══ BSS      25752    zeroed variables
// . Instruction RAM (IRAM_ATTR, ICACHE_RAM_ATTR), used 60331 / 65536 bytes (92%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╠══ ICACHE   32768    reserved space for flash instruction cache
// ╚══ IRAM     27563    code in IRAM    
// . Code in flash (default, ICACHE_FLASH_ATTR), used 236724 / 1048576 bytes (22%)
// ║   SEGMENT  BYTES    DESCRIPTION
// ╚══ IROM     236724   code in flash   
