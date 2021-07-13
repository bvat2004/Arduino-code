int photocellPin = A1;
int pirSensor= 9;         
int ledPin = 5;                 
int relayPin = 7;                 
int v1=0;
int val=0;
  

void setup() 
{
  pinMode(photocellPin,INPUT);
  pinMode(pirSensor,INPUT);
  pinMode(relayPin,OUTPUT);           
  pinMode(ledPin,OUTPUT);             
  Serial.begin(9600);                 //initialize the serial communication as 9600bps
  digitalWrite(relayPin,HIGH); 
  digitalWrite(ledPin,LOW);  
}
   
void loop(){

     v1 = analogRead(photocellPin);  
    
     Serial.print("read v1 v2 =  ");
     Serial.print(v1);
    delay(1000);
  
  if(val==1){
        
          while(v1<400){onlamp();blink();}offlamp();
     }else{offlamp();}

     delay(500);
}       

void blink(){
     
            digitalWrite(ledPin, HIGH);             // sets the LED on
            delay(50);                             // waits for 150ms
            digitalWrite(ledPin, LOW);             // sets the LED on
            delay(50);  
            digitalWrite(ledPin, HIGH);             // sets the LED on
            delay(100);    
            digitalWrite(ledPin, LOW);              // sets the LED off
            delay(10000);                             // waits for 100ms         
}

void onlamp(){
   
     digitalWrite(relayPin,LOW);    
     Serial.print("open onlamp v1 =  ");
     Serial.println(v1);
      
    }

void offlamp(){

     digitalWrite(relayPin,HIGH);    
     Serial.print("close offlamp v1= ");
     Serial.println(v1);
    }

//.................................................
