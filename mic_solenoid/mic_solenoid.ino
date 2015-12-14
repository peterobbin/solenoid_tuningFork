#define pinC 2
#define pinD 3
#define pinE 4
#define pinF 5
#define pinG 6
#define pinA 7
#define pinB 8
#define pinCplus 9

#define micPinF 0

long previousHitTimeC = 0;
long previousWaitTimeC = 0;
boolean hittingC = false;

long previousHitTimeD = 0;
long previousWaitTimeD = 0;
boolean hittingD = false;

long previousHitTimeE = 0;
long previousWaitTimeE = 0;
boolean hittingE = false;

long previousHitTimeF = 0;
long previousWaitTimeF = 0;
boolean hittingF = false;

long previousHitTimeG = 0;
long previousWaitTimeG = 0;
boolean hittingG = false;

long previousHitTimeA = 0;
long previousWaitTimeA = 0;
boolean hittingA = false;


long previousHitTimeB = 0;
long previousWaitTimeB = 0;
boolean hittingB = false;

long previousHitTimeCplus = 0;
long previousWaitTimeCplus = 0;
boolean hittingCplus = false;


long hitIntervalC = 49;
long waitIntervalC = 2048 - hitIntervalC;

long hitIntervalD = 51;
long waitIntervalD = 2304 - hitIntervalD;

long hitIntervalE = 52;
long waitIntervalE = 2560 - hitIntervalE;

long hitIntervalF = 48;
long waitIntervalF = 2730 - hitIntervalF;

long hitIntervalG = 47;
long waitIntervalG = 3072 - hitIntervalG;

long hitIntervalA = 54;
long waitIntervalA = 3408 - hitIntervalA;

long hitIntervalB = 55;
long waitIntervalB = 3840 - hitIntervalB;

long hitIntervalCplus = 46;
long waitIntervalCplus = 4096 - hitIntervalCplus;



unsigned long currentTime = 0;


float volumeHighLimit = 430;
float volumeLowLimit = 220;



void setup(){
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinCplus, OUTPUT);
  pinMode(micPinF, INPUT);
  Serial.begin(9600);

}


void loop(){


  currentTime = millis();

  if (trigger() == true){
    solenoidC();
    solenoidD();
    solenoidE();
    solenoidF();
    solenoidG();
    solenoidA();
    solenoidB();
    solenoidCplus();
  }else{
    resetSolenoidC();
    resetSolenoidD();
    resetSolenoidE();
    resetSolenoidF();
    resetSolenoidG();
    resetSolenoidA();
    resetSolenoidB();
    resetSolenoidCplus();
  }


}


boolean trigger(){
  // getting volume
  // volume is normally 300ish, when touched it will go higher than 350 or lower than 300
  float volume = analogRead(micPinF);
  Serial.println(volume);
  if (volume < volumeLowLimit || volume > volumeHighLimit){
    return true;
  }else{
    return false;
  }
}


void solenoidC(){
  // timer setup for hit 
  // using delay() will not grant us multitasking 
  if (currentTime + random(20) - previousHitTimeC < hitIntervalC && hittingC == true){
   digitalWrite(pinC, HIGH);
  }else{
    hittingC = false;
    previousHitTimeC = currentTime;
  }
  
  // timer setup for wait
  if (currentTime + random(20) - previousWaitTimeC < waitIntervalC && hittingC == false){
   digitalWrite(pinC, LOW);
  }else{
    hittingC = true;
    previousWaitTimeC = currentTime;
  }
}

void resetSolenoidC(){
  digitalWrite(pinC, LOW);
}


void solenoidD(){
  // timer setup for hit 
  // using delay() will not grant us multitasking 
  if (currentTime - random(23) - previousHitTimeD < hitIntervalD && hittingD == true){
   digitalWrite(pinD, HIGH);
  }else{
    hittingD = false;
    previousHitTimeD = currentTime;
  }
  
  // timer setup for wait
  if (currentTime -  random(23) - previousWaitTimeD < waitIntervalD && hittingD == false){
   digitalWrite(pinD, LOW);
  }else{
    hittingD = true;
    previousWaitTimeD = currentTime;
  }
}



void resetSolenoidD(){
  digitalWrite(pinD, LOW);
}




