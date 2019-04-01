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

// Now we'll wrap the 3 steppers in an AccelStepper object
AccelStepper stepperTurn(forwardstep1, backwardstep1);
AccelStepper stepperTilt(forwardstep2, backwardstep2);

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
    while(Serial.available() > 3) {
        // read the incoming byte:
        char axes[2];

        int MaxSpeedMulitplierTilt = 10;
        int MaxSpeedMulitplierTurn = 10;

        Serial.readBytesUntil('\n', axes, 2);

        for (int i = 0; i < 2; i++){
          Serial.print(axes[i]);
        }

		if (axes[0] != 0){
			switch(axes[0]){
				case 'a': //level 1 up
                    stepperTilt.setMaxSpeed(1*MaxSpeedMulitplierTilt);
                    stepperTilt.moveTo(stepperTilt.currentPosition()+50);
                    break;
                case 'b': //level2 up
                    stepperTilt.setMaxSpeed(2*MaxSpeedMulitplierTilt);
                    stepperTilt.moveTo(stepperTilt.currentPosition()+50);
                    break;
                case 'c': //level3 up
                    stepperTilt.setMaxSpeed(3*MaxSpeedMulitplierTilt);
                    stepperTilt.moveTo(stepperTilt.currentPosition()+50);
                    break;
                case 'd': //level4 up
                    stepperTilt.setMaxSpeed(4*MaxSpeedMulitplierTilt);
                    stepperTilt.moveTo(stepperTilt.currentPosition()+50);
                    break;
                case 'e': //level5 up
                    stepperTilt.setMaxSpeed(5*MaxSpeedMulitplierTilt);
                    stepperTilt.moveTo(stepperTilt.currentPosition()+50);
                    break;
                case 'f': //level6 up
                    stepperTilt.setMaxSpeed(6*MaxSpeedMulitplierTilt);
                    stepperTilt.moveTo(stepperTilt.currentPosition()+50);
                    break;
                case 'g': //level 7 up
                    stepperTilt.setMaxSpeed(7*MaxSpeedMulitplierTilt);
                    stepperTilt.moveTo(stepperTilt.currentPosition()+50);
                    break;
                case 'h': //level 8 up
                    stepperTilt.setMaxSpeed(8*MaxSpeedMulitplierTilt);
                    stepperTilt.moveTo(stepperTilt.currentPosition()+50);
                    break;
                case 'i': //level 9 up
                    stepperTilt.setMaxSpeed(9*MaxSpeedMulitplierTilt);
                    stepperTilt.moveTo(stepperTilt.currentPosition()+50);
                    break;
                case 'j': //level 10 up
                    stepperTilt.setMaxSpeed(10*MaxSpeedMulitplierTilt);
                    stepperTilt.moveTo(stepperTilt.currentPosition()+50);
                    break;
                
                case 'k': //level 1 down
                    stepperTilt.setMaxSpeed(1*MaxSpeedMulitplierTilt);
                    stepperTilt.moveTo(stepperTilt.currentPosition()-50);
                    break;
                case 'l': //level 2 down
                    stepperTilt.setMaxSpeed(2*MaxSpeedMulitplierTilt);
                    stepperTilt.moveTo(stepperTilt.currentPosition()-50);
                    break;
                case 'm': //level 3 down
                    stepperTilt.setMaxSpeed(3*MaxSpeedMulitplierTilt);
                    stepperTilt.moveTo(stepperTilt.currentPosition()-50);
                    break;
                case 'n': //level 4 down
                    stepperTilt.setMaxSpeed(4*MaxSpeedMulitplierTilt);
                    stepperTilt.moveTo(stepperTilt.currentPosition()-50);
                    break;
                case 'o': //level 5 down
                    stepperTilt.setMaxSpeed(5*MaxSpeedMulitplierTilt);
                    stepperTilt.moveTo(stepperTilt.currentPosition()-50);
                    break;
                case 'p': //level 6 down
                    stepperTilt.setMaxSpeed(6*MaxSpeedMulitplierTilt);
                    stepperTilt.moveTo(stepperTilt.currentPosition()-50);
                    break;
                case 'q': //level 7 down
                    stepperTilt.setMaxSpeed(7*MaxSpeedMulitplierTilt);
                    stepperTilt.moveTo(stepperTilt.currentPosition()-50);
                    break;
                case 'r': //level 8 down
                    stepperTilt.setMaxSpeed(8*MaxSpeedMulitplierTilt);
                    stepperTilt.moveTo(stepperTilt.currentPosition()-50);
                    break;
                case 's': //level 9 down
                    stepperTilt.setMaxSpeed(9*MaxSpeedMulitplierTilt);
                    stepperTilt.moveTo(stepperTilt.currentPosition()-50);
                    break;
                case 't': //level 10 down
                    stepperTilt.setMaxSpeed(10*MaxSpeedMulitplierTilt);
                    stepperTilt.moveTo(stepperTilt.currentPosition()-50);
                    break;
                }

        if (axis[1] != 0){
            switch(axis[1]){
                case 'A': //level 1 right
                    stepperTurn.setMaxSpeed(1*MaxSpeedMulitplierTurn);
                    stepperTurn.moveTo(stepperTurn.currentPosition()+50)
                    break;
                case 'B': //level 2 right
                    stepperTurn.setMaxSpeed(2*MaxSpeedMulitplierTurn);
                    stepperTurn.moveTo(stepperTurn.currentPosition()+50)
                    break;
                case 'C': //level 3 right
                    stepperTurn.setMaxSpeed(3*MaxSpeedMulitplierTurn);
                    stepperTurn.moveTo(stepperTurn.currentPosition()+50)
                    break;
                case 'D': //level 4 right
                    stepperTurn.setMaxSpeed(4*MaxSpeedMulitplierTurn);
                    stepperTurn.moveTo(stepperTurn.currentPosition()+50)
                    break;
                case 'E': //level 5 right
                    stepperTurn.setMaxSpeed(5*MaxSpeedMulitplierTurn);
                    stepperTurn.moveTo(stepperTurn.currentPosition()+50)
                    break;
                case 'F': //level 6 right
                    stepperTurn.setMaxSpeed(6*MaxSpeedMulitplierTurn);
                    stepperTurn.moveTo(stepperTurn.currentPosition()+50)
                    break;
                case 'G': //level 7 right
                    stepperTurn.setMaxSpeed(7*MaxSpeedMulitplierTurn);
                    stepperTurn.moveTo(stepperTurn.currentPosition()+50)
                    break;
                case 'H': //level 8 right
                    stepperTurn.setMaxSpeed(8*MaxSpeedMulitplierTurn);
                    stepperTurn.moveTo(stepperTurn.currentPosition()+50)
                    break;
                case 'I': //level 9 right
                    stepperTurn.setMaxSpeed(9*MaxSpeedMulitplierTurn);
                    stepperTurn.moveTo(stepperTurn.currentPosition()+50)
                    break;
                case 'J': //level 10 right
                    stepperTurn.setMaxSpeed(10*MaxSpeedMulitplierTurn);
                    stepperTurn.moveTo(stepperTurn.currentPosition()+50)
                    break;
                
                case 'K': //level 1 left
                    stepperTurn.setMaxSpeed(1*MaxSpeedMulitplierTurn);
                    stepperTurn.moveTo(stepperTurn.currentPosition()-50)
                    break;
                case 'L': //level 2 left
                    stepperTurn.setMaxSpeed(2*MaxSpeedMulitplierTurn);
                    stepperTurn.moveTo(stepperTurn.currentPosition()-50)
                    break;
                case 'M': //level 3 left
                    stepperTurn.setMaxSpeed(3*MaxSpeedMulitplierTurn);
                    stepperTurn.moveTo(stepperTurn.currentPosition()-50)
                    break;
                case 'N': //level 4 left
                    stepperTurn.setMaxSpeed(4*MaxSpeedMulitplierTurn);
                    stepperTurn.moveTo(stepperTurn.currentPosition()-50)
                    break;
                case 'O': //level 5 left
                    stepperTurn.setMaxSpeed(5*MaxSpeedMulitplierTurn);
                    stepperTurn.moveTo(stepperTurn.currentPosition()-50)
                    break;
                case 'P': //level 6 left
                    stepperTurn.setMaxSpeed(6*MaxSpeedMulitplierTurn);
                    stepperTurn.moveTo(stepperTurn.currentPosition()-50)
                    break;
                case 'Q': //level 7 left
                    stepperTurn.setMaxSpeed(7*MaxSpeedMulitplierTurn);
                    stepperTurn.moveTo(stepperTurn.currentPosition()-50)
                    break;
                case 'R': //level 8 left 
                    stepperTurn.setMaxSpeed(8*MaxSpeedMulitplierTurn);
                    stepperTurn.moveTo(stepperTurn.currentPosition()-50)
                    break;
                case 'S': //level 9 left
                    stepperTurn.setMaxSpeed(9*MaxSpeedMulitplierTurn);
                    stepperTurn.moveTo(stepperTurn.currentPosition()-50)
                    break;
                case 'T': //level 10 left
                    stepperTurn.setMaxSpeed(10*MaxSpeedMulitplierTurn);
                    stepperTurn.moveTo(stepperTurn.currentPosition()-50)
                    break;
            }
        }
		}
		if(axes[1] != 0){

		}

    axes[0] = 0;
    axes[1] = 0;

    stepperTurn.run();
    stepperTilt.run();
}
}
