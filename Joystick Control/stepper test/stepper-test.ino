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

bool vertUp, horRight;

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
        byte axes[4];

        Serial.readBytesUntil('\n', axes, 4);

        for (int i = 0; i < 4; i++){
          Serial.print(axes[i]);
        }

        if (axes[0] != 0 || axes[2] != 0){
			if (axes[0] != 0) {

				if (axes[1] == 1) {
					vertUp = true;
				}else{
					vertUp = false;
				}

				if (vertUp == true){
					stepperTilt.moveTo(stepperTilt.currentPosition()+50);
					stepperTilt.setMaxSpeed(axes[0]);
				}else {
					stepperTilt.setMaxSpeed(axes[0] * -1);
					stepperTilt.moveTo(stepperTilt.currentPosition()+50);
				}
			}

			if (axes[2] != 0) {
				if (axes[3] == 1){
					horRight = true;
				}else {
					horRight = false;
				}
			}

			if (horRight == true) {
				stepperTurn.moveTo(stepperTurn.currentPosition()+50);
				stepperTurn.setMaxSpeed(axes[2]);
			}else {
				stepperTurn.moveTo(stepperTurn.currentPosition()+50);
				stepperTurn.setMaxSpeed(axes[2] * -1);
			}
        }

    axes[0] = 0;
	axes[2] = 0;

    stepperTurn.run();
    stepperTilt.run();
}
}
