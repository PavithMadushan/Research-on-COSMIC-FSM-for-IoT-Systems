/*
    This sketch demonstrates how to scan WiFi networks.
    The API is almost the same as with the WiFi Shield library,
    the most obvious difference being the different file you need to include:
*/

#include <ESP8266WiFi.h>

void setup() {                                                                     //1E
  Serial.begin(115200);                                                            //1X+1W
  Serial.println(F("\nESP8266 WiFi scan example"));                                //2X

  // Set WiFi to station mode
  WiFi.mode(WIFI_STA);                                                             //1X+1W

  // Disconnect from an AP if it was previously connected
  WiFi.disconnect();                                                               //1X+1W
  delay(100);                                                                      //1X
}

void loop() {                                                                      //1E
  String ssid;                                                                     //1W
  int32_t rssi;                                                                    //1W
  uint8_t encryptionType;                                                          //1W
  uint8_t *bssid;                                                                  //1W
  int32_t channel;                                                                 //1W
  bool hidden;                                                                     //1W
  int scanResult;                                                                  //1W

  Serial.println(F("Starting WiFi scan..."));                                      //2X

  scanResult = WiFi.scanNetworks(/*async=*/false, /*hidden=*/true);                //1X+1E+1W

  if (scanResult == 0) {                                                           //1R
    Serial.println(F("No networks found"));                                        //2X
  } else if (scanResult > 0) {                                                     //1R
    Serial.printf(PSTR("%d networks found:\n"), scanResult);                       //1R+1W+2X         

    // Print unsorted scan results
    for (int8_t i = 0; i < scanResult; i++) {                                      //1W+1R+1R+1W
      WiFi.getNetworkInfo(i, ssid, encryptionType, rssi, bssid, channel, hidden);  //1X+1E

      // get extra info
      const bss_info *bssInfo = WiFi.getScanInfoByIndex(i);                        //1X+1E+2W
      String phyMode;                                                              //1W
      const char *wps = "";                                                        //2W
      if (bssInfo) {                                                               //1R
        phyMode.reserve(12);                                              
        phyMode = F("802.11");
        String slash;                                                              //1W
        if (bssInfo->phy_11b) {
          phyMode += 'b';                                                          //1R+1W
          slash = '/';                                                             //1W
        }
        if (bssInfo->phy_11g) {
          phyMode += slash + 'g';                                                  //1R+1R+1W
          slash = '/';                                                             //1W
        }
        if (bssInfo->phy_11n) {
          phyMode += slash + 'n';                                                  //1R+1R+1W
        }
        if (bssInfo->wps) {
          wps = PSTR("WPS");
        }
      }
      Serial.printf(PSTR("  %02d: [CH %02d] [%02X:%02X:%02X:%02X:%02X:%02X] %ddBm %c %c %-11s %3S %s\n"), i, channel, bssid[0], bssid[1], bssid[2], bssid[3], bssid[4], bssid[5], rssi, (encryptionType == ENC_TYPE_NONE) ? ' ' : '*', hidden ? 'H' : 'V', phyMode.c_str(), wps, ssid.c_str());
                                                                                   //1R+1W+2X
      yield();
    }
  } else {
    Serial.printf(PSTR("WiFi scan error %d"), scanResult);
  }

  // Wait a bit before scanning again
  delay(5000);
}
