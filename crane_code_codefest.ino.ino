void setup() {
  pinMode(27,OUTPUT);
  pinMode(14,OUTPUT);
  pinMode(26,OUTPUT);
  pinMode(25,OUTPUT);
Serial.begin(115200);
}
void loop() {
  if (Serial.available()>0){
   String user_input=Serial.readString();
    if (user_input == "up"){
      analogWrite(27,20);
      analogWrite(26,0);
      analogWrite(14,0);
      analogWrite(25,0);
    }
    if (user_input == "down"){
      analogWrite(27,0);
      analogWrite(26,0);
      analogWrite(14,20);
      analogWrite(25,0);
    }
    if (user_input =="left"){
      analogWrite(27,0);
      analogWrite(26,0);
      analogWrite(14,0);
      analogWrite(25,20);
    }
    if (user_input=="right"){ 
    analogWrite(27,0);
    analogWrite(26,20);
    analogWrite(14,0);
    analogWrite(25,0);
    }
    }
    }
