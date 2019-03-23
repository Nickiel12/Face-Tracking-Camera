#include <Servo.h>

Servo turnServo;
Servo tiltServo;

void setup()
{
    tiltServo.attach(9);
    turnServo.attach(10);

    Stop();
    Serial.begin(9600);
}

void loop() {

        // send data only when you receive data:
        while(Serial.available() > 0) {
                // read the incoming byte:
                char incomingByte = Serial.read();

                Serial.write(incomingByte);

                switch (incomingByte){
                    case 'a':
                        turnServo.write(84);
                        Serial.write('Got an a');
                        break;
                    case 'b':
                        turnServo.write(97);
                        break;
                    case 'c':
                        Serial.write('Stopping');
                        Stop();
                        break;

                }
                
        }
}

void Stop(){
    turnServo.write(90);
    tiltServo.write(90);
}