
void setup(){
    Serial.begin(9600);
}

void loop(){
    Serial.write('hello');
    delay(1000);
}