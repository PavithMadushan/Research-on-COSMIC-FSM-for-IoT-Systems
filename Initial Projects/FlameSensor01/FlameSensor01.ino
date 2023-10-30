void setup()                                    //1E
{
  pinMode(2, INPUT);                            //1X
  pinMode(LED_BUILTIN, OUTPUT);                 //1X
  Serial.begin(9600);                           //1X
}

void loop()                                     //1E
{
  if (digitalRead(2) == 0 )                     //1E
  {
    digitalWrite(LED_BUILTIN, HIGH);            //1X
    Serial.println("** Fire detected!!! **");   //1X
  }
  else
  {
    digitalWrite(LED_BUILTIN, LOW);             //1X
    Serial.println("No Fire detected");         //1X
  }
  delay(100);                                   //1X
}
                                                //11CFP