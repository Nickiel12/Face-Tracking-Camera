
const int LEDPIN = 6

void setup() {
    Serial.begin(9600);

    pinMode(LEDPIN, OUTPUT);

}

void loop() {
    char incoming = Serial.read();

    if(incoming > 0) {
        switch (incoming){
            case 'a':
                digitalWrite(LEDPIN, HIGH);
                break;
            case 'c':
                digitalWrite(LEDPIN, LOW);
                break;
        }
    }
}