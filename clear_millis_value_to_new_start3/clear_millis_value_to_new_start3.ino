extern volatile unsigned long timer0_millis;
unsigned long previousMillis = 0;
int ledState = LOW;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("System Start");
}

void loop() {
  //callibrate();
  timer1();
  timer2();
  
}

void timer1(){
  
  unsigned long timer1 = millis();
  Serial.println(timer1); 
  
  if(timer1-previousMillis>=1000){
    previousMillis = timer1;
    
    if(ledState==LOW){
      ledState = HIGH;
      
    } else{
      ledState = LOW;
    }
      digitalWrite(LED_BUILTIN, ledState);
    }
  
   if(m>5000){
     timer0_millis = 0;
   }      
 }
void timer2(){
  
  unsigned long timer2 = millis();
  Serial.println(timer2); 
  
  if(timer2-previousMillis>=1000){
    previousMillis = timer2;
    
    if(ledState==LOW){
      ledState = HIGH;
      
    } else{
      ledState = LOW;
    }
      digitalWrite(LED_BUILTIN, ledState);
    }
  
   if(m>5000){
     timer0_millis = 0;
   }      
 }  
