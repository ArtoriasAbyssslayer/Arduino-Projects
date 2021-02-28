#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

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

bool flag = 0;
void battlemenu(int x){
  if (flag == 1){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("FIGHT    BAG");
    lcd.setCursor(0,1);
    lcd.print("POKEMON  RUN");
  } else if (x == 0){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("         BAG");
    lcd.setCursor(0,1);
    lcd.print("POKEMON  RUN");
  } else if (x == 1){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("FIGHT       ");
    lcd.setCursor(0,1);
    lcd.print("POKEMON  RUN");
  } else if (x == 2){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("FIGHT    BAG");
    lcd.setCursor(0,1);
    lcd.print("         RUN");
  } else if (x == 3){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("FIGHT    BAG");
    lcd.setCursor(0,1);
    lcd.print("POKEMON     ");
  }
  flag = !flag;
}

// Code Variables
int pos = 0;
String msg[4] = {"Attacking","Choose Item",
"Change Pokemon","Escaping"};

void setup() {
  pinMode(10, INPUT);
  pinMode(A0, INPUT);
  lcd.begin(16,2);

  // Initial Settings
  battlemenu(pos);
  delay(500);
}

void loop() {
  int btn = KeypadWithDebounce();
  if (btn == btnSELECT){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(msg[pos]);
    delay(2000);
    pos = 0;
  } else if (btn == btnRIGHT){
    pos++;
  } else if (btn == btnLEFT){
    pos--;
  } else if (btn == btnUP){
    pos = pos - 2;
  } else if (btn == btnDOWN){
    pos = pos + 2;
  }
  if (pos<0){
    pos = 4 - pos;
  } else if (pos>3){
    pos = pos - 4;
  }
  battlemenu(pos);
  delay(500);
}
