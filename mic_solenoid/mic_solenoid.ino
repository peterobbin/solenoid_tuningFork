#define soloPin 3
#define micPin 0


long previousHitTime = 0;
long previousWaitTime = 0;
long hitInterval = 90;
long waitInterval = 1000;
unsigned long currentTime = 0;
boolean hitting = false;



void setup(){
  pinMode(soloPin, OUTPUT);
  Serial.begin(9600);

}


void loop(){

  currentTime = millis();





  // timer setup for hit 
  // using delay() will not grant us multitasking 
  if (currentTime - previousHitTime < hitInterval && hitting == true){
    digitalWrite(soloPin, HIGH);
    Serial.println("hit");
    Serial.println(currentTime - previousHitTime);
  }else{
    hitting = false;
    previousHitTime = currentTime;
  }
  
  // timer setup for wait
  if (currentTime - previousWaitTime < waitInterval && hitting == false){
    digitalWrite(soloPin, LOW);
    Serial.println("wait");
    Serial.println(currentTime - previousWaitTime);
  }else{
    hitting = true;
    previousWaitTime = currentTime;
  }
  
  
  
  
  delay(10);






}


