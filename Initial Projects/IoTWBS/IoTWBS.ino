#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>

#define FIREBASE_HOST "tronicslab-82cba-default-rtdb.firebaseio.com"      //1W
#define FIREBASE_AUTH "ScmKXsjG8n2kppEaBv49L8kmAxjaLanHRtHZAqZN"          //1W
// #define WIFI_SSID "Moto"
// #define WIFI_PASSWORD "12345678"

FirebaseData firebaseData;                                                //1W
String path_1 = "/AquaApp/Rates";                                         //2W
String path_2 = "/AquaApp/Usages";                                        //2W
// String path_3 = "/AquaApp/Leakages";
// String path_4 = "/AquaApp/Status";

unsigned long count = 0;                                                  //2W


#define RELAY_PIN D3                                                      //2W

const char* ssid="Dialog 4G";                                             //2W
const char* password = "4472B4D1";                                        //2W

String command;                                                           //1W

int flowPin1 = D7;                                                        //2W
int flowPin2 = D2;                                                        //2W

// WF 01
float mLMeasured1;                                                        //1W
float totalmL1 = 0;                                                       //2W
volatile int pulses1 = 0;                                                 //2W
unsigned int totalPulses1 = 0;                                            //2W
unsigned long lastMillis= 0;                                              //2W

// WF 02
float mLMeasured2;                                                        //1W
float totalmL2 = 0;                                                       //2W
volatile int pulses2 = 0;                                                 //2W
unsigned int totalPulses2 = 0;                                            //2W
//unsigned long lastMillis2 = 0;

void setup() {                                                            //1E

  pinMode(RELAY_PIN, OUTPUT);                                             //1X
  
  Serial.begin(9600);                                                     //1X
  
  pinMode(flowPin1, INPUT_PULLUP);                                        //1X
    attachInterrupt(digitalPinToInterrupt(flowPin1), Flow1, FALLING);     //2X

  pinMode(flowPin2, INPUT_PULLUP);                                        //1X
    attachInterrupt(digitalPinToInterrupt(flowPin2), Flow2, FALLING);     //2X

    Serial.println("\n");                                                 //1X
  
    // Wifi Setup
    Serial.print("Wifi connecting to ");                                  //1X
    Serial.println( ssid );                                               //1X

  WiFi.begin(ssid,password);                                              //1X

  Serial.println();                                                       //1X
  Serial.print("Connecting");                                             //1X

  while( WiFi.status() != WL_CONNECTED ){                                 //1E
      delay(500);                                                         //1X
      Serial.print("..");   }                                             //1X


      Serial.println();                                                   //1X

 
  Serial.println("Wifi Connected Success!");                              //1X
  Serial.print("NodeMCU IP Address : ");                                  //1X
  Serial.println(WiFi.localIP() );                                        //2X


  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);                           //1X
  Firebase.reconnectWiFi(true);                                           //1X
  firebaseData.setBSSLBufferSize(1024, 1024);                             //1X
  firebaseData.setResponseSize(1024);                                     //1X

  if (!Firebase.beginStream(firebaseData, path_1)) {                      //1X
    Serial.println("Can't begin stream connection...");                   //1X
  }else{ 
    Firebase.beginStream(firebaseData, path_2);                           //1X
  }

 // Serial.println("\n\n\n\n\n\n");
   
  Serial.println("                                         SMART WATER MANAGEMENT SYSTEM                           ");   //1X
  
  Serial.println("              ---------------------------------------------------------------------------        ");   //1X
}

void loop() {                                                             //1E

command = Serial.readStringUntil('\n');                                   //1E,1W

  if (command=="ON"){                                                     //1R
    Serial.print("Command: ");                                            //1X
    Serial.println(command);                                              //1X

     digitalWrite(RELAY_PIN, HIGH); // open valve                         //1X
  

  while(!(Serial.available())){                                           //1E
     if( millis() - lastMillis >= 5000 ) {                                //1X,1R
      
    detachInterrupt(digitalPinToInterrupt(flowPin1));                     //2X
    detachInterrupt(digitalPinToInterrupt(flowPin2));                     //2X
    
    lastMillis = millis();                                                //1X,1W
    /*
     * flow rate is 330 pulses per liter
     * convert to mL per pulse (1000/330) = 3.03
     * multiply pulses by mL per pulse to get usage
     */
  
    mLMeasured1 = (pulses1 * 3.03);                                       //1R,1W
    totalmL1 += mLMeasured1;                                              //1R,1W
    totalPulses1 += pulses1;                                              //1R,1W

    mLMeasured2 = (pulses2 * 3.03);                                       //1R,1W                            
    totalmL2 += mLMeasured2;                                              //1R,1W
    totalPulses2 += pulses2;                                              //1R,1W
    
  Serial.println("                   === WATER FLOW SENSOR-01 ===         === WATER FLOW SENSOR-02 ===             ");    //1X
  Serial.print("                      Flow Rate (mL/Hr): ");                                                              //1X
  Serial.print(mLMeasured1);                                                                                              //1X
  
  if (Firebase.setString(firebaseData, path_1 + "/flow_Rate_1", String(mLMeasured1))) {                                   //2R,1X
    Firebase.setString(firebaseData, path_1 + "/flow_Rate_2", String(mLMeasured2));
    Firebase.setString(firebaseData, path_2 + "/usage_1", String(totalmL1));
    Firebase.setString(firebaseData, path_2 + "/usage_2", String(totalmL2));
    // Firebase.setString(firebaseData, path_3 + "/leakage", "0");
    // Firebase.setString(firebaseData, path_4 + "/on_off", "ON");
    //Serial.print("data sent into firebase , data : ");
    //Serial.println(data);
  } else {
    //Serial.println("data sending faild... ");
  }

  Serial.print("                Flow Rate (mL/Hr): "); 
  Serial.println(mLMeasured2);

  Serial.print("                      Total Usage (mL) : ");
  Serial.print(totalmL1);

  Serial.print("                Total Usage (mL) : ");
  Serial.println(totalmL2);

  Serial.println("\n");
      
   
    if(0.9*mLMeasured1 > mLMeasured2){
      //Serial.println("***");
      Serial.println("                       Leak");
      //Serial.println("***");
      }

      else{
      //Serial.println("***");
      Serial.println("                       No Leak");
      //Serial.println("***");
      }
      Serial.println("\n");

  Serial.println("              ---------------------------------------------------------------------------        ");
    
    
    
    pulses1 = 0;
    attachInterrupt(digitalPinToInterrupt(flowPin1), Flow1, FALLING); 

    pulses2 = 0;
    attachInterrupt(digitalPinToInterrupt(flowPin2), Flow2, FALLING);
  }}

  // Serial.print("Command: ");
  //Serial.println(command);
  }

  delay(100);

  
}


ICACHE_RAM_ATTR void Flow1(){
    pulses1++; //Every time this function is called, increment "pulses" by 1
}

ICACHE_RAM_ATTR void Flow2(){
    pulses2++; //Every time this function is called, increment "pulses" by 1
}
