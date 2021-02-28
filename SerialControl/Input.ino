int number_in = 0;
int sign = 1;
void read_Num(char c){
  if (c == '-'){
   sign = -1;
  }else{
    number_in = number_in*10 + (c - '0');
  }
}

String text_in = "";
void read_Text(char c){
  text_in += ((String)c);
}

void set_Command(){
  number_out = number_in * sign;
  number_in = 0;
  sign = 1;
  text_out = text_in;
  text_in = "";
}
