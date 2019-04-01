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

        Serial.readBytesUntil('\n', axes, 2);

        for (int i = 0; i < 2; i++){
          Serial.print(axes[i]);
        }

		if (axes[0] != 0){
			switch(axes[0]){
				case 'a': //level 1 up

                    break;
                case 'b': //level2 up

                    break;
                case 'c': //level3 up

                    break;
                case 'd': //level4 up

                    break;
                case 'e': //level5 up

                    break;
                case 'f': //level6 up

                    break;
                case 'g': //level 7 up

                    break;
                case 'h': //level 8 up

                    break;
                case 'i': //level 9 up

                    break;
                case 'j': //level 10 up

                    break;
                
                case 'k': //level 1 down

                    break;
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