void solenoidE(){
  // timer setup for hit 
  // using delay() will not grant us multitasking 
  if (currentTime + random(17) - previousHitTimeE < hitIntervalE && hittingE == true){
   digitalWrite(pinE, HIGH);
  }else{
    hittingE = false;
    previousHitTimeE = currentTime;
  }
  
  // timer setup for wait
  if (currentTime + random(17) - previousWaitTimeE < waitIntervalE && hittingE == false){
   digitalWrite(pinE, LOW);
  }else{
    hittingE = true;
    previousWaitTimeE = currentTime;
  }
}

void resetSolenoidE(){
  digitalWrite(pinE, LOW);
}





void solenoidF(){
  // timer setup for hit 
  // using delay() will not grant us multitasking 
  if (currentTime - random(19) - previousHitTimeF < hitIntervalF && hittingF == true){
   digitalWrite(pinF, HIGH);
//    Serial.println("hit");
//    Serial.println(currentTime - previousHitTimeF);
  }else{
    hittingF = false;
    previousHitTimeF = currentTime;
  }
  
  // timer setup for wait
  if (currentTime - random(19) - previousWaitTimeF < waitIntervalF && hittingF == false){
   digitalWrite(pinF, LOW);
//    Serial.println("wait");
//    Serial.println(currentTime - previousWaitTimeF);
  }else{
    hittingF = true;
    previousWaitTimeF = currentTime;
  }
}

void resetSolenoidF(){
  digitalWrite(pinF, LOW);
}



void solenoidG(){
  // timer setup for hit 
  // using delay() will not grant us multitasking 
  if (currentTime + random(25) - previousHitTimeG < hitIntervalG && hittingG == true){
   digitalWrite(pinG, HIGH);
  }else{
    hittingG = false;
    previousHitTimeG = currentTime;
  }
  
  // timer setup for wait
  if (currentTime + random(25) - previousWaitTimeG < waitIntervalG && hittingG == false){
   digitalWrite(pinG, LOW);
  }else{
    hittingG = true;
    previousWaitTimeG = currentTime;
  }
}

void resetSolenoidG(){
  digitalWrite(pinG, LOW);
}



void solenoidA(){
  // timer setup for hit 
  // using delay() will not grant us multitasking 
  if (currentTime + random(14) - previousHitTimeA < hitIntervalA && hittingA == true){
   digitalWrite(pinA, HIGH);
  }else{
    hittingA = false;
    previousHitTimeA = currentTime;
  }
  
  // timer setup for wait
  if (currentTime  + random(14) -  previousWaitTimeA < waitIntervalA && hittingA == false){
   digitalWrite(pinA, LOW);
  }else{
    hittingA = true;
    previousWaitTimeA = currentTime;
  }
}

void resetSolenoidA(){
  digitalWrite(pinA, LOW);
}



void solenoidB(){
  // timer setup for hit 
  // using delay() will not grant us multitasking 
  if (currentTime + random(23) - previousHitTimeB < hitIntervalB && hittingB == true){
   digitalWrite(pinB, HIGH);
  }else{
    hittingB = false;
    previousHitTimeB = currentTime;
  }
  
  // timer setup for wait
  if (currentTime - random(23) - previousWaitTimeB < waitIntervalB && hittingB == false){
   digitalWrite(pinB, LOW);
  }else{
    hittingB = true;
    previousWaitTimeB = currentTime;
  }
}

void resetSolenoidB(){
  digitalWrite(pinB, LOW);
}





void solenoidCplus(){
  // timer setup for hit 
  // using delay() will not grant us multitasking 
  if (currentTime  + random(26) - previousHitTimeCplus < hitIntervalCplus && hittingCplus == true){
   digitalWrite(pinCplus, HIGH);
  }else{
    hittingCplus = false;
    previousHitTimeCplus = currentTime;
  }
  
  // timer setup for wait
  if (currentTime + random(26) - previousWaitTimeCplus < waitIntervalCplus && hittingCplus == false){
   digitalWrite(pinCplus, LOW);
  }else{
    hittingCplus = true;
    previousWaitTimeCplus = currentTime;
  }
}

void resetSolenoidCplus(){
  digitalWrite(pinCplus, LOW);
}








