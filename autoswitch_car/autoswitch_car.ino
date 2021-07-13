int ldrPin = A0;          
int ledPin = 5;                 
int relayPin = 2;                 
int v1 = 0;


void setup() 
{
  Serial.begin(9600);   
  pinMode(ldrPin,INPUT);
  pinMode(relayPin,OUTPUT);           
  pinMode(ledPin,OUTPUT);             
  digitalWrite(relayPin,HIGH); 
  digitalWrite(ledPin,HIGH);  
   
}
   
void loop(){

     v1 = analogRead(ldrPin);  
     Serial.print("read v1 =  ");
     Serial.println(v1);  
     delay(500);
   
   if(v1>800){
          onlamp();
          blink();
  }else{
          offlamp();     
          }
 delay(500);
        
 }
       
void blink(){

            digitalWrite(ledPin, HIGH);             // sets the LED on
            delay(100);                             // waits for 150ms
            digitalWrite(ledPin, LOW);             // sets the LED on
            delay(100);  
            digitalWrite(ledPin, HIGH);             // sets the LED on
            delay(100);    
            digitalWrite(ledPin, LOW);              // sets the LED off
            delay(1000);           
    
}

void onlamp(){
     digitalWrite(relayPin,LOW);    
     Serial.print("open readonlamp v1 =  ");
     Serial.println(v1);
     delay(500);
   
    }

void offlamp(){

     digitalWrite(relayPin,HIGH); 
     digitalWrite(ledPin, LOW);    
     Serial.print("close offlamp v1 :  voltage = ");
     Serial.println(v1);
     delay(500);
}
