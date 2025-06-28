int data = 0;
char control;
const int enb = 6;
const int lml = 7; //left motor low
const int lmh = 8; //left motor high
const int ena = 11;
const int rmh = 12; //right motor high
const int rml = 13; //right motor low
void setup() {
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(6,OUTPUT);
  digitalWrite(lml,0);
  digitalWrite(lmh,0);
  digitalWrite(rmh,0);
  digitalWrite(rml,0);
  analogWrite(11,0);
  analogWrite(6,0);
  Serial.begin(9600);

}

void loop() {
  while(Serial.available()>0){
    data = Serial.read();
    control = (char)data;
    switch (control) {
      case 'F': moveForward(); break;
      case 'R': moveRight(); break;
      case 'B': moveBackward(); break;
      case 'L': moveLeft(); break;
      case 'A': ANTONY(); break;
      case 'S': stopMotors(); break;
      default:
        Serial.println("Invalid command");
        break;
    }
        Serial.println(control);
        analogWrite(11,50);
        analogWrite(6,50);
  }

}
void moveForward(){
  analogWrite(11,90);
  analogWrite(6,90);
  digitalWrite(lml,0);
  digitalWrite(lmh,1);
  digitalWrite(rmh,1);
  digitalWrite(rml,0);
}
void stopMotors(){
  digitalWrite(lml,0);
  digitalWrite(lmh,0);
  digitalWrite(rmh,0);
  digitalWrite(rml,0);
}
void moveBackward(){
  analogWrite(11,50);
  analogWrite(6,50);
  digitalWrite(lml,1);
  digitalWrite(lmh,0);
  digitalWrite(rmh,0);
  digitalWrite(rml,1);
}
void moveRight(){
  analogWrite(11,90);
  analogWrite(6,90);
  digitalWrite(lml,0);
  digitalWrite(lmh,1);
  digitalWrite(rmh,0);
  digitalWrite(rml,0);  
}
void moveLeft(){
  analogWrite(11,90);
  analogWrite(6,90);
  digitalWrite(lml,0);
  digitalWrite(lmh,0);
  digitalWrite(rmh,1);
  digitalWrite(rml,0);
}
void ANTONY(){
  analogWrite(11,90);
  analogWrite(6,90);
  digitalWrite(lml,0);
  digitalWrite(lmh,1);
  digitalWrite(rmh,0);
  digitalWrite(rml,1);
}
