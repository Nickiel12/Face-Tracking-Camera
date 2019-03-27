int phase1 = 8;
int phase2 = 9;
int phase3 = 10;
int speed = 7;

void setup() {
  pinMode(phase1, OUTPUT);
  pinMode(phase2, OUTPUT);
  pinMode(phase3, OUTPUT);
}

void loop(){
digitalWrite(phase1, HIGH); delay(speed);
digitalWrite(phase3, LOW); delay(speed);
digitalWrite(phase2, HIGH); delay(speed);
digitalWrite(phase1, LOW); delay(speed);
digitalWrite(phase3, HIGH); delay(speed);
digitalWrite(phase2, LOW); delay(speed);
}