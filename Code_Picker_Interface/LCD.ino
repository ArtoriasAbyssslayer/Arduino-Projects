String opt[2] = {"Option 1","Option 2"};
void lcdPrint(int x){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(opt[x]);
}

void lcdSetup(){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Press any key to");
    lcd.setCursor(0,1);
    lcd.print("display options.");
}
