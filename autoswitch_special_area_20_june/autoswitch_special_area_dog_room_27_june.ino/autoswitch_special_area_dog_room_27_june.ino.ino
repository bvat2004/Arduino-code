int photocellPin = A0;          
int pirSensor1 = 9;
int pirSensor2 = 11;
//int ledPin = 5;        no connect         
int relayPin = 7;                  
int Val1 = 0;   
int Val2 = 0; 
int sensor_Val = 0;           //read photocell
int Mapped;


void setup() 
{
  pinMode(photocellPin,INPUT);
  pinMode(pirSensor1,INPUT);  
  pinMode(pirSensor2,INPUT);        
  pinMode(relayPin,OUTPUT);           
  //pinMode(ledPin,OUTPUT);             no connect
  Serial.begin(9600);                 //initialize the serial communication as 9600bps
  lightclose();  
}
   
void loop() 
{
sensor_Val = analogRead(A1);                         //collect value photo data
Serial.print("Original value = ");
Serial.println(sensor_Val);


Mapped = map(sensor_Val, 0, 1023,0,255);
Serial.print("Mapped value = ");
Serial.println(Mapped);
Serial.println(" ");



Val1=digitalRead(pirSensor1);
Val2=digitalRead(pirSensor2);
Serial.print("val pirsensor1 = ");
Serial.println(Val1);
Serial.print("val pirsensor2 = ");
Serial.println(Val2);
Serial.println(" ");
delay(1000);


  if (Val1 == 1 || Val2 == 1){
    if(Mapped <= 235 && Mapped < 270){
    lightopen();
  }
}else
lightclose();

}

void  lightopen(){
  digitalWrite(relayPin,LOW); 
  Serial.print("open light pirsensor1 value =  ");
  Serial.println(Val1);
  Serial.print("open light pirsensor2 value =  ");
  Serial.println(Val2);
  Serial.print("Mapped value =  ");
  Serial.println(Mapped);
  Serial.println(" ");
  delay(500);
  
}
     
void  lightclose(){
  digitalWrite(relayPin,HIGH); 
  
  Serial.print("close light pirsensor1 value =  ");
  Serial.println(Val1);
  Serial.print("open light pirsensor2 value =  ");
  Serial.println(Val2);

  Serial.print("Mapped  value =  ");
  Serial.println(Mapped);
  Serial.println(" ");

  delay(500);     
}


