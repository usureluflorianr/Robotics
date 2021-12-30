#define sample 300

const int buttonPin = 2;

const int pinTone = 4; 

const int pinLed1 = 5;
const int pinLed2 = 6;
const int pinLed3 = 7;
const int pinLed4 = 8;
const int pinLed5 = 9;
const int pinLed6 = 10;
const int pinBLed = 11;
const int pinGLed = 12;

const int pinGhost = 5; 
const int toneMultiply = 300; 

unsigned long averaging = 0;
unsigned int lastDebounceTime = 0;
unsigned int debounceDelay = 50; 

int ghostVal = 0;
int counter = 0; 
int buttonPushCounter = 0;

bool buttonState = LOW; 
bool lastButtonState = LOW;

float val = 0; 

void shine(int level, int counter) {
  if (level != 7) {
    digitalWrite(pinBLed, LOW);
    digitalWrite(pinGLed, LOW);
  }
  
  if (level >= 1)
    digitalWrite(pinLed1, HIGH);
  else 
    digitalWrite(pinLed1, LOW);
  
  if (level >= 2)
    digitalWrite(pinLed2, HIGH);
  else 
    digitalWrite(pinLed2, LOW);
  
  if (level >= 3)
    digitalWrite(pinLed3, HIGH);
  else 
    digitalWrite(pinLed3, LOW);
  
  if (level >= 4)
    digitalWrite(pinLed4, HIGH);
  else 
    digitalWrite(pinLed4, LOW);
  
  if (level >= 5) 
    digitalWrite(pinLed5, HIGH);
  else 
    digitalWrite(pinLed5, LOW);
    
  if (level >= 6)
    digitalWrite(pinLed6, HIGH);
  else 
    digitalWrite(pinLed6, LOW);
  
  if (level >= 7) {
    if (counter == 1 || counter == 3) 
      digitalWrite(pinBLed, HIGH);
    else 
      digitalWrite(pinBLed, LOW);
 
    if (counter == 2 || counter == 3)
      digitalWrite(pinGLed, HIGH);
    else 
      digitalWrite(pinGLed, LOW);
  }   
}

void soundr(int level) {
  tone(pinTone, level * toneMultiply, 100);
}

void setup() {
  pinMode(buttonPin,INPUT_PULLUP);
  
  pinMode(pinLed1, OUTPUT);
  pinMode(pinLed2, OUTPUT);
  pinMode(pinLed3, OUTPUT);
  pinMode(pinLed4, OUTPUT);
  pinMode(pinLed5, OUTPUT);
  pinMode(pinLed6, OUTPUT);
  pinMode(pinBLed, OUTPUT);
  pinMode(pinGLed, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // aici avem codul daca aveam rezistor de 3M si sarma buna
  
  /*val = 0; 
  averaging = 0; 
  for(int i = 0; i < sample; ++i) {
    ghostVal = analogRead(pinGhost);
    averaging += ghostVal;   
  }

  val = averaging / sample;
  Serial.println(val); 
  ghostVal = analogRead(pinGhost);
  Serial.println(ghostVal);
  
  ++counter; 
  if (counter == 4)
    counter = 1; 
 
  shine(counter, counter);
  soundr(counter);
  delay(500);
  */

  if (millis() % 1000 == 0) {
    int randNumber = random(4);
    shine(randNumber + 1, 1);
    soundr(1);
  }

  int reading = digitalRead(buttonPin);

  if (reading != lastButtonState) {
    lastDebounceTime = millis(); 
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading; 

      if (buttonState == LOW) {
        shine(1, 1);
        soundr(1); 
        delay(150);
        shine(2, 1);
        soundr(2); 
        delay(150);
        shine(3, 1);
        soundr(3); 
        delay(150);
        shine(4, 1);
        soundr(4); 
        delay(150);
        shine(5, 1);
        soundr(5); 
        delay(150);
        shine(6, 1);
        soundr(6); 
        delay(150);
        shine(7, 1);
        soundr(7); 
        delay(150);
        shine(7, 2);
        soundr(7); 
        delay(150);
        shine(7, 3);
        soundr(7); 
        delay(150);
        shine(1, 0);
      }
    }
  }

  lastButtonState = reading;  
}












