#include <Wire.h>
#include <Adafruit_MotorShield.h>

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
// Or, create it with a different I2C address (say for stacking)
// Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61); 

// Connect a stepper motor with 200 steps per revolution (1.8 degree)
// to motor port #2 (M3 and M4)
Adafruit_StepperMotor *tiltMotor = AFMS.getStepper(200, 2);

//Same as above, except for assigned to motor port #1, (M1 and M2)
Adafruit_StepperMotor *turnMotor = AFMS.getStepper(200, 1);

Adafruit_StepperMotor *joystickMotorTilt = AFMS.getStepper(200, 2);
Adafruit_StepperMotor *joystickMotorTurn = AFMS.getStepper(200, 1);

bool joystickControl;

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps

  joystickControl = false;

  AFMS.begin();  // create with the default frequency 1.6KHz
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz
  
  tiltMotor->setSpeed(20);  // 10 rpm   
  turnMotor->setSpeed(20);

  joystickMotorTilt->setSpeed(20);
  joystickMotorTurn->setSpeed(20);
}

void loop() {

    // send data only when you receive data:
    while(Serial.available() > 0) {
        // read the incoming byte:
        char incomingByte = Serial.read();

        switch (incomingByte){
            case 'j': //enable joystickControl
                joystickControl = true;
                break;
            case 'c': //disable joystickControl and enable face detect joystickControl
                joystickControl = false;
                break;
        }

        if (joystickControl == true){
            switch (incomingByte)
            {
                case '1': //level one Speed tilt
                    joystickMotorTilt->setSpeed(20)
                    break;
                case '2': //level one speed turn
                    joystickMotorTurn->setSpeed(20);
                    break;
                case '3': //level two speed tilt
                    joystickMotorTilt->setSpeed(40);
                    break;
                case '4': //level two speed turn
                    joystickMotorTurn->setSpeed(40);
                    break;
                case '5': //level three speed tilt
                    joystickMotorTilt->setSpeed(60);
                    break;
                case '6': //level three speed turn
                    joystickMotorTurn->setSpeed(60);
                    break;
                case '7': //level four speed tilt
                    joystickMotorTilt->setSpeed(80);
                    break;
                case '8': //level four speed turn
                    joystickMotorTurn->setSpeed(80);
                    break;

                case 'u': //up
                    joystickMotorTilt->step(1, FORWARD, MICROSTEP);
                    break;

                case 'd': //down
                    joystickMotorTilt->step(1, BACKWARD, MICROSTEP);
                    break;

                case 'l': //left
                    joystickMotorTurn->step(1, FORWARD, MICROSTEP);
                    break;
                
                case 'r': //right
                    joystickMotorTurn->step(1, FORWARD, MICROSTEP);
                    break;
            }
        }       

        if(joystickControl == false){
            switch (incomingByte){
                case 'u': //up
                    tiltMotor->step(1.5, FORWARD, INTERLEAVE);
                    break;
                case '1': //up fast
                    tiltMotor->step(2, FORWARD, SINGLE);
                    break;
                case 'd': //down
                    tiltMotor->step(2, BACKWARD, INTERLEAVE);
                    break;
                case '2': //down fast
                    tiltMotor->step(2, BACKWARD, SINGLE);
                    break;

                case 'l': //left
                    turnMotor->step(2, FORWARD, INTERLEAVE);
                    break;
                case '3': //left fast
                    turnMotor->step(2, FORWARD, SINGLE);
                    break;

                case 'r': //right
                    turnMotor->step(1.5, BACKWARD, INTERLEAVE);
                    break;
                case '4': //right fast
                    turnMotor->step(2, BACKWARD, SINGLE);
                    break;
            }               
        }
    }
}