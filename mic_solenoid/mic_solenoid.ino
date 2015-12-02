#define soloPin 3
#define micPin 0


long previousHitTime = 0;
long previousWaitTime = 0;
long hitInterval = 90;
long waitInterval = 1000;
unsigned long currentTime = 0;
boolean hitting = false;

float volumeHighLimit = 390;
float volumeLowLimit = 250;



void setup(){
  pinMode(soloPin, OUTPUT);
  pinMode(micPin, INPUT);
  Serial.begin(9600);

}


void loop(){

  currentTime = millis();

  if (trigger() == true){
    solenoid();
  }

}


boolean trigger(){
  // getting volume
  // volume is normally 300ish, when touched it will go higher than 350 or lower than 300
  float volume = analogRead(micPin);
  Serial.println(volume);
  if (volume < volumeLowLimit || volume > volumeHighLimit){
    return true;
  }else{
    return false;
  }
}


void solenoid(){
  // timer setup for hit 
  // using delay() will not grant us multitasking 
  if (currentTime - previousHitTime < hitInterval && hitting == true){
    digitalWrite(soloPin, HIGH);
//    Serial.println("hit");
//    Serial.println(currentTime - previousHitTime);
  }else{
    hitting = false;
    previousHitTime = currentTime;
  }
  
  // timer setup for wait
  if (currentTime - previousWaitTime < waitInterval && hitting == false){
    digitalWrite(soloPin, LOW);
//    Serial.println("wait");
//    Serial.println(currentTime - previousWaitTime);
  }else{
    hitting = true;
    previousWaitTime = currentTime;
  }
}


