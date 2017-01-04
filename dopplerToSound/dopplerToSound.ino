/*  Doppler radar -> sound
 *  http://radiona.org/re-making-re-mixing-history-2-3/
 *  Damir Prizmić && Goran Mahovlić
 */

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(PA0, INPUT);
  pinMode(PC13,OUTPUT);
}

void loop() {
  // read the input on analog pin PA0:
  int sensorReading = analogRead(PA0);
  // print the sensor reading so you know its range
  // map the analog input range (in this case, 2000 - 2700 from the Doppler)
  // to the output pitch range (400 - 1500Hz)
  // change the minimum and maximum input numbers below
  // depending on the range your sensor's giving:
  int thisPitch = map(sensorReading, 2000, 2700, 400, 1500);
  
  // Serial.println(sensorReading);
  if (sensorReading>3500)
    {
      int pulse = pulseIn(PA0, HIGH);
      Serial.println(pulse);
      int thisPitch =  pulse/100;
      Serial.println(thisPitch);
      tone(PC13, thisPitch,200);
    }
  else
    {
       digitalWrite(PC13,HIGH);
    }
}

