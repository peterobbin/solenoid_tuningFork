#define pinC 0
#define pinD 1
#define pinE 2
#define pinF 3
#define pinG 4
#define pinA 5
#define pinB 6
#define pinCplus 7

#define micPin 0


long previousHitTime = 0;
long previousWaitTime = 0;
long hitInterval = 100;
long waitInterval = 700;
unsigned long currentTime = 0;
boolean hitting = false;

float volumeHighLimit = 400;
float volumeLowLimit = 250;



void setup(){
  pinMode(pinF, OUTPUT);
  pinMode(micPin, INPUT);
  Serial.begin(9600);

}


void loop(){

  currentTime = millis();

  if (trigger() == true){
    solenoidF();
  }else{
    resetSolenoidF();
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


void solenoidF(){
  // timer setup for hit 
  // using delay() will not grant us multitasking 
  if (currentTime - previousHitTime < hitInterval && hitting == true){
   digitalWrite(pinF, HIGH);
//    Serial.println("hit");
//    Serial.println(currentTime - previousHitTime);
  }else{
    hitting = false;
    previousHitTime = currentTime;
  }
  
  // timer setup for wait
  if (currentTime - previousWaitTime < waitInterval && hitting == false){
   digitalWrite(pinF, LOW);
//    Serial.println("wait");
//    Serial.println(currentTime - previousWaitTime);
  }else{
    hitting = true;
    previousWaitTime = currentTime;
  }
}

void resetSolenoidF(){
  digitalWrite(pinF, LOW);
}


