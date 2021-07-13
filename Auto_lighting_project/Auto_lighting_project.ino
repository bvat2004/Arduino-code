int photocellPin = A0;           //photoresistor module attach to A0
int ledPin = 2;                 //pin 13 built-in led
int relayPin = 8;                  //relay module attach to digital 8
int outputValue = 0;


void setup() 
{
  pinMode(photocellPin,INPUT);          
  pinMode(relayPin,OUTPUT);           //set relayPin as OUTPUT
  pinMode(ledPin,OUTPUT);             //set ledPin as OUTPUT
  Serial.begin(9600);                 //initialize the serial communication as 9600bps
    
}
   
void loop() 
{
     
     outputValue = analogRead(photocellPin);       //read the value of photoresistor
     Serial.println(outputValue);  
      
      if  (outputValue <200 && outputValue <500){
         
          digitalWrite(relayPin,LOW);    
          Serial.println("open");
          digitalWrite(ledPin,HIGH);                  //turn on the led
          delay(2000);
          digitalWrite(ledPin,LOW);                  //turn on the led
          delay(2000);
      }
    
      else{
      
        digitalWrite(relayPin,HIGH); 
        Serial.println("close");
        digitalWrite(ledPin,LOW);                  //turn on the led
        //delay(1000);
      }
              
     delay(500);                                  //delay 1s
}
/*************************************************/


