const int buttonPin = 2; 
const int ledPin = 11; 
bool buttonState = HIGH;

bool previousState = HIGH; 
bool ledState = LOW;

int reading = HIGH;
int previousReading = HIGH; 

unsigned int lastDebounceTime = 0; 
unsigned int debounceDelay = 50; 

void setup() { 
  pinMode(buttonPin, INPUT_PULLUP); 
  pinMode(ledPin, OUTPUT); 
  Serial.begin(9600);
}

void loop() {
  reading = digitalRead(buttonPin); 

  if (reading != previousReading) {
    lastDebounceTime = millis(); 
  }

  if (millis() - lastDebounceTime > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading; 
      if (buttonState == HIGH) {
        ledState = !ledState; 
        digitalWrite(ledPin, ledState); 
      }
    }
  }

  previousReading = reading;
  
}







