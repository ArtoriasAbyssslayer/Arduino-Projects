#define tolerance 10
bool filter(int value, int timee){
  int x = new_reading - value;
  if (abs(x) < (tolerance*timee)){
    new_trust++;
    return 0;
  } else {
    new_trust--;
    return 1; 
  }
}

void applyFilters(){
  changeTrustFactor();
  if (current_trust == 1){
    bool flag1 = filter(current_reading,1);
  }
  if (last_trust == 1){
    bool flag2 = filter(last_reading,2);
  }
  if (second_last_trust == 1){
    bool flag3 = filter(second_last_reading,3);
  }
  if (new_trust > 0){
    rotateValues();
    current_trust = 1;
  } else if (new_trust < 0){
    rotateValues();
    current_trust = 0;
  }
  changeTrustFactor();
}
