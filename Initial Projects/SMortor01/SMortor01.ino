#include <Servo.h>                         
Servo myservo;                            //1W
int pos = 0;                              //2W
  
void setup() {                            //1E
  myservo.attach(26);                     //1X
}

void loop() {                             //1E
  for (pos = 0; pos <= 180; pos += 1) {   //1E,1W,1R,1W
    myservo.write(pos);                   //1X
    delay(15);                            //1X
  }
  for (pos = 180; pos >= 0; pos -= 1) {   //1E,1W,1R,1W
    myservo.write(pos);                   //1X
    delay(15);                            //1X
  }
}
                                          //18CFP