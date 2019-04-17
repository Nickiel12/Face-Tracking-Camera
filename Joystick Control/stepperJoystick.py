import arduinoController as ardCon

controller = ardCon.Controller('/dev/ttyACM0')
stepper = controller.Stepper()
joystick = ardCon.Joystick(stepper, 0)

joystick.begin_joystick()