#include <Wire.h>
#include <AccelStepper.h>
#include <Adafruit_MotorShield.h>

int hallSensorTop = 2, hallSensorBottom = 3, touchSensor = 4; // Upper sensor, lower sensor, and internal touch switch
int top, bottom, lever; // vars to store sensor values

Adafruit_MotorShield AFMStop = Adafruit_MotorShield(); //Initialize the motor shield

// Connect two steppers with 200 steps per revolution (1.8 degree)
// to the shield
Adafruit_StepperMotor *myStepperTilt = AFMStop.getStepper(200, 1); //Attach a stepper motor to motor mount 1, M1 & M2
Adafruit_StepperMotor *myStepperTurn = AFMStop.getStepper(200, 2); //Attach a second stepper motor to motor mount 2, M3 & M4

// you can change these to SINGLE or DOUBLE or INTERLEAVE or MICROSTEP!
//MICROSTEP sets the motor to move in 1/16 steps
//INTERLEAVE sets the motor to move in 1/2 steps
//SINGLE sets the motors to move in 1 steps
//DOUBLE sets the motors to move in 2 steps

// wrappers for the first motor!
void forwardstepTurn() {  
    myStepperTurn->onestep(FORWARD, MICROSTEP);
}
void backwardStepTurn() {  
    myStepperTurn->onestep(BACKWARD, MICROSTEP);
}
// wrappers for the second motor!
void forwardStepTilt() {  
    myStepperTilt->onestep(FORWARD, MICROSTEP);
}
void backwardStepTilt() {  
    myStepperTilt->onestep(BACKWARD, MICROSTEP);
}

int MaxSpeedMulitplierTilt = 10; //The base multiplier for the steppers speed
int MaxSpeedMulitplierTurn = 50; //change these number to adjust how fast the motors turn

// Now we'll wrap both steppers in an AccelStepper object
AccelStepper stepperTurn(forwardstepTurn, backwardStepTurn);
AccelStepper stepperTilt(forwardStepTilt, backwardStepTilt);

void setup()
{  
	AFMStop.begin(); // Start the top shield

	Serial.begin(19200);  //Begin serial input

    pinMode(hallSensorTop, INPUT_PULLUP); // Set the input pins
    pinMode(hallSensorBottom, INPUT_PULLUP);
    pinMode(touchSensor, INPUT_PULLUP);
  
	stepperTurn.setMaxSpeed(0); //Begin motors
	stepperTurn.setAcceleration(2000.0);
    
    stepperTilt.setMaxSpeed(0); //Begin motors
     stepperTilt.setAcceleration(2000.0);

}

void turn(bool right, int speed) { //A function that turns the stepperTurn

    stepperTurn.setMaxSpeed(speed * MaxSpeedMulitplierTurn); //set the speed

    if (right == true){ //If the boolean 'right' if true, turn stepperTurn to the right
        if (lever != LOW){
            stepperTurn.moveTo(stepperTurn.currentPosition()+50);
        }
    }else { //If the boolean 'right' is false, turn stepperTurn motor to the left
        if (bottom != LOW){
            stepperTurn.moveTo(stepperTurn.currentPosition()-50);
        }
    }
}

void tilt(bool down, int speed) { //A function that turns the stepperTilt motor

    stepperTilt.setMaxSpeed(speed * MaxSpeedMulitplierTilt); //Sets the speed

    if (down == true) { //If the boolean 'down' is true, tilt the motor down
        stepperTilt.moveTo(stepperTilt.currentPosition()-50);

    }else { //If the boolean 'down' if false, tilt the motor up
        if (top != LOW){
            stepperTilt.moveTo(stepperTilt.currentPosition()+50);
        }
    }
}

void stop(bool tilt) {
    /*
    A function that stops the motor of choice
    */
    if (tilt == true) { //If the boolean 'tilt' is true, stop the stepperTilt motor
        stepperTilt.setMaxSpeed(0);
        stepperTilt.moveTo(stepperTilt.currentPosition());

    }else { //If the boolean 'tilt' is false, stop the stepperTurn motor
        stepperTurn.setMaxSpeed(0);
        stepperTurn.moveTo(stepperTurn.currentPosition());
    }
}

void loop()
{
    top = digitalRead(hallSensorTop); // Read the sensor pins
    bottom = digitalRead(hallSensorBottom);
    lever = digitalRead(touchSensor);

    while(Serial.available() > 0) {
        // read the incoming byte:
        char axes = Serial.read();
        if (axes == 'z'){
            stop(true);
        } else if (axes == 'Z') {
            stop(false);
        }

        switch(axes){
            case 'y': //send signal
                Serial.print('o');
                Serial.print('n');
                Serial.print("!!!");
                break;
            case 'a': //level 1 up
                tilt(true,1);
                break;
            case 'b': //level2 up
                tilt(true,2);
                break;
            case 'c': //level3 up
                tilt(true,3);
                break;
            case 'd': //level4 up
                tilt(true,4);
                break;
            case 'e': //level5 up
                tilt(true,5);
                break;
            case 'f': //level6 up
                tilt(true,6);
                break;
            case 'g': //level 7 up
                tilt(true,7);
                break;
            case 'h': //level 8 up
                tilt(true,8);
                break;
            case 'i': //level 9 up
                tilt(true,9);
                break;
            case 'j': //level 10 up
                tilt(true,10);
                break;
            
            case 'k': //level 1 down
                tilt(false, 1);
                break;
            case 'l': //level 2 down
                tilt(false, 2);
                break;
            case 'm': //level 3 down
                tilt(false, 3);
                break;
            case 'n': //level 4 down
                tilt(false, 4);
                break;
            case 'o': //level 5 down
                tilt(false, 5);
                break;
            case 'p': //level 6 down
                tilt(false, 6);
                break;
            case 'q': //level 7 down
                tilt(false, 7);
                break;
            case 'r': //level 8 down
                tilt(false, 8);
                break;
            case 's': //level 9 down
                tilt(false, 9);
                break;
            case 't': //level 10 down
                tilt(false, 10);
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