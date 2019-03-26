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
                    case 'u': //up
                        tiltServo.write(88);
                        break;
                    case 'd': //down
                        tiltServo.write(94);
                        break;
                    case 'l': //left
                        turnServo.write(85);
                        break;
                    case 'r': //right
                        turnServo.write(96);
                        break;
                    case 's': //stop
                        Stop();
                        break;
                    default:
                        Stop();
                        break;

                }
                
        }
}

void Stop(){
    turnServo.write(90);
    tiltServo.write(90);
}