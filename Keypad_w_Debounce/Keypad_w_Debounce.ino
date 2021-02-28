#define btnNONE 0
#define btnRIGHT 1
#define btnUP 2
#define btnDOWN 3
#define btnLEFT 4
#define btnSELECT 5

int readkeypad(){
  int key_in = analogRead(A0);
  if (key_in <= 50){
    return btnRIGHT;
  } else if (key_in>=51 && key_in<=200){
    return btnUP;
  } else if (key_in>=201 && key_in<=300){
    return btnDOWN;
  } else if (key_in>=301 && key_in<=500){
    return btnLEFT;
  } else if (key_in>=501 && key_in<=800){
    return btnSELECT;
  } else{
    return btnNONE;
  }
 }

// Debouncing Time
#define debounceDelay 50

// Debounce Variables
int inputState = 0;
int lastInputState = 0;
unsigned long lastDebounceTime = 0;

// Button value for actual use
int buttonState = 0;

// Debouncing function
int KeypadWithDebounce(){
  inputState = readkeypad();
  if (inputState != lastInputState) {
    lastDebounceTime = millis();
  }
   if ((millis() - lastDebounceTime) > debounceDelay) {
      buttonState = inputState;
  }
  lastInputState = inputState;
  return buttonState;
}

//void setup() {
//  pinMode(A0, INPUT);
//  Serial.begin(9600);
//}
//
//void loop() {
//  Serial.println(KeypadWithDebounce());
//  delay(1000);
//
//}
