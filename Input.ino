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

int number_in = 0;
int number_sign = 1;
void read_Num(char c){
  if (c == '-'){
   number_sign = -1;
  }else{
    number_in = number_in*10 + (c - '0');
  }
}

String text_in = "";
void read_Text(char c){
  text_in += ((String)c);
}

int number_out = 0;
String text_out = "";
void set_Command(){
  number_out = number_in * number_sign;
  number_in = 0;
  number_sign = 1;
  text_out = text_in;
  text_in = "";
}

void execute(){
  if (text_out == "x"){
    x = long(number_out);
    x_flag = 1;
    Serial.print("x=");
    Serial.println(x);
  } else if (text_out == "y"){
    y = long(number_out);
    y_flag = 1;
    Serial.print("y=");
    Serial.println(y);
  } else if (text_out == "z"){
    z = long(number_out);
    z_flag = 1;
    Serial.print("z=");
    Serial.println(z);
  }
}
