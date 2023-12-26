#include <ESP8266WiFi.h>

// Set GPIOs for LED and reedswitch
const int reedSwitch = 4;                                  //2W
const int led = 2; //optional                              //2W

// Detects whenever the door changed state
bool changeState = false;                                  //2W

// Holds reedswitch state (1=opened, 0=close)
bool state;                                                //1W
String doorState;                                          //1W
 
// Auxiliary variables 
unsigned long previousMillis = 0;                          //2W
const long interval = 1500;                                //2W

const char* ssid = "REPLACE_WITH_YOUR_SSID";               //2W
const char* password = "REPLACE_WITH_YOUR_PASSWORD";       //2W
const char* host = "maker.ifttt.com";                      //2W
const char* apiKey = "REPLACE_WITH_YOUR_IFTTT_API_KEY";    //2W

// Runs whenever the reedswitch changes state
ICACHE_RAM_ATTR void changeDoorStatus() {                  
  Serial.println("State changed");                         //2X
  changeState = true;                                      //1W
}

void setup() {                                             //1E
  // Serial port for debugging purposes
  Serial.begin(115200);                                    //2X

  // Read the current door state
  pinMode(reedSwitch, INPUT_PULLUP);                       //1R+2X
  state = digitalRead(reedSwitch);                         //1R+1X+1E+1W

  // Set LED state to match door state
  pinMode(led, OUTPUT);                                    //1R+1X+1W
  digitalWrite(led, state);                                //2R+2X
  
  // Set the reedswitch pin as interrupt
  attachInterrupt(digitalPinToInterrupt(reedSwitch),       //2R+2X+2W
  changeDoorStatus, CHANGE);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);                              //2R+1X+1W
  while (WiFi.status() != WL_CONNECTED) {                  //1X+1R
    delay(500);                                            //1X
    Serial.print(".");                                     //2X
  }
  Serial.println("");                                      //2X
  Serial.println("WiFi connected");                        //2X
}

void loop() {                                              //1E
  if (changeState){                                        //1R
    unsigned long currentMillis = millis();                //1X+1E+2W
    if(currentMillis - previousMillis >= interval) {       //3R
      previousMillis = currentMillis;                      //1R+1W
      //If a state has occured,invert the current door state   
      state = !state;                                      //1R+1W
      if(state) {                                          //1R
        doorState = "closed";                              //1W
      }
      else{
        doorState = "open";                                //1W
      }
      digitalWrite(led, state);                            //2R+2X
      changeState = false;                                 //1W
      Serial.println(state);                               //1R+2X
      Serial.println(doorState);                           //1R+2X
        
      //Send email
      Serial.print("connecting to ");                      //2X
      Serial.println(host);                                //1R+2X
      WiFiClient client;                                   //1W
      const int httpPort = 80;                             //2W 
      if (!client.connect(host, httpPort)) {               //2R+1X+1R
        Serial.println("connection failed");               //2X
        return;
      }
    
      String url = "/trigger/door_status/with/key/";       //2W
      url += apiKey;                                       //1R+1W
          
      Serial.print("Requesting URL: ");                    //2X
      Serial.println(url);                                 //1R+2X
      client.print(String("POST ") + url + " HTTP/1.1\r\n"+//1R+3X+1E
               "Host: " + host + "\r\n" +                  //1R
               "Content-Type: application/x-www-form-urlencoded\r\n" + 
               "Content-Length: 13\r\n\r\n" +
               "value1=" + doorState + "\r\n");            //1R
  }
}
}
