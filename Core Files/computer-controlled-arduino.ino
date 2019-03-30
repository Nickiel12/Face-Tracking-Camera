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


void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps

  AFMS.begin();  // create with the default frequency 1.6KHz
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz
  
  tiltMotor->setSpeed(20);  // 10 rpm   
  turnMotor->setSpeed(20);
}

void loop() {

        // send data only when you receive data:
        while(Serial.available() > 0) {
                // read the incoming byte:
                char incomingByte = Serial.read();

                Serial.write(incomingByte);

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
                        turnMotor->step(1, FORWARD, INTERLEAVE);
                        break;
                    case '3': //left fast
                        turnMotor->step(2, FORWARD, SINGLE);
                        break;

                    case 'r': //right
                        turnMotor->step(1, BACKWARD, INTERLEAVE);
                        break;
                    case '4': //right fast
                        turnMotor->step(2, BACKWARD, SINGLE);
                        break;
                }               
        }
}