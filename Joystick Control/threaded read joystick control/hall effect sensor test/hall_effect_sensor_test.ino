int potPin = 2;    // select the input pin for the potentiometer
int val = 0;       // variable to store the value coming from the sensor
int loopnum = 0;

void setup() {
  Serial.begin(9600);
  pinMode(potPin, INPUT_PULLUP);
  Serial.println("begin");
}

void loop() {

    val = digitalRead(potPin);
  
  Serial.println(val);
}
