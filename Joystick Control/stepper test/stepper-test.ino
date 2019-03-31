#include <Wire.h>
#include <AccelStepper.h>
#include <Adafruit_MotorShield.h>

Adafruit_MotorShield AFMStop = Adafruit_MotorShield();

// Connect two steppers with 200 steps per revolution (1.8 degree)
// to the top shield
Adafruit_StepperMotor *myStepper1 = AFMStop.getStepper(200, 1);
Adafruit_StepperMotor *myStepper2 = AFMStop.getStepper(200, 2);

float f;

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
  myStepper2->onestep(FORWARD, MICROSTEP);
}
  void backwardstep2() {  
  myStepper2->onestep(BACKWARD, MICROSTEP);
}

// Now we'll wrap the 3 steppers in an AccelStepper object
AccelStepper stepper1(forwardstep1, backwardstep1);
AccelStepper stepper2(forwardstep2, backwardstep2);

void setup()
{  
  AFMStop.begin(); // Start the top shield

  Serial.begin(9600);
  
  stepper1.setMaxSpeed(100.0);
  stepper1.setAcceleration(200.0);
  stepper1.moveTo(0);
    
  stepper2.setMaxSpeed(100.0);
  stepper2.setAcceleration(20.0);

}

void loop()
{
    // Change direction at the limits
  
        // send data only when you receive data:
    while(Serial.available() > 0) {
        // read the incoming byte:
        f = Serial.parseFloat();

        if (f != 0){
            
            stepper2.moveTo(f);
        }

    stepper1.run();
    stepper2.run();
}
}
