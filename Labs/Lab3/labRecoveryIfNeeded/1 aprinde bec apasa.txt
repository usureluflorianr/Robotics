const int buttonPin = 2; 
const int ledPin = 11; 
bool buttonState = HIGH;

int counter = 0; 
bool previousState = HIGH; 
bool ledState = LOW;

void setup() { 
  pinMode(buttonPin, INPUT_PULLUP); 
  pinMode(ledPin, OUTPUT); 
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  ledState = !buttonState;
  digitalWrite(ledPin, ledState);  
}
