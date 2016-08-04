int hopperPin = 22;
int relayPin = 50;
unsigned long startTime;
unsigned long delayTime;
int pennyCount = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(hopperPin, INPUT);
  pinMode(relayPin, OUTPUT);
  startTime = 0;
  
}

void loop() {
 
  digitalWrite(relayPin,HIGH);

  
  while(!digitalRead(hopperPin)){
    digitalWrite(relayPin,LOW);
    
    delayTime = 200-(millis()-startTime);
    if(delayTime > 3000){
      delayTime = 0;  
    }
    Serial.print("Delay: ");
    Serial.println(delayTime);
    
    delay(delayTime);
    startTime = millis();
    pennyCount ++;
    Serial.print("Pennies: ");
    Serial.println(pennyCount);
    
  
    
    
  }
  
  

}
