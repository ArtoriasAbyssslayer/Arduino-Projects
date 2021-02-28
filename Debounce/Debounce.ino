// Debouncing Time
#define debounceDelay 50

// Debounce Variables
bool inputState = 0;
bool lastInputState = 0;
unsigned long lastDebounceTime = 0;

// Button value for actual use
bool buttonState = 0;

// Debouncing function
bool inputWithDebounce(){
  inputState = digitalRead(2);
  if (inputState != lastInputState) {
    lastDebounceTime = millis();
  }
   if ((millis() - lastDebounceTime) > debounceDelay) {
      buttonState = inputState;
  }
  lastInputState = inputState;
  return buttonState;
}

// Loop Variables
//bool Button = 0;
//bool lastButton = 0;
//bool LEDstate = 0;
//
//void setup() {
//  pinMode(2, INPUT_PULLUP);
//  pinMode(8, OUTPUT);
//  digitalWrite(8, LOW);
//  pinMode(9, OUTPUT);
//}
//
//void loop() {
//  bool Button = !inputWithDebounce();
//
//  if (Button==HIGH && lastButton==LOW){
//    LEDstate = !LEDstate;
//    analogWrite(9, 120*LEDstate);
//  }
//  lastButton = Button;
//}
