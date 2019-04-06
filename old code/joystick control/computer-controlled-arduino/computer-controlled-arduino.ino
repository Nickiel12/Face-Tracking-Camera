#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include <AccelStepper.h>

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
// Or, create it with a different I2C address (say for stacking)
// Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61); 

// Connect a stepper motor with 200 steps per revolution (1.8 degree)
// to motor port #2 (M3 and M4)
Adafruit_StepperMotor *joystickMotorTiltLv2 = AFMS.getStepper(200, 2);
Adafruit_StepperMotor *joystickMotorTiltLv3 = AFMS.getStepper(200, 2);
Adafruit_StepperMotor *joystickMotorTiltLv4 = AFMS.getStepper(200, 2);

//Same as above, except for assigned to motor port #1, (M1 and M2)
Adafruit_StepperMotor *joystickMotorTurnLv2 = AFMS.getStepper(200, 1);
Adafruit_StepperMotor *joystickMotorTurnLv3 = AFMS.getStepper(200, 1);
Adafruit_StepperMotor *joystickMotorTurnLv4 = AFMS.getStepper(200, 1);



void setup() {
    Serial.begin(9600);           // set up Serial library at 9600 bps

    AFMS.begin();  // create with the default frequency 1.6KHz
    //AFMS.begin(1000);  // OR with a different frequency, say 1KHz

    joystickMotorTiltLv2->setSpeed(40);
    joystickMotorTurnLv2->setSpeed(40);

    joystickMotorTiltLv3->setSpeed(60);
    joystickMotorTurnLv3->setSpeed(60);

    joystickMotorTiltLv4->setSpeed(80);
    joystickMotorTurnLv4->setSpeed(80);
}

void loop() {

    // send data only when you receive data:
    while(Serial.available() > 0) {
        // read the incoming byte:
        char incomingByte = Serial.read();

        switch (incomingByte)
        {
            case 'b': //L2 up
                joystickMotorTiltLv2->step(1, FORWARD, MICROSTEP);
                break;
            case 'c': //L3 up
                joystickMotorTiltLv3->step(1, FORWARD, MICROSTEP);
                break;
            case 'd': //L4 up
                joystickMotorTiltLv4->step(1, FORWARD, MICROSTEP);
                break;

            case 'f': //L2 down
                joystickMotorTiltLv2->step(1, BACKWARD, MICROSTEP);
                break;
            case 'g': //L3 down
                joystickMotorTiltLv3->step(1, BACKWARD, MICROSTEP);
                break;
            case 'h': //L4 down
                joystickMotorTiltLv4->step(1, BACKWARD, MICROSTEP);
                break;

            case '2': //L2 right
                joystickMotorTurnLv2->step(1, FORWARD, MICROSTEP);
                break;
            case '3': //L3 right
                joystickMotorTurnLv3->step(1, FORWARD, MICROSTEP);
                break;
            case '4': //L4 right
                joystickMotorTurnLv4->step(1, FORWARD, MICROSTEP);
                break;
            case '6': //L2 left
                joystickMotorTurnLv2->step(1, BACKWARD, MICROSTEP);
                break;
            case '7': //L3 left
                joystickMotorTurnLv3->step(1, BACKWARD, MICROSTEP);
                break;
            case '8': //L4 left
                joystickMotorTurnLv4->step(1, BACKWARD, MICROSTEP);
                break;
        }       
    }
}