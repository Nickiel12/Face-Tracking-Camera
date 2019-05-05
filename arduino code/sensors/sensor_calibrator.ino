int hallSensorTop = 2, hallSensorBottom = 3, touchSensor = 4; // Upper sensor, lower sensor, and internal touch switch
int top, bottom, lever; // vars to store sensor values

void setup() {
  Serial.begin(9600);
  pinMode(hallSensorTop, INPUT_PULLUP);
  pinMode(hallSensorBottom, INPUT_PULLUP);
  pinMode(touchSensor, INPUT);
  Serial.println("begin");
}

void loop() {

    top = digitalRead(hallSensorTop);
    bottom = digitalRead(hallSensorBottom);
    touchSensor = digitalRead(touchSensor);

    Serial.println(top);
    Serial.println(bottom);
    Serial.println(touchSensor);
}
