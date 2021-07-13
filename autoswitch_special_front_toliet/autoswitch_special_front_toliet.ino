int ldrPin = A1; 
int pirSensor = 9;         
int ledPin = 5; 
int relayPin = 7; 
//int state_move=2;  
int v1 = 0;
int v2 = 0;
volatile boolean state_move=false;

void setup() 
{  
  Serial.begin(9600); 
  pinMode(ldrPin,INPUT);
  pinMode(pirSensor,INPUT);  
  pinMode(relayPin,OUTPUT);     
  pinMode(ledPin,OUTPUT);
  attachInterrupt(0, pin_ISR, RISING);
             
}
void pin_ISR() {
  //digitalWrite(relayPin,LOW);
  //if(state_move){
  //  state_move=true;
    //onlamp();
 // }else{
  //  state_move=false;
  //  offlamp();
  //}
 }  

void loop() {
     v1 = analogRead(ldrPin);
     v2 = digitalRead(pirSensor);
     Serial.print("v1 light : v2 pir  = ");
     Serial.print(v1);
     Serial.print("\t");
     Serial.print(v2);
     Serial.println('\n');
     delay(500);

      if(v1>700){
        digitalWrite(relayPin,LOW);
        //state_move=true;
        
        }digitalWrite(relayPin,HIGH);
        //state_move=false;
        
}
void blink(){
            digitalWrite(ledPin, HIGH);             // sets the LED on
            delay(50);                             // waits for 150ms
            digitalWrite(ledPin, LOW);             // sets the LED on
            delay(50);  
            digitalWrite(ledPin, HIGH);             // sets the LED on
            delay(100);    
            digitalWrite(ledPin, LOW);              // sets the LED off
            delay(100);              
}

void onlamp(){
     digitalWrite(relayPin,LOW);    
     readopen();
}

void offlamp(){

     digitalWrite(relayPin,HIGH);
     digitalWrite(ledPin, LOW);              // sets the LED off
                     
     }

void readopen(){
     Serial.print("open v1 light : v2 pir  = ");
     Serial.print(v1);
     Serial.print("\t");
     Serial.print(v2);
     Serial.println('\n');
     delay(1000);
}



  


