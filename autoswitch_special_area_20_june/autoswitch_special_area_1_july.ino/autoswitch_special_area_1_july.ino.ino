int photocellPin = A1;          
int pirSensor = 9;
int ledPin = 5;                 
int relayPin = 7;                  
int Val = 0;   
int sensor_Val = 0;           //read photocell
//int Mapped;


void setup() 
{
  pinMode(photocellPin,INPUT);
  pinMode(pirSensor,INPUT);        
  pinMode(relayPin,OUTPUT);           
  pinMode(ledPin,OUTPUT);             
  Serial.begin(9600);                 //initialize the serial communication as 9600bps
  lightclose();  
}
   
void loop() 
{
sensor_Val = (analogRead(A1)/4); ;                         //collect value photo data
Serial.print("Original value = ");
Serial.println(sensor_Val);

Val=digitalRead(pirSensor);
Serial.print("val pirsensor = ");
Serial.println(Val);
Serial.println(" ");
delay(1000);


  if (Val == 1){
    if(sensor_Val <= 28 && sensor_Val < 70){
    lightopen();
  }
}else
lightclose();

}

void  lightopen(){
  digitalWrite(relayPin,HIGH); 
   
  Serial.print("open light pirsensor value =  ");
  Serial.println(Val);
  
  Serial.print("sensor_Val =  ");
  Serial.println(sensor_Val);
  Serial.println(" ");
  delay(500);
  blink();
}
     
void  lightclose(){
  digitalWrite(relayPin,LOW); 
  
  Serial.print("close light pirsensor value =  ");
  Serial.println(Val);

  Serial.print("sensor_Val =  ");
  Serial.println(sensor_Val);
  Serial.println(" ");

  delay(500);     
}

void blink(){
   digitalWrite(ledPin,HIGH);  
   delay(100);
   digitalWrite(ledPin,LOW);  
   delay(100);
    digitalWrite(ledPin,HIGH);  
   delay(100);
   digitalWrite(ledPin,LOW);  
   delay(5000); 
}
