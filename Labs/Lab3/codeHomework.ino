// constante pt pinii componentelor
const int buttonPin = 2; 
const int soundPin = 4;

const int ledPinCarRed = 13;
const int ledPinCarYellow = 12;
const int ledPinCarGreen = 8; 

const int ledPinManRed = 7; 
const int ledPinManGreen = 5; 
//---------------------------------------------

// starile componentelor
bool buttonState = HIGH;
bool previousState = HIGH; 

bool ledStateCarGreen = HIGH; 
bool ledStateCarYellow = LOW; 
bool ledStateCarRed = LOW; 

bool ledStateManGreen = LOW;
bool ledStateManRed = HIGH; 
//---------------------------------------------

// necesare pentru apasarea butonului
int reading = HIGH;
int previousReading = HIGH; 

unsigned int lastDebounceTime = 0; 
unsigned int debounceDelay = 50; 
//---------------------------------------------

const int beepTone = 30;


void printLeds() {
  digitalWrite(ledPinCarGreen, ledStateCarGreen); 
  digitalWrite(ledPinCarYellow, ledStateCarYellow); 
  digitalWrite(ledPinCarRed, ledStateCarRed); 

  digitalWrite(ledPinManGreen, ledStateManGreen); 
  digitalWrite(ledPinManRed, ledStateManRed);
}

void state1() {
  ledStateCarGreen = HIGH;
  ledStateCarYellow = LOW; 
  ledStateCarRed = LOW;

  ledStateManGreen = LOW; 
  ledStateManRed = HIGH;

  printLeds();
}

void state2() {
  delay(2000);
   
  ledStateCarGreen = LOW; 
  ledStateCarYellow = HIGH;
  
  printLeds();
  delay(3000);
}

void state3() {
  
  ledStateCarYellow = LOW; 
  ledStateCarRed = HIGH;
  ledStateManRed = LOW; 
  ledStateManGreen = HIGH;
        
  printLeds();

  for (int i = 1; i <= 3; ++i) {
    tone(soundPin, beepTone);
    delay(500);
    noTone(soundPin);
    delay(500);
  }
}

void state4() {
  for (int i = 1; i <= 5; ++i) {
    ledStateManGreen = HIGH; 
    printLeds(); 
    tone(soundPin, beepTone);
    delay(250);
    
    ledStateManGreen = LOW; 
    printLeds(); 
    noTone(soundPin);
    delay(250); 
  }
}

void setup() { 
  pinMode(buttonPin, INPUT_PULLUP); 
  pinMode(ledPinCarGreen, OUTPUT); 
  pinMode(ledPinCarYellow, OUTPUT);
  pinMode(ledPinCarRed, OUTPUT);
  pinMode(ledPinManGreen, OUTPUT);
  pinMode(ledPinManRed, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  reading = digitalRead(buttonPin); 
  
  if (reading != previousReading) {
    lastDebounceTime = millis(); 
  }

  printLeds();

  if (millis() - lastDebounceTime > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading; 
      if (buttonState == HIGH) {
        state2();
        state3();
        state4();
        state1();
      }
    }
  }

  previousReading = reading;
  
}







