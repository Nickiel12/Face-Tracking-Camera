#include <Wire.h>
#include <AccelStepper.h>
#include <Adafruit_MotorShield.h>

Adafruit_MotorShield AFMStop = Adafruit_MotorShield();

// Connect two steppers with 200 steps per revolution (1.8 degree)
// to the top shield
Adafruit_StepperMotor *myStepper1 = AFMStop.getStepper(200, 1);
Adafruit_StepperMotor *myStepper2 = AFMStop.getStepper(200, 2);

// you can change these to DOUBLE or INTERLEAVE or MICROSTEP!
// wrappers for the first motor!
void forwardstep1() {  
    myStepper1->onestep(FORWARD, INTERLEAVE);
}
void backwardstep1() {  
    myStepper1->onestep(BACKWARD, INTERLEAVE);
}
// wrappers for the second motor!
void forwardstep2() {  
    myStepper2->onestep(FORWARD, SINGLE);
}
void backwardstep2() {  
    myStepper2->onestep(BACKWARD, SINGLE);
}
int MaxSpeedMulitplierTilt = 10;
int MaxSpeedMulitplierTurn = 10;

// Now we'll wrap the 3 steppers in an AccelStepper object
AccelStepper stepperTurn(forwardstep1, backwardstep1);
AccelStepper stepperTilt(forwardstep2, backwardstep2);

void turn(bool right, int speed) {
    stepperTurn.setMaxSpeed(speed * MaxSpeedMulitplierTurn);
    if (right == true){
        stepperTurn.moveTo(stepperTurn.currentPosition()+50);
    }else{
        stepperTurn.moveTo(stepperTurn.currentPosition()-50);
    }
}

void tilt(bool down, int speed) {
    stepperTilt.setMaxSpeed(speed * MaxSpeedMulitplierTilt);
    if (down == true) {
        stepperTilt.moveTo(stepperTilt.currentPosition()+50);
    }else {
        stepperTilt.moveTo(stepperTilt.currentPosition()-50);
    }
}

void stop(bool tilt) {
    if (tilt == true) {
        stepperTilt.setMaxSpeed(0);
        stepperTilt.moveTo(stepperTilt.currentPosition());
    }else {
        stepperTurn.setMaxSpeed(0);
        stepperTurn.moveTo(stepperTurn.currentPosition());
    }
}

void setup()
{  
	AFMStop.begin(); // Start the top shield

	Serial.begin(19200);
	Serial.setTimeout(1500);
  
	stepperTurn.setMaxSpeed(20.0);
	stepperTurn.setAcceleration(2000.0);
    
    stepperTilt.setMaxSpeed(20.0);
     stepperTilt.setAcceleration(2000.0);

}

void loop()
{
    // Change direction at the limits
  
        // send data only when you receive data:
    while(Serial.available() > 0) {
        // read the incoming byte:

        axes = Serial.read();

        switch(axes){
            case 'a': //level 1 up
                tilt(false,1);
                break;
            case 'b': //level2 up
                tilt(false,2);
                break;
            case 'c': //level3 up
                tilt(false,3);
                break;
            case 'd': //level4 up
                tilt(false,4);
                break;
            case 'e': //level5 up
                tilt(false,5);
                break;
            case 'f': //level6 up
                tilt(false,6);
                break;
            case 'g': //level 7 up
                tilt(false,7);
                break;
            case 'h': //level 8 up
                tilt(false,8);
                break;
            case 'i': //level 9 up
                tilt(false,9);
                break;
            case 'j': //level 10 up
                tilt(false,10);
                break;
            
            case 'k': //level 1 down
                tilt(true, 1);
                break;
            case 'l': //level 2 down
                tilt(true, 2);
                break;
            case 'm': //level 3 down
                tilt(true, 3);
                break;
            case 'n': //level 4 down
                tilt(true, 4);
                break;
            case 'o': //level 5 down
                tilt(true, 5);
                break;
            case 'p': //level 6 down
                tilt(true, 6);
                break;
            case 'q': //level 7 down
                tilt(true, 7);
                break;
            case 'r': //level 8 down
                tilt(true, 8);
                break;
            case 's': //level 9 down
                tilt(true, 9);
                break;
            case 't': //level 10 down
                tilt(true, 10);
                break;
            case 'A': //level 1 right
                turn(true, 1);
                break;
            case 'B': //level 2 right
                turn(true, 2);
                break;
            case 'C': //level 3 right
                turn(true, 3);
                break;
            case 'D': //level 4 right
                turn(true, 4);
                break;
            case 'E': //level 5 right
                turn(true, 5);
                break;
            case 'F': //level 6 right
                turn(true, 6);
                break;
            case 'G': //level 7 righ
                turn(true, 7);
                break;
            case 'H': //level 8 right
                turn(true, 8);
                break;
            case 'I': //level 9 right
                turn(true, 9);
                break;
            case 'J': //level 10 right
                turn(true, 10);
                break;
            
            case 'K': //level 1 left
                turn(false, 1);
                break;
            case 'L': //level 2 left
                turn(false, 2);
                break;
            case 'M': //level 3 left
                turn(false, 3);
                break;
            case 'N': //level 4 left
                turn(false, 4);
                break;
            case 'O': //level 5 left
                turn(false, 5);
                break;
            case 'P': //level 6 left
                turn(false, 6);
                break;
            case 'Q': //level 7 left
                turn(false, 7);
                break;
            case 'R': //level 8 left 
                turn(false, 8);
                break;
            case 'S': //level 9 left
                turn(false, 9);
                break;
            case 'T': //level 10 left
                turn(false, 10);
                break;
            }
        }
    stepperTurn.run();
    stepperTilt.run();
}