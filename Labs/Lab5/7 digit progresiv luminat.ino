const int pinA = 2; 
const int pinB = 3; 
const int pinC = 4;
const int pinD = 5; 
const int pinE = 6; 
const int pinF = 7; 
const int pinG = 8;
const int pinDP = 9; 

const int segSize = 8; 

bool dpState = LOW; 
bool state = HIGH;

int segments[segSize] = {
  pinA, pinB, pinC, pinD, pinE, pinF, pinG, pinDP
};

int index = 0;

void setup() { 

  for (int i = 0; i < segSize; i++) {
    pinMode(segments[i], OUTPUT);
  }

}

void loop() {
  digitalWrite(segments[index], state); 
  index++;
  
  if (index > segSize) {
    state = !state; 
    index = 0; 
  }

  delay(500); 
}