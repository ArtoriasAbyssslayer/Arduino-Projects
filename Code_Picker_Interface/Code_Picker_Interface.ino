#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

#define btnNONE 0
#define btnRIGHT 1
#define btnUP 2
#define btnDOWN 3
#define btnLEFT 4
#define btnSELECT 5

// Number of codes
#define CODES 2
// Menu Variables
bool menu_flag = 0;
int last_btn = btnNONE;
int pos = 0;
// Interface Variables
int code_flag = 0;
bool setup_flag = 0;

void setup() {
  pinMode(10, INPUT);
  pinMode(A0, INPUT);
  lcd.begin(16,2);
  lcdSetup();
  Serial.begin(9600);
}

void loop() {
  int btn = KeypadWithDebounce();
  if (btn != btnNONE && last_btn == btnNONE){
    Serial.print("Button pressed: ");
    Serial.println(btn);
    menu(btn);
  }
  last_btn = btn;
  
  CodePicker();
}

void CodePicker(){
  if (code_flag == 1){
    code1();
  } else if (code_flag == 2){
    code2();
  }
}

void menu(int x){
  if (menu_flag == 0){
    menu_flag = 1;
    lcdPrint(pos);
    return;
  }
  
  if (x==btnUP || x==btnLEFT){
    pos--;
    if (pos < 0){
      pos = 0;
    }
  } else if (x==btnDOWN || x==btnRIGHT){
    pos++;
    if (pos > CODES-1){
      pos = CODES-1;
    }
  }
  lcdPrint(pos);
  
  if (x == btnSELECT){
    code_flag = pos+1;
    setup_flag = 1;
    pos = 0;
    menu_flag = 0;
    lcdSetup();
  }
}
