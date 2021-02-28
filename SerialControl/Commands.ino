void execute(){
  if (text_out == ""){
    Serial.println("Empty command!");
  } else{
    Serial.print("The command was: ");
    Serial.print(text_out);
    Serial.print(" ");
    Serial.println(number_out);
  }
}
