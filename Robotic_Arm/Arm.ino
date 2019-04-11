template <typename type>
type sign(type value) { 
 return type((value>0)-(value<0)); 
}

void MoveServos(){
  long xx = abs(x);
  long yy = abs(y);
  long zz = abs(z);
  // Servo 1
  long dxy = sqrt(sq(xx)+sq(yy));
  Serial.print("dxy=");
  Serial.println(dxy);
  if (y == 0L){
    angle1 = 90;
  } else if (x == 0L){
    angle1 = -(sign(y)*90 - 90);
  } else {
    angle1 = acos((sq(xx)+sq(dxy)-sq(yy))/((double)(2*xx*dxy)))*4068/71;
    angle1 = -(sign(y)*angle1 - 90);
  }
  Serial.print("angle1=");
  Serial.println(angle1);
  Servo1.write((int)angle1);
  delay(1000);
  
  // Servo 2,3
  long dxyz = sqrt(sq(dxy)+sq(zz));
  Serial.print("dxyz=");
  Serial.println(dxyz);
  double xyz_angle;
  if (dxy == 0){
    if (sign(z) < 0){
      xyz_angle = -90;
    } else if (sign(z) > 0){
      xyz_angle = 90;
    } else {
      Serial.println("Zero coordinates.");
      Serial.println("Arm not moving.");
      return;
    }
  } else if (z == 0L){
    xyz_angle = 0;
  } else {
    xyz_angle = acos((sq(dxy)+sq(dxyz)-sq(zz))
    /((double)(2*dxy*dxyz)))*4068/71;
    xyz_angle = xyz_angle*sign(z);
  }
  Serial.print("xyz_angle=");
  Serial.println(xyz_angle);
  
  if (dxyz > (length1+length2)){
    Serial.println("Object is too far.");
    Serial.println("Arm not moving.");
    return;
  } else {
    angle2 = acos((sq(length1)+sq(dxyz)-sq(length2))
    /((double)(2*length1*dxyz)))*4068/71;
    Serial.print("triangle_angle2=");
    Serial.println(angle2);
    angle2 = 90 - xyz_angle - angle2 - 20; // - error
    Serial.print("angle2=");
    Serial.println(angle2);
    angle3 = acos((sq(length1)+sq(length2)-sq(dxyz))
    /(double(2*length1*length2)))*4068/71;
    Serial.print("triangle_angle3=");
    Serial.println(angle3);
    angle3 = - 90 + angle3 + (-10); // + error
    Serial.print("angle3=");
    Serial.println(angle3);
  }
  if ((angle2<0) || (angle2>180)){
    Serial.println("Servo2 can not go there.");
    Serial.println("Arm not moving.");
    return;
  } else if ((angle3<0) || (angle3>180)){
    Serial.println("Servo3 can not go there.");
    Serial.println("Arm not moving.");
    return;
  } else {
    Servo2.write((int)angle2);
    delay(1000);
    Servo3.write((int)angle3);
    delay(1000);
  }
}
