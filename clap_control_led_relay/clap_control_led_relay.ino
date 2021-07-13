int sound_sensor = 3;
int relay = 7;
int ledPin = 5;

int clap = 0;
long detection_range_start = 0;
long detection_range = 0;
boolean status_lights = false;
 
void setup() {

  pinMode(sound_sensor, INPUT);
  pinMode(relay, OUTPUT);
  pinMode(ledPin,OUTPUT);
  Serial.begin(9600);
  digitalWrite(relay, HIGH);
  digitalWrite(ledPin, LOW);
}
 
void loop() {
  int status_sensor = digitalRead(sound_sensor);
  Serial.print("status sensor  = ");
  Serial.println(status_sensor);
  
  if (status_sensor == 0)
  {
    if (clap == 0)                                         //no clab sound
    {
      detection_range_start = detection_range = millis();
      clap++;
Serial.print("detection range start  = ");
Serial.println(detection_range_start);
delay(1000);
      
    }
    else if (clap > 0 && millis()-detection_range >= 50)    //get clab sound
    {
      detection_range = millis();
      clap++;
    }
  }
  if (millis()-detection_range_start >= 400)
  {
    if (clap == 2)
    {
      if (!status_lights)
        {
          status_lights = true;
          digitalWrite(relay, HIGH);
          digitalWrite(ledPin, LOW);
          Serial.print("led close");
    delay(1000); 
         
        }
        else if (status_lights)
        {
          status_lights = false;
          digitalWrite(relay, LOW);
          digitalWrite(ledPin, HIGH);
          Serial.print("led open");
   delay(1000);       
        }
    }
    clap = 0;
  }
}
