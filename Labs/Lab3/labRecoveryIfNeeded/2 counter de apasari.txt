const int buttonPin = 2; 
bool buttonState = HIGH;

int counter = 0; 
bool previousState = HIGH; 

void setup() { 
  pinMode(buttonPin, INPUT_PULLUP); 
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  Serial.println(buttonState);   
  if (previousState != buttonState && buttonState == LOW) {
    counter++; 
    previousState = buttonState;  
  }

  Serial.println(counter); 
}
