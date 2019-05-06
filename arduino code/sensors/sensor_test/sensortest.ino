
int val; // vars to store sensor values

void setup() {
  Serial.begin(9600);
  Serial.println("begin");
}

void loop() {

    val = analogRead(2);
    Serial.println(val);
}
