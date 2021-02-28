int number_out = 0;
String text_out = "";

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (readSerial()){
    Serial.println("A command was read!");
    execute();
  }
}

bool readSerial(){
  if (Serial.available()){
    char char_in = Serial.read();
    if (char_in == '\n'){
      // Ignore
    } else if ((char_in>='0' && char_in<='9')
    || char_in=='-'){
      read_Num(char_in);
    } else if (char_in == ';'){
      set_Command();
      return true;
    } else {
      read_Text(char_in);
    }
  }
  return false;
}
