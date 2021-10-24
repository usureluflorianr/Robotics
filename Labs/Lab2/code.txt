const int ledPinRed = 9;
const int ledPinGreen = 10;
const int ledPinBlue = 11;
const int potPinRed = A2;
const int potPinGreen = A1;
const int potPinBlue = A0;
const int divModulo = 4;
int potValueRed = 0; 
int potValueGreen = 0; 
int potValueBlue = 0; 

void setup() {
  pinMode(ledPinGreen, OUTPUT);
  pinMode(ledPinBlue, OUTPUT);
  pinMode(potPinGreen, INPUT); 
  pinMode(potPinBlue, INPUT); 
}

void loop() {
  potValueRed = analogRead(potPinRed);
  potValueGreen = analogRead(potPinGreen);
  potValueBlue = analogRead(potPinBlue);

  analogWrite(ledPinRed, potValueRed / divModulo);
  analogWrite(ledPinGreen, potValueGreen / divModulo);
  analogWrite(ledPinBlue, potValueBlue / divModulo);
}
